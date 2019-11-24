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
    TextDisplay();
    void updateDisplay(Board grid);
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
