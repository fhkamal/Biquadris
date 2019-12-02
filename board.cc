#include "board.h"

using namespace std;

// Initialize the board
void Board::init() {  
    for (int i = 0; i < height; i++) {
        vector<shared_ptr<Cell>> row;
        for (int j = 0; j < width; j++) {
            row.push_back(make_shared<Cell>(i, j));
        }
        grid.push_back(row);
    }

    td = make_shared<TextDisplay>();

}

// Clear the rows starting from the bottom if 
int Board::clearRow() {
    int count = 0;
    for (int i = height - 1; i >= 0; i--) {
        bool deleteRow = true;
        for (int j = 0; j < width && deleteRow; j++) {
            deleteRow = grid[i][j]->getIsOccupied(); 
        }
        if (deleteRow) {
	    vector<shared_ptr<Cell>> c;
            for (int k = 0; k < width; k++) {
               grid[i][k]->setIsOccupied(false);
	       c.emplace_back(make_shared<Cell>(0, k));              
            }
	    for (int j = i; j >= 0; j--){
		for (int k = 0;  k < width; k++){
			grid[j][k]->setCoordinates(j + 1, k);
		}
	    }
            grid.erase(grid.begin() + i);
            grid.emplace(grid.begin(), c);
            count++;
            i++;
        }

    }
    td->updateDisplay(*this, false);
    return count;
}

bool Board::tooTall() {
    for (int i = 0; i < width; i++) {
        if (grid[2][i]->getIsOccupied()) return true;
    }
    return false;
}

// bool Board::validMove(unique_ptr<Block> b) {

// }

// void Board::setDisplay(unique_ptr<TextDisplay> td) {

// }

// void Board::setPiece(unique_ptr<Block> b) {

// }

shared_ptr<TextDisplay> Board::getTextDisplay(){
	return td;
}

std::ostream &operator<<(std::ostream &out, const Board &b) {
    out << *(b.td);
    return out;
}

vector<vector<shared_ptr<Cell>>> Board::getGrid() {
    return grid;
}
