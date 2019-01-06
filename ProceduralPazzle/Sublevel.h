#pragma once
#include <vector>
#include "Block.h"
#include <iterator>

using namespace std;
const size_t X_SIZE = 70; //максимальный размер карты по x
const size_t Y_SIZE = 70; // максимальный размер карты по y
const size_t MIN_RAND_SIZE = 10; //8 минимальный размер подуровня
const size_t MAX_RAND_SIZE = 20; //20 максимальный размер подуровня
const size_t MAX_RAND_LOOP_COUNT = 40; //максимальное количество итераций цикла генерации размеров подуровня

enum LevelGenerationState  //перечисление, отвечающее за попадание в ситуацию бесконечного цикла в конструкторах подуровней. Если такое случается, то весь уровень будет пересоздан заново.
{
	normal, restart
};
enum direction //перечисление позиций отверстия в подуровне
{
	left_, right_, top, down
};
enum HoleDestenation //перечисление для выбора назначения отвертвия. В одном случае оно сможет принимать координаты 0-hight или 0-width в другом нет
{
	x_sided, y_sided
};
enum holeMode //перечисление для определения работы конструктора. Либо сделать вход, либо сделать выход
{
	enter, exit_//на exit без _ ругалось
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
	vector<vector<Content*>> map;//двумерный массив, хрянищий все блоки подуровня. 
	//функция с кучей параметров, необходимоя для процедурной генерации координат проходов подуровня
	void generateEnterExit(int & coordX, int & coordY, size_t width, size_t height, direction holePosition); //функция генерации координат входа или выхода, удолетворяющих размерам подуровня
	
public:
	vector<Sublevel>::iterator nextSublevelIterator;
	Sublevel();
	~Sublevel();
	Sublevel(size_t x, size_t y, int lastWidth, size_t holeCoordX, size_t holeCoordY, bool holeType, LevelGenerationState & gState, HoleDestenation holeDestenation); //конструктор подуровня с произвольной высотой
	//конструкторы с предустановленными координатами входа/выхода
	Sublevel(size_t x, size_t y, size_t holeCoordX, size_t holeCoordY, bool holeTyp, LevelGenerationState & gStatee); //конструктор для создания подуровня с отверствием с одной стороны и произвольными размерами(holeType = 0 - вход, 1 - выход)
	//конструкторы с произвольными координатами входа/выхода
	Sublevel(size_t x, size_t y, direction holePosition, holeMode mode, LevelGenerationState & gState); //конструктор подуровня с произвольной координатой отверстия или отверстий(зависит от mode)
	vector<vector<Content*>> & getMap();
	Content * findContentByPosition(size_t x, size_t y); //функция поиска контента по координатам
	void addExit(direction holePosition); //функция для создания выхода в уже созданном подуровне
	void addEnter(direction holePosition);
	//get методы
	void getExitGlobalCoords(int & x, int & y); //функция для получения глобальных координат выхода(в классе хранятся координаты относительно начала)
	void getEnterGlobalCoords(int & x, int & y); //функция для получения глобальных координат выхода(в классе хранятся координаты относительно начала)
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

