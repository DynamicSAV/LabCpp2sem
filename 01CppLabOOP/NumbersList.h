#pragma once
#include <iostream>
class NumbersList
{
private:

	int num;
	int index;
	int elementsCount;
	int elementIndex;
	bool search;
	int* arr;

public:

	NumbersList();
	void setNum();
	int getNum(int index);
	void printNum();
	void deleteNum();
	void searchNum();
};

