#include <iostream>

#include <sndfile.h>

#include "dsp.hpp"
#include "process.hpp"

int main(const int argc, char* argv[]) {
    const int sr = std::stoi(argv[1]);
    const int bfsize = std::stoi(argv[2]);
    const char* matfile = argv[3];

    UI ui;
    PhyModel model;
    model.init(sr);
    model.buildUserInterface(&ui);

    SF_INFO in_info = { sr, sr, 3, SF_FORMAT_MAT5 | SF_FORMAT_FLOAT | SF_ENDIAN_LITTLE, 0, 0};
    SNDFILE* in_sf = sf_open(matfile, SFM_READ, &in_info);

    SF_INFO out_info = { sr, sr, model.getNumOutputs(), SF_FORMAT_WAV | SF_FORMAT_FLOAT | SF_ENDIAN_LITTLE, 0, 0};
    SNDFILE* out_sf = sf_open("out.wav", SFM_WRITE, &out_info);

    Interleaver ilv(bfsize, model.getNumOutputs(), model.getNumOutputs());
    for (;;) {
        float buf[3];
        int count = sf_read_float(in_sf, buf, 3);
        if ( count != 3) {
            break;
        }

        float p = buf[0];
        float c = buf[1];
        float l = buf[2];

        *ui.freq = p;
        //*ui.gate = 1.0;
        *ui.gain = l * 0.25;

        model.compute(bfsize, nullptr, ilv.inputs());
        ilv.interleave();
        sf_write_float(out_sf, ilv.output(), bfsize *  model.getNumOutputs());
    }

    sf_close(out_sf);
    sf_close(in_sf);
    return 0;
}
