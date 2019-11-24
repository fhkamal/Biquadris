#include "iblock.h"
using namespace std;

IBlock::IBlock(shared_ptr<Board> board) : Block{'I', board} {
	one = (board->getGrid()[3][0]);
	two = &board->getGrid()[3][1];
	three = &board->getGrid()[3][2];
	four = &board->getGrid()[3][3];
}	

void IBlock::rotate(string direction){
	if(direction == "clockwise"){
			
	}
}

void IBlock::movement(string dir) {

}
