#ifndef BLOCK_H
#define BLOCK_H
#include "../cell.h"

class Block{
	protected:
		char let;
		std::shared_ptr<Cell> one, two, three, four;
		int orient;
		std::shared_ptr<Board> board;
	public:
		bool isValid();
		void movement(std::string dir);
		Block(char let, Board *board);
		virtual ~Block();
		virtual void rotate(std::string direction) = 0;
};

#endif
