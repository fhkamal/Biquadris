#include "level.h"
using namespace std;

Level::Level() {
}

Level::~Level() {}

vector<string> Level::getSequence() {
    return sequence;
};

int Level::getLevel(){
	return level;
}

void Level::generateSequence(int seed) {}

void Level::increment() {
	turns++;
}

int Level::getTurns() {
	return turns;
}
