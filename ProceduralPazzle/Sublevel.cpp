#include "Sublevel.h"
int randomNumber(int minNum, int maxNum) {
	int result;
	int lowNum = 0;
	int hiNum = 0;
	if (minNum < maxNum) {
		lowNum = minNum;
		hiNum = maxNum + 1;
	}
	else {
		lowNum = maxNum + 1;
		hiNum = minNum;
	}
	result = (rand() % (hiNum - lowNum)) + lowNum;
	return result;
}

Sublevel::Sublevel()
{

}
Sublevel::~Sublevel()
{

}
Sublevel::Sublevel(size_t x, size_t y, size_t holeCoordX, size_t holeCoordY, bool holeType, LevelGenerationState & gState)  //����������� ��� �������� ��������� � ����������� � ����� �������(holeType = 0 - ����, 1 - �����)
{
	bool doesHoleExist = 0;
	size_t iterationsCounter = 0;
	while(!doesHoleExist || enterPosX > width || enterPosY >= height-2 || enterPosY < 1){ 
		iterationsCounter++;
		if (iterationsCounter > MAX_RAND_LOOP_COUNT) //� ������ ���� ����������� ����� � ����������� ����, �� ������ �� ���� � ���������� ��� �������
		{
			gState = restart;
			break;
		}
		map.clear();
		this->x = x;
		this->y = y;

		if(holeType)//� ����������� �� ����, ���� ��� ��� ����� ��������� ���������� � ������������� ����������
		{
			exitPosX = holeCoordX;
			exitPosY = holeCoordY;
		}
		else
		{
			enterPosX = holeCoordX;
			enterPosY = holeCoordY;
		}
		int times = 0; //���������� ����� ��� ���� ������, ����� ����������� ������ ��������� ��� ���������� ����������� ������ ����� �� ����� �������, ���
		//�� ���������� ������� ����� ������ ������������� ������� � ��������� ������ � ����������� ����
		do //������
		{
			width = randomNumber(MIN_RAND_SIZE, MAX_RAND_SIZE);
			times++;
		} while (width + x > X_SIZE && times < MAX_RAND_LOOP_COUNT); //���� ������� �� �������� ������� � ���������� �������� ������ �������������
		times = 0;
		do//������
		{
			height = randomNumber(MIN_RAND_SIZE, MAX_RAND_SIZE);
			times++;
		} while (height + y > Y_SIZE && times < MAX_RAND_LOOP_COUNT);

		for (int i = 0; i < height; i++) //����� ��������� ������ ���������� ������������ ������ Content
		{
			map.push_back(vector<Content*>(width));
		}
		for (int i = 0; i < height; i++)  //���� ������� �� ������� ��� ������������ ������
		{
			for (int j = 0; j < width; j++)
			{
				if (i == 0 || j == 0 || j == width - 1 || i == height - 1)//���� ��� �������, �� ������ �������
				{
					map[i][j] = new Block(x + j, y + i, brick);
				}
				else//���� ���, �� �������
				{
					map[i][j] = new Block(x + j, y + i, none);
				}
				if(i == holeCoordY && j == holeCoordX)//����� �� ���������
				{
					map[i][j] = new Block(x + j, y + i, none);
					doesHoleExist = 1;
				}
			}
		}
	}
}
Sublevel::Sublevel(size_t x, size_t y, int lastWidth, size_t holeCoordX, size_t holeCoordY, bool holeType, LevelGenerationState & gState, HoleDestenation holeDestenation) //������������ ������ � ���������� �����
{
	bool doesHoleExist = 0; //� ������, ���� �� ���������� �������� ������, �� ��� ���������� ����� ����. ���� ��� ����, ���� ����� ������������� ����������

	size_t iterationsCounter = 0; //������� �������� �����. ���� �� ���������� ������, ��� ��������� MAX_RAND_LOOP_COUNT, �� ���� ���� �����������, 
	//� ������ ����������� ���������� ��� �� ���� ����������� ������� ���������� � ���� ������������� ������� ������.

	//������������ � ����������� ���������� ��� �����/������
	int minimalXHolePos = 0;
	int minimalYHolePos = 0;
	int maximumXHolePos = width;
	int maximumYHolePos = height;

	if(holeDestenation == x_sided) //� ������������ �� ����, ����� ��� ����� ������������ ������, ��������������� ���������� ������ ����� ���������� 0 � ���� ����� ������ ���, 
		//���� ������ �������� ������ ������ � ����. �� ������� ���� ������ ���� if � ���������������, �� ����� �����, � ��� � ������.  
	{
		maximumYHolePos = height - 2;
		maximumXHolePos = width;
		minimalYHolePos = 1;
	}
	else
	{
		maximumXHolePos = width - 2;
		maximumYHolePos = height;
		minimalXHolePos = 1;
	}
	while (!doesHoleExist || enterPosX > maximumXHolePos  || enterPosX < minimalXHolePos || enterPosY > maximumYHolePos || enterPosY < minimalYHolePos) {
		iterationsCounter++;
		if(iterationsCounter > MAX_RAND_LOOP_COUNT) //� ������ ���� ����������� ����� � ����������� ����, �� ������ �� ���� � ���������� ��� �������
		{
			gState = restart;
			break;
		}
		map.clear();
		this->x = x;
		this->y = y;

		if (holeType)//� ����������� �� ����, ���� ��� ��� ����� ��������� ���������� � ������������� ����������
		{
			exitPosX = holeCoordX;
			exitPosY = holeCoordY;
		}
		else
		{
			enterPosX = holeCoordX;
			enterPosY = holeCoordY;
		}
		int times = 0; //���������� ����� ��� ���� ������, ����� ����������� ������ ��������� ��� ���������� ����������� ������ ����� �� ����� �������, ���
		//�� ���������� ������� ����� ������ ������������� ������� � ��������� ������ � ����������� ����

		width = lastWidth; 
		times = 0;
		do//������
		{
			height = randomNumber(MIN_RAND_SIZE, MAX_RAND_SIZE);
			times++;
		} while (height + y > Y_SIZE && times < MAX_RAND_LOOP_COUNT);
		
		for (int i = 0; i < height; i++) //����� ��������� ������ ���������� ������������ ������ Content
		{
			map.push_back(vector<Content*>(width));
		}
		for (int i = 0; i < height; i++)  //���� ������� �� ������� ��� ������������ ������
		{
			for (int j = 0; j < width; j++)
			{
				if (i == 0 || j == 0 || j == width - 1 || i == height - 1)//���� ��� �������, �� ������ �������
				{
					map[i][j] = new Block(x + j, y + i, brick);
				}
				else//���� ���, �� �������
				{
					map[i][j] = new Block(x + j, y + i, none);
				}
				if (i == holeCoordY && j == holeCoordX)//����� �� ���������
				{
					map[i][j] = new Block(x + j, y + i, none);
					doesHoleExist = 1;
				}
			}
		}
		if (holeDestenation == x_sided) //������ ����������, ���� �������� ������� �������� �� ������, ���� ���� ���������� ��� ���
		{
			maximumYHolePos = height - 2;
			maximumXHolePos = width;
			minimalXHolePos = 0;
			minimalYHolePos = 1;
		}
		else
		{
			maximumXHolePos = width - 2;
			maximumYHolePos = height;
			minimalXHolePos = 1;
			minimalYHolePos = 0;

		}
	}
}


