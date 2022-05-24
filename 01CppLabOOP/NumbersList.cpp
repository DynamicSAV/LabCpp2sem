#include "NumbersList.h"
#include <iostream>

NumbersList::NumbersList()
{
	this->elementsCount = 1;
	this->arr = new int[elementsCount + 1];
}

void NumbersList::setNum()//���������� ����� � ������
{
	std::cout << "������� ����� ��� ���������� � ������" << std::endl;
	std::cin >> num;
	this->elementsCount++;
	this->arr[elementIndex] = num;
	this->elementIndex++;
}

int NumbersList::getNum(int index)
{
	return arr[index];
}

void NumbersList::printNum()//�������� ����� �� �������
{
	std::cout << "������� ������ �������� ��� ���������" << std::endl;
	std::cin >> index;
	std::cout << "����� ��� ��������  " << index << "  �����  " << getNum(index) << std::endl;
}

void NumbersList::deleteNum()
{
	std::cout << "������� ������ �������� ��� ��������" << std::endl;
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
	std::cout << "������� ������� ��� ������" << std::endl;
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
		std::cout << "�������� ������� � ��� ������ ����� " << index << std::endl;
	}
	else
	{
		std::cout << "������ ����� � ������ ���" << std::endl;
	}
}
