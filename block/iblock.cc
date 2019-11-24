#include "iblock.h"
using namespace std;

IBlock::IBlock(Board& board) : Block{'I', board} {
	// The block spawns in the top left
	one = &board.getGrid()[3][0];
	two = &board.getGrid()[3][1];
	three = &board.getGrid()[3][2];
	four = &board.getGrid()[3][3];
	
	// Set the block in the cells
	one->setBlockType('I');
    one->setIsOccupied(true);

    two->setBlockType('I');
    two->setIsOccupied(true);

    three->setBlockType('I');
    three->setIsOccupied(true);
    
    four->setBlockType('I');
    four->setIsOccupied(true);
}	

void IBlock::rotate(string direction){
	if(direction == "clockwise"){
			
	}
}

void IBlock::movement(string dir) {

}
