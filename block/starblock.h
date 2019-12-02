#ifndef STARBLOCK_H_
#define STARBLOCK_H_
#include "block.h"
#include <memory>

class StarBlock: public Block{
	public:
		void movement(std::string dir);
		StarBlock(std::shared_ptr<Board> b);
		StarBlock();
		bool bounds();
		bool collide(StarBlock &b);
};
#endif
