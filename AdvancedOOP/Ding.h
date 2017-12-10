#pragma once
#include"Traits.h"
#include<iostream>
using namespace std;

class Ding
{
	double _time;
public:
	Ding(double time = 0.8);
	double operator()() const { return _time; }

	double get_time(){ return _time; }

	Ding& operator=(double time)
	{
		_time = time;
		return *this;
	}

	friend ostream& operator<<(ostream& os, Ding& ding);
};

template <>
class Traits<Ding> : public BaseTraits
{
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const bool _jest_liczba_calkowita = false;
	static const int _numbers_after_point = 4;
	static const double dolna_granica_przedzialu() { return 0.8; };
	static const double gorna_granica_przedzialu() { return 24.8; };
	static const bool _is_ding = true;
};

Ding::Ding(double time)
{
	bool not_ding = true;
	for (int j = 1; j <= 12; j++)
	{
		double formula = 0.8*j + 1.2*(j - 1);
		if (abs(formula - time) < 0.001)
		{
			not_ding = false;
		}
	}

	/*if (time <= Traits<Ding>::_dolna_granica_przedzialu() || time >= Traits<Ding>::_gorna_granica_przedzialu)
	{
		not_ding = false;
	}
	else
	{
		not_ding = true;
	}*/

	if (not_ding)
	{
		_time = 0.8;
	}
	else
	{
		_time = time;
	}
}