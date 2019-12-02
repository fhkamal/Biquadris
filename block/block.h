#ifndef BLOCK_H
#define BLOCK_H
#include "../cell.h"
#include "../board.h"
#include <memory>

//class Board;

class Block
{
protected:
	const char let;
	// Cell *one;
	// Cell *two;
	// Cell *three;
	// Cell *four;

	// cell's that a block occupies
	std::shared_ptr<Cell> one;
	std::shared_ptr<Cell> two;
	std::shared_ptr<Cell> three;
	std::shared_ptr<Cell> four;

	// corners of the smallest bounding rectangle
	std::shared_ptr<Cell> topLeft;
	std::shared_ptr<Cell> topRight;
	std::shared_ptr<Cell> bottomLeft;
	std::shared_ptr<Cell> bottomRight;

	std::shared_ptr<Board> board;
	bool canDown;
	const int length;
	int levelCreated;

public:
	std::vector<std::shared_ptr<Cell>> getCells();
	void setCanDown(bool b);
	bool getCanDown();
	int getLevelCreated();
	bool inBounds(std::string dir);
	bool collision(Block &b);
	virtual void movement(std::string dir);
	Block(char let, std::shared_ptr<Board> board, int length);
	virtual ~Block();
	// Block &operator=(const Block& other);
	// Block &operator=(Block&& other);
	virtual void rotate(std::string direction);
	char getLet();
};

#endif
