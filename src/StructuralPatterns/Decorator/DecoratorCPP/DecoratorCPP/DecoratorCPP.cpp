#include "stdafx.h"

using namespace std;

//Интерфейс расширяемого обьекта
class IComponent
{
public:
	virtual ~IComponent() {}

	virtual void Action() = 0;
};

//Объект который необходимо расиширить
class Component : public virtual IComponent
{
public:
	virtual void Action() override
	{
		cout << "World!" << endl;
	}
};

//Первое расширение
class DecoratorOne : public virtual IComponent
{
private:
	shared_ptr<IComponent> base;

public:
	DecoratorOne(IComponent* comp) : base(comp) {}

	virtual void Action() override
	{
		cout << ", ";
		base->Action();
	}
};

//Второе расширение
class DecoratorTwo : public virtual IComponent
{
private:
	shared_ptr<IComponent> base;

public:
	DecoratorTwo(IComponent* comp) : base(comp) {}

	virtual void Action() override
	{
		cout << "Hello";
		base->Action();
	}
};

int main()
{
	system("color 70");
	setlocale(0, "");
	SetConsoleTitle(TEXT("Decorator"));

	DecoratorTwo tw(new DecoratorOne(new Component()));
	tw.Action();

	system("pause");
    return 0;
}

