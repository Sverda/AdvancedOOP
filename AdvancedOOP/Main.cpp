#include<iostream>
#include<stdlib.h>
#include <ctime>
#include "Content.h"
using namespace std;

void main()
{
	Content<double> container;

	srand(time(nullptr));
	int stackCount = rand() % 100;
	//cout << "Number of elements on stock: " << stackCount << endl;
	for (int i = 0; i < stackCount; i++)
	{
		double randomNumber = (double)rand() / (double)RAND_MAX * 10.0;
		container.push(randomNumber);
	}
	/*for (int i = 0; i < stackCount; ++i)
	{
		cout << "Element " << i << ": " << container.pop() << endl;
	}*/
	getchar();
}