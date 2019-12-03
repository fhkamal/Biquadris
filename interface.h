#ifndef INCLUDE_H
#define INCLUDE_H

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "player.h"
#include "block/starblock.h"

class Interface {
    void startGame();
    void mainMenu();
    void commandInterpreter(std::string cmd, std::shared_ptr<Player>player);
    std::string currentTurn;
    bool switchTurn;
    bool printBoard;
    bool specialAction;
    std::map<std::string, std::string> macros;

    // CommandLineArguments
    bool textOnly;
    int seed;
    std::string fileName1;
    std::string fileName2;
    int level;

    public:
        Interface(bool textOnly, int seed, int level, std::string fileName1, std::string fileName2);
    	void printGame(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2);
        void initialize(); // initializes the main menu
        // Player whoseTurn(); (don't need pretty sure)
        // Player whoWon();
};

#endif
