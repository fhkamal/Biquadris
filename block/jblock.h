#ifndef JBLOCK_H_
#define JBLOCK_H_
#include "cell.h"
#include "block.h"

class JBlock: public Block {
	public:
		void rotate(std::string direction, std vector<std vector<int>> coor);
}
#endif
