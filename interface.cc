#include "interface.h"

//  Testing
#include "board.h"

using namespace std;

void Interface::mainMenu() {
    cout << "To start a game, enter start" << endl;
    cout << "To quit the main menu, enter quit" << endl;
}


void Interface::initialize() {
    mainMenu();
    string cmd;

    while (cin >> cmd) {
        if (cmd == "start") {
            cout << "Starting the game..." << endl;
            startGame();
            
        }
        else if (cmd == "quit") {
            break;
        }
        else 
        {
            cout << "You entered an invalid command: " << cmd << ". "<< endl << "Please try  again" << endl;
            mainMenu();
        }
        
    }
    cout << "Thank you for playing." << endl;
}

void Interface::startGame() {
    Board b;
    b.init();
    cout << b;
    // Create Players 1 and 2

    // Do Turn basing here

    string cmd;

    while(cin >> cmd) {
        // Exits the game loop and returns to main menu
        if (cmd == "quit" || cmd == "exit" || cmd == "q") break;

        if (cmd != "restart") {
            commandInterpreter(cmd);
        }
        else {
            cout << "Restarting" << endl;
            // Delete players and remake players
        }
    }
}

void Interface::commandInterpreter(string cmd) {
    // List of Commands

    // Block Commands: left, right, down, clockwise, counterclockwise, drop
    // Player Commands: levelup, leveldown, norandom <file>, random
    // Testing: sequence <file>, I, J. L, T, S, Z, O
    
    // Enable short forms of commands
    map<string, string> macros; // Fill in later

    int multiplier = 1;
    if (isdigit(cmd[0])) {
        int n = cmd[0] - '0'; // Converts the multiplier from char to int
        if (n > -1) { // Check if the multiplier is valid
            multiplier = n;
        }
        cmd = cmd.substr(1);
    }

    while (multiplier > 0) {

        // Block Commands
        if (cmd == "left") {
            cout << "l" << endl;
        }
        else if (cmd == "right") {
            cout << "r" << endl;
        }
        else if (cmd == "down") {
            cout << "d" << endl;
        }
        else if (cmd == "clockwise") {
            cout << "cw" << endl;
        }
        else if (cmd == "counterclockwise") {
            cout << "ccw" << endl;
        }
        else if (cmd == "drop") {
            cout << "drp" << endl;
        }

        // Player Commands
        else if (cmd == "levelup") {
            cout << "lvlu" << endl;
        }
        else if (cmd == "leveldown") {
            cout << "lvld" << endl;
        }
        else if (cmd.find("norandom") != string::npos) {
            string fileName = cmd.substr(cmd.find(' ') + 1);
            cout << fileName << endl;
            break;
        }
        else if (cmd == "random") {
            cout << "rndm" << endl;
            break;
        }
        
        // Testing Commands
        else if (cmd.find("sequence") != string::npos) {
            string fileName = cmd.substr(cmd.find_first_of(" \t") + 1);
            cout << fileName << endl;
            break;
        }
        else if (cmd == "I") {
            cout << "i-block" << endl;
        }
        else if (cmd == "J") {
            cout << "j-block" << endl;
        }
        else if (cmd == "L") {
            cout << "l-block" << endl;
        }
        else if (cmd == "O") {
            cout << "o-block" << endl;
            
        }
        else if (cmd == "S") {
            cout << "s-block" << endl;
        }
        else if (cmd == "Z") {
            cout << "z-block" << endl;
        }
        else if (cmd == "T") {
            cout << "t-block" << endl;
        }
        else if (cmd == "restart") {
            cout << "rstrt" << endl;
            break;
        }
        multiplier--;
    }
    
}