#include "levelone.h"
#include <stdlib.h>
using namespace std;

LevelOne::LevelOne(){
	level = 1;
	turns = 0;
}

void LevelOne::generateSequence(int seed){
	if (seed != INT_MAX) { //for no seed
		srand(seed);
	}
	
	for (int k = 0; k < 50; k++) { //makes a vector of 50, adding it block values
		int i = (rand() % 12) + 1;
		if(i == 1){
			sequence.emplace_back("S");
		}
		else if(i == 2){
			sequence.emplace_back("Z");
		}
		else if(i < 5){
			sequence.emplace_back("I");
		}
		else if(i < 7){
			sequence.emplace_back("T");
		}
		else if(i < 9){
			sequence.emplace_back("J");
		}
		else if(i < 11){
			sequence.emplace_back("L");
		}
		else{
			sequence.emplace_back("O");
		}
	}
	
}

LevelOne::~LevelOne() {}
