#ifndef _BOARD_H_
#define  _BOARD_H_

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "cell.h"
#include "textdisplay.h"

class TextDisplay;

class Board {

    // The grid
    std::vector<std::vector<std::shared_ptr<Cell>>> grid;
    
    // Dimensions of the grid
    const int height = 18;
    const int width = 11;

    // Text display for the grid
    std::shared_ptr<TextDisplay> td;

    public:
    // Clears rows and returns how many rows were cleared
    int clearRow();

    // Initializes the board
    void init();

    // Getters and Setters
    std::vector<std::vector<std::shared_ptr<Cell>>> getGrid();
    std::shared_ptr<TextDisplay> getTextDisplay();

    // Output operator
    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif
