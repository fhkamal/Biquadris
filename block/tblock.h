#ifndef TBLOCK_H_
#define TBLOCK_H_
#include "block.h"

class TBlock: public Block {
	public:
		void movement(std::string dir);
		//void rotate(std::string direction);
		TBlock(std::shared_ptr<Board> b);
		TBlock();
};
#endif
