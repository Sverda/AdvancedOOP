#pragma once
#include"Traits.h"
#include<iostream>
#include<limits>
using namespace std;

bool check_if_prime(int n);

class PrimeNumber
{
	int _number;
public:
	PrimeNumber(int number = 3);
	int operator()() const { return _number; }

	int get_number(){ return _number; }

	PrimeNumber& operator=(int number)
	{
		_number = number;
		return *this;
	}

	friend ostream& operator<<(ostream& os, PrimeNumber& number);
};

template <>
class Traits<PrimeNumber> : public BaseTraits
{
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const bool _jest_liczba_calkowita = true;
	static const int _dolna_granica_przedzialu = 0;
	static const int _gorna_granica_przedzialu = INT_MAX;
	static const bool _is_prime = true;
};

PrimeNumber::PrimeNumber(int number)
{
	if (number <= Traits<PrimeNumber>::_dolna_granica_przedzialu || number >= Traits<PrimeNumber>::_gorna_granica_przedzialu)
	{
		_number = 0;
	}
	else
	{
		_number = number;
	}

	if (check_if_prime(number))
	{
		_number = number;
	}
	else
	{
		_number = 3;
	}
}

bool check_if_prime(int n)
{
	if (n<2)
		return false; //gdy liczba jest mniejsza ni¿ 2 to nie jest pierwsz¹

	for (int i = 2; i*i <= n; i++)
		if (n%i == 0)
			return false; //gdy znajdziemy dzielnik, to dana liczba nie jest pierwsza
	return true;
}