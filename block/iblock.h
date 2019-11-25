#ifndef IBLOCK_H_
#define IBLOCK_H_
#include "block.h"
#include <memory>

class IBlock: public Block {
	public:
		void movement(std::string dir);
		void rotate(std::string direction);
		// IBlock(Board* b);
		IBlock(std::shared_ptr<Board> b);
};

#endif
