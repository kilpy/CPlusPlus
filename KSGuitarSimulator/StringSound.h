#include <iostream>
#include "CircularBuffer.h"
#include <vector>
#include <string>
//#include <memory>
const int SAMPLING_RATE = 44100;
const double DECAY_FACTOR = 0.996;
class StringSound{
public:
StringSound(double frequency);	//create a guitar string sound of the given
				//frequency using a sampling rate of 44,100

StringSound(vector<int16_t> init);	//create a guitar string with size
					//and initial values given by vector
void pluck(void);		//replace the buffer with random values
				//represent white noise
void tic(void);		//advance the simulation one time step
int16_t sample(void);	//return the current sample
int time(void);		//return number of times tic was called
private:
CircularBuffer* buffer;
int count = 0;
};
