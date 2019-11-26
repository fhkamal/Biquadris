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
        current = make_shared<JBlock>(board);	// block test
    }
    board->getTextDisplay()->updateDisplay(*board);
    cout << *board << endl;;

    // Testing Block Movement
    cout << "Movement Right" << endl;
    current->movement("right");
    board->getTextDisplay()->updateDisplay(*board);
    cout << *board << endl;
    cout << "Movement Left" << endl;
    current->movement("left");
    board->getTextDisplay()->updateDisplay(*board);
    cout << *board << endl;
    cout << "Movement Down" << endl;
    current->movement("down");
    board->getTextDisplay()->updateDisplay(*board);
    cout << *board << endl;

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
