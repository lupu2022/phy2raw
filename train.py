import torch
from torch.utils.tensorboard import SummaryWriter
import yaml
from effortless_config import Config
from os import path
from tqdm import tqdm
import soundfile as sf
from einops import rearrange
import numpy as np

from build_dataset import Dataset
from model import Phy2Raw, multiscale_fft, multiscale_loss

class args(Config):
    CONFIG = "config.yaml"
    NAME = "debug"
    ROOT = "runs"
    STEPS = 10000
    BATCH = 16
    LR = 1e-3

def do_train():
    args.parse_args()

    with open(args.CONFIG, "r") as config:
        config = yaml.safe_load(config)

    device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")

    model = Phy2Raw(**config["model"]).to(device)
    #model.load_state_dict( torch.load('./state_000038.pth'), True);

    dataset = Dataset(config["preprocess"]["out_dir"], True)
    dataloader = torch.utils.data.DataLoader(
        dataset,
        args.BATCH,
        True,
        drop_last=True,
    )

    writer = SummaryWriter(path.join(args.ROOT, args.NAME), flush_secs=20)

    with open(path.join(args.ROOT, args.NAME, "config.yaml"), "w") as out_config:
        yaml.safe_dump(config, out_config)

    opt = torch.optim.Adam(model.parameters(), lr=args.LR)

    best_loss = float("inf")
    mean_loss = 0
    n_element = 0
    step = 0
    epochs = int(np.ceil(args.STEPS / len(dataloader)))

    for e in tqdm(range(epochs)):
        for x,y in dataloader:
            y = y.to(device);
            x = x.to(device).unsqueeze(1);
            y_ = model(x);

            loss = multiscale_loss(y, y_, config["train"]["scales"], config["train"]["overlap"], config["train"]["weights"])

            opt.zero_grad()
            loss.backward()
            opt.step()

            writer.add_scalar("loss", loss.item(), step)

            step += 1

            n_element += 1
            mean_loss += (loss.item() - mean_loss) / n_element

            print("==============>", step, mean_loss, loss.item() )

        if not e % 2:
            writer.add_scalar("reverb_decay", model.reverb.decay.item(), e)
            writer.add_scalar("reverb_wet", model.reverb.wet.item(), e)

            if mean_loss < best_loss:
                best_loss = mean_loss
                torch.save(
                    model.state_dict(),
                    path.join(args.ROOT, args.NAME, f"state_{e:06d}.pth"),
                )

            mean_loss = 0
            n_element = 0

            audio = torch.cat([y, y_], -1).reshape(-1).detach().cpu().numpy()
            sf.write(
                path.join(args.ROOT, args.NAME, f"eval_{e:06d}.wav"),
                audio,
                config["preprocess"]["sampling_rate"],
            )

if __name__ == "__main__":
    do_train()
