#pragma once
#include "Exceptions.h"

template <typename T, int rozmiar, class _Cechy = Traits<T>>
class StockTemplate
{
	T stos[rozmiar];
	int top;
public:
	int zajetosc() { return top; };

	StockTemplate() : top(0) {}

	void push(const T& i);
	void push(int i);
	void push(double i);

	T pop();
};

template <typename T, int rozmiar, class _Cechy>
void StockTemplate<T, rozmiar, _Cechy>::push(const T& i)
{
	if (top == rozmiar)
		throw Overflow(typeid(i).name());
	stos[top++] = i;
}

template <typename T, int rozmiar, class _Cechy>
void StockTemplate<T, rozmiar, _Cechy>::push(int i)
{
	if (top == rozmiar)
		throw Overflow(typeid(i).name());

	// walidacja warto�ci przekazanej do zapisu
	if (Traits<T>::_is_prime)
	{
		if (!check_if_prime(i))
		{
			return;
		}
	}

	if (Traits<T>::_jest_liczba && Traits<T>::_jest_liczba_calkowita)
	{
		if (Traits<T>::_nalezy_do_przedzialu)
		{
			if ((Traits<T>::_dolna_granica_przedzialu <= i) && (i <= Traits<T>::_gorna_granica_przedzialu))
			{
				stos[top++] = i;
			}
		}
		else
			stos[top++] = i;
	}
}

template <typename T, int rozmiar, class _Cechy>
void StockTemplate<T, rozmiar, _Cechy>::push(double i)
{
	if (top == rozmiar)
		throw Overflow(typeid(i).name());

	// walidacja warto�ci przekazanej do zapisu

	if (Traits<T>::_is_ding)
	{
		bool not_ding = true;
		for (int j = 1; j <= 12; j++)
		{
			double formula = 0.8*j + 1.2*(j - 1);
			if ( abs(formula - i) < 0.001)
			{
				not_ding = false;
			}
		}
		if (not_ding)
		{
			return;
		}
	}

	if (Traits<T>::_is_pint)
	{
		bool not_pint = true;
		int pint = i * 1000;

		if (pint%568 == 0)
		{
			not_pint = false;
		}
		if (not_pint)
		{
			return;
		}
	}
	
	if (Traits<T>::_jest_liczba && !Traits<T>::_jest_liczba_calkowita)
	{
		if (Traits<T>::_nalezy_do_przedzialu)
		{
			if ((Traits<T>::dolna_granica_przedzialu() <= i) && (i <= Traits<T>::gorna_granica_przedzialu()))
				stos[top++] = i;
		}
		else
			stos[top++] = i;
	}
}

template <typename T, int rozmiar, class _Cechy>
T StockTemplate<T, rozmiar, _Cechy>::pop()
{
	if (top == 0)
		throw NoData(typeid(stos[0]).name());

	return stos[--top];
}