#include "levelone.h"
#include <stdlib.h>
using namespace std;

LevelOne::LevelOne(){
	level = 1;
}

string LevelOne::generateBlock(int seed){
	srand(seed);
	int i = (rand() % 12) + 1;
	if(i == 1){
		return "S";
	}
	else if(i == 2){
		return "Z";
	}
	else if(i < 5){
		return "I";
	}
	else if(i < 7){
		return "T";
	}
	else if(i < 9){
		return "J";
	}
	else if(i < 11){
		return "L";
	}
	else{
		return "O";
	}
}

LevelOne::~LevelOne() {}
