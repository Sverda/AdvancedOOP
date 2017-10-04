#include <cstdio>
#pragma once
using namespace std;

template <typename T, int rozmiar>
class Tablica {
	T A[rozmiar];
public:
	T& operator[](int index);
};

template <typename T, int rozmiar>
T& Tablica<T, rozmiar>::operator[](int index)
{
	if (index >= rozmiar || index < 0)
		return A[0];
	else
		return A[index];
}