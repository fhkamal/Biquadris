#ifndef _CELL_H_
#define _CELL_H_

#include <utility>

class Cell
{
    int col;
    int row;
    bool isOccupied;
    char blockType; // 1 represents an empty

public:
    std::pair<int, int> getCoordinates();
    void setCoordinates(int r, int c);
    Cell(int row, int col);
    ~Cell();
    bool getIsOccupied();
    void setIsOccupied(bool b);
    void setBlockType(char c);
    char getBlockType();
};

#endif
