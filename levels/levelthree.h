#ifndef _LEVELTHREE_H_
#define _LEVELTHREE_H_

#include "../level.h"

class LevelThree: public Level{
public:
        LevelThree();
        ~LevelThree() override;
        void generateSequence(int seed) override;
};
#endif
