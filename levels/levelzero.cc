#include "levelzero.h"
using namespace std;

#include <fstream>

LevelZero::LevelZero(string fileName)
{
    level = 0;
    this->getBlocks(fileName); 
}

vector<string> LevelZero::getSequence() {
    return sequence;
}

/*int LevelZero::getLevel()
{
    return level;
}*/

LevelZero::~LevelZero() {}
