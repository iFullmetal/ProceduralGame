#include "Entity.h"

void drawEntity(Entity & ent)
{
	switch (ent.getType())
	{
	case invisible:
		gotopos(ent.getX(), ent.getY());
		std::cout << ' ';
		break;
	case cross:
		gotopos(ent.getX(), ent.getY());
		std::cout << 'X';
		break;
	case snake:
		gotopos(ent.getX(), ent.getY());
		std::cout << 'S';
		break;
	default:
		break;
	}
}
void Entity::clear() //функция очистки текущей координаты от символа игрока
{
	gotopos(x, y);
	std::cout << ' ';
}
void Entity::move(int dirX, int dirY)
{
	int localX = x - current_sublevel->getX(); //получаю координаты контента в векторе
	int localY = y - current_sublevel->getY();

	if (localX + dirX >= 0 && localX + dirX < current_sublevel->getWidth() &&
		localY + dirY >= 0 && localY + dirY < current_sublevel->getHeight())//если данный элемент массива может существовать
	{
		clear(); //очищаю прежнее место пребывания заменяя его пропуском
		if (!current_sublevel->getMap()[localY + dirY][localX + dirX]->isCollides()) //и не имеет колизий
		{
			swap(x, current_sublevel->getMap()[localY + dirY][localX + dirX]->getXDirectly()); //меняю координаты этих блкоов местами, после чего меняю их в массиве местами
			swap(y, current_sublevel->getMap()[localY + dirY][localX + dirX]->getYDirectly());
			swap(current_sublevel->getMap()[localY][localX], current_sublevel->getMap()[localY + dirY][localX + dirX]);
		}
	}
	else if (localX == current_sublevel->getExitPosX() && localY == current_sublevel->getExitPosY()) //обработка выхода из подуровня. 
//В случае, если блок, на котором он стоит является выходом, то меняю местами в этом массиве этого подуровня Entity и в массиве следующего вход
	{
		clear();
		swap(x, current_sublevel->next->getMap()[current_sublevel->next->getEnterPosY()][current_sublevel->next->getEnterPosX()]->getXDirectly());
		swap(y, current_sublevel->next->getMap()[current_sublevel->next->getEnterPosY()][current_sublevel->next->getEnterPosX()]->getYDirectly());

		swap(current_sublevel->getMap()[localY][localX], current_sublevel->next->getMap()[current_sublevel->next->getEnterPosY()][current_sublevel->next->getEnterPosX()]);

		current_sublevel = current_sublevel->next;
	}



}
void Entity::move(direction dir)
{
	int localX = x - current_sublevel->getX(); //получаю координаты контента в векторе
	int localY = y - current_sublevel->getY();
	clear(); //очищаю прежнее место пребывания заменяя его пропуском
	switch (dir)
	{
	case left_:
		if(localX - 1 > 0)
		{
			if (!current_sublevel->getMap()[localY][localX - 1]->isCollides()) //и не имеет колизий
			{
				swap(x, current_sublevel->getMap()[localY][localX - 1]->getXDirectly());
				swap(y, current_sublevel->getMap()[localY][localX - 1]->getYDirectly());
				swap(current_sublevel->getMap()[localY][localX], current_sublevel->getMap()[localY][localX - 1]);
			}
		}
		break;
	case right_:
		if (localX + 1 < current_sublevel->getWidth())
		{
			
			if (!current_sublevel->getMap()[localY][localX + 1]->isCollides()) //и не имеет колизий
			{
				swap(x, current_sublevel->getMap()[localY][localX + 1]->getXDirectly());
				swap(y, current_sublevel->getMap()[localY][localX + 1]->getYDirectly());
				swap(current_sublevel->getMap()[localY][localX + 1], current_sublevel->getMap()[localY][localX]);
				Sleep(80);
	
			}
		}
		break;
	case top:
		break;
	case down:
		break;
	default:
		break;
	}
	
}
EntityType Entity::getType()
{
	return type;
}
Entity::Entity()
{
}
void Entity::setEntityType(EntityType type)
{
	this->type = type;
}
void Entity::draw()
{
	drawEntity(*this);
}
Entity::~Entity()
{
}
