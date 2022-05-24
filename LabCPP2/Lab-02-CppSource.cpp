/*
Дано натуральное m (1<=n<=10). Заполнить квадратную матрицу размера m*m
целыми числами 0, 1, 2, 3, …, m^2–1 в соответствии со схемой расположения,
определенной вариантом в таблице № 3.

Автор: Шушков А.В
Группа: ПИ-11д
Лаб.работа: 2
Вариант: 25
Дата: 09.03.2022

*/

#include <iostream>
#include <iomanip>
#include <locale.h>
#include <vector>
using namespace std;
//=======================Функции===============

// Создание динамической матрицы
void newMatrix(int**& a, int n)
{
	a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
}

// Вывод матрицы на консоль
void printMatrix(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
}

//Заполнение границ матрицы по часовой
void fillMatrixBorder(int** a, int n, int& k)
{
	int i = 0;
	int j = 0;
	while (k <= n * 4 - 5)
	{
		a[i][j] = k;
		if (j < n - 1 && k <= n - 1)
			j++;
		else if (i < n - 1 && k <= 2 * n - 2)
			i++;
		else if (j != 0)
			j--;
		else if (i != 0)
			i--;
		++k;
	}
}

//Заполнение Вправо-влево
void fillMatrixRightLeft(int** a, int n, int& k)
{
	int i = 1;
	int j = 1;
	int p = n - 2;
	int l = p / 2;
	bool bl = true;
	bool bl2 = true;
	int lambda = 1;
	while (l != 0)
	{
		i = lambda;
		j = 1;
		cout << i << "--=--" << j << endl;
		while (bl2)
		{
			a[i][j] = k;
			if (j != p && bl)
			{
				j++;
			}
			else if (i != p && 1)
			{
				bl = false;
				i++;
			}
			else if (j > 1)
				j--;
			else
				bl2 = false;
			k++;
		}
		lambda++;

		bl = true;
		bl2 = true;
		p--;
		l--;
	}
	if (n % 2 != 0)//Заполняется средняя строчка если она есть
	{
		p++;
		j = 1;
		i = n / 2;
		while (j != p)
		{
			a[i][j] = k;
			j++;
			k++;
		}
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int m = 0;
	int k = 0;

	int n = 0;
	do {
		cout << "Введите размер массива" << endl;
		cin >> n;
	} while (n < 1 || n > 10);

	int** a = NULL;
	newMatrix(a, n);
	fillMatrixBorder(a, n, k);
	fillMatrixRightLeft(a, n, k);
	printMatrix(a, n);
}