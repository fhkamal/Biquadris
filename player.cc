#include "player.h"

using namespace std;

Player::Player(string fileName, int seed, int level, int highscore) : score{0}, highscore{highscore}, fileName{fileName}, endGame{false},
	seed{seed}, isBlind{false}, specialHeavy{false}, rowsCleared{0}
{
	setLevel(level);
	board = make_shared<Board>();
	board->init();
	queue = lvl->getSequence();
	next = "N";
}

void Player::playSequence(std::vector<std::string> seq)
{
	//if the sequence is not random
	if (lvl->getLevel() == 0 || (lvl->getLevel() > 2 && !lvl->getRandom()))
	{
		if (seq.size() <= 2) //loops the sequence back around when it gets too small
		{
			for (unsigned int i = 0; i < lvl->getSequence().size(); i++)
			{
				queue.emplace_back(lvl->getSequence()[i]);
			}
		}
		// If a block can't spawn, the game must end
		if (!canSpawn(*(seq.begin())))
		{
			endGame = true;
			board->getTextDisplay()->updateDisplay(*board, isBlind);
			return;
		}

		current = createBlock(*(seq.begin()));

		next = seq[1];
		queue.erase(queue.begin());
	}
	else //sequence is random
	{

		if (queue.size() == 0) //creates sequence
		{
			lvl->generateSequence(seed);
			queue = lvl->getSequence();
		}

		// If a block can't spawn, the game must end
		if (!canSpawn(*(seq.begin())))
		{
			endGame = true;
			cout << "Here" << endl;
			board->getTextDisplay()->updateDisplay(*board, isBlind);
			return;
		}

		current = createBlock(*(seq.begin()));

		next = seq[1];
		queue.erase(queue.begin());
	}

	blocksOnBoard.emplace_back(current);
	// Update the board display and shift the queue of blocks
	board->getTextDisplay()->updateDisplay(*board, isBlind);
}

shared_ptr<Block> Player::createBlock(string s)
{// creates block based on letter
	if (s == "J")
	{
		return make_shared<JBlock>(board, lvl->getLevel());
	}
	else if (s == "S")
	{
		return make_shared<SBlock>(board, lvl->getLevel());
	}
	else if (s == "I")
	{
		return make_shared<IBlock>(board, lvl->getLevel());
	}
	else if (s == "Z")
	{
		return make_shared<ZBlock>(board, lvl->getLevel());
	}
	else if (s == "T")
	{
		return make_shared<TBlock>(board, lvl->getLevel());
	}
	else if (s == "O")
	{
		return make_shared<OBlock>(board, lvl->getLevel());
	}
	else if (s == "L")
	{
		return make_shared<LBlock>(board, lvl->getLevel());
	}
	else{
		return make_shared<StarBlock>(board);
	}
}

vector<string> Player::getQueue()
{
	return queue;
}

void Player::setQueue(vector<string> s){
	queue = s;
}

int Player::getScore()
{
	return score;
}

int Player::getLevel()
{
	return lvl->getLevel();
}

shared_ptr<Board> Player::getBoard()
{
	return board;
}
int Player::getHighScore()
{
	return highscore;
}

int Player::getRowsCleared(){
	return rowsCleared;
}

vector<shared_ptr<Block>> Player::getBlocksOnBoard(){
	return blocksOnBoard;
}

bool Player::getEndGame(){
	return endGame;
}

bool Player::getIsBlind(){
	return isBlind;
}

shared_ptr<Block> Player::getCurrentBlock()
{
	return current;
}

void Player::setBlocksOnBoard(shared_ptr<Block> b){
	blocksOnBoard.emplace_back(b);
}

void Player::setEndGame(bool b){
	endGame = b;
}

void Player::setScore(int x)
{	//checks if each block is still on the board
	for (auto it = blocksOnBoard.begin(); it != blocksOnBoard.end(); it++)
	{
		int scoreBlock = 0;
		bool deleteBlock = true;
		vector<shared_ptr<Cell>> cells = (*it)->getCells();
		for (auto it2 = cells.begin(); it2 != cells.end(); it2++) //checks each cell of the block
		{
			if ((*it2)->getIsOccupied())
				deleteBlock = false;
			if((*it)->getLet() == '*') {
				break;
			}
		}
		if (deleteBlock) //deletes block and updates score
		{
			scoreBlock = ((*it)->getLevelCreated() + 1) * ((*it)->getLevelCreated() + 1);
			blocksOnBoard.erase(it);
			it--;
		}
		score += scoreBlock;
	}
	score += (x + getLevel()) * (x + getLevel());

	if (score > highscore)
		setHighScore(score);
}

