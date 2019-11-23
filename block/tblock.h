#ifndef TBLOCK_H_
#define TBLOCK_H_
#include "cell.h"
#include "block.h"

class TBlock: public Block {
	public:
		void rotate(std::string direction, std::vector<std::vector<int>> coor);
}
#endif
