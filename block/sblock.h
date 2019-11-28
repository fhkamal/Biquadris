#ifndef SBLOCK_H_
#define SBLOCK_H_
#include "block.h"
#include <memory>

class SBlock: public Block {
	public:
		void movement(std::string dir);
		//void rotate(std::string direction);
		SBlock(std::shared_ptr<Board> b);
		SBlock();
};
#endif
