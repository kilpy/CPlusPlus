#include "MModel.h"
#include <algorithm>
#include <chrono>
MModel::MModel(std::string text, int k) {
	K = k;
	L = text.length();
	if (K > L || L == 0)
		throw std::invalid_argument("K cannot be greater than the length");
	word = text;

	// lamda expression to get our alphabet
	auto build_alphabet = [](std::string text, int L) {
		std::string Alphabet;
		for (int i = 0; i < L; i++) {
			if (Alphabet.find(text[i]) == std::string::npos)
				Alphabet += text[i];
		}
		return Alphabet;
	};
	alphabet = build_alphabet(text, L);
	std::vector <char> alpha;
	for (int i = 0; i < alphabet.length() ; ++i)
		alpha.push_back(alphabet[i]);

	std::string kGram;
	int max;
	std::vector<std::string> kGrams;
	std::string theoretical_char;
	// begin putting things into the vector! (this will our kgram)
	for (int i = 0; i < L; ++i, kGram = "") {
		bool counter = 0;
		if (i <= (L - K)) { // as long as i+k is within bounds (doesnt loop)

			for (int j = 0; j < k; j++) {
				kGram += text[i + j];
				max = i + j;
				if (max == (word.length() - 1))
					max = 0;
			}
		}
		else {// then this means that i+k LOOPS back!
			max = (i - (L - K) - 1);
			for (int j = i; j < L; j++)
				kGram += text[j];

			for (int p = 0; p <= max; p++)
				kGram += text[p];
		}
		theoretical_char = word.substr(max + 1, 1);
		kGrams.push_back(kGram);
		// lets use this theoretical character to count character
		std::map<char, int> alphaFreq;
		// if its not in the map,
		if (kGramFreq.find(kGram) == kGramFreq.end()) {
			// set the freq to 1(first time seeing)
			kGramFreq[kGram] = 1;
			// this is what came after the first kgram
			alphaFreq.insert(std::make_pair(theoretical_char[0], 1));
			// now lets create an index of the string, assign what we found to it. 
			kG[kGram] = alphaFreq;
		}
		else { // if it gets this far.. its in the map
			kGramFreq[kGram] = ++kGramFreq[kGram];
			// and adjust the according alphabet frequency
			// check if this theorietical character is already being counted
			if (kG[kGram].find(theoretical_char[0]) == kG[kGram].end()) {
				kG[kGram].insert(std::make_pair(theoretical_char[0], 1));
			}
			else//just add 1 to the char freq
				alphaFreq.insert(std::make_pair(theoretical_char[0], ++(kG[kGram].at(theoretical_char[0]))));

				//kG[kGram] = alphaFreq;
		}
	}
		//we now have map['bbb'] = 1 or 2
}


int MModel::kOrder(void) {
	return K;
}

//returns number of times the k-gram was found in the original text
//throw exception if kgram is not of length k
int MModel::freq(std::string kgram) {
	if(kgram.length() != K)
	throw(std::invalid_argument("kgram is not of length k"));

	if (kGramFreq.find(kgram) != kGramFreq.end()) {
		return kGramFreq[kgram];
	}//else, the kgram isnt in the map
	else {
		return 0;
	}
}

//returns the number of times the kgram was followed by the char c in the orig text
// (throw an exception if kgram is not of length k)
int MModel::freq(std::string kgram, char c) {
	if (kgram.length() != K)
		throw(std::invalid_argument("kgram is not of length k"));

	if (kG.find(kgram) != kG.end()) {//if the kgram is in the map..
		return kG[kgram].at(c);
	}
	return 0;
}

// (Throw an exception if kgram is not of length k.
// Throw an exception if no such kgram.)
char MModel::kRand(std::string kgram) {
	if(kgram.length() != K)
		throw std::invalid_argument("kGram is of different order than K");
	if (kG.find(kgram) == kG.end())
		throw std::invalid_argument("No such kGram");
	//total chance is also
	//int total_chance = kGramFreq[kgram];
	//int total_chance = 0;
	std::vector<int> freqs;
	//std::vector<double> freqqs;
	//acess the list of characters of the kgram. get the total probability
	for (auto it = kG[kgram].begin(); it != kG[kgram].end(); ++it) {
		//total_chance += it->second;
		freqs.push_back(it->second);
		//freqqs.push_back((double) (it->second) / (double) total_chance);
	}

	// construct a trivial random generator engine from a time-based seed:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::discrete_distribution<int> d(std::begin(freqs), std::end(freqs));
	
	 int random_index = d(generator);
	 char random;
	 for (auto it = kG[kgram].begin(); it != kG[kgram].end();--random_index, ++it)
	 {
		 if (random_index == 0)
			 return it->first;
	 }
	// return rand2;
	//return random2;

	//random = 
	
	//std::discrete_distribution<> d({
}

//return a string of length L(text length)
std::string MModel::generate(std::string kgram, int L) {
	std::string guessing = kgram;

	
	//new kgram has to be updated, we'll keep old just in case
	std::string kNew = kgram;
	char newRand;
	for (int i = 0; L > 0; i++ ,L--) {
		newRand = kRand(kNew);
		guessing.push_back(newRand);
		kNew.erase(0, 1);
		kNew.push_back(newRand);
	}
	
	return guessing;
}

