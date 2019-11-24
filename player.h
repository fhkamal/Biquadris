#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include "level.h"
#include "levels/levelzero.h"
#include "board.h"
#include "block/block.h"
#include "block/iblock.h"

class Board;
class Block;
// class Level;
// class LevelZero;

class Player { 
    int score;
    std::shared_ptr<Level> lvl;
    int highscore;
    std::string fileName;
    // std::unique_ptr<Board> board;
    Board board;
    std::shared_ptr<Block> current, next;
    std::vector<std::string> queue;
public:
    Player(std::string fileName);

    int getScore();
    int getHighScore();
    int getLevel();
	
    std::vector<std::string> getQueue();
    void setScore(int x);
    void setLevel(int x);
    void setHighScore(int x);
    void specialAction(std::string action);
    void playSequence(std::vector<std::string> seq);
   
    friend std::ostream &operator<<(std::ostream &out, const Player &p);  
};

#endif
