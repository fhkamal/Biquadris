#include "player.h"

using namespace std;
 
Player::Player(string fileName) : score {0}, highscore {0}, fileName {fileName} {
    lvl = make_shared<LevelZero>(fileName);
    board = make_shared<Board>();
    board->init();
    queue = lvl->getSequence();
}

void Player::playSequence(std::vector<std::string> seq){

    if (seq.size() <= 2) {
        for (int i = 0; i < lvl->getSequence().size(); i++) {
            queue.emplace_back(lvl->getSequence()[i]);
        }
    }
    if (*(seq.begin()) == "J") {
        current = make_shared<JBlock>(board);	// block test
    }
    else if (*(seq.begin()) == "S") {
	    current = make_shared<SBlock>(board);
    }
    else if (*(seq.begin()) == "I") {
	    current = make_shared<IBlock>(board);
    }
    else if (*(seq.begin()) == "Z") {
    	current = make_shared<ZBlock>(board);
    }
      else if (*(seq.begin()) == "T") {
    	current = make_shared<TBlock>(board);
    }
    else if (*(seq.begin()) == "O") {
    	current = make_shared<OBlock>(board);
    }
    else if (*(seq.begin()) == "L") {
    	current = make_shared<LBlock>(board);
    }

    next = seq[1];
    blocksOnBoard.emplace_back(current);
    // Update the board display and shift the queue of blocks
    board->getTextDisplay()->updateDisplay(*board);
    queue.erase(queue.begin());
}

vector<string> Player::getQueue(){
	return queue;
}

int Player::getScore()  {
    return score;
}

int Player::getLevel() {
    return lvl->getLevel();
}

shared_ptr<Board> Player::getBoard() {
    return board;
}

shared_ptr<Block> Player::getCurrentBlock() {
    return current;
}



void Player::setScore(int x) {
    score = x;
}

void Player::setHighScore(int  x) {
    highscore = x;
}

void Player::setLevel(int x) {
    if (x > 4) x = 4;
    if (x < 0) x = 0;

    if  (x == 0) lvl = make_shared<LevelZero>(fileName);
    // ADD IN REST HERE
}

void Player::specialAction(string action) {

}

void Player::setCurrent(string b) {
    if (b == "I") {
        current = make_shared<IBlock>(board);
    }
    else if (b == "J")
    {
         current = make_shared<IBlock>(board);
    }
    else if (b == "L")
    {
        // current = make_shared<IBlock>(board);
        cout << "Force L Block to be the current";
    }
    else if (b == "O")
    {
        // current = make_shared<IBlock>(board);
        cout << "Force O Block to be the current";
    }
    else if (b == "S")
    {
        // current = make_shared<IBlock>(board);
        cout << "Force S Block to be the current";
    }
    else if (b == "Z")
    {
        // current = make_shared<IBlock>(board);
        cout << "Force Z Block to be the current";
    }
    else if (b == "T")
    {
        //current = make_shared<IBlock>(board);
        cout << "Force T Block to be the current";
    }
    
    
}

void Player::moveBlock(string dir) {
    current->movement(dir);
    board->getTextDisplay()->updateDisplay(*board);
}

string Player::printBlock(string b) {
     if (b == "I") {
        return "IIII/    ";
    }
    else if (b == "J")
    {
        return "J   /JJJ ";
    }
    else if (b == "L")
    {
        return "  L /LLL ";
    }
    else if (b == "O")
    {
        return " OO / OO ";
    }
    else if (b == "S")
    {
        return " SS /SS  ";
    }
    else if (b == "Z")
    {
        return "ZZ  / ZZ ";
    }
    else if (b == "T")
    {
       return "TTT / T  ";
    }
    else
    {
        return "";
    }
}

string Player::getNext() {
    return next;
}