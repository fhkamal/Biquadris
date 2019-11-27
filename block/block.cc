#include "block.h"
using namespace std;

Block::Block(char let, shared_ptr<Board> board) : let {let}, canDown {true}{
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
	else{
		if (one->getCoordinates().first + 1 > 17 || two->getCoordinates().first + 1 > 17 ||
                      three->getCoordinates().first + 1 > 17 || four->getCoordinates().first + 1 > 17)
                 {
		      canDown = true;
                      return false;
                 }	
	}
	return true;
}

bool Block::collision(Block &b){
	if(b.one->getIsOccupied() && (b.one != one) && (b.one != two) && (b.one != three) && (b.one != four)){
		cout << &b.one << endl;
		cout << &two << endl;
		return false;
	}
	if(b.two->getIsOccupied() && (b.two != one) && (b.two != two) && (b.two != three) && (b.two != four)){
		return false;
	}	
	if(b.three->getIsOccupied() && (b.three != one) && (b.three != two) && (b.three != three) && (b.three != four)){
		return false;
	}
	if(b.four->getIsOccupied() && (b.four != one) && (b.four != two) && (b.four != three) && (b.four != four)){
		return false;
	}
	return true;
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
