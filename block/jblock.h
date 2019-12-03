#ifndef JBLOCK_H_
#define JBLOCK_H_
#include "block.h"
#include <memory>

class JBlock: public Block {
	public:
		void movement(std::string dir);
		JBlock(std::shared_ptr<Board> b, int level);
		JBlock();
};
#endif
