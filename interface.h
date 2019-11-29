#ifndef INCLUDE_H
#define INCLUDE_H

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "player.h"

class Interface {
    void startGame();
    void mainMenu();
    void commandInterpreter(std::string cmd, Player &player);
    std::string currentTurn;
    bool switchTurn;
    bool printBoard;

    // CommandLineArguments
    bool textOnly;
    int seed;
    std::string fileName1;
    std::string fileName2;
    int level;

    public:
        Interface(bool textOnly, int seed, int level, std::string fileName1, std::string fileName2);
    	void printGame(Player &p1, Player &p2);
        void initialize(); // initializes the main menu
        // Player whoseTurn(); (don't need pretty sure)
        // Player whoWon();
};

#endif
