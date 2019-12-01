#include "leveltwo.h"
#include <stdlib.h>
using namespace std;

LevelTwo::LevelTwo(){
	level = 2;
}

string LevelTwo::generateBlock(int seed){
	srand(seed);
	int i = (rand() % 7) + 1;
	if(i == 1){
		return "S";
	}
	else if(i == 2){
		return "Z";
	}
	else if(i == 3){
		return "I";
	}
	else if(i == 4){
		return "T";
	}
	else if(i == 5){
		return "J";
	}
	else if(i == 6){
		return "L";
	}
	else{
		return "O";
	}
}

LevelTwo::~LevelTwo() {}
