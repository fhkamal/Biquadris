#ifndef BLOCK_H
#define BLOCK_H
#include "../cell.h"
#include "../board.h"
#include <memory>

//class Board;

class Block{
	protected:
		const char let;
		Cell *one;
		Cell *two;
		Cell *three;
		Cell *four;

		// std::shared_ptr<Cell> one;
		// std::shared_ptr<Cell> two;
		// std::shared_ptr<Cell> three;
		// std::shared_ptr<Cell> four;
		// int orient;
		std::shared_ptr<Board> board;
	public:
		bool isValid();
		virtual void movement(std::string dir) = 0;
		Block(char let, Board& board);
		virtual ~Block();
		virtual void rotate(std::string direction) = 0;
};

#endif
