#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include "level.h"
#include "levels/levelzero.h"
#include "board.h"

class Board;
// class Level;
// class LevelZero;

class Player { 
    int score;
    std::unique_ptr<Level> lvl;
    int highscore;
    std::string fileName;
    // std::unique_ptr<Board> board;
    Board board;
public:
    Player(std::string fileName);

    int getScore();
    int getHighScore();
    int getLevel();

    void setScore(int x);
    void setLevel(int x);
    void setHighScore(int x);
    void specialAction(std::string action);
   

    friend std::ostream &operator<<(std::ostream &out, const Player &p);  
};

#endif
