#ifndef SBLOCK_H_
#define SBLOCK_H_
#include "cell.h"
#include "block.h"

class SBlock: public Block {
	public:
		void rotate(std::string direction, std::vector<std::vector<int>> coor);
}
#endif
