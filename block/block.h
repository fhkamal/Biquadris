#ifndef BLOCK_H
#define BLOCK_H
#include "cell.h"

class Block{
	protected:
		char let;
		Cell *one, *two, *three, *four;
		int orient;
		Board *board;
	public:
		Block(char let, Board *board);
		virtual ~Block();
		virtual void rotate(std::string direction) = 0;
};
#endif
