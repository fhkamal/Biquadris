#ifndef _LEVELZERO_H_
#define _LEVELZERO_H_

#include "../level.h"

class LevelZero : public Level
{
public:
    std::vector<std::string> getSequence() override;
    LevelZero(std::string fileName);
    void getBlocks(std::string fileName);
    int getLevel() override;
    ~LevelZero() override;
};

#endif