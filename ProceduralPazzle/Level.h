#pragma once
//#include <vector>
#include "Sublevel.h"
#include "Entity.h"
//using namespace std;
#include <windows.h>
const bool DEBUG_GENERATION_DRAW = false; //��������� ���������� �� ����� ������ ������������ ������
//void gotopos(int x, int y)
//{
//	COORD position = { x, y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
//}
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
	if(DEBUG_GENERATION_DRAW) //����� �������� ������� ��� ������������
	{
		Sleep(70);
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
	vector<Sublevel> level; //������ ����������, � ������� ������ ���������� �����, � ����� ���������� ��� ����������
public:
	Level();
	
	int levelLenght; //���������� ���������� �� �����������
	vector<Sublevel> & getLevelMap();
	void draw();
	~Level();
};

