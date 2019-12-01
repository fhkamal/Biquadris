#include "player.h"

using namespace std;
 
Player::Player(string fileName) : score {0}, highscore {0}, fileName {fileName}, endGame {false} {
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
    // If a block can't spawn, the game must end
    if (!canSpawn(*(seq.begin())))  {
        endGame = true;
        board->getTextDisplay()->updateDisplay(*board);
        return;
    }

    if (*(seq.begin()) == "J") {
        current = make_shared<JBlock>(board, lvl->getLevel());	// block test
    }
    else if (*(seq.begin()) == "S") {
	    current = make_shared<SBlock>(board, lvl->getLevel());
    }
    else if (*(seq.begin()) == "I") {
	    current = make_shared<IBlock>(board, lvl->getLevel());
    }
    else if (*(seq.begin()) == "Z") {
    	current = make_shared<ZBlock>(board, lvl->getLevel());
    }
      else if (*(seq.begin()) == "T") {
    	current = make_shared<TBlock>(board, lvl->getLevel());
    }
    else if (*(seq.begin()) == "O") {
    	current = make_shared<OBlock>(board, lvl->getLevel());
    }
    else if (*(seq.begin()) == "L") {
    	current = make_shared<LBlock>(board, lvl->getLevel());
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
int Player::getHighScore() {
    return highscore;
}

shared_ptr<Block> Player::getCurrentBlock() {
    return current;
}



void Player::setScore(int x) {
    score += (x + getLevel()) * (x + getLevel());    
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


void Player::moveBlock(string dir) {
    current->movement(dir);
    board->getTextDisplay()->updateDisplay(*board);
}

void Player::rotateBlock(string direction) {
    current->rotate(direction);
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

bool Player::canSpawn(string b) {
    if (b == "I") {
        if (board->getGrid()[3][0]->getIsOccupied() || board->getGrid()[3][1]->getIsOccupied() ||
             board->getGrid()[3][2]->getIsOccupied() || board->getGrid()[3][3]->getIsOccupied()) return false;
    }
    else if (b == "J")
    {
        if (board->getGrid()[3][0]->getIsOccupied() || board->getGrid()[3][1]->getIsOccupied() ||
             board->getGrid()[3][2]->getIsOccupied()) return false;
    }
    else if (b == "L")
    {
        if (board->getGrid()[3][0]->getIsOccupied() || board->getGrid()[3][1]->getIsOccupied() ||
             board->getGrid()[3][2]->getIsOccupied()) return false;
    }
    else if (b == "O")
    {
        if (board->getGrid()[3][0]->getIsOccupied() || board->getGrid()[3][1]->getIsOccupied()) return false;
    }
    else if (b == "S")
    {
        if (board->getGrid()[3][0]->getIsOccupied() || board->getGrid()[3][1]->getIsOccupied()) return false;
    }
    else if (b == "Z")
    {
        if (board->getGrid()[3][1]->getIsOccupied() || board->getGrid()[3][2]->getIsOccupied()) return false;
    }
    else if (b == "T")
    {
       if (board->getGrid()[3][1]->getIsOccupied()) return false;
    }
    return true;
}

bool Player::getEndGame() {
    return endGame;
}
