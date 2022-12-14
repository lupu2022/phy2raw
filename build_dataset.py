import yaml
import pathlib
import librosa as li
from effortless_config import Config
import numpy as np
from tqdm import tqdm
import numpy as np
from os import makedirs, path
import os
import soundfile as sf
from scipy.io import wavfile, savemat
import pyloudnorm as pyln
import crepe
import torch
import subprocess

def extract_loudness(signal, sampling_rate, block_size, n_fft=2048):
    S = li.stft (
        signal,
        n_fft=n_fft,
        hop_length=block_size,
        win_length=n_fft,
        center=True,
    )

    S = abs(S);
    S = np.mean(S, 0)[..., :-1]

    return S;

def extract_pitch(signal, sampling_rate, block_size):
    length = signal.shape[-1] // block_size
    f0 = crepe.predict(
        signal,
        sampling_rate,
        step_size=int(1000 * block_size / sampling_rate),
        verbose=1,
        center=True,
        viterbi=True,
    )
    conf = f0[2].reshape(-1)[:-1]
    f0 = f0[1].reshape(-1)[:-1]

    conf[ np.isnan(conf) ] = 1.0
    f0[ np.isnan(conf) ] = 0.0

    if f0.shape[-1] != length:
        f0 = np.interp(
            np.linspace(0, 1, length, endpoint=False),
            np.linspace(0, 1, f0.shape[-1], endpoint=False),
            f0,
        )
        conf = np.interp(
            np.linspace(0, 1, length, endpoint=False),
            np.linspace(0, 1, conf.shape[-1], endpoint=False),
            conf,
        )

    return f0, conf

def physical_mode(sr, bs, p, c, l) :
    p = p.reshape(1, -1);
    c = c.reshape(1, -1);
    l = l.reshape(1, -1);

    r = np.concatenate([p,c,l], 0);
    savemat('perf.mat', {'array': r});

    cmd = "./phy/process " + str(sr) + " " +  str(bs) +  " perf.mat";
    os.system(cmd);
    x, sr = li.load("out.wav", sr=sr)
    os.system("rm -f out.wav perf.mat");

    return x

def get_files(data_location, extension, **kwargs):
    return list(pathlib.Path(data_location).rglob(f"*.{extension}"))

dropped = 0
def preprocess(f, sampling_rate, block_size, signal_length, conf_threshold, **kwargs):
    y, sr = li.load(f, sr=sampling_rate)
    N = (signal_length - len(y) % signal_length) % signal_length
    y = np.pad(y, (0, N))

    pitch, conf = extract_pitch(y, sampling_rate, block_size)
    loudness = extract_loudness(y, sampling_rate, block_size)

    '''
    generated physical model output
    '''
    x = physical_mode(sampling_rate, block_size, pitch, conf, loudness);

    hop_size = int( signal_length )
    hop_num = int( x.shape[0] / hop_size)

    assert( sr == sampling_rate)
    assert( int(hop_size/block_size) * block_size == hop_size)

    xx = []
    yy = []
    for h in range(0, hop_num):
        left = h * hop_size
        right = left + signal_length

        bleft = int(left / block_size)
        bright = int(right / block_size)

        mean_conf = np.mean(conf[bleft:bright])
        if (mean_conf >= conf_threshold):
            yy.append( y[left:right] )
            xx.append( x[left:right] )
        else:
            global dropped
            dropped = dropped + 1

    if len(xx) > 0:
        x = np.concatenate(xx, 0)
        y = np.concatenate(yy, 0)

        x = x.reshape(-1, signal_length)
        y = y.reshape(-1, signal_length)
        return x, y
    else:
        return [], []

class Dataset(torch.utils.data.Dataset):
    def __init__(self, out_dir, is_train):
        super().__init__()
        self.inputs = np.load(path.join(out_dir, "inputs.npy"))
        self.outputs = np.load(path.join(out_dir, "outputs.npy"))

        self.is_train = is_train;
        self.split = int(self.inputs.shape[0] * 0.10);

    def __len__(self):
        if ( self.is_train ) :
            return self.inputs.shape[0] - self.split
        return self.split;

    def __getitem__(self, idx):
        if ( self.is_train ) :
            idx = idx + self.split

        x = torch.from_numpy(self.inputs[idx])
        y = torch.from_numpy(self.outputs[idx])
        return x, y

def main():
    class args(Config):
        CONFIG = "config.yaml"

    args.parse_args()
    with open(args.CONFIG, "r") as config:
        config = yaml.safe_load(config)

    files = get_files(**config["preprocess"])
    pb = tqdm(files)

    ins = []
    outs = []

    num = 0
    for f in pb:
        pb.set_description(str(f))
        x, y = preprocess(f, **config["preprocess"])
        if len(x) > 0:
            num = num + x.shape[0]
            ins.append(x)
            outs.append(y)
            print("Current sample number = %d, dropped = " % num, dropped)

    ins = np.concatenate(ins, 0).astype(np.float32)
    outs = np.concatenate(outs, 0).astype(np.float32)

    out_dir = config["preprocess"]["out_dir"]
    makedirs(out_dir, exist_ok=True)

    np.save(path.join(out_dir, "inputs.npy"), ins)
    np.save(path.join(out_dir, "outputs.npy"), outs)

class args(Config):
    CONFIG = "config.yaml"

def test():
    args.parse_args()
    with open(args.CONFIG, "r") as config:
        config = yaml.safe_load(config)

    dataset = Dataset(config["preprocess"]["out_dir"], True)
    x, y = dataset[100]
    sf.write("x.wav", x, 16000);
    sf.write("y.wav", y, 16000);

if __name__ == "__main__":
    main()
    #test()
