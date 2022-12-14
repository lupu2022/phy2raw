/* ------------------------------------------------------------
name: "clarinet"
Code generated with Faust 2.54.8 (https://faust.grame.fr)
Compilation options: -lang cpp -cn PhyModel -es 1 -mcd 16 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __PhyModel_H__
#define  __PhyModel_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS PhyModel
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

class PhyModelSIG0 {
	
  private:
	
	int iVec1[2];
	int iRec14[2];
	
  public:
	
	int getNumInputsPhyModelSIG0() {
		return 0;
	}
	int getNumOutputsPhyModelSIG0() {
		return 1;
	}
	
	void instanceInitPhyModelSIG0(int sample_rate) {
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			iVec1[l4] = 0;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			iRec14[l5] = 0;
		}
	}
	
	void fillPhyModelSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec1[0] = 1;
			iRec14[0] = (iVec1[1] + iRec14[1]) % 65536;
			table[i1] = std::sin(9.58738e-05f * float(iRec14[0]));
			iVec1[1] = iVec1[0];
			iRec14[1] = iRec14[0];
		}
	}

};

static PhyModelSIG0* newPhyModelSIG0() { return (PhyModelSIG0*)new PhyModelSIG0(); }
static void deletePhyModelSIG0(PhyModelSIG0* dsp) { delete dsp; }

static float PhyModel_faustpower2_f(float value) {
	return value * value;
}
static float ftbl0PhyModelSIG0[65536];

class PhyModel : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst3;
	float fConst4;
	float fConst6;
	float fConst7;
	float fRec11[2];
	float fConst8;
	float fRec10[2];
	int IOTA0;
	float fVec0[16384];
	int iConst10;
	float fConst11;
	float fConst12;
	FAUSTFLOAT fHslider1;
	float fRec12[2];
	float fConst13;
	float fRec15[2];
	FAUSTFLOAT fButton0;
	float fVec2[2];
	int iRec16[2];
	int iRec17[2];
	float fConst14;
	float fConst15;
	float fConst16;
	float fRec18[2];
	int iRec19[2];
	float fConst17;
	float fRec20[2];
	float fConst18;
	FAUSTFLOAT fEntry0;
	float fConst19;
	float fRec22[2];
	float fRec28[2];
	float fRec27[2];
	float fRec26[2];
	float fRec25[2];
	float fRec24[2];
	float fRec23[2];
	float fRec21[2];
	float fRec13[8192];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fEntry1;
	float fVec3[4096];
	int iConst20;
	float fVec4[4096];
	int iConst21;
	float fRec8[2];
	float fConst24;
	float fRec32[2];
	float fConst25;
	float fRec31[2];
	float fVec5[16384];
	int iConst27;
	float fVec6[2048];
	int iConst28;
	float fRec29[2];
	float fConst31;
	float fRec36[2];
	float fConst32;
	float fRec35[2];
	float fVec7[16384];
	int iConst34;
	float fVec8[4096];
	int iConst35;
	float fRec33[2];
	float fConst38;
	float fRec40[2];
	float fConst39;
	float fRec39[2];
	float fVec9[16384];
	int iConst41;
	float fVec10[2048];
	int iConst42;
	float fRec37[2];
	float fConst45;
	float fRec44[2];
	float fConst46;
	float fRec43[2];
	float fVec11[32768];
	int iConst48;
	float fVec12[8192];
	FAUSTFLOAT fHslider3;
	float fVec13[4096];
	float fVec14[4096];
	int iConst49;
	float fRec41[2];
	float fConst52;
	float fRec48[2];
	float fConst53;
	float fRec47[2];
	float fVec15[16384];
	int iConst55;
	float fVec16[4096];
	int iConst56;
	float fRec45[2];
	float fConst59;
	float fRec52[2];
	float fConst60;
	float fRec51[2];
	float fVec17[32768];
	int iConst62;
	float fVec18[4096];
	int iConst63;
	float fRec49[2];
	float fConst66;
	float fRec56[2];
	float fConst67;
	float fRec55[2];
	float fVec19[32768];
	int iConst69;
	float fVec20[2048];
	int iConst70;
	float fRec53[2];
	float fRec0[3];
	float fRec1[3];
	float fRec2[3];
	float fRec3[3];
	float fRec4[3];
	float fRec5[3];
	float fRec6[3];
	float fRec7[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.8");
		m->declare("compile_options", "-lang cpp -cn PhyModel -es 1 -mcd 16 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("envelopes.lib/adsr:author", "Yann Orlarey and Andrey Bundin");
		m->declare("envelopes.lib/asr:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.2");
		m->declare("filename", "clarinet.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/allpassnn:author", "Julius O. Smith III");
		m->declare("filters.lib/allpassnn:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpassnn:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("instruments.lib/author", "Romain Michon (rmichon@ccrma.stanford.edu)");
		m->declare("instruments.lib/copyright", "Romain Michon");
		m->declare("instruments.lib/licence", "STK-4.3");
		m->declare("instruments.lib/name", "Faust-STK Tools Library");
		m->declare("instruments.lib/version", "1.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "clarinet");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.4");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.3");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "0.2");
		m->declare("routes.lib/hadamard:author", "Remy Muller, revised by Romain Michon");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.3");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	
	static void classInit(int sample_rate) {
		PhyModelSIG0* sig0 = newPhyModelSIG0();
		sig0->instanceInitPhyModelSIG0(sample_rate);
		sig0->fillPhyModelSIG0(65536, ftbl0PhyModelSIG0);
		deletePhyModelSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = std::floor(0.174713f * fConst0 + 0.5f);
		float fConst2 = (0.0f - 6.9077554f * fConst1) / fConst0;
		fConst3 = 0.5f * fConst2;
		fConst4 = std::cos(37699.113f / fConst0);
		float fConst5 = 1.0f / std::tan(628.31854f / fConst0);
		fConst6 = 1.0f - fConst5;
		fConst7 = 1.0f / (fConst5 + 1.0f);
		fConst8 = 0.33333334f * fConst2;
		float fConst9 = std::floor(0.022904f * fConst0 + 0.5f);
		iConst10 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst1 - fConst9)));
		fConst11 = 44.1f / fConst0;
		fConst12 = 1.0f - fConst11;
		fConst13 = 5.0f / fConst0;
		fConst14 = 1.0f - 1.0f / std::pow(1e+05f, 1e+02f / fConst0);
		fConst15 = 0.1f * fConst0;
		fConst16 = 1.1111112f / fConst0;
		fConst17 = 1.0f / std::max<float>(1.0f, fConst15);
		fConst18 = 1.0f / std::max<float>(1.0f, 0.01f * fConst0);
		fConst19 = 0.5f * fConst0;
		iConst20 = int(std::min<float>(8192.0f, std::max<float>(0.0f, 0.02f * fConst0)));
		iConst21 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst9 + -1.0f)));
		float fConst22 = std::floor(0.153129f * fConst0 + 0.5f);
		float fConst23 = (0.0f - 6.9077554f * fConst22) / fConst0;
		fConst24 = 0.5f * fConst23;
		fConst25 = 0.33333334f * fConst23;
		float fConst26 = std::floor(0.020346f * fConst0 + 0.5f);
		iConst27 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst22 - fConst26)));
		iConst28 = int(std::min<float>(1024.0f, std::max<float>(0.0f, fConst26 + -1.0f)));
		float fConst29 = std::floor(0.127837f * fConst0 + 0.5f);
		float fConst30 = (0.0f - 6.9077554f * fConst29) / fConst0;
		fConst31 = 0.5f * fConst30;
		fConst32 = 0.33333334f * fConst30;
		float fConst33 = std::floor(0.031604f * fConst0 + 0.5f);
		iConst34 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst29 - fConst33)));
		iConst35 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst33 + -1.0f)));
		float fConst36 = std::floor(0.125f * fConst0 + 0.5f);
		float fConst37 = (0.0f - 6.9077554f * fConst36) / fConst0;
		fConst38 = 0.5f * fConst37;
		fConst39 = 0.33333334f * fConst37;
		float fConst40 = std::floor(0.013458f * fConst0 + 0.5f);
		iConst41 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst36 - fConst40)));
		iConst42 = int(std::min<float>(1024.0f, std::max<float>(0.0f, fConst40 + -1.0f)));
		float fConst43 = std::floor(0.210389f * fConst0 + 0.5f);
		float fConst44 = (0.0f - 6.9077554f * fConst43) / fConst0;
		fConst45 = 0.5f * fConst44;
		fConst46 = 0.33333334f * fConst44;
		float fConst47 = std::floor(0.024421f * fConst0 + 0.5f);
		iConst48 = int(std::min<float>(16384.0f, std::max<float>(0.0f, fConst43 - fConst47)));
		iConst49 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst47 + -1.0f)));
		float fConst50 = std::floor(0.192303f * fConst0 + 0.5f);
		float fConst51 = (0.0f - 6.9077554f * fConst50) / fConst0;
		fConst52 = 0.5f * fConst51;
		fConst53 = 0.33333334f * fConst51;
		float fConst54 = std::floor(0.029291f * fConst0 + 0.5f);
		iConst55 = int(std::min<float>(8192.0f, std::max<float>(0.0f, fConst50 - fConst54)));
		iConst56 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst54 + -1.0f)));
		float fConst57 = std::floor(0.256891f * fConst0 + 0.5f);
		float fConst58 = (0.0f - 6.9077554f * fConst57) / fConst0;
		fConst59 = 0.5f * fConst58;
		fConst60 = 0.33333334f * fConst58;
		float fConst61 = std::floor(0.027333f * fConst0 + 0.5f);
		iConst62 = int(std::min<float>(16384.0f, std::max<float>(0.0f, fConst57 - fConst61)));
		iConst63 = int(std::min<float>(2048.0f, std::max<float>(0.0f, fConst61 + -1.0f)));
		float fConst64 = std::floor(0.219991f * fConst0 + 0.5f);
		float fConst65 = (0.0f - 6.9077554f * fConst64) / fConst0;
		fConst66 = 0.5f * fConst65;
		fConst67 = 0.33333334f * fConst65;
		float fConst68 = std::floor(0.019123f * fConst0 + 0.5f);
		iConst69 = int(std::min<float>(16384.0f, std::max<float>(0.0f, fConst64 - fConst68)));
		iConst70 = int(std::min<float>(1024.0f, std::max<float>(0.0f, fConst68 + -1.0f)));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.72f);
		fHslider1 = FAUSTFLOAT(0.137f);
		fButton0 = FAUSTFLOAT(0.0f);
		fEntry0 = FAUSTFLOAT(4.4e+02f);
		fHslider2 = FAUSTFLOAT(0.6f);
		fEntry1 = FAUSTFLOAT(1.0f);
		fHslider3 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec11[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec10[l1] = 0.0f;
		}
		IOTA0 = 0;
		for (int l2 = 0; l2 < 16384; l2 = l2 + 1) {
			fVec0[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec12[l3] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec15[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fVec2[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			iRec16[l8] = 0;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			iRec17[l9] = 0;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec18[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			iRec19[l11] = 0;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec20[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			fRec22[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fRec28[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec27[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec26[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec25[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec24[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec23[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec21[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 8192; l21 = l21 + 1) {
			fRec13[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 4096; l22 = l22 + 1) {
			fVec3[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 4096; l23 = l23 + 1) {
			fVec4[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			fRec8[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			fRec32[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			fRec31[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 16384; l27 = l27 + 1) {
			fVec5[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2048; l28 = l28 + 1) {
			fVec6[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			fRec29[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fRec36[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			fRec35[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 16384; l32 = l32 + 1) {
			fVec7[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 4096; l33 = l33 + 1) {
			fVec8[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			fRec33[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fRec40[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			fRec39[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 16384; l37 = l37 + 1) {
			fVec9[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2048; l38 = l38 + 1) {
			fVec10[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = l39 + 1) {
			fRec37[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fRec44[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			fRec43[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 32768; l42 = l42 + 1) {
			fVec11[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 8192; l43 = l43 + 1) {
			fVec12[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 4096; l44 = l44 + 1) {
			fVec13[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 4096; l45 = l45 + 1) {
			fVec14[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = l46 + 1) {
			fRec41[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2; l47 = l47 + 1) {
			fRec48[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 2; l48 = l48 + 1) {
			fRec47[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 16384; l49 = l49 + 1) {
			fVec15[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 4096; l50 = l50 + 1) {
			fVec16[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 2; l51 = l51 + 1) {
			fRec45[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = l52 + 1) {
			fRec52[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 2; l53 = l53 + 1) {
			fRec51[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 32768; l54 = l54 + 1) {
			fVec17[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 4096; l55 = l55 + 1) {
			fVec18[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 2; l56 = l56 + 1) {
			fRec49[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 2; l57 = l57 + 1) {
			fRec56[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 2; l58 = l58 + 1) {
			fRec55[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 32768; l59 = l59 + 1) {
			fVec19[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 2048; l60 = l60 + 1) {
			fVec20[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 2; l61 = l61 + 1) {
			fRec53[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 3; l62 = l62 + 1) {
			fRec0[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 3; l63 = l63 + 1) {
			fRec1[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 3; l64 = l64 + 1) {
			fRec2[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 3; l65 = l65 + 1) {
			fRec3[l65] = 0.0f;
		}
		for (int l66 = 0; l66 < 3; l66 = l66 + 1) {
			fRec4[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 3; l67 = l67 + 1) {
			fRec5[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 3; l68 = l68 + 1) {
			fRec6[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 3; l69 = l69 + 1) {
			fRec7[l69] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual PhyModel* clone() {
		return new PhyModel();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("clarinet");
		ui_interface->openHorizontalBox("Basic_Parameters");
		ui_interface->declare(&fEntry0, "1", "");
		ui_interface->declare(&fEntry0, "tooltip", "Tone frequency");
		ui_interface->declare(&fEntry0, "unit", "Hz");
		ui_interface->addNumEntry("freq", &fEntry0, FAUSTFLOAT(4.4e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fEntry1, "1", "");
		ui_interface->declare(&fEntry1, "tooltip", "Gain (value between 0 and 1)");
		ui_interface->addNumEntry("gain", &fEntry1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fButton0, "1", "");
		ui_interface->declare(&fButton0, "tooltip", "noteOn = 1, noteOff = 0");
		ui_interface->addButton("gate", &fButton0);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Reverb");
		ui_interface->addHorizontalSlider("reverbGain", &fHslider1, FAUSTFLOAT(0.137f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("roomSize", &fHslider0, FAUSTFLOAT(0.72f), FAUSTFLOAT(0.01f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->openVerticalBox("Spat");
		ui_interface->addHorizontalSlider("pan angle", &fHslider2, FAUSTFLOAT(0.6f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("spatial width", &fHslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		float fSlow1 = std::exp(fConst3 / fSlow0);
		float fSlow2 = PhyModel_faustpower2_f(fSlow1);
		float fSlow3 = 1.0f - fSlow2;
		float fSlow4 = 1.0f - fConst4 * fSlow2;
		float fSlow5 = std::sqrt(std::max<float>(0.0f, PhyModel_faustpower2_f(fSlow4) / PhyModel_faustpower2_f(fSlow3) + -1.0f));
		float fSlow6 = fSlow4 / fSlow3;
		float fSlow7 = fSlow6 - fSlow5;
		float fSlow8 = std::exp(fConst8 / fSlow0) / fSlow1 + -1.0f;
		float fSlow9 = fSlow1 * (fSlow5 + (1.0f - fSlow6));
		float fSlow10 = fConst11 * float(fHslider1);
		float fSlow11 = float(fButton0);
		int iSlow12 = fSlow11 > 0.0f;
		int iSlow13 = fSlow11 <= 0.0f;
		int iSlow14 = fSlow11 == 0.0f;
		float fSlow15 = float(fEntry0);
		float fSlow16 = fConst19 / fSlow15;
		float fSlow17 = fSlow16 + -1.5f;
		int iSlow18 = int(fSlow17);
		int iSlow19 = std::min<int>(4097, std::max<int>(0, iSlow18 + 1)) + 1;
		float fSlow20 = std::floor(fSlow17);
		float fSlow21 = fSlow16 + (-1.5f - fSlow20);
		int iSlow22 = std::min<int>(4097, std::max<int>(0, iSlow18)) + 1;
		float fSlow23 = fSlow20 + (2.5f - fSlow16);
		float fSlow24 = float(fHslider2);
		float fSlow25 = float(fEntry1);
		float fSlow26 = 2.5f * fSlow25 * (1.0f - fSlow24);
		float fSlow27 = std::exp(fConst24 / fSlow0);
		float fSlow28 = PhyModel_faustpower2_f(fSlow27);
		float fSlow29 = 1.0f - fSlow28;
		float fSlow30 = 1.0f - fConst4 * fSlow28;
		float fSlow31 = std::sqrt(std::max<float>(0.0f, PhyModel_faustpower2_f(fSlow30) / PhyModel_faustpower2_f(fSlow29) + -1.0f));
		float fSlow32 = fSlow30 / fSlow29;
		float fSlow33 = fSlow32 - fSlow31;
		float fSlow34 = std::exp(fConst25 / fSlow0) / fSlow27 + -1.0f;
		float fSlow35 = fSlow27 * (fSlow31 + (1.0f - fSlow32));
		float fSlow36 = std::exp(fConst31 / fSlow0);
		float fSlow37 = PhyModel_faustpower2_f(fSlow36);
		float fSlow38 = 1.0f - fSlow37;
		float fSlow39 = 1.0f - fConst4 * fSlow37;
		float fSlow40 = std::sqrt(std::max<float>(0.0f, PhyModel_faustpower2_f(fSlow39) / PhyModel_faustpower2_f(fSlow38) + -1.0f));
		float fSlow41 = fSlow39 / fSlow38;
		float fSlow42 = fSlow41 - fSlow40;
		float fSlow43 = std::exp(fConst32 / fSlow0) / fSlow36 + -1.0f;
		float fSlow44 = fSlow36 * (fSlow40 + (1.0f - fSlow41));
		float fSlow45 = std::exp(fConst38 / fSlow0);
		float fSlow46 = PhyModel_faustpower2_f(fSlow45);
		float fSlow47 = 1.0f - fSlow46;
		float fSlow48 = 1.0f - fConst4 * fSlow46;
		float fSlow49 = std::sqrt(std::max<float>(0.0f, PhyModel_faustpower2_f(fSlow48) / PhyModel_faustpower2_f(fSlow47) + -1.0f));
		float fSlow50 = fSlow48 / fSlow47;
		float fSlow51 = fSlow50 - fSlow49;
		float fSlow52 = std::exp(fConst39 / fSlow0) / fSlow45 + -1.0f;
		float fSlow53 = fSlow45 * (fSlow49 + (1.0f - fSlow50));
		float fSlow54 = std::exp(fConst45 / fSlow0);
		float fSlow55 = PhyModel_faustpower2_f(fSlow54);
		float fSlow56 = 1.0f - fSlow55;
		float fSlow57 = 1.0f - fConst4 * fSlow55;
		float fSlow58 = std::sqrt(std::max<float>(0.0f, PhyModel_faustpower2_f(fSlow57) / PhyModel_faustpower2_f(fSlow56) + -1.0f));
		float fSlow59 = fSlow57 / fSlow56;
		float fSlow60 = fSlow59 - fSlow58;
		float fSlow61 = std::exp(fConst46 / fSlow0) / fSlow54 + -1.0f;
		float fSlow62 = fSlow54 * (fSlow58 + (1.0f - fSlow59));
		float fSlow63 = 2.5f * fSlow25;
		int iSlow64 = int(std::min<float>(4096.0f, std::max<float>(0.0f, fConst19 * (float(fHslider3) / fSlow15))));
		float fSlow65 = std::exp(fConst52 / fSlow0);
		float fSlow66 = PhyModel_faustpower2_f(fSlow65);
		float fSlow67 = 1.0f - fSlow66;
		float fSlow68 = 1.0f - fConst4 * fSlow66;
		float fSlow69 = std::sqrt(std::max<float>(0.0f, PhyModel_faustpower2_f(fSlow68) / PhyModel_faustpower2_f(fSlow67) + -1.0f));
		float fSlow70 = fSlow68 / fSlow67;
		float fSlow71 = fSlow70 - fSlow69;
		float fSlow72 = std::exp(fConst53 / fSlow0) / fSlow65 + -1.0f;
		float fSlow73 = fSlow65 * (fSlow69 + (1.0f - fSlow70));
		float fSlow74 = std::exp(fConst59 / fSlow0);
		float fSlow75 = PhyModel_faustpower2_f(fSlow74);
		float fSlow76 = 1.0f - fSlow75;
		float fSlow77 = 1.0f - fConst4 * fSlow75;
		float fSlow78 = std::sqrt(std::max<float>(0.0f, PhyModel_faustpower2_f(fSlow77) / PhyModel_faustpower2_f(fSlow76) + -1.0f));
		float fSlow79 = fSlow77 / fSlow76;
		float fSlow80 = fSlow79 - fSlow78;
		float fSlow81 = std::exp(fConst60 / fSlow0) / fSlow74 + -1.0f;
		float fSlow82 = fSlow74 * (fSlow78 + (1.0f - fSlow79));
		float fSlow83 = std::exp(fConst66 / fSlow0);
		float fSlow84 = PhyModel_faustpower2_f(fSlow83);
		float fSlow85 = 1.0f - fSlow84;
		float fSlow86 = 1.0f - fConst4 * fSlow84;
		float fSlow87 = std::sqrt(std::max<float>(0.0f, PhyModel_faustpower2_f(fSlow86) / PhyModel_faustpower2_f(fSlow85) + -1.0f));
		float fSlow88 = fSlow86 / fSlow85;
		float fSlow89 = fSlow88 - fSlow87;
		float fSlow90 = std::exp(fConst67 / fSlow0) / fSlow83 + -1.0f;
		float fSlow91 = fSlow83 * (fSlow87 + (1.0f - fSlow88));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec11[0] = 0.0f - fConst7 * (fConst6 * fRec11[1] - (fRec4[1] + fRec4[2]));
			fRec10[0] = fSlow9 * (fRec4[1] + fSlow8 * fRec11[0]) + fSlow7 * fRec10[1];
			fVec0[IOTA0 & 16383] = 0.35355338f * fRec10[0] + 1e-20f;
			fRec12[0] = fSlow10 + fConst12 * fRec12[1];
			fRec15[0] = fConst13 + (fRec15[1] - std::floor(fConst13 + fRec15[1]));
			fVec2[0] = fSlow11;
			iRec16[0] = iSlow12 & (iRec16[1] | (fRec18[1] >= 1.0f));
			iRec17[0] = iSlow12 * (iRec17[1] + 1);
			int iTemp0 = iSlow13 & (fRec18[1] > 0.0f);
			float fTemp1 = float(iRec17[1]);
			fRec18[0] = (fConst16 * float(((((iRec16[1] == 0) & iSlow12) & (fRec18[1] < 1.0f)) & (fTemp1 > fConst15)) * (1 - (fTemp1 < fConst15))) + fRec18[1] * (1.0f - fConst14 * float(iTemp0))) * float((iTemp0 == 0) | (fRec18[1] >= 1e-06f));
			iRec19[0] = iSlow14 * (iRec19[1] + 1);
			float fTemp2 = fConst17 * float(iRec19[0]);
			fRec20[0] = fSlow11 + fRec20[1] * float(fVec2[1] >= fSlow11);
			float fTemp3 = std::max<float>(0.0f, std::min<float>(fConst18 * fRec20[0], 1.0f) * (1.0f - fTemp2)) * (0.09f * fRec18[0] * ftbl0PhyModelSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec15[0]), 65535))] + 0.9f);
			float fTemp4 = fSlow23 * fRec13[(IOTA0 - iSlow22) & 8191] + fSlow21 * fRec13[(IOTA0 - iSlow19) & 8191];
			fRec22[0] = fConst12 * fRec22[1];
			float fTemp5 = 3.1415927f * fRec22[0] * fTemp4 * std::max<float>(0.0f, std::min<float>(fConst17 * fRec20[0], 1.0f) - fTemp2);
			float fTemp6 = std::cos(fTemp5);
			float fTemp7 = std::sin(fTemp5);
			float fTemp8 = fTemp4 * fTemp6 - fTemp7 * fRec23[1];
			float fTemp9 = fTemp6 * fTemp8 - fTemp7 * fRec24[1];
			float fTemp10 = fTemp6 * fTemp9 - fTemp7 * fRec25[1];
			float fTemp11 = fTemp6 * fTemp10 - fTemp7 * fRec26[1];
			float fTemp12 = fTemp6 * fTemp11 - fTemp7 * fRec27[1];
			fRec28[0] = fTemp6 * fTemp12 - fTemp7 * fRec28[1];
			fRec27[0] = fTemp7 * fTemp12 + fTemp6 * fRec28[1];
			fRec26[0] = fTemp7 * fTemp11 + fTemp6 * fRec27[1];
			fRec25[0] = fTemp7 * fTemp10 + fTemp6 * fRec26[1];
			fRec24[0] = fTemp7 * fTemp9 + fTemp6 * fRec25[1];
			fRec23[0] = fTemp7 * fTemp8 + fTemp6 * fRec24[1];
			fRec21[0] = 0.5f * (fRec21[1] + fRec22[0] * (fTemp4 * fTemp7 + fRec23[1] * fTemp6) + (1.0f - fRec22[0]) * fTemp4);
			float fTemp13 = 0.0f - (0.95f * fRec21[0] + fTemp3);
			float fTemp14 = 0.7f - 0.31f * fTemp13;
			float fTemp15 = float(fTemp14 > 1.0f) + fTemp14 * float(fTemp14 <= 1.0f);
			fRec13[IOTA0 & 8191] = fTemp3 + fTemp13 * (float(0 - (fTemp15 < -1.0f)) + fTemp15 * float(fTemp15 >= -1.0f));
			float fTemp16 = fRec13[IOTA0 & 8191];
			fVec3[IOTA0 & 4095] = fSlow26 * fTemp16 * fRec12[0];
			float fTemp17 = 0.3f * fVec3[(IOTA0 - iConst20) & 4095];
			float fTemp18 = fTemp17 + fVec0[(IOTA0 - iConst10) & 16383] - 0.6f * fRec8[1];
			fVec4[IOTA0 & 4095] = fTemp18;
			fRec8[0] = fVec4[(IOTA0 - iConst21) & 4095];
			float fRec9 = 0.6f * fTemp18;
			fRec32[0] = 0.0f - fConst7 * (fConst6 * fRec32[1] - (fRec0[1] + fRec0[2]));
			fRec31[0] = fSlow35 * (fRec0[1] + fSlow34 * fRec32[0]) + fSlow33 * fRec31[1];
			fVec5[IOTA0 & 16383] = 0.35355338f * fRec31[0] + 1e-20f;
			float fTemp19 = fVec5[(IOTA0 - iConst27) & 16383] + fTemp17 - 0.6f * fRec29[1];
			fVec6[IOTA0 & 2047] = fTemp19;
			fRec29[0] = fVec6[(IOTA0 - iConst28) & 2047];
			float fRec30 = 0.6f * fTemp19;
			float fTemp20 = fRec30 + fRec9;
			fRec36[0] = 0.0f - fConst7 * (fConst6 * fRec36[1] - (fRec2[1] + fRec2[2]));
			fRec35[0] = fSlow44 * (fRec2[1] + fSlow43 * fRec36[0]) + fSlow42 * fRec35[1];
			fVec7[IOTA0 & 16383] = 0.35355338f * fRec35[0] + 1e-20f;
			float fTemp21 = fVec7[(IOTA0 - iConst34) & 16383] - (fTemp17 + 0.6f * fRec33[1]);
			fVec8[IOTA0 & 4095] = fTemp21;
			fRec33[0] = fVec8[(IOTA0 - iConst35) & 4095];
			float fRec34 = 0.6f * fTemp21;
			fRec40[0] = 0.0f - fConst7 * (fConst6 * fRec40[1] - (fRec6[1] + fRec6[2]));
			fRec39[0] = fSlow53 * (fRec6[1] + fSlow52 * fRec40[0]) + fSlow51 * fRec39[1];
			fVec9[IOTA0 & 16383] = 0.35355338f * fRec39[0] + 1e-20f;
			float fTemp22 = fVec9[(IOTA0 - iConst41) & 16383] - (fTemp17 + 0.6f * fRec37[1]);
			fVec10[IOTA0 & 2047] = fTemp22;
			fRec37[0] = fVec10[(IOTA0 - iConst42) & 2047];
			float fRec38 = 0.6f * fTemp22;
			float fTemp23 = fRec38 + fRec34 + fTemp20;
			fRec44[0] = 0.0f - fConst7 * (fConst6 * fRec44[1] - (fRec1[1] + fRec1[2]));
			fRec43[0] = fSlow62 * (fRec1[1] + fSlow61 * fRec44[0]) + fSlow60 * fRec43[1];
			fVec11[IOTA0 & 32767] = 0.35355338f * fRec43[0] + 1e-20f;
			fVec12[IOTA0 & 8191] = fSlow63 * fTemp16;
			float fTemp24 = fVec12[(IOTA0 - iSlow64) & 8191];
			fVec13[IOTA0 & 4095] = fSlow24 * fRec12[0] * fTemp24;
			float fTemp25 = 0.3f * fVec13[(IOTA0 - iConst20) & 4095];
			float fTemp26 = fTemp25 + 0.6f * fRec41[1] + fVec11[(IOTA0 - iConst48) & 32767];
			fVec14[IOTA0 & 4095] = fTemp26;
			fRec41[0] = fVec14[(IOTA0 - iConst49) & 4095];
			float fRec42 = 0.0f - 0.6f * fTemp26;
			fRec48[0] = 0.0f - fConst7 * (fConst6 * fRec48[1] - (fRec5[1] + fRec5[2]));
			fRec47[0] = fSlow73 * (fRec5[1] + fSlow72 * fRec48[0]) + fSlow71 * fRec47[1];
			fVec15[IOTA0 & 16383] = 0.35355338f * fRec47[0] + 1e-20f;
			float fTemp27 = fVec15[(IOTA0 - iConst55) & 16383] + fTemp25 + 0.6f * fRec45[1];
			fVec16[IOTA0 & 4095] = fTemp27;
			fRec45[0] = fVec16[(IOTA0 - iConst56) & 4095];
			float fRec46 = 0.0f - 0.6f * fTemp27;
			fRec52[0] = 0.0f - fConst7 * (fConst6 * fRec52[1] - (fRec3[1] + fRec3[2]));
			fRec51[0] = fSlow82 * (fRec3[1] + fSlow81 * fRec52[0]) + fSlow80 * fRec51[1];
			fVec17[IOTA0 & 32767] = 0.35355338f * fRec51[0] + 1e-20f;
			float fTemp28 = 0.6f * fRec49[1] + fVec17[(IOTA0 - iConst62) & 32767] - fTemp25;
			fVec18[IOTA0 & 4095] = fTemp28;
			fRec49[0] = fVec18[(IOTA0 - iConst63) & 4095];
			float fRec50 = 0.0f - 0.6f * fTemp28;
			fRec56[0] = 0.0f - fConst7 * (fConst6 * fRec56[1] - (fRec7[1] + fRec7[2]));
			fRec55[0] = fSlow91 * (fRec7[1] + fSlow90 * fRec56[0]) + fSlow89 * fRec55[1];
			fVec19[IOTA0 & 32767] = 0.35355338f * fRec55[0] + 1e-20f;
			float fTemp29 = 0.6f * fRec53[1] + fVec19[(IOTA0 - iConst69) & 32767] - fTemp25;
			fVec20[IOTA0 & 2047] = fTemp29;
			fRec53[0] = fVec20[(IOTA0 - iConst70) & 2047];
			float fRec54 = 0.0f - 0.6f * fTemp29;
			fRec0[0] = fRec53[1] + fRec49[1] + fRec45[1] + fRec41[1] + fRec37[1] + fRec33[1] + fRec8[1] + fRec29[1] + fRec54 + fRec50 + fRec46 + fRec42 + fTemp23;
			fRec1[0] = fRec37[1] + fRec33[1] + fRec8[1] + fRec29[1] + fTemp23 - (fRec53[1] + fRec49[1] + fRec45[1] + fRec41[1] + fRec54 + fRec50 + fRec42 + fRec46);
			float fTemp30 = fRec34 + fRec38;
			fRec2[0] = fRec45[1] + fRec41[1] + fRec8[1] + fRec29[1] + fRec46 + fRec42 + fTemp20 - (fRec53[1] + fRec49[1] + fRec37[1] + fRec33[1] + fRec54 + fRec50 + fTemp30);
			fRec3[0] = fRec53[1] + fRec49[1] + fRec8[1] + fRec29[1] + fRec54 + fRec50 + fTemp20 - (fRec45[1] + fRec41[1] + fRec37[1] + fRec33[1] + fRec46 + fRec42 + fTemp30);
			float fTemp31 = fRec9 + fRec38;
			float fTemp32 = fRec30 + fRec34;
			fRec4[0] = fRec49[1] + fRec41[1] + fRec33[1] + fRec29[1] + fRec50 + fRec42 + fTemp32 - (fRec53[1] + fRec45[1] + fRec37[1] + fRec8[1] + fRec54 + fRec46 + fTemp31);
			fRec5[0] = fRec53[1] + fRec45[1] + fRec33[1] + fRec29[1] + fRec54 + fRec46 + fTemp32 - (fRec49[1] + fRec41[1] + fRec37[1] + fRec8[1] + fRec50 + fRec42 + fTemp31);
			float fTemp33 = fRec9 + fRec34;
			float fTemp34 = fRec30 + fRec38;
			fRec6[0] = fRec53[1] + fRec41[1] + fRec37[1] + fRec29[1] + fRec54 + fRec42 + fTemp34 - (fRec49[1] + fRec45[1] + fRec33[1] + fRec8[1] + fRec50 + fRec46 + fTemp33);
			fRec7[0] = fRec49[1] + fRec45[1] + fRec37[1] + fRec29[1] + fRec50 + fRec46 + fTemp34 - (fRec53[1] + fRec41[1] + fRec33[1] + fRec8[1] + fRec54 + fRec42 + fTemp33);
			output0[i0] = FAUSTFLOAT(2.0f * ((1.0f - fRec12[0]) * (fSlow26 * fTemp16 + fSlow24 * fTemp24) + 0.37f * (fRec1[0] + fRec2[0] + (fRec1[0] - fRec2[0]))));
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			IOTA0 = IOTA0 + 1;
			fRec12[1] = fRec12[0];
			fRec15[1] = fRec15[0];
			fVec2[1] = fVec2[0];
			iRec16[1] = iRec16[0];
			iRec17[1] = iRec17[0];
			fRec18[1] = fRec18[0];
			iRec19[1] = iRec19[0];
			fRec20[1] = fRec20[0];
			fRec22[1] = fRec22[0];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec21[1] = fRec21[0];
			fRec8[1] = fRec8[0];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec29[1] = fRec29[0];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			fRec33[1] = fRec33[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec37[1] = fRec37[0];
			fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec41[1] = fRec41[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fRec45[1] = fRec45[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec49[1] = fRec49[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec53[1] = fRec53[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
		}
	}

};

#endif
