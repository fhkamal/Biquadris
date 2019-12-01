#include "zblock.h"
using namespace std;

ZBlock::ZBlock(shared_ptr<Board> b, int level) : Block{'Z', b, 3}
{
	levelCreated = level;

	// The block spawns in the top left
	one = b->getGrid()[2][0];
	two = b->getGrid()[2][1];
	three = b->getGrid()[3][1];
	four = b->getGrid()[3][2];

	// Set the bounding rectangle
	topLeft = b->getGrid()[2][0];
	bottomLeft = b->getGrid()[3][0];
	topRight = b->getGrid()[2][2];
	bottomRight = b->getGrid()[3][2];

	// Set the block in the cells
	one->setBlockType('Z');
	one->setIsOccupied(true);

	two->setBlockType('Z');
	two->setIsOccupied(true);

	three->setBlockType('Z');
	three->setIsOccupied(true);

	four->setBlockType('Z');
	four->setIsOccupied(true);
}

// Constructor for temp blocks
ZBlock::ZBlock() : Block{'Z', make_shared<Board>(), 3} {}

//void ZBlock::rotate(string direction){
//        if(direction == "clockwise"){
//
//        }
//}

void ZBlock::movement(string dir)
{
	if (!inBounds(dir))
	{
		return;
	}
	// call temp block constructor
	ZBlock tmp = ZBlock();

	// Set the new Block to current block position
	tmp.one = one;
	tmp.two = two;
	tmp.three = three;
	tmp.four = four;
	tmp.topLeft = topLeft;
	tmp.topRight = topRight;
	tmp.bottomLeft = bottomLeft;
	tmp.bottomRight = bottomRight;

	if (dir == "right")
	{
		// Shift the block 1 block to right
		tmp.one = board->getGrid()[(one->getCoordinates().first)][one->getCoordinates().second + 1];
		tmp.two = board->getGrid()[(two->getCoordinates().first)][two->getCoordinates().second + 1];
		tmp.three = board->getGrid()[(three->getCoordinates().first)][three->getCoordinates().second + 1];
		tmp.four = board->getGrid()[(four->getCoordinates().first)][four->getCoordinates().second + 1];
		tmp.bottomLeft = board->getGrid()[(bottomLeft->getCoordinates().first)][bottomLeft->getCoordinates().second + 1];
		tmp.bottomRight = board->getGrid()[(bottomRight->getCoordinates().first)][bottomRight->getCoordinates().second + 1];
		tmp.topLeft = board->getGrid()[(topLeft->getCoordinates().first)][topLeft->getCoordinates().second + 1];
		tmp.topRight = board->getGrid()[(topRight->getCoordinates().first)][topRight->getCoordinates().second + 1];
	}
	else if (dir == "left")
	{
		// Shift the block 1 block to left
		tmp.one = board->getGrid()[(one->getCoordinates().first)][one->getCoordinates().second - 1];
		tmp.two = board->getGrid()[(two->getCoordinates().first)][two->getCoordinates().second - 1];
		tmp.three = board->getGrid()[(three->getCoordinates().first)][three->getCoordinates().second - 1];
		tmp.four = board->getGrid()[(four->getCoordinates().first)][four->getCoordinates().second - 1];
		tmp.bottomLeft = board->getGrid()[(bottomLeft->getCoordinates().first)][bottomLeft->getCoordinates().second - 1];
		tmp.bottomRight = board->getGrid()[(bottomRight->getCoordinates().first)][bottomRight->getCoordinates().second - 1];
		tmp.topLeft = board->getGrid()[(topLeft->getCoordinates().first)][topLeft->getCoordinates().second - 1];
		tmp.topRight = board->getGrid()[(topRight->getCoordinates().first)][topRight->getCoordinates().second - 1];;
	}
	else if (dir == "down")
	{
		// Shift the block 1 block to left
		tmp.one = board->getGrid()[(one->getCoordinates().first) + 1][one->getCoordinates().second];
		tmp.two = board->getGrid()[(two->getCoordinates().first) + 1][two->getCoordinates().second];
		tmp.three = board->getGrid()[(three->getCoordinates().first) + 1][three->getCoordinates().second];
		tmp.four = board->getGrid()[(four->getCoordinates().first) + 1][four->getCoordinates().second];
		tmp.bottomLeft = board->getGrid()[(bottomLeft->getCoordinates().first) + 1][bottomLeft->getCoordinates().second];
		tmp.bottomRight = board->getGrid()[(bottomRight->getCoordinates().first) + 1][bottomRight->getCoordinates().second];
		tmp.topLeft = board->getGrid()[(topLeft->getCoordinates().first) + 1][topLeft->getCoordinates().second];
		tmp.topRight = board->getGrid()[(topRight->getCoordinates().first) + 1][topRight->getCoordinates().second];
	}
	
	// Check is collision occurs
	if (!collision(tmp) && dir == "down")
	{
		canDown = false;
		return;
	}
	if (!collision(tmp)) return;

	// Set the current cells to empty
	one->setBlockType(' ');
	one->setIsOccupied(false);
	two->setBlockType(' ');
	two->setIsOccupied(false);
	three->setBlockType(' ');
	three->setIsOccupied(false);
	four->setBlockType(' ');
	four->setIsOccupied(false);

	// Swap pointers to cells with the temporary block
	swap(one, tmp.one);
	swap(two, tmp.two);
	swap(three, tmp.three);
	swap(four, tmp.four);
	swap(topLeft, tmp.topLeft);
	swap(topRight, tmp.topRight);
	swap(bottomLeft, tmp.bottomLeft);
	swap(bottomRight, tmp.bottomRight);

	// Set temp values to sa random cell so they don't delete board cells
	tmp.one = make_shared<Cell>(3, 1);
	tmp.two = tmp.one;
	tmp.three = tmp.one;
	tmp.four = tmp.one;
	tmp.topRight = tmp.one;
	tmp.topLeft = tmp.one;
	tmp.bottomRight = tmp.one;
	tmp.bottomLeft = tmp.one;

	// Set the new cell values
	one->setBlockType('Z');
	one->setIsOccupied(true);
	two->setBlockType('Z');
	two->setIsOccupied(true);
	three->setBlockType('Z');
	three->setIsOccupied(true);
	four->setBlockType('Z');
	four->setIsOccupied(true);
}
