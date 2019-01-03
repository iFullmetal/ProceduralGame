#pragma once
#include <vector>
#include "Block.h"
using namespace std;
const size_t X_SIZE = 70; //максимальный размер карты по x
const size_t Y_SIZE = 70; // максимальный размер карты по y
const size_t MIN_RAND_SIZE = 8; //минимальный размер подуровня
const size_t MAX_RAND_SIZE = 20; //максимальный размер подуровня
const size_t MAX_RAND_LOOP_COUNT = 500; //максимальное количество итераций цикла генерации размеров подуровня

enum LevelGenerationState  //перечисление, отвечающее за попадание в ситуацию бесконечного цикла в конструкторах подуровней. Если такое случается, то весь уровень будет пересоздан заново.
{
	normal, restart
};
enum hole //перечисление позиций отверстия в подуровне
{
	left, right, top, down
};
enum holeMode //перечисление для определения работы конструктора. Либо сделать вход, либо сделать выход, либо и то и то.
{
	enter, exit_, enter_and_exit //на exit без _ ругалось
};
class Sublevel
{
private:
	size_t x, y; //координаты подуровня в уровне
	size_t height, width; //высота и ширины подуровня
	int enterPosX = -1; //координаты точек входа и выхода
	int enterPosY = -1; // -1 взята как координата, которой не может быть на карте. Дальше это нужно в алгоритме генерации проходов
	int exitPosX = -1;
	int exitPosY = -1;
	vector<vector<Content*>> map;
	//функция с кучей параметров, необходимоя для процедурной генерации координат проходов подуровня
	void generateEnterExit(int & coordX, int & coordY, size_t width, size_t height, hole holePosition);
	
public:

	Sublevel();
	Sublevel(size_t x, size_t y);//конструктор подуровня с произвольной шириной и высотой
	Sublevel(size_t x, size_t y, int lastWidth); //конструктор подуровня с произвольной высотой
	Sublevel(size_t x, size_t y, int lastWidth, size_t holeCoordX, size_t holeCoordY, bool holeType, LevelGenerationState & gState); //конструктор подуровня с произвольной высотой
	//конструкторы с предустановленными координатами входа/выхода
	Sublevel(size_t x, size_t y, size_t holeCoordX, size_t holeCoordY, bool holeTyp, LevelGenerationState & gStatee); //конструктор для создания подуровня с отверствием с одной стороны и произвольными размерами(holeType = 0 - вход, 1 - выход)
	//конструкторы с произвольными координатами входа/выхода
	Sublevel(size_t x, size_t y, hole holePosition, holeMode mode); //конструктор подуровня с произвольной координатой отверстия или отверстий(зависит от mode)

	vector<vector<Content*>> & getMap();
	void addExit(hole holePosition); //функция для создания выхода в уже созданном подуровне
	void addEnter(hole holePosition);
	//get методы
	void getExitGlobalCoords(int & x, int & y); //функция для получения глобальных координат выхода(в классе хранятся координаты относительно начала)
	size_t getX();
	size_t getY();
	size_t getHeight();
	size_t getWidth();
	size_t getEnterPosX();
	size_t getEnterPosY();
	size_t getExitPosX();
	size_t getExitPosY();
};

