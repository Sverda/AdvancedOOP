#pragma once
#include "Traits.h"

class CollarSizeNo
{
	int sizeNumber;
public:
	CollarSizeNo():sizeNumber(40) {}
	CollarSizeNo(int _sizeNumber):sizeNumber(_sizeNumber) {}
	int operator()() { return sizeNumber; }
	CollarSizeNo& operator=(int _sizeNumber);
};

inline CollarSizeNo& CollarSizeNo::operator=(int _sizeNumber)
{
	sizeNumber = _sizeNumber;
	return *this;
}

template<>
class Cechy<CollarSizeNo> : public BaseTraits
{
public:
	static const bool _jest_liczba = true;
	static const bool _jest_liczba_calkowita = true;
	static const bool _nalezy_do_przedzialu = true;
	static const double dolna_granica_przedzialu() { return 37; }
	static const double gorna_granica_przedzialu() { return 48; }
};