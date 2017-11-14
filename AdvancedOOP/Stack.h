#pragma once
#include "Exceptions.h"

template<typename T, int rozmiar, class _Cechy = Cechy<T>>
class SzablonStosu {
	T stos[rozmiar];
	int top;
public:
	int zajetosc() { return top; };
	SzablonStosu() : top(0) {}

	void push(const T& i);
	void push(int i);
	void push(double i);
	T pop();
};

template <typename T, int rozmiar, class _Cechy>
void SzablonStosu<T, rozmiar, _Cechy>::push(const T& i)
{
	if (top == rozmiar)
		throw Przepelnienie(typeid(i).name());
	stos[top++] = i;
}

template <typename T, int rozmiar, class _Cechy>
void SzablonStosu<T, rozmiar, _Cechy>::push(int i)
{
	if (top == rozmiar)
		throw Przepelnienie(typeid(i).name());

	// walidacja warto�ci przekazanej do zapisu
	if (Cechy<T>::_jest_liczba && Cechy<T>::_jest_liczba_calkowita)
	{
		if (Cechy<T>::_nalezy_do_przedzialu)
		{
			if ((Cechy<T>::_dolna_granica_przedzialu <= i) && (i <= Cechy<T>::_gorna_granica_przedzialu))
				stos[top++] = i;
		}
		else
			stos[top++] = i;
	}
}

template <typename T, int rozmiar, class _Cechy>
void SzablonStosu<T, rozmiar, _Cechy>::push(double i)
{
	if (top == rozmiar)
		throw Przepelnienie(typeid(i).name());

	// walidacja warto�ci przekazanej do zapisu
	if (Cechy<T>::_jest_liczba && !Cechy<T>::_jest_liczba_calkowita)
	{
		if (Cechy<T>::_nalezy_do_przedzialu)
		{
			if ((Cechy<T>::dolna_granica_przedzialu() <= i) && (i <= Cechy<T>::gorna_granica_przedzialu()))
				stos[top++] = i;
		}
		else
			stos[top++] = i;
	}
}

template <typename T, int rozmiar, class _Cechy>
T SzablonStosu<T, rozmiar, _Cechy>::pop()
{
	if (top == 0)
		throw BrakDanych(typeid(stos[0]).name());

	return stos[--top];
}
