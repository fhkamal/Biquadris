#include "block.h"
using namespace std;

Block::Block(char let, std::shared_ptr<Board> board) : let {let}, board{board} {};

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
