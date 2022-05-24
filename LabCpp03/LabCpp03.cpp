/*
Дано натуральное m (1>=m>=10), целочисленный квадратный массив-матрица размера mxm.
Матрица заполнена случайными числами из диапазона [0, m^2). Отсортировать элементы матрицы так,
чтобы при прохождении по схеме, указанной в таблице № 3, они были бы упорядочены по не убыванию. Метод сортировки тот же, что и в таблице № 1.

Автор: Шушков А.В
Группа: ПИ-11д
Лаб.работа: 3
Вариант: 25
Дата: 01.05.2022

*/

#include <iostream>
#include <iomanip>
#include <locale.h>
#include <vector>
using namespace std;


//Функция сортирует массив слиянием
void mergeSort(int* c, int start, int  end)
{
	if (end - start < 2)
		return;
	if (end - start == 2)
	{
		if (c[start] > c[start + 1])
			swap(c[start], c[start + 1]);
		return;
	}
	mergeSort(c, start, start + (end - start) / 2);
	mergeSort(c, start + (end - start) / 2, end);
	vector<int> b;
	size_t b1 = start;
	size_t e1 = start + (end - start) / 2;
	size_t b2 = e1;
	while (b.size() < end - start)
	{
		if (b1 >= e1 || (b2 < end && c[b2] <= c[b1]))
		{
			b.push_back(c[b2]);
			++b2;
		}
		else
		{
			b.push_back(c[b1]);
			++b1;
		}
	}
	for (size_t i = start; i < end; ++i)
		c[i] = b.at(i - start);
}

// Создание динамической матрицы
void newMatrix(int**& a, int n)
{
	a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
}

// Заполнение матрицы случайными числами в диапазоне [0, m^2)
void fillRandomMatrix(int** a, int m)
{
	if (m != 1)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				a[i][j] = rand() % (m * m - 1);
			}
		}
	}
	else
		a[0][0] = 0;
}

// Вывод матрицы на консоль(Вспомогательная)
void printMatrix(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
}

// Вывод массива на консоль
void printArray(int* b, int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(4) << b[i] << endl;
}

// Заполнение границ матрицы по часовой
void fillMatrixBorder(int** a, int n, int& k, int* b)
{
	int i = 0;
	int j = 0;
	while (k <= n * 4 - 5)
	{
		a[i][j] = b[k];
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

// Заполнение Вправо-влево
void fillMatrixRightLeft(int** a, int n, int& k, int* b)
{
	if (n != 1)
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
			while (bl2)
			{
				a[i][j] = b[k];
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
				a[i][j] = b[k];
				j++;
				k++;
			}
		}
	}
	else
		return;

}

// Копирование матрицы на новый массив
void copyAndSortMatrix(int** a, int n, int* b)
{
	// Копирование
	int it = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[it] = a[i][j] ;
			it++;
			
		}
	}

	// Сортировка
	mergeSort(b, 0, n * n);

}

int main()
{
	setlocale(LC_ALL, "Russian");

	int n = 0;
	do {
		cout << "Введите размер массива" << endl;
		cin >> n;
	} while (n < 1 || n > 10);
	int** a = NULL;
	int* b = new int[n * n];
	int m = 0;
	int k = 0;

	// Начальная матрица
	newMatrix(a, n);
	fillRandomMatrix(a, n);
	cout << "Начальная матрица" << endl;
	printMatrix(a, n);
	// Изменение матрицы
	copyAndSortMatrix(a, n, b);
	fillMatrixBorder(a, n, k, b);
	fillMatrixRightLeft(a, n, k, b);
	cout << endl;
	//Вывод матрицы
	cout << "Конечная матрица" << endl;
	printMatrix(a, n);
}