#ifndef _LEVELFOUR_H_
#define _LEVELFOUR_H_

#include "../level.h"

class LevelFour: public Level{
	bool random;
public:
        LevelFour();
        ~LevelFour() override;
        void generateSequence(int seed) override;
};
#endif