void Player::setHighScore(int x)
{
	highscore = x;
}

shared_ptr<Level> Player::getLvl(){
	return lvl;
}

void Player::setLevel(int x)
{
	queue.clear();
	if (x > 4)
		x = 4;
	if (x < 0)
		x = 0;

	if (x == 0)
		lvl = make_shared<LevelZero>(fileName);
	if (x == 1)
		lvl = make_shared<LevelOne>();
	if (x == 2)
		lvl = make_shared<LevelTwo>();
	if (x == 3)
		lvl = make_shared<LevelThree>();
	if(x == 4)
		lvl = make_shared<LevelFour>();
	lvl->generateSequence(seed);
	queue = lvl->getSequence();
}

void Player::setRowsCleared(int rows){
	rowsCleared = rows;
}

void Player::specialAction(string action)
{
	if (action == "blind"){
		isBlind = true;
	}
	else if (action == "heavy"){
		specialHeavy = true;
	}
	else { //sets block to force on the opposing player
		string block;
		cin >> block;
		while (block != "S" && block != "Z" && block != "I" && block != "T" && block != "O" && block != "J" && block != "L"){
			cout << "You are not forcing a valid block. Enter a valid block to force: ";
			cin >> block;
			cout << endl;
		}
		force(block);
	}
	board->getTextDisplay()->updateDisplay(*board, isBlind);
}

void Player::resetSpecialActions(){
	isBlind = false;
	specialHeavy = false;
	board->getTextDisplay()->updateDisplay(*board, isBlind);
}

bool Player::getSpecialHeavy(){
	return specialHeavy;
}
void Player::force(string b){ //forces the block onto the other player
	current = nullptr;
	unsigned int i = blocksOnBoard.size()-1;
	for (; blocksOnBoard[i]->getLet() == '*'; --i){}
	blocksOnBoard.erase(blocksOnBoard.begin() + i);
	//blocksOnBoard.pop_back();
	queue.emplace(queue.begin(), b);
	playSequence(queue);
	board->getTextDisplay()->updateDisplay(*board, isBlind);
}

void Player::moveBlock(string dir)
{
	current->movement(dir);
	board->getTextDisplay()->updateDisplay(*board, isBlind);
}

void Player::rotateBlock(string direction)
{
	current->rotate(direction);
	board->getTextDisplay()->updateDisplay(*board, isBlind);
}
string Player::printBlock(string b)
{
	if (b == "I")
	{
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

string Player::getNext()
{
	return next;
}

bool Player::canSpawn(string b)
{	//checks if each block can spawn
	if (b == "I")
	{
		if (board->getGrid()[3][0]->getIsOccupied() || board->getGrid()[3][1]->getIsOccupied() ||
				board->getGrid()[3][2]->getIsOccupied() || board->getGrid()[3][3]->getIsOccupied())
			return false;
	}
	else if (b == "J")
	{
		if (board->getGrid()[3][0]->getIsOccupied() || board->getGrid()[3][1]->getIsOccupied() ||
				board->getGrid()[3][2]->getIsOccupied())
			return false;
	}
	else if (b == "L")
	{
		if (board->getGrid()[3][0]->getIsOccupied() || board->getGrid()[3][1]->getIsOccupied() ||
				board->getGrid()[3][2]->getIsOccupied())
			return false;
	}
	else if (b == "O")
	{
		if (board->getGrid()[3][0]->getIsOccupied() || board->getGrid()[3][1]->getIsOccupied())
			return false;
	}
	else if (b == "S")
	{
		if (board->getGrid()[3][0]->getIsOccupied() || board->getGrid()[3][1]->getIsOccupied())
			return false;
	}
	else if (b == "Z")
	{
		if (board->getGrid()[3][1]->getIsOccupied() || board->getGrid()[3][2]->getIsOccupied())
			return false;
	}
	else if (b == "T")
	{
		if (board->getGrid()[3][1]->getIsOccupied())
			return false;
	}
	else{
		if(board->getGrid()[3][5]->getIsOccupied())
			return false;
	}
	return true;
}
