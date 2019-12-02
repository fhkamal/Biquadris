#include "player.h"

using namespace std;

Player::Player(string fileName, int seed, int level) : score{0}, highscore{0}, fileName{fileName}, endGame{false},
	seed{seed}, isBlind{false}, specialHeavy{false}
{
	setLevel(level);
	board = make_shared<Board>();
	board->init();
	queue = lvl->getSequence();
	next = "N";
}

void Player::playSequence(std::vector<std::string> seq)
{
	if (lvl->getLevel() == 0)
	{
		if (seq.size() <= 2)
		{
			for (int i = 0; i < lvl->getSequence().size(); i++)
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
	else if (lvl->getLevel() == 1 || lvl->getLevel() == 2 || lvl->getLevel() == 3)
	{

		if (queue.size() == 0)
		{
			lvl->generateSequence(seed);
			queue = lvl->getSequence();
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

	blocksOnBoard.emplace_back(current);
	// Update the board display and shift the queue of blocks
	board->getTextDisplay()->updateDisplay(*board, isBlind);
}

shared_ptr<Block> Player::createBlock(string s)
{
	if (s == "J")
	{
		return make_shared<JBlock>(board, lvl->getLevel()); // block test
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
	else
	{
		return make_shared<LBlock>(board, lvl->getLevel());
	}
}

vector<string> Player::getQueue()
{
	return queue;
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

shared_ptr<Block> Player::getCurrentBlock()
{
	return current;
}

void Player::setScore(int x)
{
	for (auto it = blocksOnBoard.begin(); it != blocksOnBoard.end(); it++)
	{
		int scoreBlock = 0;
		bool deleteBlock = true;
		vector<shared_ptr<Cell>> cells = (*it)->getCells();
		for (auto it2 = cells.begin(); it2 != cells.end(); it2++)
		{
			if ((*it2)->getIsOccupied())
				deleteBlock = false;
		}
		if (deleteBlock)
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
	lvl->generateSequence(seed);
	queue = lvl->getSequence();
}

void Player::specialAction(string action)
{
	if (action == "blind"){
		isBlind = true;
	}
	else if (action == "heavy"){
		specialHeavy = true;
	}
	else {
		string block;
		cin >> block;
		while (block != "S" && block != "Z" && block != "I" && block != "T" && block != "O" && block != "J" && block != "L"){
			cout << "You are not forcing a valid block. Enter a valid block to force: ";
			cin >> block;
			cout << endl;
		}
		current = nullptr;
		blocksOnBoard.pop_back();
		queue.emplace(queue.begin(), block);
		playSequence(queue);
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
{
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
	return true;
}

bool Player::getEndGame()
{
	return endGame;
}
