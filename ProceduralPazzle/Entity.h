#pragma once
//#include "Content.h"
#include "Block.cpp"
#include "Level.h"
enum EntityType
{
	invisible, cross, snake 
};

class Entity : public Content
{
protected:
	EntityType type;
	int health;
	Sublevel * current_sublevel;
	size_t vectorXPos;
	size_t vectorYPos;
public:
	void move(direction dir);
	void move(int dirX, int dirY);
	void setEntityType(EntityType type);
	void clear();
	EntityType getType();
	void draw();
	Entity();
	~Entity();
};

