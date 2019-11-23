#ifndef ZBLOCK_H_
#define ZBLOCK_H_
#include "cell.h"
#include "block.h"

class ZBlock: public Block {
	public:
		void rotate(std::string direction, std::vector<std::vector<int>> coor);
}
#endif
