#ifndef INCLUDE_H
#define INCLUDE_H

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "player.h"

class Interface {
    void startGame(std::string fileNameSeq1 = "biquadris_sequence1.txt", std::string fileNameSeq2 = "biquadris_sequence2.txt");
    void mainMenu();
    void commandInterpreter(std::string cmd, Player &player);
    std::string currentTurn;
    bool switchTurn;
    bool printBoard;

    public:
    	void printGame(Player &p1, Player &p2);
        void initialize(); // initializes the main menu
        // Player whoseTurn(); (don't need pretty sure)
        // Player whoWon();
};

#endif
