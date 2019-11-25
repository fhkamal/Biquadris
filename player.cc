#include "player.h"

using namespace std;
 
Player::Player(string fileName) : score {0}, highscore {0}, fileName {fileName} {
    lvl = make_shared<LevelZero>(fileName);
    board = make_shared<Board>();
    board->init();
    queue = lvl->getSequence();
}

void Player::playSequence(std::vector<std::string> seq){
    if (*(seq.begin()) == "I") {
        current = make_shared<IBlock>(board);	
    }
    cout << "here";
    board->getTextDisplay()->updateDisplay(*board);
    cout << *board;
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

void Player::setScore(int x) {
    score = x;
}

void Player::setHighScore(int  x) {
    highscore = x;
}

void Player::setLevel(int x) {
}

void Player::specialAction(string action) {

}
