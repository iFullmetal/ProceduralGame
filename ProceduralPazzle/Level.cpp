#include "Level.h"

Level::Level()
{
	size_t lx = 0;
	size_t ly = 0;
	int enterX;
	int enterY;
	Sublevel sub(lx, ly, right, exit_);
	int lenght = 0; //длина горизантальной линии
	//создание первой горизонтальной полосы из подуровней
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
	//создание вертикальных столбцов по ширине каждого из горизонтальных подуровней
	for(int i = 0; i < lenght; i++)
	{
		ly = level[i].getHeight(); //высота соответсвующего подуровня по горизонтали становится y-координатой вертикального подуровня
		lx = level[i].getX(); // x аналогичен
		while (ly < Y_SIZE - 3)
		{
			sub = Sublevel(lx, ly, level[i].getWidth()); //вызов конструкора подуровеня с фиксированной шириной
			level.push_back(sub);
			ly += sub.getHeight(); // y следующего подуровня увеличивается на высоту преидущего
		}
	}
}
Level::Level(int uselessvaluethatgivesmeposabilitytocreatesecondconstructor)
{
	sublevelLineState state = start; //старт - создается линия подуровней без изначального входа, но с выходом справа снизу.
	//rightEnterLeftExit - создается линия подуровней с входом срправа сверху и выходом слева снизу
	//leftEnterRightExit - наоборот
	LevelGenerationState generationState = normal; //переменная, отвечающая за попадание в ситуацию бесконечного цикла в конструкторах подуровней. Если такое случается, то уровень будет пересоздан заново.
	size_t lx = 0;
	size_t ly = 0;
	int enterX = -1; //изначальные позиции выхода из текущего-входа в следующий имею координату, которой не может быть. То есть вход не добавится.
	int enterY = -1;
	vector<int> sublevelHorizontalLineHeight; //вектор для хранения суммы высот каждого подуровня по вертикали. Необходим для того, чтобы знать на какой коориднате по y делать подуровень
	Sublevel sub(lx, ly, right, exit_); //создаю первую стартовую комнату, в которой будет только выход
	sublevelHorizontalLineHeight.push_back(sub.getHeight());
	level.push_back(sub);
	int lenght = 0; //длина первой линии из подуровней по горизонтали
	int some = 0;
	do
	{
		state = start;
		generationState = normal;
		lx = 0;
		ly = 0;
		enterX = -1;
		enterY = -1;
		level.clear();
		sublevelHorizontalLineHeight.clear();
		sub = Sublevel(lx, ly, right, exit_);
		sublevelHorizontalLineHeight.push_back(sub.getHeight());
		level.push_back(sub);
		lenght = 0;
		some = 0;
		do
		{
			switch (state)
			{
			case start:
			{
				while (lx < X_SIZE - 3)
				{
					level.push_back(sub);
					sublevelHorizontalLineHeight.push_back(sub.getHeight()); //заполняю вектор высот
					lx += sub.getWidth();
					enterX = sub.getExitPosX();
					enterY = sub.getExitPosY();
					sub = Sublevel(lx, ly, 0, enterY, 0);
					sub.addExit(right);
					lenght++;
				}

				Block * block = (Block*)level[lenght].getMap()[level[lenght].getExitPosY()][level[lenght].getExitPosX()]; //убераю старый выход в бок, вместо него ставлю стену
				block->setBlockType(brick);
				level[lenght].getMap()[level[lenght].getExitPosY()][level[lenght].getExitPosX()] = block;

				level[lenght].addExit(down); //теперь делаю новый выход уже вниз


				state = rightEnterLeftExit;
				enterX = level[lenght].getExitPosX();
				enterY = level[lenght].getExitPosY();
				some++;
			}
			break;
			case rightEnterLeftExit:
				sub = Sublevel(level[lenght].getX(), sublevelHorizontalLineHeight[lenght], level[lenght].getWidth(), enterX, 0, 0, generationState);
				sublevelHorizontalLineHeight[lenght] += sub.getHeight(); //увеличиваю высоту горизонтали подуровней за счет высоты нового подуровня. Теперь это будет новым y для следующего подуровня
				sub.addExit(left); //добавляю выход в левую стенку подуровня
				enterX = sub.getExitPosX(); //получаю координаты выхода из этого подуровня
				enterY = sub.getExitPosY();
				//level.insert(level.begin() + lenght, sub);
				level.push_back(sub);
				for (int i = lenght - 1; i > 0; i--)
				{
					sub.getExitGlobalCoords(enterX, enterY); //получаю координаты выхода из прошлого подуровня
					sub = Sublevel(level[i].getX(), sublevelHorizontalLineHeight[i], level[i].getWidth(), level[i].getWidth() - 1, enterY - sublevelHorizontalLineHeight[i], 0, generationState);
					//первый аргумент это x позиция верхнего подуровня, 
					//второй это текущия позиция данного столбика из вектора высот, 
					//третий это ширина верхнего подуровня(в это она не будет рандомится) в отличии от высоты
					//четвертый это ширина-1 т.е. позиция входа в подуровень по X(то есть самая правая стенка)
					//пятый это разница между глобальной координатой выхода из прошлого подуровня и текущей высотой этого столбика подуровней - в результате получается координата относительно начала этого подуровня
					//шестой 0 - тип прохода в подуровне - вход
					//относительные координаты выхода/входа нужны из-за цикла в конструкторе подуровня, который расставляет блоки в зависимости от текущих значений i и j которые начинаются от нуля
					sublevelHorizontalLineHeight[i] += sub.getHeight(); //увеличиваю высоту горизонтали подуровней за счет высоты нового подуровня. Теперь это будет новым y для следующего подуровня
					sub.addExit(left); //добавляю выход в новый подуровень
					enterX = sub.getExitPosX(); //получаю координаты выхода из этого подуровня
					enterY = sub.getExitPosY();
					level.insert(level.begin() + lenght, sub); //добавляю новый подуровень в вектор
					//level.push_back(sub);
				}
				some++;
				break;
			case leftEnterRightExit:
				break;
			default:
				break;
			}
		} while (some < 2/*ly < Y_SIZE - 3*/);
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
