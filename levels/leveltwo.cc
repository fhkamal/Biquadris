#include "leveltwo.h"
#include <stdlib.h>
using namespace std;

LevelTwo::LevelTwo(){
	level = 2;
}

void LevelTwo::generateSequence(int seed){
	if (seed != INT_MAX) {
		srand(seed);
	}
	
	for (int k = 0; k < 50; k++) {
		int i = (rand() % 7) + 1;
		if(i == 1){
			sequence.emplace_back("S");
		}
		else if(i == 2){
			sequence.emplace_back("Z");
		}
		else if(i == 3){
			sequence.emplace_back("I");
		}
		else if(i == 4){
			sequence.emplace_back("T");
		}
		else if(i == 5){
			sequence.emplace_back("J");
		}
		else if(i == 6){
			sequence.emplace_back("L");
		}
		else{
			sequence.emplace_back("O");
		}
	}
}

LevelTwo::~LevelTwo() {}
