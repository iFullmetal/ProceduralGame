#include "Block.h"
#include <windows.h>
#include <iostream>

void gotopos(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void drawBlock(Block & block)
{
	switch (block.type)
	{
	case none:
		gotopos(block.getX(), block.getY());
		std::cout << " ";
		break;
	case brick:
		gotopos(block.getX(), block.getY());
		std::cout << char(176);
		break;
	default:
		break;
	}
}
Block::Block()
{
	type = none;
}
void Block::draw()
{
	drawBlock(*this);
}
void Block::update()
{
	draw();
}
void Block::setBlockType(BlockType type) 
{
	this->type = type;
}
Block::Block(size_t x, size_t y, BlockType type)
{
	this->x = x;
	this->y = y;
	this->type = type;
	switch (type)
	{
	case none:
		collides = false;
		break;
	case brick:
		collides = true;
		break;
	default:
		break;
	}
}
Block::~Block()
{
}
