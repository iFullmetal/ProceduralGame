#include "Bullet.h"



Bullet::Bullet()
{
}
Bullet::Bullet(int dirX, int dirY)
{
	if(dirX == 0 && dirY == -1)
	{
		type = v_arrow_up;
	}
	if (dirX == 0 && dirY == 1)
	{
		type = v_arrow_down;
	}
	if (dirX == 1 && dirY == 0)
	{
		type = v_arrow_right;
	}
	if (dirX == -1 && dirY == 0)
	{
		type = v_arrow_left;
	}
	this->dirX = dirX;
	this->dirY = dirY;
}
void Bullet::fly()
{
	move(dirX, dirY);
}
void Bullet::update()
{
	fly();
	draw();
}
Bullet::~Bullet()
{
}
