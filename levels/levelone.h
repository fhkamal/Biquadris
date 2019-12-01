#ifndef _LEVELONE_H_
#define _LEVELONE_H_

#include "../level.h"

class LevelOne: public Level{
public:
	LevelOne();
	~LevelOne() override;
	std::string generateBlock(int seed);
};
#endif
