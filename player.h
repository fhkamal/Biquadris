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
    Player(std::string fileName, int seed, int level, int highscore); //constructor
    int getScore(); //returns score
    int getHighScore(); //returns high score
    int getLevel(); // returns level
    std::shared_ptr<Level> getLvl(); //returns the level object
    bool getEndGame(); //return endGame
    void setRowsCleared(int rows); //updates rowsCleared field
    void setBlocksOnBoard(std::shared_ptr<Block>); //adds blocks to the blocksOnBoard vector
    void setQueue(std::vector<std::string> s); //sets the sequence to the queue in its level object
    std::string getNext(); //returns the next block
    std::shared_ptr<Board> getBoard(); //returns the board
    std::shared_ptr<Block> getCurrentBlock(); //returns current block
    bool canSpawn(std::string b); //returns if a block can spwawn
    std::vector<std::string> getQueue(); //returns the queue of blocks
    void setScore(int x); //sets the score of the player
    void setLevel(int x); //sets the level of the player
    void setEndGame(bool b); //sets whether or not the player can continue playing
    void setHighScore(int x); //sets the highscore of the player
    void setCurrent(std::string b); //sets the current block of the player
    void moveBlock(std::string dir); //calls the movement functions in each block
    void specialAction(std::string action); //activates special actions for the player
    void resetSpecialActions(); //deactivates specials actions
    bool getSpecialHeavy(); //returns if heavy action is active
    void force(std::string b); //implements the force special action
    int getRowsCleared(); //returns number of rows cleared
    std::vector<std::shared_ptr<Block>> getBlocksOnBoard(); //returns the vector containing the blocks on the board
    bool getIsBlind(); //returns if blind is active
    void playSequence(std::vector<std::string> seq); //plays the current queue
    std::string printBlock(std::string b); //prints the next block
    void rotateBlock(std::string direction); //calls the rotate function on the block
    std::shared_ptr<Block> createBlock(std::string s); //creates the current block
    friend std::ostream &operator<<(std::ostream &out, const Player &p); //outputs the board
};

#endif
