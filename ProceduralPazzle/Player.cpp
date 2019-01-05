#include "Player.h"



Player::Player()
{
	type = cross;
	health = 5;
}
Player::Player(size_t x, size_t y, Sublevel * sub) : Player()
{
	this->x = x;
	this->y = y;
	current_sublevel = sub;
}
void Player::movement()
{
	if(GetAsyncKeyState(VK_UP))
	{
		move(0, -1);
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		move(0, 1);
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		move(1, 0);
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		move(-1, 0);
	}
}
void Player::update()
{
	movement();
	draw();
}
Player::~Player()
{
}
