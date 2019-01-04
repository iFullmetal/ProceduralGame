#include "Level.h"
//#include <iostream>
#include "time.h"
//#include "windows.h"
#include <windows.h>
#include <iostream>
//#include "Block.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void main()
{
	srand(time(NULL));
#pragma region Resolution
	HWND hwnd; //уникальный номер окна
	char Title[1024];
	GetConsoleTitle(Title, 1024); // узнаем им€ окна
	hwnd = FindWindow(NULL, Title); // узнаем hwnd окна
	MoveWindow(hwnd, 400, 100, 1200, 1100, TRUE);//xnew,ynew,wnew,hnew -новые положение x,y, ширина и высота
#pragma endregion

#pragma region Font
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(fontInfo);
	GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
	wcscpy_s(fontInfo.FaceName, L"Lucida Console");  //мен€ю шрифт
	fontInfo.dwFontSize.Y =	9; //мен€ю размеры шрифта
	fontInfo.dwFontSize.X = 8;
	SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
#pragma endregion
	Level level;
	//Level level;
	/*for(int count = 0; count < 5; count++)
	{
		for (int i = 0; i < Y_SIZE; i++)
		{
			for (int j = 0; j < X_SIZE; j++)
			{
				level.getMap()[i][j]->draw();
			}
		}
		int randY = rand() % 50;
		int randX = rand() % 50;
		Block * block = (Block*)level.getMap()[randY][randX];
		block->setBlockType(none);
		level.getMap()[randY][randX] = block;
		Sleep(1000);
		system("cls");
	}*/
	
	level.draw();
	getchar();
	//system("pause");
}