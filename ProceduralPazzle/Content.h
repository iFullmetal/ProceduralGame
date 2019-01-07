#pragma once
//struct Position
//{
//	size_t x;
//	size_t y;
//	Position(size_t x, size_t y)
//	{
//		this->x = x;
//		this->y = y;
//	}
//};
class Content
{
protected:
	size_t x;//глобальные координаты в масштабах уровня
	size_t y;
	bool collides;
	bool hitable;
public:
	Content();
    virtual void draw() = 0;
	virtual void update() = 0;
	bool isCollides();
	bool isHitable();
	size_t getX();
	size_t getY();
	void setX(size_t x);
	void setY(size_t y);
	size_t & getXDirectly();
	size_t & getYDirectly();
	~Content();
};

