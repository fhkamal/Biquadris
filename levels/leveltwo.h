#ifndef _LEVELTWO_H_
#define _LEVELTWO_H_

#include "../level.h"

class LevelTwo: public Level{
public:
	LevelTwo(); //constructor
	~LevelTwo() override; //destructor
	void generateSequence(int seed) override; //randomly generates sequence of blocks given a seed
};
#endif
