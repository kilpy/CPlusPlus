#include <iostream>
#include "StringSound.h"
#include <random>
StringSound::StringSound(double frequency){	//create a guitar string sound of the given
						//frequency using a sampling rate of 44,100
//make an exception to make sure its >0
//assign it to variable,
if(frequency < 0){
	throw std::invalid_argument("Frequency cannot be lower than 0");
}
int buff = ceil(SAMPLING_RATE/frequency);
buffer = new CircularBuffer(buff);
for(int i = 0; i < buff; i++)
{buffer->enqueue(0);}

count = 0;
}
StringSound::StringSound(vector<int16_t> init)	//create a guitar string with size
{					//and initial values given by vector
	if(init.empty())
	throw std::invalid_argument("vectore must be empty");

	buffer = new CircularBuffer(init.size());
	for(int i = 0; i < init.size();i++)
	{buffer->enqueue(init.at(i));}

count = 0;
}
void StringSound::pluck(void)		//replace the buffer with random values
{
	std::random_device rd;
while(!(buffer->isEmpty()))
	buffer->dequeue();

while(!(buffer->isFull())){
int16_t rng = -32768 + (rd() % ((32767 - (-32768)) + 1));
buffer->enqueue(rng);
}

}
void StringSound::tic(void){		//advance the simulation one time step
auto return_enqueue = [&](int16_t x) {buffer->enqueue(x); };

int16_t step = ((buffer->dequeue() + buffer->peek()) / 2) * DECAY_FACTOR;
count++;
return_enqueue(step);
}

int16_t StringSound::sample(void){	//return the current sample
return buffer->peek();
}
int StringSound::time(void){		//return number of times tic was called
return count;
}

