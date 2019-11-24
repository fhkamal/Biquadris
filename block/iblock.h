#ifndef IBLOCK_H_
#define IBLOCK_H_
#include "block.h"

class IBlock: public Block {
	public:
		void movement(std::string dir);
		void rotate(std::string direction);
		IBlock(Board& board);
};

#endif
