#include "starblock.h"
using namespace std;

StarBlock::StarBlock(shared_ptr<Board> b) : Block('*', b, 1){
	one = b->getGrid()[3][5];
	one->setIsOccupied(true);
	levelCreated = 4;
}

StarBlock::StarBlock() : Block{'*', make_shared<Board>(), 1} {}

bool StarBlock::bounds(){
	if(one->getCoordinates().first + 1 > 17){
		canDown = false;
		return false;
	}
	return true;
}

bool StarBlock::collide(StarBlock &b){
	shared_ptr<Cell> c = make_shared<Cell>(30, 30);
	if(b.one->getIsOccupied()){
		b.one = c;
		return false;
	}
	return true;
}

void StarBlock::movement(string dir){
	if(!bounds()){
		return;
	}
	StarBlock tmp = StarBlock();
	tmp.one = board->getGrid()[(one->getCoordinates().first) + 1][one->getCoordinates().second];

	if(!collide(tmp)){
		canDown = false;
		return;
	}
	one->setBlockType(' ');
	one->setIsOccupied(false);
	swap(one, tmp.one);
	tmp.one = make_shared<Cell>(30, 30);
	tmp.two = tmp.one;
	tmp.three = tmp.one;
	tmp.four = tmp.one;
	one->setBlockType('*');
	one->setIsOccupied(true);
}
