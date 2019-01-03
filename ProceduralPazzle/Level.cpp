#include "Level.h"

Level::Level()
{
	size_t lx = 0;
	size_t ly = 0;
	int enterX;
	int enterY;
	Sublevel sub(lx, ly, right, exit_);
	int lenght = 0; //����� �������������� �����
	//�������� ������ �������������� ������ �� ����������
	while(lx < X_SIZE - 3)
	{
		level.push_back(sub);
		lx += sub.getWidth();
		enterX = sub.getExitPosX();
		enterY = sub.getExitPosY();
		sub = Sublevel(lx, ly, 0, enterY, 0);
		sub.addExit(right);
		lenght++;
	}

	levelLenght = lenght;
	//�������� ������������ �������� �� ������ ������� �� �������������� ����������
	for(int i = 0; i < lenght; i++)
	{
		ly = level[i].getHeight(); //������ ��������������� ��������� �� ����������� ���������� y-����������� ������������� ���������
		lx = level[i].getX(); // x ����������
		while (ly < Y_SIZE - 3)
		{
			sub = Sublevel(lx, ly, level[i].getWidth()); //����� ����������� ���������� � ������������� �������
			level.push_back(sub);
			ly += sub.getHeight(); // y ���������� ��������� ������������� �� ������ ����������
		}
	}
}
Level::Level(int uselessvaluethatgivesmeposabilitytocreatesecondconstructor)
{
	sublevelLineState state = start; //����� - ��������� ����� ���������� ��� ������������ �����, �� � ������� ������ �����.
	//rightEnterLeftExit - ��������� ����� ���������� � ������ ������� ������ � ������� ����� �����
	//leftEnterRightExit - ��������
	LevelGenerationState generationState = normal; //����������, ���������� �� ��������� � �������� ������������ ����� � ������������� ����������. ���� ����� ���������, �� ������� ����� ���������� ������.
	size_t lx;
	size_t ly;
	int enterX; //����������� ������� ������ �� ��������-����� � ��������� 
	int enterY;
	vector<int> sublevelHorizontalLineHeight; //������ ��� �������� ����� ����� ������� ��������� �� ���������. ��������� ��� ����, ����� ����� �� ����� ���������� �� y ������ ����������
	Sublevel sub;
	int lenght = 0; //����� ������ ����� �� ���������� �� �����������
	int some = 0;
	do //������ ���� ��������� ��� ��������� ��������� ������������� Sublevel � ��������� ������������ �����. ��� ������, ����� �� ���������� ������� ���������� � ��������� ����� ���������
		//��-�� ������������ �� ������. �� ����, � ����� �������� ��������� ���������� � ������� �������� ��������, � � ������ ������� ����������. � ����� ������ ����������� ��������� ����������
		// � generationState �������� restart � ������� �� �����. �� ��������� ���������� ����� normal, �� ������ ��� ��� do while ���� ���������� ���� ���.
	{
		state = start; //������ ��������� ������ ���� � �����
		generationState = normal; //������ ��������� ��������� � ����������
		lx = 0;
		ly = 0;
		enterX = -1; //���������� -1 �� ����� ����, �� ����� ��� ����� ����������� �����������
		enterY = -1;
		level.clear();
		sublevelHorizontalLineHeight.clear();
		sub = Sublevel(lx, ly, right, exit_); //������ ������ ��������� �������, � ������� ����� ������ �����
		sublevelHorizontalLineHeight.push_back(sub.getHeight());
		level.push_back(sub);
		lenght = 0;
		some = 0;
		do //������ ���� ��������� ��� ����������� ����� �� ����������. �� ���� ���� ������ ������, ����� ����� ����� � ���� ����� ������ � ����� ������ �����
			//���� ��������� ��-�� ����, ��� ���������� ������� ������ ���������� ����� ���������� �� ������ �.�. �� �������� ���������� ����������� rightEnterLeftExit � leftEnterRightExit
			//start ���������� ���� ��� � ������ � ���� � ���� �� ������
		{
			switch (state)
			{
			case start: //�� ����� ������ ��������� ����� ������ ����� �� ���������� � ������������ ������� � �������. � ������ ������ ������������ ����� ������ ������.
			{
				while (lx < X_SIZE - 3)
				{
					level.push_back(sub);
					sublevelHorizontalLineHeight.push_back(sub.getHeight()); //�������� ������ �����
					lx += sub.getWidth();
					enterX = sub.getExitPosX(); //
					enterY = sub.getExitPosY();
					sub = Sublevel(lx, ly, 0, enterY, 0);
					sub.addExit(right);
					lenght++;
				}

				Block * block = (Block*)level[lenght].getMap()[level[lenght].getExitPosY()][level[lenght].getExitPosX()]; //������ ������ ����� � ���, ������ ���� ������ �����
				block->setBlockType(brick);
				level[lenght].getMap()[level[lenght].getExitPosY()][level[lenght].getExitPosX()] = block;

				level[lenght].addExit(down); //������ ����� ����� ����� ��� ����


				state = rightEnterLeftExit;
				enterX = level[lenght].getExitPosX();
				enterY = level[lenght].getExitPosY();
				some++;
			}
			break;
			case rightEnterLeftExit:
			{
				sub = Sublevel(level[lenght].getX(), sublevelHorizontalLineHeight[lenght], level[lenght].getWidth(), enterX, 0, 0, generationState);
				sublevelHorizontalLineHeight[lenght] += sub.getHeight(); //���������� ������ ����������� ���������� �� ���� ������ ������ ���������. ������ ��� ����� ����� y ��� ���������� ���������
				sub.addExit(left); //�������� ����� � ����� ������ ���������
				enterX = sub.getExitPosX(); //������� ���������� ������ �� ����� ���������
				enterY = sub.getExitPosY();
				//level.insert(level.begin() + lenght, sub);
				level.push_back(sub);
				for (int i = lenght - 1; i > 0; i--)
				{
					sub.getExitGlobalCoords(enterX, enterY); //������� ���������� ������ �� �������� ��������� � �������� ����� ������(�� ����, �� ������������ ������ ���������)
					sub = Sublevel(level[i].getX(), sublevelHorizontalLineHeight[i], level[i].getWidth(), level[i].getWidth() - 1, enterY - sublevelHorizontalLineHeight[i], 0, generationState);
					//������ �������� ��� x ������� �������� ���������, 
					//������ ��� ������� ������� ������� �������� �� ������� �����, 
					//������ ��� ������ �������� ���������(� ��� ��� �� ����� ����������) � ������� �� ������
					//��������� ��� ������-1 �.�. ������� ����� � ���������� �� X(�� ���� ����� ������ ������)
					//����� ��� ������� ����� ���������� ����������� ������ �� �������� ��������� � ������� ������� ����� �������� ���������� - � ���������� ���������� ���������� ������������ ������ ����� ���������
					//������ 0 - ��� ������� � ��������� - ����
					//������������� ���������� ������/����� ����� ��-�� ����� � ������������ ���������, ������� ����������� ����� � ����������� �� ������� �������� i � j ������� ���������� �� ����
					sublevelHorizontalLineHeight[i] += sub.getHeight(); //���������� ������ ����������� ���������� �� ���� ������ ������ ���������. ������ ��� ����� ����� y ��� ���������� ���������
					sub.addExit(left); //�������� ����� � ����� ����������
					enterX = sub.getExitPosX(); //������� ���������� ������ �� ����� ���������
					enterY = sub.getExitPosY();
				//	level.insert(level.begin() + lenght + 1, sub); //�������� ����� ���������� � ������
					level.push_back(sub);
				}
				//������ ������ ����� �����, ������ ���� ����� ����� ����
				Block * block = (Block*)level[lenght].getMap()[level[lenght].getExitPosY()][level[lenght].getExitPosX()]; //������ ������ ����� � ���, ������ ���� ������ �����
				block->setBlockType(brick);
				level[lenght].getMap()[level[lenght].getExitPosY()][level[lenght].getExitPosX()] = block;

				level[lenght].addExit(down); //������ ����� ����� ����� ��� ����
				level[lenght].getExitPosX(); //������� ���������� ������ �� ����� ���������
				level[lenght].getExitPosY();
				state = leftEnterRightExit;//������� ��������� ����� ���������� �� ������ �����
				some++;
			}
				break;
			case leftEnterRightExit:
				sub = Sublevel(level[0].getX(), sublevelHorizontalLineHeight[0], level[0].getWidth(), enterX, 0, 0, generationState);
				sublevelHorizontalLineHeight[lenght] += sub.getHeight(); //���������� ������ ����������� ���������� �� ���� ������ ������ ���������. ������ ��� ����� ����� y ��� ���������� ���������
				sub.addExit(right); //�������� ����� � ����� ������ ���������
				enterX = sub.getExitPosX(); //������� ���������� ������ �� ����� ���������
				enterY = sub.getExitPosY();
				//level.insert(level.begin() + lenght, sub);
				level.push_back(sub);
				for (int i = 1; i < lenght; i++)
				{
					sub.getExitGlobalCoords(enterX, enterY); //������� ���������� ������ �� �������� ��������� � �������� ����� ������(�� ����, �� ������������ ������ ���������)
					sub = Sublevel(level[i].getX(), sublevelHorizontalLineHeight[i], level[i].getWidth(), 0, enterY - sublevelHorizontalLineHeight[i], 0, generationState);
					//������ �������� ��� x ������� �������� ���������, 
					//������ ��� ������� ������� ������� �������� �� ������� �����, 
					//������ ��� ������ �������� ���������(� ��� ��� �� ����� ����������) � ������� �� ������
					//��������� ��� ������-1 �.�. ������� ����� � ���������� �� X(�� ���� ����� ������ ������)
					//����� ��� ������� ����� ���������� ����������� ������ �� �������� ��������� � ������� ������� ����� �������� ���������� - � ���������� ���������� ���������� ������������ ������ ����� ���������
					//������ 0 - ��� ������� � ��������� - ����
					//������������� ���������� ������/����� ����� ��-�� ����� � ������������ ���������, ������� ����������� ����� � ����������� �� ������� �������� i � j ������� ���������� �� ����
					sublevelHorizontalLineHeight[i] += sub.getHeight(); //���������� ������ ����������� ���������� �� ���� ������ ������ ���������. ������ ��� ����� ����� y ��� ���������� ���������
					sub.addExit(right); //�������� ����� � ����� ����������
					enterX = sub.getExitPosX(); //������� ���������� ������ �� ����� ���������
					enterY = sub.getExitPosY();
					//level.insert(level.begin() + lenght, sub); //�������� ����� ���������� � ������
					level.push_back(sub);
				}
				some++;
				state = rightEnterLeftExit;
				break;
			default:
				break;
			}
		} while (some < 3/*ly < Y_SIZE - 3*/);
	} while (generationState == restart);
	
}
vector<Sublevel> & Level::getLevelMap()
{
	return level;
}

void Level::draw()
{
	drawLevel(level);
}

Level::~Level()
{
}
