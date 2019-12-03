#include "board.h"

using namespace std;

void Board::init() {
    // Create cells for the grid	
    for (int i = 0; i < height; i++) {
        vector<shared_ptr<Cell>> row;
        for (int j = 0; j < width; j++) {
            row.push_back(make_shared<Cell>(i, j));
        }
        grid.push_back(row);
    }
    // make the text display board
    td = make_shared<TextDisplay>();

}

 
int Board::clearRow() {
    int count = 0;
    for (int i = height - 1; i >= 0; i--) {
        bool deleteRow = true;
	
	// if any of the rows are not occupied it will stop checking
        for (int j = 0; j < width && deleteRow; j++) {
            deleteRow = grid[i][j]->getIsOccupied(); 
        }
	
	// if all the rows are occupied deleteRow will remain true and 
	// we will clear the row
        if (deleteRow) {
	    // temp row created to put at the top of the board
	    vector<shared_ptr<Cell>> c;
            for (int k = 0; k < width; k++) {
	       // set row being cleared field's to empty
               grid[i][k]->setIsOccupied(false);
	       // initialize new empty row
	       c.emplace_back(make_shared<Cell>(0, k));              
            }
	    
	    // Shifts the cells coordinates after a row has been cleared
	    for (int j = i; j >= 0; j--){
		for (int k = 0;  k < width; k++){
			grid[j][k]->setCoordinates(j + 1, k);
		}
	    }

	    // erases the row that was cleared
            grid.erase(grid.begin() + i);
	    // adds an empty row of cells to the beginning of the grid
            grid.emplace(grid.begin(), c);
            count++;
	    // increment row so it checks the location that was just cleared
	    // to make sure we aren't skipping rows
            i++;
        }

    }
    td->updateDisplay(*this, false);
    return count;
}

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
