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
	bool isRendered = 0; //переменная сделанная дл того, чтобы увеличить производительность, потому что перересовывать все сразу ресурсоемко.
	BlockType type;
	Block();
	Block(size_t x, size_t y, BlockType type);
	void setBlockType(BlockType type);
	void draw();
	void update(float time);
	~Block();
};

