#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_

#include <vector>
#include <iostream>
// #include "player.h"
 // #include "board.h"

class TextDisplay
{
    std::vector<std::vector<char>> board;
    int height = 18;
    int width = 11;

public:
    TextDisplay();

    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
