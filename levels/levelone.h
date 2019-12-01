#ifndef _LEVELONE_H_
#define _LEVELONE_H_

#include "../level.h"

class LevelOne: public Level{
public:
	LevelOne();
	~LevelOne() override;
	void generateSequence(int seed) override;
};
#endif
