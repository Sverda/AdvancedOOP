#include<iostream>
#include<stdlib.h>
#include <ctime>
#include "Content.h"
using namespace std;

void main()
{
	Content<double> container;

	srand(time(nullptr));
	int stockCount = rand() % 100;
	//cout << "Number of elements on stock: " << stockCount << endl;
	for (int i = 0; i < stockCount; i++)
	{
		double randomNumber = (double)rand() / (double)RAND_MAX * 10.0;
		container.push(randomNumber);
	}
	/*for (int i = 0; i < stockCount; ++i)
	{
		cout << "Element " << i << ": " << container.pop() << endl;
	}*/
	getchar();
}