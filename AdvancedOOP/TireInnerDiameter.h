#pragma once
#include "Traits.h"
#include <ostream>
#include <iomanip>

class TireInnerDiameter
{
	int innerDiameter;
public:
	TireInnerDiameter(int inner_diameter = 10):innerDiameter(inner_diameter) { }
	int operator()() const { return innerDiameter; }

	TireInnerDiameter& TireInnerDiameter::operator=(int inner_diameter)
	{
		innerDiameter = inner_diameter;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, TireInnerDiameter& tire);
};

template<>
class Traits<TireInnerDiameter> : public BaseTraits
{
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const bool _jest_liczba_calkowita = true;
	static const int _dolna_granica_przedzialu = 10;
	static const int _gorna_granica_przedzialu = 24;
};
