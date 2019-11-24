#ifndef ZBLOCK_H_
#define ZBLOCK_H_
#include "block.h"

class ZBlock: public Block {
	public:
		void movement(std::string dir);
		void rotate(std::string direction);
		ZBlock(Board& board);
};
#endif
