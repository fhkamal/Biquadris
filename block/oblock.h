#ifndef OBLOCK_H_
#define OBLOCK_H_
#include "cell.h"
#include "block.h"

class OBlock: public Block {
	public:
		void rotate(std::string direction, std::vector<Cell> coor);
}
#endif
