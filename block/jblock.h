#ifndef JBLOCK_H_
#define JBLOCK_H_
#include "block.h"

class JBlock: public Block {
	public:
		void movement(std::string dir);
		void rotate(std::string direction);
		JBlock(Board& Board);
};
#endif
