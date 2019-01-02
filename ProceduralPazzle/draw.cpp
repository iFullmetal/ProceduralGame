//#pragma once
//#include <windows.h>
//#include <iostream>
//#include "Block.h"
////#include "Level.h"
////#include "Sublevel.h"
//
//using namespace std;
//
//enum ConsoleColorCode
//{
//	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHT_B, LIGHT_G, LIGHT_C, LIGHTRED, LIGHT_M, YELLOW, WHITE
//};
//
//void SetColor(ConsoleColorCode text, ConsoleColorCode background, HANDLE & hConsole)
//{
//	SetConsoleTextAttribute(hConsole, (WORD)((background << 4) | text));
//}
//
//void gotopos(int x, int y)
//{
//	COORD position = { x, y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
//}
//
//void drawBlock(Block & block)
//{
//	switch (block.type)
//	{
//	case none:
//		gotopos(block.getX(), block.getY());
//		cout << " ";
//		break;
//	case brick:
//		gotopos(block.getX(), block.getY());
//		cout << char(176);
//		break;
//	default:
//		break;
//	}
//}
///*	доступ к функциям потомков из вектора базового класса
//		int randY = rand() % 50;
//		int randX = rand() % 50;
//		Block * block = (Block*)sublevel.getMap()[randY][randX];
//		block->setBlockType(none);
//		sublevel.getMap()[randY][randX] = block;
//*/
//void drawSublevel(Sublevel & sublevel)
//{
//	gotopos(sublevel.getX(), sublevel.getY());
//	for (int i = 0; i < sublevel.getHeight(); i++)
//	{
//		for (int j = 0; j < sublevel.getWidth(); j++)
//		{
//			sublevel.getMap()[i][j]->draw();
//		}
//	}	
//}
//void drawLevel(vector<Sublevel> & level)
//{
//	for(int i = 0; i < level.size(); i++)
//	{
//		drawSublevel(level[i]);
//	}
//}