#include "interface.h"
#include "iomanip"

//  Testing
// #include "board.h"
//#include "player.h"

using namespace std;

Interface::Interface(bool textOnly, int seed, int level, string fileName1, string fileName2) : textOnly{textOnly},
																							   seed{seed}, level{level}, fileName1{fileName1}, fileName2{fileName2}
{
	// Enable short forms of commands
	map<string, string> macros; // Fill in later
};

void Interface::mainMenu()
{
	cout << "To start a game, enter start" << endl;
	cout << "To quit the main menu, enter quit" << endl;
}

void Interface::initialize()
{
	mainMenu();
	string cmd;

	while (cin >> cmd)
	{
		if (cmd == "start")
		{
			cout << "Starting the game..." << endl;
			startGame();
		}
		else if (cmd == "quit" || cmd == "exit") 
		{
			break;
		}
		else
		{
			cout << "You entered an invalid command: " << cmd << ". " << endl
				 << "Please try again" << endl;
			mainMenu();
		}
	}
	cout << "Thank you for playing." << endl;
}

void Interface::startGame()
{
	// Create Players 1 and 2
	Player p1(fileName1, seed, level);
	p1.playSequence(p1.getQueue());
	Player p2(fileName2, seed, level);
	p2.playSequence(p2.getQueue());
	printGame(p1, p2);

	// Set player levels

	// set seed for random generation

	currentTurn = "p1";
	switchTurn = false;
	specialAction = false;

	string cmd;

	while (cin >> cmd)
	{
		if (p1.getEndGame() || p2.getEndGame())
			break;
		/*
		   cout << specialAction << endl;
		   if (specialAction)
		   {
		   string action;
		   cout << "Enter special action: ";
		   cin >> action;
		   cout << endl;
		   if (currentTurn == "p1")
		   {
		   p2.specialAction(action);
		   }
		   else
		   {
		   p1.specialAction(action);
		   }
		   }*/

		if (switchTurn)
		{
			if (currentTurn == "p1")
			{
				currentTurn = "p2";
			}
			else
			{
				currentTurn = "p1";
			}
			switchTurn = false;
		}

		// Exits the game loop and returns to main menu
		if (cmd == "quit" || cmd == "exit" || cmd == "q")
			break;

		if (cmd != "restart")
		{
			if (currentTurn == "p1")
			{
				commandInterpreter(cmd, p1);
				if (p1.getLevel() == 4 && (p1.getLvl()->getTurns() % 5 == 0) && switchTurn)
				{
					if (p1.getRowsCleared() == 0)
					{
						if (!p1.canSpawn("*"))
						{
							p1.setEndGame(true);
							p1.getBoard()->getTextDisplay()->updateDisplay(*(p1.getBoard()), p1.getIsBlind());
							//cout << "test" << endl;
							return;
						}
						shared_ptr<Block> s = p1.createBlock("*");
						p1.setBlocksOnBoard(s);
						p1.getBoard()->getTextDisplay()->updateDisplay(*(p1.getBoard()), p1.getIsBlind());
						while (s->getCanDown())
						{
							s->movement("down");
						}
						p1.getBoard()->getTextDisplay()->updateDisplay(*(p1.getBoard()), p1.getIsBlind());
						int score = p1.getBoard()->clearRow();
						if (score != 0)
						{
							if (score >= 2)
								specialAction = true;
							p1.setScore(score);
							p1.setRowsCleared(score);
						}
						printBoard = true;
					}
					else
					{
						p1.setRowsCleared(0);
					}
				}
			}
			else if (currentTurn == "p2")
			{
				commandInterpreter(cmd, p2);
				if (p2.getLevel() == 4 && (p2.getLvl()->getTurns() % 5) == 0 && switchTurn)
				{
					if (p2.getRowsCleared() == 0)
					{
						if (!p2.canSpawn("*"))
						{
							p2.setEndGame(true);
							p2.getBoard()->getTextDisplay()->updateDisplay(*(p2.getBoard()), p2.getIsBlind());
							//cout << "test" << endl;
							return;
						}
						shared_ptr<Block> s = p2.createBlock("*");
						p2.setBlocksOnBoard(s);
						p2.getBoard()->getTextDisplay()->updateDisplay(*(p2.getBoard()), p2.getIsBlind());
						while (s->getCanDown())
						{
							s->movement("down");
						}
						p2.getBoard()->getTextDisplay()->updateDisplay(*(p2.getBoard()), p2.getIsBlind());
						int score = p2.getBoard()->clearRow();
						if (score != 0)
						{
							if (score >= 2)
								specialAction = true;
							p2.setScore(score);
							p2.setRowsCleared(score);
						}
						printBoard = true;
					}
					else
					{
						p2.setRowsCleared(0);
					}
				}
			}
		}

		if (switchTurn)
		{

			if (currentTurn == "p1")
				p1.resetSpecialActions();
			else
				p2.resetSpecialActions();
		}

		if (printBoard)
			printGame(p1, p2);

		if (specialAction)
		{
			string action;
			cout << "Enter special action: ";
			cin >> action;
			cout << endl;
			while (action != "blind" && action != "heavy" && action != "force")
			{
				cout << "Not a valid special action. Please enter a valid speical action: ";
				cin >> action;
				cout << endl;
			}
			if (currentTurn == "p1")
			{
				p2.specialAction(action);
			}
			else
			{
				p1.specialAction(action);
			}

			printGame(p1, p2);
			specialAction = false;
		}
		if (p1.getEndGame() || p2.getEndGame()) {
			cout << "Break from loop" << endl;
			break;
		}
	}

	if (!p1.getEndGame() && p2.getEndGame())
	{
		cout << endl
			 << endl
			 << "Player 1 wins with a score of: " << p1.getScore() << "!" << endl;
	}
	else if (p1.getEndGame() && !p2.getEndGame())
	{
		cout << endl
			 << endl
			 << "Player 2 wins with a score of: " << p2.getScore() << "!" << endl;
	}
	else if (p1.getEndGame() && !p2.getEndGame())
	{
		cout << endl
			 << endl
			 << "The game ends in a Tie!" << endl;
	}

	cout << "Enter start to play again. " << endl
		 << "Enter exit to quit." << endl;
}

