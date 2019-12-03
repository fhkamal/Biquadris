#ifndef _LEVELONE_H_
#define _LEVELONE_H_

#include "../level.h"

class LevelOne: public Level{
public:
	LevelOne(); //constuctor
	~LevelOne() override; //destructor
	void generateSequence(int seed) override; //creates random sequence of blocks
};
#endif
