#include "block.h"
using namespace std;

Block::Block(char let, Board *board): let{let}, board{board} orient{0}, 
one{nullptr}, two{nullptr}, three{nullptr}, four{nullptr} {}
Block::~Block() {}
