#pragma once
#include "Traits.h"

class Dice
{
	int n;
public:
	Dice(int num = 1) : n(num) {}
	int operator()() const { return n; }

	Dice& operator=(int num);
};

Dice& Dice::operator=(int num)
{
	n = num;
	return *this;
}

template <>
class Traits<Dice> : public BaseTraits
{
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const bool _jest_liczba_calkowita = true;
	static const int _dolna_granica_przedzialu = 1;
	static const int _gorna_granica_przedzialu = 6;
};