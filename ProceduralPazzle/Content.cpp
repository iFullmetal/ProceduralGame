#include "Content.h"



Content::Content()
{
}
bool Content::isCollides()
{
	return collides;
}
size_t Content::getX()
{
	return x;
}
size_t Content::getY()
{
	return y;
}
void Content::setX(size_t x)
{
	this->x = x;
}
void Content::setY(size_t y)
{
	this->y = y;
}
size_t & Content::getXDirectly()
{
	return x;
}
size_t & Content::getYDirectly()
{
	return y;
}
Content::~Content()
{
}
