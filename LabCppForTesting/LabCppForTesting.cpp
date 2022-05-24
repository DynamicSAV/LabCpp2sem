#include <iostream>
#include <iomanip>
#include <locale.h>
#include <vector>
#include <cstdlib> // для system
using namespace std;

//Функция создает  матрицу
vector<vector<int>> CreateMatrix(int n) {
    vector<vector<int>> vec;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            temp.push_back(0);
        }
        vec.push_back(temp);
    }
    return vec;
}

// Функция выводит на консольный экран матрицу a размера m * n
void PrintMatrix(vector<vector<int>> a)
{
    for (vector<vector<int>>::iterator row = a.begin(); row != a.end(); row++) {
        for (vector<int>::iterator element = (*row).begin(); element != (*row).end(); element++)
            cout << setw(4) << *element;
        cout << endl;
    }

}


//Функция заполняет матрицу  (Выбран способ 1,простой перебор)
vector<vector<int>> FillUpMatrix(vector<vector<int>> vec, int MaxX, int MaxY, int MinX, int& MinY, int& k) {
    if (MinY < MaxY) {
        for (int i = MinX; i <= (MaxX - 1); i++) {
            vec.at(i).at(MinY) = k;
            k++;
        }
        MinY++;
    }

    if (MinY < MaxY) {
        for (int i = MaxX - 1; i >= (MinX); i--) {
            vec.at(i).at(MinY) = k;
            k++;
        }
        MinY++;
    }

    return vec;
}

vector<vector<int>> FillDownMatrix(vector<vector<int>> vec, int MaxX, int& MaxY, int MinX, int MinY, int& k) {
    if (MinY < MaxY) {
        for (int i = MaxX; i >= (MinX); i--) {
            vec.at(i).at(MaxY - 1) = k;
            k++;
        }
        MaxY--;
    }
    if (MinY < MaxY)
    {
        for (int i = MinX; i <= (MaxX); i++) {
            vec.at(i).at(MaxY - 1) = k;
            k++;
        }
        MaxY--;
    }
    return vec;
}

int main()
{
    int n;
    int m = 0;
    int k = 0;
    int MinX = 0;
    int MinY = 0;
    setlocale(LC_ALL, "Russian");
    cout << "Введите n" << endl;
    cin >> n;
    cout << endl;

    int MaxX;
    if (n % 2 == 0) {
        MaxX = n / 2;
    }
    else MaxX = (n / 2) + 1;
    int MaxY = n;

    //Создание массива
    vector<vector<int>> vec = CreateMatrix(n);
    for (int i = n / 2; i >= 0; i -= 1) {
        vec = FillUpMatrix(vec, MaxX, MaxY, MinX, MinY, k);
    }

    MinY = 0;
    MinX = MaxX;
    MaxX = n - 1;

    for (int i = n / 2; i >= 0; i -= 1) {
        vec = FillDownMatrix(vec, MaxX, MaxY, MinX, MinY, k);
    }
    PrintMatrix(vec);
    system("pause");
    return 0;
}