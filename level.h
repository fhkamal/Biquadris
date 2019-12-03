#ifndef _LEVEL_H_
#define _LEVEL_H_
#include <iostream>
#include <memory>
#include <vector>
//#include <board.h>
//#include <block.h>
#include <string>
#include <limits.h>
#include <fstream>

class Level
{
protected:
    int level;
    int turns;
    std::vector<std::string> sequence;
public:
    Level();
    void getBlocks(std::string filename);
    int getLevel();
    virtual std::vector<std::string> getSequence();
    //virtual std::unique_ptr<Block> generateBlock(Board &board, std::string blockType);
    virtual void generateSequence(int seed);
    virtual ~Level() = 0;
    void increment();
    int getTurns();
};

#endif
