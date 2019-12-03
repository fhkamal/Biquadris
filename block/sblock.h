#ifndef SBLOCK_H_
#define SBLOCK_H_
#include "block.h"
#include <memory>

class SBlock: public Block {
	public:
		void movement(std::string dir);
		SBlock(std::shared_ptr<Board> b, int level);
		SBlock();
};
#endif
