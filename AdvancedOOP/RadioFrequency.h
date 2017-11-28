#pragma once
#include"Traits.h"
#include <ostream>
#include <iomanip>

class RadioFrequency
{
	double frequency;
public:
	RadioFrequency(double _frequency = 88.0):frequency(_frequency) {}
	double operator()() const { return  frequency; }
	
	RadioFrequency& RadioFrequency::operator=(double _frequency)
	{
		frequency = _frequency;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const  RadioFrequency& radio_frequency);
};

template<>
class Traits<RadioFrequency> : public BaseTraits
{
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const bool _jest_liczba_calkowita = false;
	static const int _dolna_granica_przedzialu = 88;
	static const int _gorna_granica_przedzialu = 108;
	static const int _numbers_after_point = 2;
};