#pragma once
#include "Entity.h"
class Player :
	public Entity
{
public:
	Player();
	Player(size_t x, size_t y, Sublevel * sub);
	void movement();
	void update();
	~Player();
};

