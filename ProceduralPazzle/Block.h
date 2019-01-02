#pragma once
#include "Content.h"
//#include "draw.cpp"


enum BlockType
{
	none, brick
};
class Block : public Content
{
public:
	BlockType type;
	Block();
	Block(size_t x, size_t y, BlockType type);
	void setBlockType(BlockType type);
	void draw();
	~Block();
};

