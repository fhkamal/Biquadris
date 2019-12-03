#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_

#include <vector>
#include <iostream>
#include "board.h"
// #include "player.h"

class Board;
class TextDisplay
{
    std::vector<std::vector<char>> board;
    int height = 18;
    int width = 11;

public:
    TextDisplay(); //constructor
    void updateDisplay(Board grid, bool blind); //updates the display given the board
    std::vector<std::vector<char>> getBoard(); //returns the board
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td); //outputs the board in text
};

#endif
