#ifndef BLOCK_H
#define BLOCK_H
#include "../cell.h"
#include "../board.h"
#include <memory>

//class Board;

class Block
{
protected:
	// what type of block it is
	const char let;

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
	
	// Board that the block is on
	std::shared_ptr<Board> board;

	// Can the block move down one row
	bool canDown;

	// Length of the smallest bounding rectangle
	const int length;

	// Level the block was created
	int levelCreated;

public:
	// Returns block's cells 
	std::vector<std::shared_ptr<Cell>> getCells();

	// Getters and Setters
	void setCanDown(bool b);
	bool getCanDown();
	int getLevelCreated();
	char getLet();

	// Checks if the block will be inside of the board after movement
	bool inBounds(std::string dir);

	// Checks if b collides with any blocks on the current board
	bool collision(Block &b);

	// Moves the block in direction dir
	virtual void movement(std::string dir);

	// Constructor
	Block(char let, std::shared_ptr<Board> board, int length);

	// Destructor
	virtual ~Block();

	// Rotates a block based on direction
	virtual void rotate(std::string direction);
};

#endif
