#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <random>



class MModel {
	// creates a Markov model of order k for the specified text
public:
	MModel(std::string text, int k);

		// returns the order k of this Markov model
	int kOrder(void);

		// returns a string representation of the Markov model (as described below)
	//String toString();

		// returns the number of times the specified kgram appears in the text
	int freq(std::string kgram);

		// returns the number of times the character c follows the specified
		// kgram in the text
	 int freq(std::string kgram, char c);

		// returns a random character that follows the specified kgram in the text,
		// chosen with weight proportional to the number of times that character
		// follows the specified kgram in the text
	 char kRand(std::string kgram);

	 // generate a string of length L characters
	// by simulating a trajectory through the corresponding
	// Markov chain. The first k characters of the newly
	// generated string should be the argument kgram.
	// Throw an exception if kgram is not of length k.
	// Assume that L is at least k.
	 std::string generate(std::string kgram, int L);

	 friend std::ostream& operator<< (std::ostream& out, MModel M) {
		 out << "K is: " << M.K << std::endl;
		 out << "L is: " << M.L << std::endl;
		 //out << "kG is: " << M.kG << endl;
		 return out;
	 }

private:
	int K;
	int L;
	std::string alphabet;
	std::map< std::string, std::map <char, int> > kG;
	std::map <std::string, int> kGramFreq;
	std::map <char, int> alphaFreq;
	std::string word;
};