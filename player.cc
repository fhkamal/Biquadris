#include "player.h"

using namespace std;
 
Player::Player(string fileName) : score {0}, highscore {0}, fileName {fileName} {
    lvl = make_shared<LevelZero>(fileName);
    board = make_shared<Board>();
    board->init();
    queue = lvl->getSequence();
}

void Player::playSequence(std::vector<std::string> seq){
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
    board->getTextDisplay()->updateDisplay(*board);
    cout << *board << endl;;

    // Testing Block Movement
    // cout << "Movement Right" << endl;
    // current->movement("right");
    // board->getTextDisplay()->updateDisplay(*board);
    // cout << *board << endl;
    // cout << "Movement Left" << endl;
    // current->movement("left");
    // board->getTextDisplay()->updateDisplay(*board);
    // cout << *board << endl;
    // cout << "Movement Down" << endl;
    // current->movement("down");
    // board->getTextDisplay()->updateDisplay(*board);
    // cout << *board << endl;

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

std::shared_ptr<Board> Player::getBoard() {
    return board;
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
