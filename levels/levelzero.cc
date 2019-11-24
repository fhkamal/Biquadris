#include "levelzero.h"
using namespace std;

#include <fstream>

LevelZero::LevelZero(string fileName)
{
    level = 0;
    this->getBlocks(fileName); 
}

void LevelZero::getBlocks(string fileName)
{
    ifstream f{fileName};
    string block;

    while (f >> block)
    {
        sequence.emplace_back(block);
    }
}

vector<string> LevelZero::getSequence() {
    return sequence;
}

int LevelZero::getLevel()
{
    return level;
}

LevelZero::~LevelZero() {}