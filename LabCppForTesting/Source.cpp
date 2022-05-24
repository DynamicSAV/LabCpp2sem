/*
Дано натуральное m (1<=m<=10). Заполнить квадратную матрицу размера m*m
целыми числами 0, 1, 2, 3, …, m^2–1 в соответствии со схемой расположения,
определенной вариантом в таблице № 3.



Автор: Шушков А.В
Группа: ПИ-11д
Лаб.работа: 1
Вариант: 25
Дата: 09.03.2022

*/
#include <iostream>
#include <iomanip>

using namespace std;

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

// Фукнция заполняет матрицу по схеме расположения (по строкам)
void fillSnakeMatrix(int** a, int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			for (int j = 0; j < n; j++)
				a[i][j] = k++;
		else
			for (int j = n - 1; j >= 0; j--)
				a[i][j] = k++;
	}
}

// Функция вычисляет координаты [i][j] элемента квадратной матрицы размера  n * n
// имеющего значение k в змейке
//void coordinates(int k, int n, int& i, int& j)
//{
//	i = k / n;
//	if (i % 2 == 0)
//		j = k % n;
//	else
//		j = n - 1 - k % n;
//}

void outerRing(int& k, int n, int& i, int& j)
{
	int switcher = (j - i + n) / n;
	int Xs = i + j - 1;
	k = switcher * Xs + abs(switcher - 1) * (4 * n - 2 - Xs);;
}

void innerRing(int& k, int n, int& i, int& j)
{
	int switcher = (j - i + n) / n;
	int Ic = abs(i - n / 2 - 1) + (i - 1) / (n / 2) * ((n - 1) % 2);//Центр
	int Jc = abs(j - n / 2 - 1) + (j - 1) / (n / 2) * ((n - 1) % 2);//Центр
	int Ring = n / 2 - (abs(Ic - Jc) + Ic + Jc) / 2;
	int Xs = i - Ring + j - Ring - 1;
	int Coef = 4 * Ring * (n - Ring);
	k = switcher * (Xs)+abs(switcher - 1) * (4 * (n - 2 * Ring) - 2 - Xs);
}

//void coordinates(int& k, int n, int& i, int& j)
//{
//	int switcher = (j - i + n) / n;
//	int Ic = abs(i - n / 2 - 1) + (i - 1) / (n / 2) * ((n - 1) % 2);
//	int Jc = abs(j - n / 2 - 1) + (j - 1) / (n / 2) * ((n - 1) % 2);
//	int Ring = n / 2 - (abs(Ic - Jc) + Ic + Jc) / 2;
//	int Xs = i - Ring + j - Ring - 1;
//	int Coef = 4 * Ring * (n - Ring);
//	k = Coef + switcher * Xs + abs(switcher - 1) * (4 * (n - 2 * Ring) - 2 - Xs);
//}

// Фукнция заполняет матрицу по схеме расположения (по строкам) через вычисление координат
//void fillSnakeMatrix2(int** a, int n)
//{
//	for (int k = 0; k < n * n; k++)
//	{
//		int i, j;
//		//coordinates(k, n, i, j);
//		a[i][j] = k;
//	}
//}

int main()
{
	int k = 0;
	int i = 0;
	int j = 0;
	//Ввод размера
	int n = 0;
	do {
		cout << "Input n" << endl;
		cin >> n;
	} while (n < 1 || n > 10);

	int** a = NULL;
	newMatrix(a, n);
	printMatrix(a, n);

	cin >> i;
	cin >> j;

	innerRing(k, n, i, j);

	cout << k << endl;

}
