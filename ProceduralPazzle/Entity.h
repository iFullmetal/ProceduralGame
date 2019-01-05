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
public:
	void move(size_t x, size_t y);
	void setEntityType(EntityType type);

	EntityType getType();
	void draw();
	Entity();
	~Entity();
};

