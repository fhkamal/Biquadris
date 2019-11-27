#include "interface.h"

//  Testing
// #include "board.h"
//#include "player.h"

using namespace std;

void Interface::mainMenu() {
	cout << "To start a game, enter start" << endl;
	cout << "To quit the main menu, enter quit" << endl;
}


void Interface::initialize()  {
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
	// Create Players 1 and 2
	Player p1("biquadris_sequence1.txt");
	p1.playSequence(p1.getQueue());
	Player p2("biquadris_sequence2.txt");
	p2.playSequence(p2.getQueue());
	printGame(p1, p2);

	currentTurn = "p1";
	switchTurn = false;

	string cmd;

	while(cin >> cmd) {

		if (switchTurn) {
			if (currentTurn == "p1") {
				currentTurn = "p2";
			}
			else
			{
				currentTurn = "p1";
			}
			switchTurn = false;
		}


		// Exits the game loop and returns to main menu
		if (cmd == "quit" || cmd == "exit" || cmd == "q") break;

		if (cmd != "restart") {
			if (currentTurn == "p1") {
				commandInterpreter(cmd, p1);
			}
			else if (currentTurn == "p2") {
				cout << "p2";
				commandInterpreter(cmd, p2);
			}
		}
		if (printBoard) printGame(p1, p2);
	}
}

void Interface::commandInterpreter(string cmd, Player &player) {
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
	while (isdigit(cmd[0])) {
		int n = cmd[0] - '0'; // Converts the multiplier from char to int
		multiplier = multiplier * 10 + n;
		cmd = cmd.substr(1);
	}
	printBoard = false;

	while (multiplier > 0) {

		// Block Commands
		if (cmd == "left") {
			player.moveBlock("left");
			printBoard = true;
		}
		else if (cmd == "right") {
			player.moveBlock("right");
			printBoard = true;
		}
		else if (cmd == "down") {
			// use a getter to check if file can go anymore down from block field and if false then change player
			if (!player.getCurrentBlock()->getCanDown()) {
				cout << "switch" << endl;
				switchTurn = true;
				printBoard = true;
				break;
			}
			player.moveBlock("down");
			printBoard = true;
		}
		else if (cmd == "clockwise") {
			cout << "cw" << endl;
			printBoard = true;
		}
		else if (cmd == "counterclockwise") {
			cout << "ccw" << endl;
			printBoard = true;
		}
		else if (cmd == "drop") {
			// use a getter to check if file can go anymore down from block field and if false then change player
			while (player.getCurrentBlock()->getCanDown()) {
				player.moveBlock("down");
			}
			switchTurn = true;
			printBoard = true;
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
			printBoard = true;
		}
		else if (cmd == "J") {
			cout << "j-block" << endl;
			printBoard = true;
		}
		else if (cmd == "L") {
			cout << "l-block" << endl;
			printBoard = true;
		}
		else if (cmd == "O") {
			cout << "o-block" << endl;
			printBoard = true;

		}
		else if (cmd == "S") {
			cout << "s-block" << endl;
			printBoard = true;
		}
		else if (cmd == "Z") {
			cout << "z-block" << endl;
			printBoard = true;
		}
		else if (cmd == "T") {
			cout << "t-block" << endl;
			printBoard = true;
		}
		else if (cmd == "restart") {
			cout << "rstrt" << endl;
			break;
		}
		multiplier--;
	}
	if (printBoard == true) {
		//cout << *(player.getBoard());
	}    
}

void Interface::printGame(Player &p1, Player &p2) {
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			cout << p1.getBoard()->getTextDisplay()->getBoard()[i][j];
		}

		cout << "      ";

		for (int j = 0; j < 11; j++)
		{
			cout << p2.getBoard()->getTextDisplay()->getBoard()[i][j];
		}
		cout << endl;
	}	
}