void Interface::commandInterpreter(string cmd, Player &player)
{
	// List of Commands

	// Block Commands: left, right, down, clockwise, counterclockwise, drop
	// Player Commands: levelup, leveldown, norandom <file>, random
	// Testing: sequence <file>, I, J. L, T, S, Z, O

	int multiplier = 1;

	if (isdigit(cmd[0]))
	{
		int n = cmd[0] - '0'; // Converts the multiplier from char to int
		if (n > -1)
		{ // Check if the multiplier is valid
			multiplier = n;
		}
		cmd = cmd.substr(1);
	}
	while (isdigit(cmd[0]))
	{
		int n = cmd[0] - '0'; // Converts the multiplier from char to int
		multiplier = multiplier * 10 + n;
		cmd = cmd.substr(1);
	}
	printBoard = false;

	while (multiplier > 0)
	{
		// Player Commands
		if (cmd == "levelup" || cmd == "levelu")
		{
			player.setLevel(player.getLevel() + 1);
			printBoard = true;
		}
		else if (cmd == "leveldown" || cmd == "leveld")
		{
			player.setLevel(player.getLevel() - 1);
			printBoard = true;
		}
		else if (cmd.find("norandom") != string::npos || cmd.find("nor") != string::npos || cmd.find("no") != string::npos)
		{
			string fileName;
			cin >> fileName;
			cout << fileName << endl;
			break;
		}
		else if (cmd == "random" || cmd.find("ra") != string::npos)
		{
			cout << "rndm" << endl;
			break;
		}

		// Block Commands
		else if (cmd.find("lef") != string::npos)
		{
			player.moveBlock("left");
			if (player.getLevel() > 2 && multiplier == 1)
			{
				player.moveBlock("down");
				if (!player.getCurrentBlock()->getCanDown())
				{
					player.getLvl()->increment();
					int score = player.getBoard()->clearRow();
					if (score != 0)
					{
						if (score >= 2)
							specialAction = true;
						player.setScore(score);
						player.setRowsCleared(score);
					}
					player.getBoard()->clearRow();
					switchTurn = true;
					printBoard = true;
					player.playSequence(player.getQueue());
					break;
				}
			}
			if (player.getSpecialHeavy() && multiplier == 1)
			{
				player.moveBlock("down");
				player.moveBlock("down");
				if (!player.getCurrentBlock()->getCanDown())
				{
					player.getLvl()->increment();
					int score = player.getBoard()->clearRow();
					if (score != 0)
					{
						if (score >= 2)
							specialAction = true;
						player.setScore(score);
						player.setRowsCleared(score);
					}
					player.getBoard()->clearRow();
					switchTurn = true;
					printBoard = true;
					player.playSequence(player.getQueue());
					break;
				}
			}
			printBoard = true;
		}
		else if (cmd.find("ri") != string::npos)
		{
			player.moveBlock("right");
			if (player.getLevel() > 2 && multiplier == 1)
			{
				player.moveBlock("down");
				if (!player.getCurrentBlock()->getCanDown())
				{
					player.getLvl()->increment();
					int score = player.getBoard()->clearRow();
					if (score != 0)
					{
						if (score >= 2)
							specialAction = true;
						player.setScore(score);
						player.setRowsCleared(score);
					}
					player.getBoard()->clearRow();
					switchTurn = true;
					printBoard = true;
					player.playSequence(player.getQueue());
					break;
				}
			}
			if (player.getSpecialHeavy() && multiplier == 1)
			{
				player.moveBlock("down");
				player.moveBlock("down");
				if (!player.getCurrentBlock()->getCanDown())
				{
					player.getLvl()->increment();
					int score = player.getBoard()->clearRow();
					if (score != 0)
					{
						if (score >= 2)
							specialAction = true;
						player.setScore(score);
						player.setRowsCleared(score);
					}
					player.getBoard()->clearRow();
					switchTurn = true;
					printBoard = true;
					player.playSequence(player.getQueue());
					break;
				}
			}
			printBoard = true;
		}
		else if (cmd.find("do") != string::npos)
		{
			// use a getter to check if file can go anymore down from block field and if false then change player
			player.moveBlock("down");
			if (!player.getCurrentBlock()->getCanDown())
			{
				player.getLvl()->increment();
				int score = player.getBoard()->clearRow();
				if (score != 0)
				{
					if (score >= 2)
						specialAction = true;
					player.setScore(score);
					player.setRowsCleared(score);
				}
				player.getBoard()->clearRow();
				switchTurn = true;
				printBoard = true;
				player.playSequence(player.getQueue());
				break;
			}
			printBoard = true;
		}
		else if (cmd == "clockwise" || cmd == "cl" || cmd == "clo" || cmd == "cloc" || cmd == "clock" || cmd == "clockw" || cmd == "clockwi" || cmd == "clockwis")
		{
			player.rotateBlock(cmd);
			if (player.getLevel() > 2 && multiplier == 1)
			{
				player.moveBlock("down");
				if (!player.getCurrentBlock()->getCanDown())
				{
					player.getLvl()->increment();
					int score = player.getBoard()->clearRow();
					if (score != 0)
					{
						if (score >= 2)
							specialAction = true;
						player.setScore(score);
						player.setRowsCleared(score);
					}
					player.getBoard()->clearRow();
					switchTurn = true;
					printBoard = true;
					player.playSequence(player.getQueue());
					break;
				}
			}
			printBoard = true;
		}
		else if (cmd == "counterclockwise" || cmd.find("counter") != string::npos || cmd.find("co") != string::npos || cmd.find("cou") != string::npos || cmd.find("count") != string::npos)
		{
			player.rotateBlock(cmd);
			if (player.getLevel() > 2 && multiplier == 1)
			{
				player.moveBlock("down");
				if (!player.getCurrentBlock()->getCanDown())
				{
					player.getLvl()->increment();
					int score = player.getBoard()->clearRow();
					if (score != 0)
					{
						if (score >= 2)
							specialAction = true;
						player.setScore(score);
						player.setRowsCleared(score);
					}
					player.getBoard()->clearRow();
					switchTurn = true;
					printBoard = true;
					player.playSequence(player.getQueue());
					break;
				}
			}
			printBoard = true;
		}
		else if (cmd == "drop" || cmd.find("dr") == 0)
		{
			// use a getter to check if file can go anymore down from block field and if false then change player
			while (player.getCurrentBlock()->getCanDown())
			{
				player.moveBlock("down");
			}
			player.getLvl()->increment();
			int score = player.getBoard()->clearRow();
			if (score != 0)
			{
				if (score >= 2)
					specialAction = true;
				player.setScore(score);
				player.setRowsCleared(score);
			}

			switchTurn = true;
			printBoard = true;
			player.playSequence(player.getQueue());
		}

		// Testing Commands
		else if (cmd.find("sequence") != string::npos || cmd.find("s") != string::npos)
		{
			// string fileName = cmd.substr(cmd.find_first_of(" \t") + 1);
			string s;
			cin >> s;
			cout << s << endl;
			break;
		}
		else if (cmd == "I" || cmd == "O" || cmd == "T" || cmd == "Z" || cmd == "S" || cmd == "L" || cmd == "J")
		{
			player.force(cmd);
			printBoard = true;
		}
		else if (cmd == "restart")
		{
			cout << "rstrt" << endl;
			break;
		}
		multiplier--;
	}
	if (printBoard == true)
	{
		//cout << *(player.getBoard());
	}
}

void Interface::printGame(Player &p1, Player &p2)
{
	cout << endl;
	//p1.getBoard()->clearRow();
	//p2.getBoard()->clearRow();
	cout << "Level:    " << p1.getLevel() << "      "
		 << "Level:    " << p2.getLevel() << endl;
	cout << "Score:" << right << setw(5) << p1.getScore();
	cout << "      "
		 << "Score:" << right << setw(5) << p2.getScore() << endl;
	cout << "-----------      -----------" << endl;
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
	cout << "-----------      -----------" << endl;
	cout << "Next:            Next:" << endl;
	string x = p1.printBlock(p1.getNext());
	string y = p2.printBlock(p2.getNext());
	cout << x.substr(0, x.find('/')) + "             " + y.substr(0, y.find('/')) << endl;
	cout << x.substr(x.find('/') + 1) + "             " + y.substr(y.find('/') + 1) << endl;
	cout << endl;
}
