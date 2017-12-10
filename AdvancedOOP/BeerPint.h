#pragma once
#include"Traits.h"
#include<iostream>
#include<limits>
using namespace std;

class BeerPint
{
	double _pinta;
public:
	BeerPint(double pinta = 0.568);
	double operator()() const { return _pinta; }

	double get_pinta(){ return _pinta; }

	BeerPint& operator=(double pinta)
	{
		_pinta = pinta;
		return *this;
	}

	friend ostream& operator<<(ostream& os, BeerPint& beer_pint);
};

template <>
class Traits<BeerPint> : public BaseTraits
{
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const bool _jest_liczba_calkowita = false;
	static const int _numbers_after_point = 4;
	static const double dolna_granica_przedzialu() { return 0; };
	static const double gorna_granica_przedzialu() { return std::numeric_limits<double>::max(); };
	static const bool _is_pint = true;
};

BeerPint::BeerPint(double i)
{
	bool not_pint = true;
	int pint = i * 1000;

	if (pint % 568 == 0)
	{
		not_pint = false;
	}

	/*if (i <= Traits<Ding>::_dolna_granica_przedzialu() || i >= Traits<Ding>::_gorna_granica_przedzialu())
	{
		not_pint = false;
	}
	else
	{
		not_pint = true;
	}*/

	if (not_pint)
	{
		_pinta = 0.568;
	}
	else
	{
		_pinta = i;
	}
}