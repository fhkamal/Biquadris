#ifndef _BOARD_H_
#define  _BOARD_H_

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "cell.h"
// #include "textdisplay.h"
// #include "player.h"
//#include "block/block.h"
#include "textdisplay.h"

class TextDisplay;

class Board {
    // The grid
    std::vector<std::vector<Cell>> grid;
    // Dimensions of the grid
    const int height = 18;
    const int width = 11;
    std::unique_ptr<TextDisplay> td;

    public:

    std::vector<std::vector<Cell>> getGrid();
    void clearRow();
    // void setDisplay(unique_ptr<TextDisplay> td);
    bool tooTall();
    void init();
    // bool validMove(unique_ptr<Block> b);
    // void setPiece(unique_ptr<Block> b);
    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif
