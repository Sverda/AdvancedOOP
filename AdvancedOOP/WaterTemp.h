#pragma once
#include "Traits.h"

class WaterTemp
{
	double t;
public:
	WaterTemp(double temp = 50) : t(temp) { }
	double operator()() const { return t; }

	WaterTemp& operator=(double temp);
};

WaterTemp& WaterTemp::operator=(double temp)
{
	t = temp;
	return *this;
}

template <>
class Traits<WaterTemp> : public BaseTraits
{
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const double dolna_granica_przedzialu() { return 0; };
	static const double gorna_granica_przedzialu() { return 100; };
};
