#include "Bullet.h"



Bullet::Bullet()
{
}
Bullet::Bullet(int x, int y, int dirX, int dirY, Sublevel * current_sublevel)
{
	this->x = x;
	this->y = y;
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
	this->current_sublevel = current_sublevel;
	this->dirX = dirX;
	this->dirY = dirY;
}
void Bullet::fly()
{
	move(dirX, dirY);
}
void Bullet::hit()
{
	int localX = x - current_sublevel->getX();
	int localY = y - current_sublevel->getY();
	if((localY + dirY) != current_sublevel->getExitPosY() && (localX + dirX) != current_sublevel->getExitPosX())
	{
		if (current_sublevel->getMap()[localY + dirY][localX + dirX]->isCollides())
		{
			current_sublevel->getMap()[localY][localX] = new Block(x, y, none);
			//clear();
		}
	}
	

	//else if(current_sublevel->getMap()[localY + dirY][localX + dirX]->isHitable())
	//{

	//	current_sublevel->getMap()[localY + dirY][localX + dirX] = new Block(x, y, none);
	//	clear();
	//}
}
void Bullet::update()
{
	
	fly();
	hit();
	draw();
	

}
Bullet::~Bullet()
{
}
