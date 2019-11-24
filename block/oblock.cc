#include "oblock.h"
using namespace std;

OBlock::OBlock(Board& board) : Block{'O', board} {
        // The block spawns in the top left
        one = &board.getGrid()[3][0];
        two = &board.getGrid()[3][1];
        three = &board.getGrid()[4][0];
        four = &board.getGrid()[4][1];

        // Set the block in the cells
        one->setBlockType('O');
    one->setIsOccupied(true);

    two->setBlockType('O');
    two->setIsOccupied(true);

    three->setBlockType('O');
    three->setIsOccupied(true);

    four->setBlockType('O');
    four->setIsOccupied(true);
}

void OBlock::rotate(string direction){}

void OBlock::movement(string dir) {

}
