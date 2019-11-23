#ifndef LBLOCK_H_
#define LBLOCK_H_
#include "cell.h"
#include "block.h"

class LBlock: public Block {
	public:
		void rotate(std::string direction, std::vector<std::vector<int>> coor);
}
#endif
