#ifndef BLOCK_H
#define BLOCK_H
#include "../cell.h"
#include "../board.h"
#include <memory>

//class Board;

class Block{
	protected:
		const char let;
		std::shared_ptr<Cell> one, two, three, four;
		// int orient;
		std::shared_ptr<Board> board;
	public:
		bool isValid();
		virtual void movement(std::string dir) = 0;
		Block(char let, std::shared_ptr<Board> board);
		virtual ~Block();
		virtual void rotate(std::string direction) = 0;
};

#endif
