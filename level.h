#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <memory>
#include <vector>
//#include <board.h>
//#include <block.h>
#include <string>

class Level
{
protected:
    int level;
    std::vector<std::string> sequence;

public:
    Level();

    virtual int getLevel() = 0;
    virtual std::vector<std::string> getSequence();
    //virtual std::unique_ptr<Block> generateBlock(Board &board, std::string blockType);

    virtual ~Level() = 0;
};

#endif
