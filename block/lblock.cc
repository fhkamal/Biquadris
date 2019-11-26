#include "lblock.h"
using namespace std;

LBlock::LBlock(shared_ptr<Board> b) : Block{'L', b} {
        // The block spawns in the top left
        one = b->getGrid()[3][2];
        two = b->getGrid()[4][0];
        three = b->getGrid()[4][1];
        four = b->getGrid()[4][2];

        // Set the block in the cells
        one->setBlockType('L');
    one->setIsOccupied(true);

    two->setBlockType('L');
    two->setIsOccupied(true);

    three->setBlockType('L');
    three->setIsOccupied(true);

    four->setBlockType('L');
    four->setIsOccupied(true);
}

// Constructor for temp blocks
LBlock::LBlock() : Block{'L', make_shared<Board>()} {}

void LBlock::rotate(string direction){
        if(direction == "clockwise"){

        }
}

void LBlock::movement(string dir)
{
        // call temp block constructor
        LBlock tmp = LBlock();

        // Set the new Block to current block position
        tmp.one = one;
        tmp.two = two;
        tmp.three = three;
        tmp.four = four;

        if (dir == "right")
        {
                // // Check if blocks to the right are in bounds
                // if (one->getCoordinates().second + 1 > 10 || two->getCoordinates().second + 1 > 10 ||
                //      three->getCoordinates().second + 1 > 10 || four->getCoordinates().second + 1 > 10)
                // {
                //      return;
                // }

                // // Check if blocks to the right are occupied
                // if (board->getGrid()[(one->getCoordinates().first + 1)][one->getCoordinates().second + 1]->getIsOccupied() ||
                //      board->getGrid()[(two->getCoordinates().first + 1)][two->getCoordinates().second + 1]->getIsOccupied() ||
                //      board->getGrid()[(three->getCoordinates().first + 1)][three->getCoordinates().second + 1]->getIsOccupied() ||
                //      board->getGrid()[(four->getCoordinates().first + 1)][four->getCoordinates().second + 1]->getIsOccupied())
                //      return;

                // Shift the block 1 block to right
                tmp.one = board->getGrid()[(one->getCoordinates().first)][one->getCoordinates().second + 1];
                tmp.two = board->getGrid()[(two->getCoordinates().first)][two->getCoordinates().second + 1];
                tmp.three = board->getGrid()[(three->getCoordinates().first)][three->getCoordinates().second + 1];
                tmp.four = board->getGrid()[(four->getCoordinates().first)][four->getCoordinates().second + 1];

                // Set the current block cells to empty

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

                // Set temp values to sa random cell so they don't delete board cells
                tmp.one = make_shared<Cell>(3, 1);
                tmp.two = tmp.one;
                tmp.three = tmp.one;
                tmp.four = tmp.one;

                // Set the new cell values
                one->setBlockType('L');
                one->setIsOccupied(true);
                two->setBlockType('L');
                two->setIsOccupied(true);
                three->setBlockType('L');
                three->setIsOccupied(true);
                four->setBlockType('L');
                four->setIsOccupied(true);
        }
        else if (dir =="left") {
                        // Shift the block 1 block to left
                tmp.one = board->getGrid()[(one->getCoordinates().first)][one->getCoordinates().second - 1];
                tmp.two = board->getGrid()[(two->getCoordinates().first)][two->getCoordinates().second - 1];
                tmp.three = board->getGrid()[(three->getCoordinates().first)][three->getCoordinates().second - 1];
                tmp.four = board->getGrid()[(four->getCoordinates().first)][four->getCoordinates().second - 1];

                // Set the current block cells to empty

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

                // Set temp values to sa random cell so they don't delete board cells
                tmp.one = make_shared<Cell>(3, 1);
                tmp.two = tmp.one;
                tmp.three = tmp.one;
                tmp.four = tmp.one;

                // Set the new cell values
                one->setBlockType('L');
                one->setIsOccupied(true);
                two->setBlockType('L');
                two->setIsOccupied(true);
                three->setBlockType('L');
                three->setIsOccupied(true);
                four->setBlockType('L');
                four->setIsOccupied(true);
        }
        else if (dir =="down") {
                        // Shift the block 1 block to left
                tmp.one = board->getGrid()[(one->getCoordinates().first) + 1][one->getCoordinates().second];
                tmp.two = board->getGrid()[(two->getCoordinates().first) + 1][two->getCoordinates().second];
                tmp.three = board->getGrid()[(three->getCoordinates().first) + 1][three->getCoordinates().second];
                tmp.four = board->getGrid()[(four->getCoordinates().first) + 1][four->getCoordinates().second];

                // Set the current block cells to empty

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

                // Set temp values to sa random cell so they don't delete board cells
                tmp.one = make_shared<Cell>(3, 1);
                tmp.two = tmp.one;
                tmp.three = tmp.one;
                tmp.four = tmp.one;

                // Set the new cell values
                one->setBlockType('L');
                one->setIsOccupied(true);
                two->setBlockType('L');
                two->setIsOccupied(true);
                three->setBlockType('L');
                three->setIsOccupied(true);
                four->setBlockType('L');
                four->setIsOccupied(true);
        }
}

