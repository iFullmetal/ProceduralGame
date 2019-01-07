#pragma once
#include "Entity.h"
#include "Bullet.h"
class Player :
	public Entity
{
protected:
	int dirX, dirY;
public:
	Player();
	Player(size_t x, size_t y, Sublevel * sub);
	void movement();
	void update();
	void shoot();
	~Player();
};

