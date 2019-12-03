#include "levelfour.h"
#include <stdlib.h>
using namespace std;

LevelFour::LevelFour(){
	level = 4;
	turns = 0;
	random = true;
}

void LevelFour::generateSequence(int seed){
	if (seed != INT_MAX) {
		srand(seed);
	}
	
	for (int k = 0; k < 50; k++) {
		int i = (rand() % 9) + 1;
		if(i < 3){
			sequence.emplace_back("S");
		}
		else if(i < 5){
			sequence.emplace_back("Z");
		}
		else if(i == 5){
			sequence.emplace_back("I");
		}
		else if(i == 6){
			sequence.emplace_back("T");
		}
		else if(i == 7){
			sequence.emplace_back("J");
		}
		else if(i == 8){
			sequence.emplace_back("L");
		}
		else{
			sequence.emplace_back("O");
		}
	}
	
}

LevelFour::~LevelFour() {}
