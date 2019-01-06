#pragma once
#include <vector>
#include "Block.h"
#include <iterator>

using namespace std;
const size_t X_SIZE = 70; //������������ ������ ����� �� x
const size_t Y_SIZE = 70; // ������������ ������ ����� �� y
const size_t MIN_RAND_SIZE = 10; //8 ����������� ������ ���������
const size_t MAX_RAND_SIZE = 20; //20 ������������ ������ ���������
const size_t MAX_RAND_LOOP_COUNT = 40; //������������ ���������� �������� ����� ��������� �������� ���������

enum LevelGenerationState  //������������, ���������� �� ��������� � �������� ������������ ����� � ������������� ����������. ���� ����� ���������, �� ���� ������� ����� ���������� ������.
{
	normal, restart
};
enum direction //������������ ������� ��������� � ���������
{
	left_, right_, top, down
};
enum HoleDestenation //������������ ��� ������ ���������� ���������. � ����� ������ ��� ������ ��������� ���������� 0-hight ��� 0-width � ������ ���
{
	x_sided, y_sided
};
enum holeMode //������������ ��� ����������� ������ ������������. ���� ������� ����, ���� ������� �����
{
	enter, exit_//�� exit ��� _ ��������
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
	vector<vector<Content*>> map;//��������� ������, �������� ��� ����� ���������. 
	//������� � ����� ����������, ����������� ��� ����������� ��������� ��������� �������� ���������
	void generateEnterExit(int & coordX, int & coordY, size_t width, size_t height, direction holePosition); //������� ��������� ��������� ����� ��� ������, �������������� �������� ���������
	
public:
	vector<Sublevel>::iterator nextSublevelIterator;
	Sublevel();
	~Sublevel();
	Sublevel(size_t x, size_t y, int lastWidth, size_t holeCoordX, size_t holeCoordY, bool holeType, LevelGenerationState & gState, HoleDestenation holeDestenation); //����������� ��������� � ������������ �������
	//������������ � ������������������ ������������ �����/������
	Sublevel(size_t x, size_t y, size_t holeCoordX, size_t holeCoordY, bool holeTyp, LevelGenerationState & gStatee); //����������� ��� �������� ��������� � ����������� � ����� ������� � ������������� ���������(holeType = 0 - ����, 1 - �����)
	//������������ � ������������� ������������ �����/������
	Sublevel(size_t x, size_t y, direction holePosition, holeMode mode, LevelGenerationState & gState); //����������� ��������� � ������������ ����������� ��������� ��� ���������(������� �� mode)
	vector<vector<Content*>> & getMap();
	Content * findContentByPosition(size_t x, size_t y); //������� ������ �������� �� �����������
	void addExit(direction holePosition); //������� ��� �������� ������ � ��� ��������� ���������
	void addEnter(direction holePosition);
	//get ������
	void getExitGlobalCoords(int & x, int & y); //������� ��� ��������� ���������� ��������� ������(� ������ �������� ���������� ������������ ������)
	void getEnterGlobalCoords(int & x, int & y); //������� ��� ��������� ���������� ��������� ������(� ������ �������� ���������� ������������ ������)
	void addPlayer();
	
	size_t getX();
	size_t getY();
	size_t getHeight();
	size_t getWidth();
	size_t getEnterPosX();
	size_t getEnterPosY();
	size_t getExitPosX();
	size_t getExitPosY();
};

