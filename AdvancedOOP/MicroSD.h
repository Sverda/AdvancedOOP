#pragma once
#include "Traits.h"
#include <ostream>
#include <iomanip>

class MicroSD
{
	int _size;
public:
	MicroSD(int size = 0): _size(size) {}
	int operator()() const { return  _size; }

	MicroSD& MicroSD::operator=(int size)
	{
		_size = size;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, MicroSD& micro_sd);
};

template<>
class Traits<MicroSD> : public BaseTraits
{
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const bool _jest_liczba_calkowita = true;
	static const int _dolna_granica_przedzialu = 0;
	static const int _gorna_granica_przedzialu = 128;
	static const bool _is_power_of_2 = true;
};