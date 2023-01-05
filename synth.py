import torch
from torch.utils.tensorboard import SummaryWriter
import yaml
from effortless_config import Config
from os import path
from tqdm import tqdm
import soundfile as sf
from einops import rearrange
import numpy as np
import librosa as li
import sys

from model import Phy2Raw

def do_synth(configFile, pthFile, wavFile):
    with open(configFile, "r") as config:
        config = yaml.safe_load(config)


    device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")

    model = Phy2Raw(**config["model"]).to(device)
    model.load_state_dict( torch.load(pthFile), True);
    model.eval();

    config = config["preprocess"];
    x, sr = li.load(wavFile, sr=config["sampling_rate"]);

    x = torch.from_numpy(x)
    x = x.reshape(1, -1);
    x = x.to(device);

    y = model(x);

    audio = y.reshape(-1).detach().cpu().numpy()
    sf.write(
        "out_.wav",
        audio,
        config["sampling_rate"],
    )

    return y;

if __name__ == "__main__":
    if len(sys.argv) < 4:
        print("Please input config_file weight_file source_file");
        sys.exit(0);

    configFile = sys.argv[1];
    pthFile = sys.argv[2];
    wavFile = sys.argv[3];

    out = do_synth(configFile, pthFile, wavFile);

