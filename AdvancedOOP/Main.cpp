#include<iostream>
#include<stdlib.h>
#include <ctime>
#include "Content.h"
using namespace std;

int RandomInt();
double RandomDouble();
template<typename T> T FindMin(typename Content<T>::iterator begin, typename Content<T>::iterator end);
template<typename T> T FindMedian(typename Content<T>::iterator begin, typename Content<T>::iterator end);
template<typename T> int CountElements(typename Content<T>::iterator begin, typename Content<T>::iterator end);
template<typename T> void PrintRange(typename Content<T>::iterator begin, typename Content<T>::iterator end);

void main()
{
	srand(time(nullptr));
	Content<double> container;
	const int n = 8;

	cout << "Stock content: " << endl;
	for (int i = 0; i < n; i++)
	{
		double randomDouble = RandomDouble();
		cout << randomDouble << endl;
		container.push(randomDouble);
	}

	cout << "Min: " << FindMin<double>(container.begin(), container.end()) << endl;
	cout << endl;
	cout << "Median: " << FindMedian<double>(container.begin(), container.end()) << endl;

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
	T min = begin++;
	T next;
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

template<typename T> T FindMedian(typename Content<T>::iterator begin, typename Content<T>::iterator end)
{
	T median;
	const int numberOfElements = CountElements<T>(begin, end);

	begin.Sort();
	PrintRange<T>(begin, end);

	if (numberOfElements % 2 == 1)
	{
		for (int i = 0; i < numberOfElements / 2; ++i)
		{
			++begin;
		}
		median = *begin;
	}
	else
	{
		for (int i = 0; i <= numberOfElements / 2; ++i)
		{
			if (i == numberOfElements / 2 - 1)
			{
				median = *begin;
			} else if (i == numberOfElements / 2)
			{
				median += *begin;
			}
			++begin;
		}
		median /= 2.0;
	}
	return median;
}

template<typename T> int CountElements(typename Content<T>::iterator begin, typename Content<T>::iterator end)
{
	int numberOfElements = 0;
	while (begin != end)
	{
		++begin;
		numberOfElements++;
	}
	begin.ResetToBegin();
	return numberOfElements;
}

template<typename T> void PrintRange(typename Content<T>::iterator begin, typename Content<T>::iterator end)
{
	cout << "Print range: " << endl;
	while (begin != end)
	{
		cout << begin++ << endl;
	}
	begin.ResetToBegin();
}