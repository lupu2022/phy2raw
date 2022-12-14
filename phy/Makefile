faust:
	#rm -rf *svg
	#faust2svg clarinet.dsp
	#faust clarinet.dsp -cn PhyModel -o process.hpp
	faust sawtooth.dsp -cn PhyModel -o process.hpp
all:
	g++ -std=c++14 -O3 -o process process.cpp -lsndfile 

clean:
	rm -rf *svg out.wav process process.hpp
