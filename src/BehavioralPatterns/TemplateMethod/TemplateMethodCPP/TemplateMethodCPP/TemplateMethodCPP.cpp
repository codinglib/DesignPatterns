#include "stdafx.h"

using namespace std;

//Абстрактный класс сортировки
//"интерфейс"
class IShellSort
{
public:
	void Sort(int *arr, int size)
	{
		for (int g = size / 2; g > 0; g /= 2)
			for (int i = g; i < size; i++)
				for (int j = i - g; j >= 0; j -= g)
					if (Predicate(arr[j], arr[j + g]))
						Swap(arr[j], arr[j + g]);
	}

protected:
	void Swap(int &a, int &b)
	{
		int t = a;
		a = b;
		b = t;
	}
	virtual bool Predicate(int&, int&) = 0;
};

//Законченная сортировка с переопределенным
//template method'ом
class ShellSortUp : public virtual IShellSort
{
protected:
	virtual bool Predicate(int &a, int &b) { return a > b; }
};

//Законченная сортировка с переопределенным
//template method'ом
class ShellSortDown : public virtual IShellSort
{
protected:
	virtual bool Predicate(int &a, int &b) { return a < b; }
};

int main()
{
	system("color 70");
	setlocale(0, "");
	SetConsoleTitle(TEXT("Template method"));

	int arr[] = { 3,7,1,3,6,1,5,7,1,9 };

	cout << "ShellSortUp: " << endl;

	ShellSortUp su;
	su.Sort(arr, 10);

	for (auto i : arr)
		cout << i << " ";

	cout << "\nShellSortDown: " << endl;

	ShellSortDown sd;
	sd.Sort(arr, 10);

	for (auto i : arr)
		cout << i << " ";

	cout << endl;

	system("pause");
    return 0;
}

