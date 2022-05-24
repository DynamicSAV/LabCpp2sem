/*
  Натуральное число n (1<=n<=100) вводится с клавиатуры. Целочисленный линейный массив
  a0, a1, …, an-1 заполняется случайными целыми числами из диапазона [0, n).
  Требуется отсортировать массив по не убыванию. Метод сортировки определяется вариантом в
  соответствии с таблицей № 1. После сортировки вводится целое значение k,
  требуется произвести поиск в массиве этого значения.
  Алгоритм поиска определяется в таблице № 2.

  Сортировка слиянием

  Последовательный поиск с барьером по массиву слева направо

Автор: Шушков А.В
Группа: ПИ-11д
Лаб.работа: 1
Вариант: 25
Дата: 09.03.2022

*/

#include <iostream>
#include <iomanip>
#include <locale.h>
#include<vector>
using namespace std;


// Функция заполняет массив а случайными целыми числами
void randomArray(vector<int> &v, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		v.push_back(rand() % n);
}

// Функция выводит массив а на консоль
void printArray(vector<int> v)
{
	vector<int>::iterator it;
	for (it = v.begin(); it < v.end(); ++it)
		cout << setw(4) << *it;
}

//Функция сортирует массив слиянием
void mergeSort(vector<int> &v, size_t start, size_t end)
{
	cout << "size_t start" << start << endl;
	cout << "size_t end" << end << endl;

	if (end - start < 2)
		return;
	if (end - start == 2)
	{
		if (v[start] > v[start + 1])
			swap(v[start], v[start + 1]);
		return;
	}
	mergeSort(v, start, start + (end - start) / 2);
	mergeSort(v, start + (end - start) / 2, end);
	vector<int> b;
	size_t b1 = start;
	size_t e1 = start + (end - start) / 2;
	size_t b2 = e1;
	while (b.size() < end - start)
	{
		if (b1 >= e1 || (b2 < end && v.at(b2) <= v.at(b1)))
		{
			b.push_back(v.at(b2));
			++b2;
		}
		else
		{
			b.push_back(v.at(b1));
			++b1;
		}
	}
	for (size_t i = start; i < end; ++i)
		v.at(i) = b.at(i - start);
}

void includeBarier(vector<int> v, int n, int value)
{
	int last = v.at(n - 1);
	int i = 0;
	vector<int>::iterator it;
	v.at(n - 1) = value;
	for (it = v.begin();*it != value; ++it)
	{
		i++;
		v.at(n - 1) = last;
		if (i != (n - 1) || value == last)
			cout << i << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");

	vector<int> v;
	int n = 0;
	int k = 0;

	cout << "Введите размер массива" << endl;
	cin >> n;

	randomArray(v, n);
	cout << "Исходный массив" << endl;
	printArray(v);
	cout << endl;

	cout << "Отсортированный массив" << endl;
	mergeSort(v, 0, n);
	printArray(v);
	cout << endl;

	cout << "Введите число для поиска" << endl;
	cin >> k;
	includeBarier(v, n, k);
}
