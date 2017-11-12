#include<iostream>
#include<stdlib.h>
#include <ctime>
#include "Content.h"
using namespace std;

int RandomInt();
double RandomDouble();
template<typename T> T FindMin(typename Content<T>::iterator begin, typename Content<T>::iterator end);

void main()
{
	srand(time(nullptr));
	Content<double> container;
	const int n = 7;

	cout << "Stock content: " << endl;
	for (int i = 0; i < n; i++)
	{
		double randomDouble = RandomDouble();
		cout << randomDouble << endl;
		container.push(randomDouble);
	}

	cout << "Min: " << FindMin<double>(container.begin(), container.end()) << endl;

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

template<typename T> T FindMin(typename Content<T>::iterator begin, typename Content<T>::iterator end)
{
	double min = begin++;
	double next;
	while (begin != end)
	{
		next = begin++;
		if (min > next)
		{
			min = next;
		}
	}
	return min;
}