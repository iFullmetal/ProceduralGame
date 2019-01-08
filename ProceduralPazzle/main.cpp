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
	HWND hwnd; //���������� ����� ����
	char Title[1024];
	GetConsoleTitle(Title, 1024); // ������ ��� ����
	hwnd = FindWindow(NULL, Title); // ������ hwnd ����
	MoveWindow(hwnd, 400, 100, 1200, 1100, TRUE);//xnew,ynew,wnew,hnew -����� ��������� x,y, ������ � ������
#pragma endregion

#pragma region Font
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(fontInfo);
	GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
	wcscpy_s(fontInfo.FaceName, L"Lucida Console");  //����� �����
	fontInfo.dwFontSize.Y =	9; //����� ������� ������
	fontInfo.dwFontSize.X = 8;
	SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
#pragma endregion
	Level level;
	//float currentTime = time(NULL);
	//float prevTime = 0;
	float deltaTime;
	SYSTEMTIME currentTime;
	SYSTEMTIME prevTime;
	GetLocalTime(&currentTime);
	while(1)
	{
		prevTime = currentTime;
		GetLocalTime(&currentTime);
		deltaTime = currentTime.wMilliseconds - prevTime.wMilliseconds;
		//deltaTime /= 10;
		level.draw(deltaTime);
		//Sleep(50);
	}
	
	

	//getchar();
	//system("pause");
}