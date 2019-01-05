#pragma once
//#include "Content.h"
#include "Block.cpp"
enum EntityType
{
	invisible, cross, snake 
};
class Entity :
	public Content
{
protected:
	EntityType type;
	int health;
public:
	void setEntityType(EntityType type);
	virtual void update() = 0;
	EntityType getType();
	void draw();
	Entity();
	~Entity();
};

