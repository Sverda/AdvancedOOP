#pragma once
#include "Traits.h"

class kostka_do_gry
{
	int n;
public:
	kostka_do_gry(int num = 1) : n(num)
	{
	};
	int operator()() const { return n; };

	kostka_do_gry& operator=(int num)
	{
		n = num;
		return *this;
	};
};

template <>
class Cechy<kostka_do_gry> : public Bazowe_Cechy
{
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const bool _jest_liczba_calkowita = true;
	static const int _dolna_granica_przedzialu = 1;
	static const int _gorna_granica_przedzialu = 6;
};
