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
	size_t x;//���������� ���������� � ��������� ������
	size_t y;
	bool collides;
public:
	Content();
    virtual void draw() = 0;
	virtual void update() = 0;
	bool isCollides();
	size_t getX();
	size_t getY();
	~Content();
};

