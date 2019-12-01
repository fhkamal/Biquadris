#ifndef LBLOCK_H_
#define LBLOCK_H_
#include "block.h"

class LBlock: public Block {
	public:
		void movement(std::string dir);
		//void rotate(std::string direction);
		LBlock(std::shared_ptr<Board> b, int level);
		LBlock();
};
#endif
