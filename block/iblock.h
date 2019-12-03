#ifndef IBLOCK_H_
#define IBLOCK_H_
#include "block.h"
#include <memory>

class IBlock: public Block {
	public:
		void movement(std::string dir);
		IBlock(std::shared_ptr<Board> b, int level);
		IBlock();
};

#endif
