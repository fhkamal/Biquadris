#include "board.h"

using namespace std;

// Initialize the board
void Board::init() {  
    for (int i = 0; i < height; i++) {
        vector<Cell> row;
        for (int j = 0; j < width; j++) {
            row.push_back(Cell(i, j));
        }
        grid.push_back(row);
    }

    td = make_unique<TextDisplay>();

}

// Clear the rows starting from the bottom if 
void Board::clearRow() {
    for (int i = 0; i < height; i++) {
        bool deleteRow = true;
        for (int j = 0; j < width && deleteRow; j++) {
            deleteRow = grid[i][j].getIsOccupied(); 
        }
        if (deleteRow) {
            for (int k = 0; k < width; k++) {
                grid[i][k].setIsOccupied(false); 
                // grid[i][k].setBlockType('1');
            }
        }

    }
}

bool Board::tooTall() {
    for (int i = 0; i < width; i++) {
        if (grid[2][i].getIsOccupied()) return true;
    }
    return false;
}

// bool Board::validMove(unique_ptr<Block> b) {

// }

// void Board::setDisplay(unique_ptr<TextDisplay> td) {

// }

// void Board::setPiece(unique_ptr<Block> b) {

// }

std::ostream &operator<<(std::ostream &out, const Board &b) {
    out << *(b.td);
    return out;
}

vector<vector<Cell>> Board::getGrid() {
    return grid;
}
