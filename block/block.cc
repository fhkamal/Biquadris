#include "block.h"
using namespace std;

Block::Block(char let, shared_ptr<Board> board, int length) : let{let}, canDown{true}, length{length}
{
	this->board = board;
};

Block::~Block(){
	one->setBlockType(' ');
	one->setIsOccupied(false);
	// star only occupies one cell
	if(let != '*'){
		two->setBlockType(' ');
		two->setIsOccupied(false);
		three->setBlockType(' ');
		three->setIsOccupied(false);
		four->setBlockType(' ');
		four->setIsOccupied(false);
	}
}

char Block::getLet(){
	return let;
}

void Block::setCanDown(bool b)
{
	canDown = b;
}

bool Block::getCanDown()
{
	return canDown;
}

int Block::getLevelCreated() {
	return levelCreated;
}

bool Block::inBounds(string dir)
{
	if (dir == "right")
	{
		// Check if blocks to the right are in bounds
		if (one->getCoordinates().second + 1 > 10 || two->getCoordinates().second + 1 > 10 ||
				three->getCoordinates().second + 1 > 10 || four->getCoordinates().second + 1 > 10)
		{
			return false;
		}
	}
	else if (dir == "left")
	{
		//Checks if blocks to the left are in bounds
		if (one->getCoordinates().second <= 0 || two->getCoordinates().second <= 0 ||
				three->getCoordinates().second <= 0 || four->getCoordinates().second <= 0)
		{
			return false;
		}
	}
	else if (dir == "down")
	{
		// Check if blocks can go down
		if (one->getCoordinates().first + 1 > 17 || two->getCoordinates().first + 1 > 17 ||
				three->getCoordinates().first + 1 > 17 || four->getCoordinates().first + 1 > 17)
		{
			canDown = false;
			return false;
		}
	}
	return true;
}

void Block::movement(string dir) {}

bool Block::collision(Block &b)
{
	// create a temp block
	shared_ptr<Cell> c = make_shared<Cell>(30, 30);

	// Check all the cells to see if the spot they were moved to is occupied. If it is then make sure it's not 
	// occupied by the original block after the move because that is still valid.
	if (b.one->getIsOccupied() && (b.one != one) && (b.one != two) && (b.one != three) && (b.one != four))
	{
		b.one = c;
		b.two = c;
		b.three = c;
		b.four = c;
		return false;
	}
	if (b.two->getIsOccupied() && (b.two != one) && (b.two != two) && (b.two != three) && (b.two != four))
	{
		b.one = c;
		b.two = c;
		b.three = c;
		b.four = c;
		return false;
	}
	if (b.three->getIsOccupied() && (b.three != one) && (b.three != two) && (b.three != three) && (b.three != four))
	{
		b.one = c;
		b.two = c;
		b.three = c;
		b.four = c;
		return false;
	}
	if (b.four->getIsOccupied() && (b.four != one) && (b.four != two) && (b.four != three) && (b.four != four))
	{
		b.one = c;
		b.two = c;
		b.three = c;
		b.four = c;
		return false;
	}
	return true;
}

