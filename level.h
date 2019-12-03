#ifndef _LEVEL_H_
#define _LEVEL_H_
#include <iostream>
#include <memory>
#include <vector>
//#include <board.h>
//#include <block.h>
#include <string>
#include <limits.h>
#include <fstream>

class Level
{
protected:
    int level;
    int turns;
    bool random;
    std::vector<std::string> sequence;
public:
    Level(); //constructor
    void getBlocks(std::string filename); //sets sequence to a vector of blocks provided by the filename
    int getLevel(); //returns level as an integer
    virtual std::vector<std::string> getSequence(); //returns the sequence of blocks
    virtual void generateSequence(int seed); //creates a random sequence of blocks given a seed
    virtual ~Level() = 0; //virtual destructor
    void increment(); //increments turns by 1
    void setRandom(bool b); //sets random to true or false when random or norandom is called respectively
    int getTurns(); //returns turns passed
    bool getRandom(); //returns random
};

#endif
