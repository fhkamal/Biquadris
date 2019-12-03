#ifndef ZBLOCK_H_
#define ZBLOCK_H_
#include "block.h"

class ZBlock: public Block {
	public:
		void movement(std::string dir);
		ZBlock(std::shared_ptr<Board> b, int level);
		ZBlock();
};
#endif
