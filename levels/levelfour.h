#ifndef _LEVELFOUR_H_
#define _LEVELFOUR_H_

#include "../level.h"

class LevelFour: public Level{
public:
        LevelFour(); //constructor
        ~LevelFour() override; //destructor
        void generateSequence(int seed) override; //generates blocks given a seed
};
#endif
