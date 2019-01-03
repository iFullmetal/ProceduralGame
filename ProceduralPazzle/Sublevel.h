#pragma once
#include <vector>
#include "Block.h"
using namespace std;
const size_t X_SIZE = 70; //������������ ������ ����� �� x
const size_t Y_SIZE = 70; // ������������ ������ ����� �� y
const size_t MIN_RAND_SIZE = 8; //����������� ������ ���������
const size_t MAX_RAND_SIZE = 20; //������������ ������ ���������
const size_t MAX_RAND_LOOP_COUNT = 500; //������������ ���������� �������� ����� ��������� �������� ���������

enum LevelGenerationState  //������������, ���������� �� ��������� � �������� ������������ ����� � ������������� ����������. ���� ����� ���������, �� ���� ������� ����� ���������� ������.
{
	normal, restart
};
enum hole //������������ ������� ��������� � ���������
{
	left, right, top, down
};
enum holeMode //������������ ��� ����������� ������ ������������. ���� ������� ����, ���� ������� �����, ���� � �� � ��.
{
	enter, exit_, enter_and_exit //�� exit ��� _ ��������
};
class Sublevel
{
private:
	size_t x, y; //���������� ��������� � ������
	size_t height, width; //������ � ������ ���������
	int enterPosX = -1; //���������� ����� ����� � ������
	int enterPosY = -1; // -1 ����� ��� ����������, ������� �� ����� ���� �� �����. ������ ��� ����� � ��������� ��������� ��������
	int exitPosX = -1;
	int exitPosY = -1;
	vector<vector<Content*>> map;
	//������� � ����� ����������, ����������� ��� ����������� ��������� ��������� �������� ���������
	void generateEnterExit(int & coordX, int & coordY, size_t width, size_t height, hole holePosition);
	
public:

	Sublevel();
	Sublevel(size_t x, size_t y);//����������� ��������� � ������������ ������� � �������
	Sublevel(size_t x, size_t y, int lastWidth); //����������� ��������� � ������������ �������
	Sublevel(size_t x, size_t y, int lastWidth, size_t holeCoordX, size_t holeCoordY, bool holeType, LevelGenerationState & gState); //����������� ��������� � ������������ �������
	//������������ � ������������������ ������������ �����/������
	Sublevel(size_t x, size_t y, size_t holeCoordX, size_t holeCoordY, bool holeTyp, LevelGenerationState & gStatee); //����������� ��� �������� ��������� � ����������� � ����� ������� � ������������� ���������(holeType = 0 - ����, 1 - �����)
	//������������ � ������������� ������������ �����/������
	Sublevel(size_t x, size_t y, hole holePosition, holeMode mode); //����������� ��������� � ������������ ����������� ��������� ��� ���������(������� �� mode)

	vector<vector<Content*>> & getMap();
	void addExit(hole holePosition); //������� ��� �������� ������ � ��� ��������� ���������
	void addEnter(hole holePosition);
	//get ������
	void getExitGlobalCoords(int & x, int & y); //������� ��� ��������� ���������� ��������� ������(� ������ �������� ���������� ������������ ������)
	size_t getX();
	size_t getY();
	size_t getHeight();
	size_t getWidth();
	size_t getEnterPosX();
	size_t getEnterPosY();
	size_t getExitPosX();
	size_t getExitPosY();
};

