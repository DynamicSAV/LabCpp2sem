/*
Список целых чисел

Вставка, исключение из списка,
доступ по номеру, поиск значения в списке.
Не использовать стандартные шаблоны, использовать
массивы.

Автор: Шушков А.В
Группа: ПИ-11д
Лаб.работа: 2.1
Вариант: 25
Дата: 02.05.2022

*/
#include <iostream>
#include <iomanip>
#include <locale.h>
using namespace std;

class listNumbers
{
private:
	int elementsCount = 1;
	int elAdd = 0;
	int elIndex = 0;
	int elIndexDel = 0;
	int searchNum;
	bool search = false;
	int searchIndex = 0;
	int *arr = new int[elementsCount+1];
public:
	void setEl()//Добавление элемента в список
	{
		elementsCount++;
		cout << "Введите целое число для добавления в список" << endl;
		cin >> elAdd;
		arr[elIndex] = elAdd;
		elIndex++;
	}
	void deleteEl()//Удаление элемента из списка
	{
		cout << "Введите индекс элемента для удаления" << endl;
		cin >> elIndexDel;
		for (int i = elIndexDel; i < elementsCount; ++i)
		{
			arr[i] = arr[i + 1];
		}
		--elementsCount;
		elIndex--;
	}
	void searchNumInList()
	{
		cout << "Введите число для поиска" << endl;
		cin >> searchNum;
		for (int k = 0; k < elementsCount - 1; k++)
			if (arr[k] == searchNum)
			{
				search = true;
				searchIndex = k;
				break;
			}
		if (search)
		{
			cout << "Значение найдено и его индекс равен " << searchIndex << endl;
		}
		else
		{
			cout << "Такого числа в списке нет" << endl;
		}
	}
	void printArr()//Вывод списк на экран
	{
		for (int i = 0; i < elementsCount - 1; i++)
			cout << setw(4) << arr[i];
		cout << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	listNumbers mainNumbers;
	mainNumbers.setEl();
	mainNumbers.setEl();
	mainNumbers.setEl();
	mainNumbers.setEl();
	mainNumbers.printArr();

	mainNumbers.deleteEl();
	mainNumbers.printArr();

	mainNumbers.setEl();
	mainNumbers.printArr();

	mainNumbers.searchNumInList();
}