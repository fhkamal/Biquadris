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

    while (f >> block)
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