Sublevel::Sublevel(size_t x, size_t y, hole holePosition, holeMode mode, LevelGenerationState & gState) //����������� ��� �������� ��������� � ������������(holeType = 0 - ����, 1 - �����)
{
	this->x = x;
	this->y = y;
	
	int times = 0; //���������� ����� ��� ���� ������, ����� ����������� ������ ��������� ��� ���������� ����������� ������ ����� �� ����� �������, ���
	//�� ���������� ������� ����� ������ ������������� ������� � ��������� ������ � ����������� ����
	do //������
	{
		width = randomNumber(MIN_RAND_SIZE, MAX_RAND_SIZE);
		times++;
		if(times > MAX_RAND_LOOP_COUNT)
		{
			gState = restart;
			break;
		}
	} while (width + x > X_SIZE); //���� ������� �� �������� ������� � ���������� �������� ������ �������������
	times = 0;
	do//������
	{
		height = randomNumber(MIN_RAND_SIZE, MAX_RAND_SIZE);
		times++;
		if (times > MAX_RAND_LOOP_COUNT)
		{
			gState = restart;
			break;
		}
	} while (height + y > Y_SIZE);
	//��������� ��������� ����� � ������
	switch (mode)
	{
	case enter:
		generateEnterExit(enterPosX, enterPosY, width, height, holePosition);
		break;
	case exit_:
		generateEnterExit(exitPosX, exitPosY, width, height, holePosition);
		break;
	default:
		break;
	}

	for (int i = 0; i < height; i++) //����� ��������� ������ ���������� ������������ ������ Content
	{
		map.push_back(vector<Content*>(width));
	}
	for (int i = 0; i < height; i++)  //���� ������� �� ������� ��� ������������ ������
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || j == 0 || j == width - 1 || i == height - 1)//���� ��� �������, �� ������ �������
			{
				map[i][j] = new Block(x + j, y + i, brick);
			}
			else //���� ���, �� �������
			{
				map[i][j] = new Block(x + j, y + i, none);
			}
			if (i == enterPosY && j == enterPosX || i == exitPosY && j == exitPosX) //������ ����� ���� ����
			{
				map[i][j] = new Block(x + j, y + i, none);
				
			}
		}
	}
}
void Sublevel::generateEnterExit(int & coordX, int & coordY, size_t width, size_t height, hole holePosition)
{
	switch (holePosition) //�� ����� ����� ������� �������
	{
	case left_:

		coordY = randomNumber(3, height-2);
		coordX = 0;
		break;
	case right_:
		coordY = randomNumber(3, height-2);
		coordX = width-1;
		break;
	case top:
		coordY = 0;
		coordX = randomNumber(3, width-2);
		break;
	case down:
		coordY = height-1;
		coordX = randomNumber(3, width-2);
		break;
	default:
		break;
	}
}
void Sublevel::getExitGlobalCoords(int & x, int & y)
{
	x = map[exitPosY][exitPosX]->getX();
	y = map[exitPosY][exitPosX]->getY();
}
void Sublevel::addExit(hole holePosition)
{
	generateEnterExit(exitPosX, exitPosY, width, height, holePosition); //��������� ����������
	map[exitPosY][exitPosX] = new Block(x + exitPosX, y + exitPosY, none); //������ �� ��� ������ ����
}
void Sublevel::addEnter(hole holePosition)
{
	generateEnterExit(enterPosX, enterPosY, width, height, holePosition); //��������� ����������
	map[enterPosY][enterPosX] = new Block(x + enterPosX, y + enterPosY, none); //������ �� ��� ������ ����
}
size_t Sublevel::getX()
{
	return x;
}
size_t Sublevel::getY()
{
	return y;
}
size_t Sublevel::getHeight()
{
	return height;
}
size_t Sublevel::getWidth()
{
	return width;
}
size_t Sublevel::getEnterPosX()
{
	return enterPosX;
}
size_t Sublevel::getEnterPosY()
{
	return enterPosY;
}
size_t Sublevel::getExitPosX()
{
	return exitPosX;
}
size_t Sublevel::getExitPosY()
{
	return exitPosY;
}
vector<vector<Content*>> & Sublevel::getMap()
{
	return map;
}

