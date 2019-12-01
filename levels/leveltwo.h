#ifndef _LEVELTWO_H_
#define _LEVELTWO_H_

#include "../level.h"

class LevelTwo: public Level{
public:
	LevelTwo();
	~LevelTwo() override;
	void generateSequence(int seed) override;
};
#endif
