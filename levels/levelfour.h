#ifndef _LEVELFOUR_H_
#define _LEVELFOUR_H_

#include "../level.h"

class LevelFour: public Level{
public:
        LevelFour();
        ~LevelFour() override;
        void generateSequence(int seed) override;
};
#endif
