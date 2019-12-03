#ifndef _LEVELTHREE_H_
#define _LEVELTHREE_H_

#include "../level.h"

class LevelThree: public Level{
public:
        LevelThree(); //constructor
        ~LevelThree() override; //destructor
        void generateSequence(int seed) override; //randomly generates sequence of blocks
};
#endif
