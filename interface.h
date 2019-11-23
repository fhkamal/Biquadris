#ifndef INCLUDE_H
#define INCLUDE_H

#include <iostream>
#include <string>
#include <map>
// #include "player.h"

class Interface {
    void startGame();
    void mainMenu();
    void commandInterpreter(std::string cmd);
    

    // Player currentTurn;
    public:
    
        void initialize(); // initializes the main menu
        // Player whoseTurn(); (don't need pretty sure)
        // Player whoWon();
};

#endif