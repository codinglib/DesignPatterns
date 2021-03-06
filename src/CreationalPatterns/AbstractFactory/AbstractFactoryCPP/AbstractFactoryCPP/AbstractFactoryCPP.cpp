#include "stdafx.h"

using namespace std;

//Абстрактный класс для всех воинов
class Warrior
{
public:
	virtual ~Warrior() {};
	virtual void GetInfo() = 0;
};

//Классы воинов рима
class RomanWarriorInfantryman : virtual public Warrior
{
public:
	void GetInfo() { cout << "Roman Warrior Infantryman" << endl; }
};

class RomanWarriorArcher : virtual public Warrior
{
public:
	void GetInfo() { cout << "Roman Warrior Archer" << endl; }
};

class RomanWarriorHorseman : virtual public Warrior
{
public:
	void GetInfo() { cout << "Roman Warrior Horseman" << endl; }
};

//Классы воинов карфагена
class CarthaginianWarriorInfantryman : virtual public Warrior
{
public:
	void GetInfo() { cout << "Carthaginian Warrior Infantryman" << endl; }
};

class CarthaginianWarriorArcher : virtual public Warrior
{
public:
	void GetInfo() { cout << "Carthaginian Warrior Archer" << endl; }
};

class CarthaginianWarriorHorseman : virtual public Warrior
{
public:
	void GetInfo() { cout << "Carthaginian Warrior Horseman" << endl; }
};

//Абстрактный класс для фабрики по произодству воинов
class ArmyFactory
{
public:
	virtual Warrior* CreateWarriorInfantryman() = 0;
	virtual Warrior* CreateWarriorArcher() = 0;
	virtual Warrior* CreateWarriorHorseman() = 0;
};

//Фабрика для производства воинов рима
class RomeArmyFactory: virtual public ArmyFactory
{
public:
	Warrior * CreateWarriorInfantryman() { return new RomanWarriorInfantryman; }
	Warrior * CreateWarriorArcher() { return new RomanWarriorArcher; }
	Warrior * CreateWarriorHorseman() { return new RomanWarriorHorseman; }
};

//Фабрика для производства воинов карфагена
class CarthaginianArmyFactory : virtual public ArmyFactory
{
public:
	Warrior * CreateWarriorInfantryman() { return new CarthaginianWarriorInfantryman; }
	Warrior * CreateWarriorArcher() { return new CarthaginianWarriorArcher; }
	Warrior * CreateWarriorHorseman() { return new CarthaginianWarriorHorseman; }
};

//Классы для демонстрации работы шаблона Абстрактная фабрика
//Класс для хранениния всех воинов
class Army
{
public:
	vector<Warrior*> warriors;

public:
	///Уничтожаем созданых воинов
	~Army()
	{
		for (int i = 0; i < warriors.size(); i++)
		{
			delete warriors[i];
		}
	}

	///Выводим информацию об каждом воине в армии
	void GetInfo()
	{
		for (int i = 0; i < warriors.size(); i++)
		{
			warriors[i]->GetInfo();
		}
	}
};

//Клас игры для согдания армий
class Game
{
public:
	///Создаем армии согласно переданой фабрики
	Army* CreateArmy(ArmyFactory& fac)
	{
		Army* ptrArmy = new Army;

		ptrArmy->warriors.push_back(fac.CreateWarriorArcher());
		ptrArmy->warriors.push_back(fac.CreateWarriorHorseman());
		ptrArmy->warriors.push_back(fac.CreateWarriorInfantryman());

		return ptrArmy;
	}
};

int main()
{
	system("color 70");
	setlocale(0, "");
	SetConsoleTitle(TEXT("Abstract factory"));

	Game game;

	RomeArmyFactory romanFactory;
	CarthaginianArmyFactory carthaginianArmyFactory;

	Army* roman = game.CreateArmy(romanFactory);
	Army* carthaginian = game.CreateArmy(carthaginianArmyFactory);

	cout << "Roman army:" << endl;
	roman->GetInfo();

	cout << endl << "Carthaginian army:" << endl;
	carthaginian->GetInfo();

	system("pause");
    return 0;
}