#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include "level.h"
#include "levels/levelzero.h"
#include "board.h"
#include "block/block.h"
#include "block/iblock.h"
#include "block/jblock.h"
#include "block/sblock.h"
#include "block/tblock.h"
#include "block/oblock.h"
#include "block/zblock.h"
#include "block/lblock.h"



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
    std::shared_ptr<Board> board;
    std::shared_ptr<Block> current;
    std::string next;
    std::vector<std::string> queue;
    std::vector<std::shared_ptr<Block>> blocksOnBoard;
    bool endGame;

public:
    Player(std::string fileName);

    int getScore();
    int getHighScore();
    int getLevel();
    bool getEndGame();
    std::string getNext();
    std::shared_ptr<Board> getBoard();
    std::shared_ptr<Block> getCurrentBlock();
	bool canSpawn(std::string b);
    std::vector<std::string> getQueue();
    void setScore(int x);
    void setLevel(int x);
    void setHighScore(int x);
    void setCurrent(std::string b);
    void moveBlock(std::string dir);
    void specialAction(std::string action);
    void playSequence(std::vector<std::string> seq);
    std::string printBlock(std::string b);
   
    friend std::ostream &operator<<(std::ostream &out, const Player &p);  
};

#endif
