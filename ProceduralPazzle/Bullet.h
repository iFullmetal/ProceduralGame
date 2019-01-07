#pragma once
#include "Entity.h"
class Bullet :
	public Entity
{
protected:
	int dirX, dirY;
public:
	Bullet();
	Bullet(int dirX, int dirY);
	void update();
	void fly();
	~Bullet();
};

