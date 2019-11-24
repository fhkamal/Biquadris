#include "player.h"

using namespace std;

// int getScore();
//     int getHighScore();

//     void setScore(int x);
//     void setLevel(int x);
//     void setHighScore(int x);
//     void specialAction(std::string action);
   

//     friend std::ostream &operator<<(std::ostream &out, const Player &p); 

 
Player::Player(string fileName) : score {0}, highscore {0}, fileName {fileName} {
    lvl = make_unique<LevelZero>(fileName); 
    board.init();
    queue = lvl->getSequence();
}

void Player::playSequence(std::vector<std::string> &seq){
    if (*(seq.begin()) == "I") current = make_unique<IBlock>(board);

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