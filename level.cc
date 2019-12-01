#include "level.h"
using namespace std;

Level::Level() {}

Level::~Level() {}

vector<string> Level::getSequence() {
    return sequence;
};

int Level::getLevel(){
	return level;
}

void Level::generateSequence(int seed) {}

bool Level::getHeavy(){
	return heavy;
}
