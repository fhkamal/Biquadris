#include "block.h"
using namespace std;

Block::Block(char let, shared_ptr<Board> board, int length) : let {let}, canDown {true}, length{length} {
    this->board = board;
};

// Block::Block(char let, Board *board): let{let}, board{board} orient{0}, 
// one{nullptr}, two{nullptr}, three{nullptr}, four{nullptr} {}
Block::~Block() {
    // Update the cells
    one->setBlockType(' ');
    one->setIsOccupied(false);

    two->setBlockType(' ');
    two->setIsOccupied(false);

    three->setBlockType(' ');
    three->setIsOccupied(false);

    four->setBlockType(' ');
    four->setIsOccupied(false);
    
}

void Block::setCanDown(bool b){
	canDown = b;
}

bool Block::getCanDown(){
	return canDown;
}

bool Block::inBounds(string dir){
	if(dir == "right"){
	// Check if blocks to the right are in bounds
                 if (one->getCoordinates().second + 1 > 10 || two->getCoordinates().second  + 1 > 10 ||
                      three->getCoordinates().second + 1 > 10 || four->getCoordinates().second  + 1 > 10)
                 {
                      return false;
                 }	 
	}
	else if(dir == "left"){
	//Checks if blocks to the left are in bounds
		if (one->getCoordinates().second  <= 0 || two->getCoordinates().second <= 0 ||
                      three->getCoordinates().second  <= 0 || four->getCoordinates().second <= 0)
                 {
                      return false;
                 }
	}
	else if(dir == "down"){
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

bool Block::collision(Block &b){
	shared_ptr<Cell> c = make_shared<Cell>(30, 30);
	if(b.one->getIsOccupied() && (b.one != one) && (b.one != two) && (b.one != three) && (b.one != four)){
		b.one = c;
		b.two = c;
		b.three = c;
		b.four = c;
		return false;
	}
	if(b.two->getIsOccupied() && (b.two != one) && (b.two != two) && (b.two != three) && (b.two != four)){
		b.one = c;
                b.two = c;
                b.three = c;
                b.four = c;
		return false;
	}	
	if(b.three->getIsOccupied() && (b.three != one) && (b.three != two) && (b.three != three) && (b.three != four)){
		b.one = c;
                b.two = c;
                b.three = c;
                b.four = c;
		return false;
	}
	if(b.four->getIsOccupied() && (b.four != one) && (b.four != two) && (b.four != three) && (b.four != four)){
		b.one = c;
                b.two = c;
                b.three = c;
                b.four = c;
		return false;
	}
	return true;
}

void Block::rotate(string dir){
	shared_ptr<Block> tmp = make_shared<Block>(let, make_shared<Board>(), length);
	tmp->one = one;
	tmp->two = two;
	tmp->three = three;
	tmp->four = four;

	if(dir == "clockwise"){
		tmp->one = board->getGrid()[one->getCoordinates().second - 1][1 - (one->getCoordinates().first - (length - 2)) + 1];
		tmp->two = board->getGrid()[two->getCoordinates().second - 1][1 - (two->getCoordinates().first - (length - 2)) + 1];
		tmp->three = board->getGrid()[three->getCoordinates().second - 1][1 - (three->getCoordinates().first - (length - 2)) + 1];
		tmp->four = board->getGrid()[four->getCoordinates().second - 1][1 - (four->getCoordinates().first - (length - 2)) + 1];
	}
	else if(dir == "counterclockwise"){
		tmp->one == board->getGrid()[1 - (one->getCoordinates().second - (length - 2))][one->getCoordinates().first];
		tmp->two == board->getGrid()[1 - (two->getCoordinates().second - (length - 2))][two->getCoordinates().first];
		tmp->three == board->getGrid()[1 - (three->getCoordinates().second - (length - 2))][three->getCoordinates().first];
		tmp->four == board->getGrid()[1 - (four->getCoordinates().second - (length - 2))][four->getCoordinates().first];
	}
	 // Set the current block cells to empty
         if(!collision(*tmp)){
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

         // Set temp values to sa random cell so they don't delete board cells
         tmp->one = make_shared<Cell>(3, 1);
         tmp->two = tmp->one;
         tmp->three = tmp->one;
         tmp->four = tmp->one;

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

// Block Block::&operator=(const Block &other) {
//     using std::swap;
//     one = other.one;
//     two = other.two;
//     three = other.three;
//     four = other.four;
//     board = other.board;
// }

// Block& Block::operator=(Block &&other) {
//     using std::swap;
//     swap(one, other.one);
//     swap(two, other.two);
//     swap(three, other.three);
//     swap(four, other.four);
//     swap(board, other.board);
//     return (*this);
// }
