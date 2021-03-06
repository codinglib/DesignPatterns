#include "stdafx.h"

using namespace std;

//Класс одиночик
class Singleton
{
public:
	int i;

protected:
	static Singleton* self;
	Singleton()
	{
		i = 0;
	}
	virtual ~Singleton() {}

public:
	static Singleton* Instance()
	{
		if (!self)
			self = new Singleton();
		
		return self;
	}
	static bool DeleteInstance()
	{
		if (self)
		{
			delete self;
			self = 0;
			return true;
		}
		else
			return false;
	}
};

Singleton* Singleton::self = 0;

int main()
{
	system("color 70");
	setlocale(0, "");
	SetConsoleTitle(TEXT("Singleton"));

	Singleton::Instance()->i = 99;

	cout << "Singleton before delete: " << Singleton::Instance()->i << endl;

	Singleton::DeleteInstance();

	cout << "Singleton after delete: " << Singleton::Instance()->i << endl;

	system("pause");
	return 0;
}

