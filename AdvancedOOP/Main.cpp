#include<iostream>
#include<stdlib.h>
#include <ctime>
#include "Content.h"
using namespace std;

int RandomInt();
double RandomDouble();

void main()
{
	srand(time(nullptr));
	Content<double> container;
	int n = RandomInt();

	for (int i = 0; i < n; i++)
	{
		double randomDouble = RandomDouble();
		container.push(randomDouble);
	}

	getchar();
}

int RandomInt()
{
	return rand() % 100;
}

double RandomDouble()
{
	return (double)rand() / (double)RAND_MAX * 10.0;
}

