/*
  Copyright 2015 Fred Martin, 
  Y. Rykalova, 2020
*/
//drums
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

//#include "CircularBuffer.h"
//#include "StringSound.h"
#include "DrumSound.h"

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100
using std::vector;

vector<int16_t> makeSamples(DrumSound gs) {
	std::vector<int16_t> samples;

	gs.pluck();
	int duration = 8;  // seconds
	int i;
	for (i = 0; i < SAMPLES_PER_SEC * duration; i++) {
		gs.tic();
		samples.push_back(gs.sample());
	}

	return samples;
}
int main() {

  //modded
  auto getFreq = [](int i) {
	return (440 * pow(2, (i-24) / 12)); };


  //vector of samples
  vector<int16_t> samples;
  double freq;

//vector of 37 vector samples
  vector<vector<int16_t>> vec_Samples;
 	//fill it up
	for(int i = 0; i < 37; i++){
	freq = getFreq(i);
	DrumSound a = DrumSound(freq);
	samples = makeSamples(a);
	vec_Samples.push_back(samples);
	}

  	//vector of soundbuffers
  vector<sf::SoundBuffer> vec_SoundBuffers;
	//load each sample vector
	for(int j = 0; j < 37; j++){
	sf::SoundBuffer buf1;
	buf1.loadFromSamples(&vec_Samples.at(j)[0], vec_Samples.at(j).size(), 2, SAMPLES_PER_SEC);
	vec_SoundBuffers.push_back(buf1);
	}

	//vector of sounds
  vector<sf::Sound> vec_sounds;
	//load each sound from the soundbuffer
	for(int k=0; k < 37; k++){
	sf::Sound sound1;
	sound1.setBuffer(vec_SoundBuffers[k]);
	vec_sounds.push_back(sound1);
	}

  sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Plucked String Sound Lite");
  sf::Event event;

  std::string keyboard = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,./'";

  while (window.isOpen()) {
	  while (window.pollEvent(event)) {
		  switch (event.type) {
			 case sf::Event::Closed:
			  window.close();
			  break;
			 case sf::Event::TextEntered:
			{	std::string user_input;
				user_input += event.text.unicode;
				std::cout << user_input << " note" << std::endl;
				int index = keyboard.find(user_input);
				if(index < 0)
					break;
				vec_sounds[index].play();
			}

			default:
			  break;
		  }
		  window.clear();
		  window.display();
	  }
  }
  return 0;
}

