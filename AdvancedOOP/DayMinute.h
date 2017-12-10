#pragma once
#include"Traits.h"
#include<iostream>
using namespace std;

class DayMinute
{
	int _minute;
public:
	DayMinute(int minute = 0);
	int operator()() const { return _minute; }

	int get_minute(){ return _minute; }

	DayMinute& operator=(int minute)
	{
		_minute = minute;
		return *this;
	}

	friend ostream& operator<<(ostream& os, DayMinute& day_minute);
};

template <>
class Traits<DayMinute> : public BaseTraits
{
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const bool _jest_liczba_calkowita = true;
	static const int _dolna_granica_przedzialu = 0;
	static const int _gorna_granica_przedzialu = 1439;
};

DayMinute::DayMinute(int minute)
{
	if (minute <= Traits<DayMinute>::_dolna_granica_przedzialu || minute >= Traits<DayMinute>::_gorna_granica_przedzialu)
	{
		_minute = 0;
	}
	else
	{
		_minute = minute;
	}
}