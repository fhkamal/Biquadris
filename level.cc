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

void Level::getBlocks(string fileName)
{
    ifstream f{fileName};
    string block;
    sequence.clear();
    while (f >> block) //reads in blocks from the file
    {
        sequence.emplace_back(block);
    }
}

void Level::generateSequence(int seed) {}

void Level::increment() {
	turns++;
}

int Level::getTurns() {
	return turns;
}

void Level::setRandom(bool b){
	random = b;
}

bool Level::getRandom(){
	return random;
}
