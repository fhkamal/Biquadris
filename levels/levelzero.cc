#include "levelzero.h"
using namespace std;

#include <fstream>

LevelZero::LevelZero(string fileName)
{
    level = 0;
    this->getBlocks(fileName); //sets the sequence to a vector of blocks by calling getBlocks 
}

LevelZero::~LevelZero() {}
