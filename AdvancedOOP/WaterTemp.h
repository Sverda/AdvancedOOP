#pragma once
#include "Traits.h"

class temperatura_wody
{
	double t;
public:
	temperatura_wody(double temp = 50) : t(temp)
	{
	};
	double operator()() { return t; };

	temperatura_wody& operator=(double temp)
	{
		t = temp;
		return *this;
	};
};

template <>
class Cechy<temperatura_wody> : public Bazowe_Cechy
{
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const double dolna_granica_przedzialu() { return 0; };
	static const double gorna_granica_przedzialu() { return 100; };
};
