#include<iostream>
#include"DayMinute.h"
#include"Dice.h"
#include"Ding.h"
#include"BeerPint.h"
#include"PrimeNumber.h"
#include"Stack.h"
using namespace std;

std::ostream& operator<<(std::ostream& os, Ding& ding)
{
	//os.setf(std::ios::fixed);
	os.precision(Traits<Ding>::_numbers_after_point + 1);
	os << ding();
	return os;
}

std::ostream& operator<<(std::ostream& os, BeerPint& beer_pint)
{
	//os.setf(std::ios::scientific);
	os.precision(Traits<BeerPint>::_numbers_after_point + 1);
	os << beer_pint();
	return os;
}

std::ostream& operator<<(std::ostream& os, PrimeNumber& number)
{
	//os.setf(std::ios::scientific);
	os.precision(Traits<PrimeNumber>::_numbers_after_point + 1);
	os << number();
	return os;
}

std::ostream& operator<<(std::ostream& os, DayMinute& day_minute)
{
	//os.setf(std::ios::scientific);
	os.precision(Traits<DayMinute>::_numbers_after_point + 1);
	os << day_minute();
	return os;
}

int main()
{
	//DayMinute
	StockTemplate<DayMinute, 10> K1;
	K1.push(-4);
	K1.push(0);
	K1.push(11);
	K1.push(DayMinute(1000));
	K1.push(DayMinute(1440));
	K1.push(8888);
	cout << "Number of data on stock K1: " << K1.zajetosc() << endl;
	cout << "Printing stock K1's data: " << endl;
	try
	{
		while (true)
			cout << K1.pop() << endl;
	}
	catch (NoData& e)
	{
		cout << "K1 is empty: " << e.what() << endl;
	}
	cout << endl;

	//Ding
	StockTemplate<Ding, 10> K2;
	K2.push(0);
	K2.push(0.8);
	K2.push(2);
	K2.push(Ding(8));
	K2.push(Ding(10.8));
	K2.push(20.8);
	K2.push(21);
	K2.push(22.8);
	K2.push(24.8);
	cout << "Number of data on stock K2: " << K2.zajetosc() << endl;
	cout << "Printing stock K2's data: " << endl;
	try
	{
		while (true)
			cout << K2.pop() << endl;
	}
	catch (NoData& e)
	{
		cout << "K2 is empty: " << e.what() << endl;
	}
	cout << endl;

	//BeerPint
	StockTemplate<BeerPint, 10> K3;
	K3.push(0);	//bad
	K3.push(0.5666);	//bad
	K3.push(0.568);	//good
	K3.push(BeerPint(0.570));	//bad
	K3.push(BeerPint(1.704));	//good
	cout << "Number of data on stock K3: " << K3.zajetosc() << endl;
	cout << "Printing stock K3's data: " << endl;
	try
	{
		while (true)
			cout << K3.pop() << endl;
	}
	catch (NoData& e)
	{
		cout << "K3 is empty: " << e.what() << endl;
	}
	cout << endl;

	//Prime
	StockTemplate<PrimeNumber, 10> K4;
	K4.push(-5);
	K4.push(0);
	K4.push(1);
	K4.push(2);
	K4.push(3);
	K4.push(4);
	K4.push(PrimeNumber(8));
	K4.push(PrimeNumber(11));
	cout << "Number of data on stock K4: " << K4.zajetosc() << endl;
	cout << "Printing stock K4's data: " << endl;
	try
	{
		while (true)
			cout << K4.pop() << endl;
	}
	catch (NoData& e)
	{
		cout << "K4 is empty: " << e.what() << endl;
	}
	cout << endl;
}