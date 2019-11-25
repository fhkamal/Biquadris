#include "cell.h"

using namespace std;

pair<int, int> Cell::getCoordinates() {
    return make_pair(row, col);
}

Cell::Cell(int row, int col) : row {row}, col {col}, isOccupied {false}, blockType {' '} {}

Cell::~Cell() {}

bool Cell::getIsOccupied() {
    return isOccupied;
}

void Cell::setIsOccupied(bool b) {
    isOccupied = b;
}

void Cell::setBlockType(char c) {
    blockType = c;
}

char Cell::getBlockType() {
	return blockType;
}
