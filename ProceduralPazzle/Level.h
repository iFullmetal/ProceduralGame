#pragma once
//#include <vector>
#include "Sublevel.h"
//using namespace std;
#include <windows.h>
void gotopos(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
void drawSublevel(Sublevel & sublevel)
{
	gotopos(sublevel.getX(), sublevel.getY());
	for (int i = 0; i < sublevel.getHeight(); i++)
	{
		for (int j = 0; j < sublevel.getWidth(); j++)
		{
			sublevel.getMap()[i][j]->draw();
		}
	}
}
void drawLevel(vector<Sublevel> & level)
{
	for (int i = 0; i < level.size(); i++)
	{
		drawSublevel(level[i]);
	}
}
enum sublevelLineState
{
	start, rightEnterLeftExit, leftEnterRightExit
};
class Level
{
protected:
	vector<Sublevel> level; //вектор подуровней, в котором каждый подуровень знает, в какой координате его отрисовать
public:
	Level();
	Level(int uselessvaluethatgivesmeposabilitytocreatesecondconstructor);
	int levelLenght; //количество подуровней по горизонтали
	vector<Sublevel> & getLevelMap();
	void draw();
	~Level();
};

