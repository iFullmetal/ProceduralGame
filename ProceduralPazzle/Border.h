#pragma once
#include <iostream>
#include "PositionChanging.h"
class Border
{
private:
	size_t x;
	size_t y;
	size_t width, height;
public:
	Border(size_t x, size_t y, size_t width, size_t height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}
	void drawBorder()
	{
		gotoPos(x, y);
		std::cout << char(206);
		for (int i = 0; i < width; i++) {
			std::cout << char(205);
		}
		gotoPos(x + width, y);
		std::cout << char(206);
		for (int i = 0; i < height; i++) {
			gotoPos(x + width, y + i + 1);
			std::cout << char(186);
		}
		gotoPos(x + width, y + height);
		std::cout << char(206);
		for (int i = 0; i < width; i++) {
			gotoPos(x + i, y + height);
			std::cout << char(205);
		}
		gotoPos(x, y + height);
		std::cout << char(206);
		for (int i = 0; i < height-1; i++) {
			gotoPos(x, y + i + 1);
			std::cout << char(186);
		}
	}

};
