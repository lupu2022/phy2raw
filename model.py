import torch
import torch.nn as nn
import torch.fft as fft
import torch.nn.functional as F
import numpy as np
import math
import msgpack
import yaml
import sys

def multiscale_fft(signal, scales, overlap):
    stfts = []
    for s in scales:
        S = torch.stft(
            signal,                     ## input
            s,                          ## n_fft
            int(s * (1 - overlap)),     ## hop_length
            s,                          ## win_length
            torch.hann_window(s).to(signal),
            True,
            normalized=True,
            return_complex=True,
        ).abs()
        stfts.append(S)
    return stfts

def safe_log(x):
    return torch.log(x + 1e-7)

def multiscale_loss(s, y, scales, overlap, weights):
    ori_stft = multiscale_fft(s, scales, overlap)
    rec_stft = multiscale_fft(y, scales, overlap)

    loss = 0
    for i in range(0, len(ori_stft)):
        s_x = ori_stft[i];
        s_y = rec_stft[i];
        lin_loss = (s_x - s_y).abs().mean()
        log_loss = (safe_log(s_x) - safe_log(s_y)).abs().mean()
        loss = loss + (lin_loss + log_loss) * weights[i]

    return loss


class CausalConv1d(torch.nn.Conv1d):
    def __init__(self, in_channels, out_channels, kernel_size, stride=1, dilation=1, groups=1, bias=True):
        self.__padding = (kernel_size - 1) * dilation

        super(CausalConv1d, self).__init__(
            in_channels,
            out_channels,
            kernel_size=kernel_size,
            stride=stride,
            padding=self.__padding,
            dilation=dilation,
            groups=groups,
            bias=bias,
        )

    def forward(self, input):
        result = super(CausalConv1d, self).forward(input)
        if self.__padding != 0:
            return result[:, :, : -self.__padding]
        return result


def _conv_stack(dilations, in_channels, out_channels, kernel_size):
    """
    Create stack of dilated convolutional layers, outlined in WaveNet paper:
    https://arxiv.org/pdf/1609.03499.pdf
    """
    return nn.ModuleList(
        [
            CausalConv1d(
                in_channels=in_channels,
                out_channels=out_channels,
                dilation=d,
                kernel_size=kernel_size,
            )
            for i, d in enumerate(dilations)
        ]
    )

class WaveNet(nn.Module):
    def __init__(self, num_channels, dilation_depth, num_repeat, kernel_size=3):
        super(WaveNet, self).__init__()
        dilations = [2 ** d for d in range(dilation_depth)] * num_repeat
        internal_channels = int(num_channels * 2)
        self.hidden = _conv_stack(dilations, num_channels, internal_channels, kernel_size)
        self.residuals = _conv_stack(dilations, num_channels, num_channels, 1)
        self.input_layer = CausalConv1d(
            in_channels=1,
            out_channels=num_channels,
            kernel_size=1,
        )

        self.linear_mix = nn.Conv1d(
            in_channels=num_channels * dilation_depth * num_repeat,
            out_channels=1,
            kernel_size=1,
        )
        self.num_channels = num_channels

    def forward(self, x):
        out = x
        skips = []
        out = self.input_layer(out)

        for hidden, residual in zip(self.hidden, self.residuals):
            x = out
            out_hidden = hidden(x)

            # gated activation
            #   split (32,16,3) into two (16,16,3) for tanh and sigm calculations
            out_hidden_split = torch.split(out_hidden, self.num_channels, dim=1)
            out = torch.tanh(out_hidden_split[0]) * torch.sigmoid(out_hidden_split[1])

            skips.append(out)

            out = residual(out)
            out = out + x[:, :, -out.size(2) :]

        # modified "postprocess" step:
        out = torch.cat([s[:, :, -out.size(2) :] for s in skips], dim=1)
        out = self.linear_mix(out)
        return out


def fft_convolve(signal, kernel):
    signal = nn.functional.pad(signal, (0, signal.shape[-1]))
    kernel = nn.functional.pad(kernel, (kernel.shape[-1], 0))

    output = fft.irfft(fft.rfft(signal) * fft.rfft(kernel))
    output = output[..., output.shape[-1] // 2:]

    return output

class Reverb(nn.Module):
    def __init__(self, length, sampling_rate, initial_wet=0, initial_decay=5):
        super().__init__()
        self.length = length
        self.sampling_rate = sampling_rate

        self.noise = nn.Parameter((torch.rand(length) * 2 - 1).unsqueeze(-1))
        self.decay = nn.Parameter(torch.tensor(float(initial_decay)))
        self.wet = nn.Parameter(torch.tensor(float(initial_wet)))

        t = torch.arange(self.length) / self.sampling_rate
        t = t.reshape(1, -1, 1)
        self.register_buffer("t", t)

    def build_impulse(self):
        t = torch.exp(-nn.functional.softplus(-self.decay) * self.t * 500)
        noise = self.noise * t
        impulse = noise * torch.sigmoid(self.wet)
        impulse[:, 0] = 1
        return impulse

    def forward(self, x):
        lenx = x.shape[1]
        impulse = self.build_impulse()
        impulse = nn.functional.pad(impulse, (0, 0, 0, lenx - self.length))

        x = fft_convolve(x.squeeze(-1), impulse.squeeze(-1)).unsqueeze(-1)

        return x

class Phy2Raw(nn.Module):
    def __init__(self, sampling_rate, num_channels, dilations, repeat, kernel_size, reverb_length):
        super().__init__();
        self.filter = WaveNet(num_channels, dilations, repeat, kernel_size);
        self.reverb = Reverb(reverb_length, sampling_rate);

    def forward(self, x):
        '''
        x_ = self.reverb(x).squeeze(-1).unsqueeze(1);
        y_ = self.filter(x_);

        return y_.squeeze(1);
        '''

        x_ = x.unsqueeze(1);
        x_ = self.filter(x_);
        x_ = x_.squeeze(1);
        y_ = self.reverb(x_);

        return y_.squeeze(-1);


def dump(model):
    model.eval()
    sdict = model.state_dict()

    allWeights = [];
    for k in sdict.keys():
        t = sdict[k]

        if k.startswith("reverb"):
            continue

        print(k, t.shape)
        if len(t.shape) > 0:
            vlist = t.numpy().flatten().tolist()
            allWeights.append({k: vlist})

    with open("weights.yaml", "w") as f:
        f.write( yaml.dump(allWeights) );

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Please input config_file weight_file");
        sys.exit(0);

    with open(sys.argv[1], "r") as data:
        config = yaml.safe_load(data)

    config = config["model"];
    model = Phy2Raw(**config)

    result = model.load_state_dict( torch.load( sys.argv[2], map_location=torch.device('cpu')), False)
    assert( len(result.missing_keys) == 0)

    dump(model);

    '''
    model.eval()
    x = torch.ones(1, 1, 64) * 0.5;
    out = model.filter(x)
    '''


