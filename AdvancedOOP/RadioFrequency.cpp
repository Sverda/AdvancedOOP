#pragma once
#include"Traits.h"

class RadioFrequency
{
	double frequency;
public:
	RadioFrequency(double _frequency):frequency(_frequency) {}
	double operator()() const { return  frequency; }
	RadioFrequency& operator=(double _frequency);
};

RadioFrequency& RadioFrequency::operator=(double _frequency)
{
	frequency = _frequency;
	return *this;
}


template<>
class Traits<RadioFrequency> : public BaseTraits
{
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const bool _jest_liczba_calkowita = false;
	static const int _dolna_granica_przedzialu = 0;
	static const int _gorna_granica_przedzialu = 0;
};