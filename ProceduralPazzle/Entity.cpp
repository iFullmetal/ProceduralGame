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
void Entity::move(size_t dirX, size_t dirY) //эксперементально
{
	int localX = x - current_sublevel->getX(); //получаю координаты контента в векторе
	int localY = y - current_sublevel->getY();
	if(localX + dirX > 0 && localX + dirX < current_sublevel->getWidth() && 
		localY + dirY > 0 && localY + dirY < current_sublevel->getHeight())//если данный элемент массива может существовать
	{
		if (!current_sublevel->getMap()[localY + dirY][localX + dirX]->isCollides()) //и не имеет колизий
		{
			x += dirX; //то становлюсь на его место
			y += dirY;
		}
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
