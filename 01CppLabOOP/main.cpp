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
#include "NumbersList.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	NumbersList a;
	//
	a.setNum();
	a.setNum();
	a.setNum();
	a.printNum();
	//
	a.deleteNum();
	a.printNum();
	//
	a.searchNum();

}