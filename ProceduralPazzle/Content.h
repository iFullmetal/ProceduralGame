#pragma once
class Content
{
protected:
	size_t x;
	size_t y;
	bool collides;
public:
	Content();
    virtual void draw() = 0;
	//void draw();
	bool isCollides();
	size_t getX();
	size_t getY();
	~Content();
};

