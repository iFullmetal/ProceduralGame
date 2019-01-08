#pragma once
#include "Entity.h"
class Bullet :
	public Entity
{
protected:
	int dirX, dirY;
public:
	Bullet();
	Bullet(int x, int y, int dirX, int dirY, Sublevel * current_sublevel);
	void hit();
	void update(float time);
	void fly(float time);
	~Bullet();
};

