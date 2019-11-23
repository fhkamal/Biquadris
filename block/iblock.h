#ifndef IBLOCK_H_
#define IBLOCK_H_
#include "cell.h"
#include "block.h"

class IBlock: public Block {
	public:
		void rotate(std::string direction, std::vector<Cell> coor);
		IBlock(Board *board);
}
#endif
