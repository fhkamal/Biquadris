#ifndef _CELL_H_
#define _CELL_H_

#include <utility>

class Cell
{
    // coordinates
    int col;
    int row;
    // is there a block inside on this cell
    bool isOccupied;
    // what block is on this cell
    char blockType; 

public:
    // Constructor and Destructor
    Cell(int row, int col);
    ~Cell();

    // Getters and Setters
    std::pair<int, int> getCoordinates();
    void setCoordinates(int r, int c);
    bool getIsOccupied();
    void setIsOccupied(bool b);
    void setBlockType(char c);
    char getBlockType();
};

#endif
