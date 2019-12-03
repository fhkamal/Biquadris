#ifndef TBLOCK_H_
#define TBLOCK_H_
#include "block.h"

class TBlock: public Block {
	public:
		void movement(std::string dir);
		TBlock(std::shared_ptr<Board> b, int level);
		TBlock();
};
#endif
