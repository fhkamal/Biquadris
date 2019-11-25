#include "iblock.h"
using namespace std;

IBlock::IBlock(shared_ptr<Board> b) : Block{'I', b} {
	// The block spawns in the top left
	cout << b;
	// // one = make_shared<board->getGrid()[3][0]>();
	// one = board->getGrid()[3][0];
	// two = b->getGrid()[3][1];
	// three = b->getGrid()[3][2];
	// four = b->getGrid()[3][3];
	
	// // Set the block in the cells
	// cout << one->getBlockType() << endl;
	// one->setBlockType('I');
    // one->setIsOccupied(true);
	// b->getGrid()[3][0]->setBlockType('I');
	// cout << one->getBlockType() << endl;
	// cout <<  &b->getGrid()[3][0] << endl;
	// cout << b->getGrid()[3][0]->getBlockType() << endl;
    // two->setBlockType('I');
    // two->setIsOccupied(true);

    // three->setBlockType('I');
    // three->setIsOccupied(true);
    
    // four->setBlockType('I');
    // four->setIsOccupied(true);
}	

void IBlock::rotate(string direction){
	if(direction == "clockwise"){
			
	}
}

void IBlock::movement(string dir) {

}