void Block::rotate(string dir)
{
	shared_ptr<Block> tmp = make_shared<Block>(let, make_shared<Board>(), length);
	tmp->one = one;
	tmp->two = two;
	tmp->three = three;
	tmp->four = four;

	// which way is it rotating
	int type;
	if (dir == "clockwise")
		type = -1;
	else
		type = 1;

	// Pivot point
	int pivotX = 0;
	int pivotY = 0;

	// Horizontal and vertical shifts
	int hs = 0;
	int vs = 0;

	if (let == 'I')
	{
		// Set pivot coordinates
		pivotX = min(one->getCoordinates().second, four->getCoordinates().second);
		pivotY = max(one->getCoordinates().first, four->getCoordinates().first);

		// Set shift size
		if (one->getCoordinates().first == four->getCoordinates().first && type == -1)
			vs = -3;
		else if (one->getCoordinates().second == four->getCoordinates().second && type == 1)
			hs = 3;

		// Apply rotation on block
		tmp->one = board->getGrid()[vs + pivotY - (abs(one->getCoordinates().second - pivotX) * type)]
			[hs + pivotX - (abs(one->getCoordinates().first - pivotY) * type)];
		tmp->two = board->getGrid()[vs + pivotY - (abs(two->getCoordinates().second - pivotX) * type)]
			[hs + pivotX - (abs(two->getCoordinates().first - pivotY) * type)];
		tmp->three = board->getGrid()[vs + pivotY - (abs(three->getCoordinates().second - pivotX) * type)]
			[hs + pivotX - (abs(three->getCoordinates().first - pivotY) * type)];
		tmp->four = board->getGrid()[vs + pivotY - (abs(four->getCoordinates().second - pivotX) * type)]
			[hs + pivotX - (abs(four->getCoordinates().first - pivotY) * type)];

	}
	else if (let != 'O')
	{
		// Set temp bounding rectangle
		tmp->bottomLeft = bottomLeft;
		tmp->bottomRight = bottomRight;
		tmp->topLeft = topLeft;
		tmp->topRight = topRight;

		// Set pivot coordinates
		pivotX = min(topLeft->getCoordinates().second, bottomRight->getCoordinates().second);
		pivotY = max(topRight->getCoordinates().first, bottomLeft->getCoordinates().first);

		// Set shift size
		if (topLeft->getCoordinates().second == bottomLeft->getCoordinates().second && type == 1)
			hs = 1;
		else if (topLeft->getCoordinates().second == bottomLeft->getCoordinates().second && type == -1)
			vs = -2;
		else if (topLeft->getCoordinates().second == topRight->getCoordinates().second && type == 1)
			hs = 2;
		else if (topLeft->getCoordinates().second == topRight->getCoordinates().second && type == -1)
			vs = -1;

		// Apply rotation on block
		tmp->one = board->getGrid()[vs + pivotY - (abs(one->getCoordinates().second - pivotX) * type)]
			[hs + pivotX - (abs(one->getCoordinates().first - pivotY) * type)];
		tmp->two = board->getGrid()[vs + pivotY - (abs(two->getCoordinates().second - pivotX) * type)]
			[hs + pivotX - (abs(two->getCoordinates().first - pivotY) * type)];
		tmp->three = board->getGrid()[vs + pivotY - (abs(three->getCoordinates().second - pivotX) * type)]
			[hs + pivotX - (abs(three->getCoordinates().first - pivotY) * type)];
		tmp->four = board->getGrid()[vs + pivotY - (abs(four->getCoordinates().second - pivotX) * type)]
			[hs + pivotX - (abs(four->getCoordinates().first - pivotY) * type)];

		tmp->topLeft = board->getGrid()[vs + pivotY - (abs(topLeft->getCoordinates().second - pivotX) * type)]
			[hs + pivotX - (abs(topLeft->getCoordinates().first - pivotY) * type)];
		tmp->topRight = board->getGrid()[vs + pivotY - (abs(topRight->getCoordinates().second - pivotX) * type)]
			[hs + pivotX - (abs(topRight->getCoordinates().first - pivotY) * type)];
		tmp->bottomLeft = board->getGrid()[vs + pivotY - (abs(bottomLeft->getCoordinates().second - pivotX) * type)]
			[hs + pivotX - (abs(bottomLeft->getCoordinates().first - pivotY) * type)];
		tmp->bottomRight = board->getGrid()[vs + pivotY - (abs(bottomRight->getCoordinates().second - pivotX) * type)]
			[hs + pivotX - (abs(bottomRight->getCoordinates().first - pivotY) * type)];
	}

	// Set the current block cells to empty
	if (!collision(*tmp))
	{
		return;
	}
	one->setBlockType(' ');
	one->setIsOccupied(false);
	two->setBlockType(' ');
	two->setIsOccupied(false);
	three->setBlockType(' ');
	three->setIsOccupied(false);
	four->setBlockType(' ');
	four->setIsOccupied(false);

	// Swap pointers to cells with the temporary block
	swap(one, tmp->one);
	swap(two, tmp->two);
	swap(three, tmp->three);
	swap(four, tmp->four);
	swap(topLeft, tmp->topLeft);
	swap(topRight, tmp->topRight);
	swap(bottomLeft, tmp->bottomLeft);
	swap(bottomRight, tmp->bottomRight);

	// Set temp values to sa random cell so they don't delete board cells
	tmp->one = make_shared<Cell>(3, 1);
	tmp->two = tmp->one;
	tmp->three = tmp->one;
	tmp->four = tmp->one;
	tmp->topLeft = tmp->one;
	tmp->topRight = tmp->one;
	tmp->bottomLeft = tmp->one;
	tmp->bottomRight = tmp->one;

	// Set the new cell values
	one->setBlockType(let);
	one->setIsOccupied(true);
	two->setBlockType(let);
	two->setIsOccupied(true);
	three->setBlockType(let);
	three->setIsOccupied(true);
	four->setBlockType(let);
	four->setIsOccupied(true);
}

vector<shared_ptr<Cell>> Block::getCells() {
	vector<shared_ptr<Cell>> cells;
	cells.emplace_back(one);
	cells.emplace_back(two);
	cells.emplace_back(three);
	cells.emplace_back(four);
	return cells;
}
