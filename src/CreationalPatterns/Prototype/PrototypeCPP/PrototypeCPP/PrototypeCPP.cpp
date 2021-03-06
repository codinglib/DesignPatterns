#include "stdafx.h"

using namespace std;

//Базовый клас прототипа
class Meal
{
public:
	virtual ~Meal() {}

	virtual void Eat() = 0;
	virtual Meal* clone() const = 0;
};

//Конкретный класс прототипа
class Spaghetti : public virtual Meal
{
public:
	virtual void Eat() override { cout << "Eat a peace of Spaghetti " << endl; }
	virtual Meal * clone() const override { return new Spaghetti(*this); }
};

//Конкретный класс прототипа
class Meat : public virtual Meal
{
public:
	virtual void Eat() override { cout << "Eat a peace of Meat" << endl; }
	virtual Meal * clone() const override { return new Meat(*this); }
};

//Фабрика по производству обьектов с прототипа
class Factory
{
private:
	Meal * meals[2];

public:
	Factory()
	{
		meals[0] = new Meat;
		meals[1] = new Spaghetti;
	}
	~Factory()
	{
		delete meals[0];
		delete meals[1];
	}

	//Создаем новые обьекты путем клонирования существующих уже "давно"
	Meal* CreateMeal(int n) { return meals[n]->clone(); }
};

int main()
{
	system("color 70");
	setlocale(0, "");
	SetConsoleTitle(TEXT("Prototype"));

	Factory factory;

	Meal* meat = factory.CreateMeal(0);
	Meal* spaghetti = factory.CreateMeal(1);

	meat->Eat();
	spaghetti->Eat();

	system("pause");
    return 0;
}

