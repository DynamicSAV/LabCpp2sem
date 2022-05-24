#include "NumbersList.h"
#include <iostream>

NumbersList::NumbersList()
{
	this->elementsCount = 1;
	this->arr = new int[elementsCount + 1];
}

void NumbersList::setNum()//Добавление числа в список
{
	std::cout << "Введите число для добавления в список" << std::endl;
	std::cin >> num;
	this->elementsCount++;
	this->arr[elementIndex] = num;
	this->elementIndex++;
}

int NumbersList::getNum(int index)
{
	return arr[index];
}

void NumbersList::printNum()//Просмотр числа по индексу
{
	std::cout << "Введите индекс элемента для просмотра" << std::endl;
	std::cin >> index;
	std::cout << "Число под индексом  " << index << "  равен  " << getNum(index) << std::endl;
}

void NumbersList::deleteNum()
{
	std::cout << "Введите индекс элемента для удаления" << std::endl;
	std::cin >> index;
	for (int i = index; i < elementsCount; ++i)
	{
		arr[i] = arr[i + 1];
	}
	this->elementsCount--;
	index--;
}

void NumbersList::searchNum()
{
	std::cout << "Введите элемент для поиска" << std::endl;
	std::cin >> num;
	for (int k = 0; k < elementsCount - 1; k++)
		if (arr[k] == num)
		{
			search = true;
			index = k;
			break;
		}
	if (search)
	{
		std::cout << "Значение найдено и его индекс равен " << index << std::endl;
	}
	else
	{
		std::cout << "Такого числа в списке нет" << std::endl;
	}
}
