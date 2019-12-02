#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include "level.h"
#include "levels/levelzero.h"
#include "levels/levelone.h"
#include "levels/leveltwo.h"
#include "levels/levelthree.h"
#include "levels/levelfour.h"
#include "board.h"
#include "block/block.h"
#include "block/iblock.h"
#include "block/jblock.h"
#include "block/sblock.h"
#include "block/tblock.h"
#include "block/oblock.h"
#include "block/zblock.h"
#include "block/lblock.h"
#include "block/starblock.h"



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
    int seed;
    bool isBlind;
    bool specialHeavy;
    int rowsCleared;

public:
    Player(std::string fileName, int seed, int level);
    int getScore();
    int getHighScore();
    int getLevel();
    std::shared_ptr<Level> getLvl();
    bool getEndGame();
    void setRowsCleared(int rows);
    void setBlocksOnBoard(std::shared_ptr<Block>);
    std::string getNext();
    std::shared_ptr<Board> getBoard();
    std::shared_ptr<Block> getCurrentBlock();
    bool canSpawn(std::string b);
    std::vector<std::string> getQueue();
    void setScore(int x);
    void setLevel(int x);
    void setEndGame(bool b);
    void setHighScore(int x);
    void setCurrent(std::string b);
    void moveBlock(std::string dir);
    void specialAction(std::string action);
    void resetSpecialActions();
    bool getSpecialHeavy();
    void force(std::string b);
    int getRowsCleared();
    std::vector<std::shared_ptr<Block>> getBlocksOnBoard();
    bool getIsBlind();
    void playSequence(std::vector<std::string> seq);
    std::string printBlock(std::string b);
    void rotateBlock(std::string direction);
    std::shared_ptr<Block> createBlock(std::string s);
    friend std::ostream &operator<<(std::ostream &out, const Player &p);  
};

#endif
