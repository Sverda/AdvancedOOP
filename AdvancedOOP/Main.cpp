#include<iostream>
#include<time.h>
#include<stdlib.h>
#include"Content.cpp"
using namespace std;
template<typename T> void Transform(typename Content<T>::iterator i1, typename Content<T>::iterator i2, typename Content<T>::iterator i3);
template<typename T> void Differentiate(typename Content<T>::iterator i1, typename Content<T>::iterator i2, typename Content<T>::iterator i3);
template<typename T> void Volume(typename Content<T>::iterator i1, typename Content<T>::iterator i2, double &a);
template<typename T> void PrintRange(typename Content<T>::iterator begin, typename Content<T>::iterator end);
int RandomInt();
double RandomDouble();

int main()
{
	srand(time(nullptr));
	Content<double> container;
	Content<double> container2;
	const int n = 3;
	double volume = 1.0;

	// input data to stocks
	double randomDouble;
	for (int i = 0; i < n; i++)
	{
		randomDouble = RandomDouble();
		container.push(randomDouble);
		randomDouble = RandomDouble();
		container2.push(randomDouble);
	}
	cout << "Stock content: " << endl;
	PrintRange<double>(container.begin(), container.end());
	cout << "Stock 2 content: " << endl;
	PrintRange<double>(container2.begin(), container2.end());

	// Finding extreme points and calculating volume
	Transform<double>(container.begin(), container.end(), container2.begin());
	cout << "Extreme points (the lowest values): " << endl;
	PrintRange<double>(container.begin(), container.end());
	cout << "Extreme points (the highest values): " << endl;
	PrintRange<double>(container2.begin(), container2.end());

	Differentiate<double>(container.begin(), container.end(), container2.begin());
	cout << "Sides: " << endl;
	PrintRange<double>(container.begin(), container.end());

	Volume<double>(container.begin(), container.end(), volume);
	cout << "Calculated volume: " << volume << endl;
}

// i1 - begin of first stock, i2 - end of first stock, i3 - begin of second stock
template<typename T> void Transform(typename Content<T>::iterator i1, typename Content<T>::iterator i2, typename Content<T>::iterator i3)
{
	do
	{
		if (*i1 < *i3)
		{
			swap(*i1, *i3);
		}
		++i1;
		++i3;

	} while (i1 != i2);
}

template<typename T> void Differentiate(typename Content<T>::iterator i1, typename Content<T>::iterator i2, typename Content<T>::iterator i3)
{
	do
	{
		*i1 = *i1 - *i3;
		++i1;
		++i3;
	} while (i1 != i2);
}

template<typename T> void Volume(typename Content<T>::iterator i1, typename Content<T>::iterator i2, double &a)
{
	do
	{
		a = a*(*i1);
		i1++;
	} while (i1 != i2);
}

int RandomInt()
{
	return rand() % 100;
}

double RandomDouble()
{
	return (double)rand() / (double)RAND_MAX * 10.0;
}

template<typename T> void PrintRange(typename Content<T>::iterator begin, typename Content<T>::iterator end)
{
	//cout << "Print range: " << endl;
	while (begin != end)
	{
		cout << begin++ << endl;
	}
	begin.ResetToBegin();
}