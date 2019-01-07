#include "Player.h"

Player::Player()
{
	type = cross;
	health = 5;
	//collides = 0;
}
Player::Player(size_t x, size_t y, Sublevel * sub) : Player()
{
	dirX = 0;
	dirY = -1;
	this->x = x;
	this->y = y;
	vectorXPos = x;
	vectorYPos = y;
	current_sublevel = sub;
}
void Player::shoot()
{
	int localX = x - current_sublevel->getX();
	int localY = y - current_sublevel->getY();
	if (localX + dirX >= 0 && localX + dirX < current_sublevel->getWidth() &&
		localY + dirY >= 0 && localY + dirY < current_sublevel->getHeight())//если данный элемент массива может существовать
	{
		if (!current_sublevel->getMap()[localY + dirY][localX + dirX]->isCollides()) //и не имеет колизий
		{
			current_sublevel->getMap()[localY + dirY][localX + dirX] = new Bullet(x + dirX, y + dirY, dirX, dirY, current_sublevel);
		}
	}
}
void Player::movement()
{

	if(GetAsyncKeyState(VK_UP))
	{
		move(0, -1);
		dirX = 0;
		dirY = -1;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		move(0, 1);
		dirX = 0;
		dirY = 1;
		Sleep(50); //костыль
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		move(1, 0);
		dirX = 1;
		dirY = 0;
		Sleep(50); //костыль
		//move(right_);
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		move(-1, 0);
		dirX = -1;
		dirY = 0;
		//move(left_);
	}
	if(GetAsyncKeyState(VK_SPACE))
	{
		shoot();
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
