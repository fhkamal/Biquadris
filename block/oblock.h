#ifndef OBLOCK_H_
#define OBLOCK_H_
#include "block.h"

class OBlock: public Block {
	public:
		void movement(std::string dir);
		void rotate(std::string direction);
		OBlock(Board& board);
};
#endif
