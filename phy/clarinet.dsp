import("stdfaust.lib");
import("instruments.lib");

//==================== GUI SPECIFICATION ================

freq = nentry("h:Basic_Parameters/freq [1][unit:Hz] [tooltip:Tone frequency]",440,20,20000,1);
gain = nentry("h:Basic_Parameters/gain [1][tooltip:Gain (value between 0 and 1)]",1,0,1,0.01); 
gate = button("h:Basic_Parameters/gate [1][tooltip:noteOn = 1, noteOff = 0]");

reedStiffness = 0.5;	//Reed stiffness (value between 0 and 1)
noiseGain = 0.0;		//Breath noise gain (value between 0 and 1)
pressure = 1.0;			//Breath pressure (value bewteen 0 and 1)

typeModulation = 0;		/*0=theta is modulated by the incoming signal;
						  1=theta is modulated by the averaged incoming signal;
						  2=theta is modulated by the squared incoming signal; 3=theta is modulated by a sine wave of frequency freqMod;
						  4=theta is modulated by a sine wave of frequency freq;*/
nonLinearity = 0.0;		//Nonlinearity factor (value between 0 and 1)
frequencyMod = 220;		//Frequency of the sine wave for the modulation of theta (works if Modulation Type=3)
nonLinAttack = 0.1;		//Attack duration of the nonlinearity (0 ~ 2 )

vibratoFreq = 5;		//Vibrato_Freq, unit:hz
vibratoGain = 0.01;		//Vibrato_Gain A value between 0 and 1
vibratoAttack = 0.5;	//Vibrato attack duration, unit:s (0 ~ 2)
vibratoRelease = 0.01;	//Vibrato release duration, unit:s (0 ~ 2)

envelopeAttack = 0.01;	//Envelope attack duration
envelopeDecay = 0.05;	//Envelope decay duration
envelopeRelease = 0.1;	//Envelope release duration

//==================== SIGNAL PROCESSING ======================

//----------------------- Nonlinear filter ----------------------------
//nonlinearities are created by the nonlinear passive allpass ladder filter declared in miscfilter.lib

//nonlinear filter order
nlfOrder = 6; 

//attack - sustain - release envelope for nonlinearity (declared in instruments.lib)
envelopeMod = en.asr(nonLinAttack,1,envelopeRelease,gate);

//nonLinearModultor is declared in instruments.lib, it adapts allpassnn from miscfilter.lib 
//for using it with waveguide instruments
NLFM =  nonLinearModulator((nonLinearity : si.smoo),envelopeMod,freq,
     typeModulation,(frequencyMod : si.smoo),nlfOrder);

//----------------------- Synthesis parameters computing and functions declaration ----------------------------

//reed table parameters
reedTableOffset = 0.7;
reedTableSlope = -0.44 + (0.26*reedStiffness);

//the reed function is declared in instruments.lib
reedTable = reed(reedTableOffset,reedTableSlope);

//delay line with a length adapted in function of the order of nonlinear filter
delayLength = ma.SR/freq*0.5 - 1.5 - (nlfOrder*nonLinearity)*(typeModulation < 2);
delayLine = de.fdelay(4096,delayLength);

//one zero filter used as a allpass: pole is set to -1
filter = oneZero0(0.5,0.5);

//stereoizer is declared in instruments.lib and implement a stereo spacialisation in function of 
//the frequency period in number of samples 
stereo = stereoizer(ma.SR/freq);

//----------------------- Algorithm implementation ----------------------------

//Breath pressure + vibrato + breath noise + envelope (Attack / Decay / Sustain / Release)
envelope = en.adsr(envelopeAttack,envelopeDecay,1,envelopeRelease,gate)*pressure*0.9;

vibrato = os.osc(vibratoFreq)*vibratoGain*
	envVibrato(0.1*2*vibratoAttack,0.9*2*vibratoAttack,100,vibratoRelease,gate);
breath = envelope + envelope*no.noise*noiseGain;
breathPressure = breath + breath*vibrato;

process =
	//Commuted Loss Filtering
	(_,(breathPressure <: _,_) : (filter*-0.95 - _ <: 
	
	//Non-Linear Scattering
	*(reedTable)) + _) ~ 
	
	//Delay with Feedback
	(delayLine : NLFM) : 
	
	//scaling and stereo
	*(gain)*2.5 : stereo : instrReverb : +(_) / 0.5;

