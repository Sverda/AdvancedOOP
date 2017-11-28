#include<iostream>
#include<fstream>
#include<string>
#include "Dice.h"
#include "Stack.h"
#include "WaterTemp.h"
#include "Exceptions.h"
#include "CollarSizeNo.h"
#include "MicroSD.h"
#include "RadioFrequency.h"
#include "TireInnerDiameter.h"
using namespace std;

std::ostream& operator<<(std::ostream& os, TireInnerDiameter& tire)
{
	os.setf(std::ios::scientific);
	os.precision(Traits<TireInnerDiameter>::_numbers_after_point);
	os << tire();
	return os;
}

std::ostream& operator<<(std::ostream& os, MicroSD& micro_sd)
{
	os.setf(std::ios::scientific);
	os.precision(Traits<MicroSD>::_numbers_after_point);
	os << micro_sd();
	return os;
}

std::ostream& operator<<(std::ostream& os, const RadioFrequency& radio_frequency)
{
	os.setf(std::ios::scientific);
	os.precision(Traits<RadioFrequency>::_numbers_after_point);
	os << radio_frequency();
	return os;
}

int main()
{
	StockTemplate<MicroSD, 10> K5;
	StockTemplate<RadioFrequency, 10> K6;
	StockTemplate<TireInnerDiameter, 10> K7;

	// pushing values to stock
	K5.push(MicroSD(39));
	K5.push(MicroSD());
	K5.push(14);
	K5.push(26);
	cout << "Number of data on stock K5: " << K5.zajetosc() << endl;

	K6.push(RadioFrequency(39));
	K6.push(RadioFrequency());
	K6.push(14);
	K6.push(26);
	cout << "Number of data on stock K6: " << K6.zajetosc() << endl;

	K7.push(TireInnerDiameter(39));
	K7.push(TireInnerDiameter());
	K7.push(14);
	K7.push(26);
	cout << "Number of data on stock K7: " << K7.zajetosc() << endl;
	cout << endl;

	// Poping stock
	cout << "Printing stock K5's data: " << endl;
	try
	{
		while (true)
			cout << K5.pop() << endl;
	}
	catch (NoData& e)
	{
		cout << "K5 is empty: " << e.what() << endl;
	}
	cout << endl;

	cout << "Printing stock K6's data: " << endl;
	try
	{
		while (true)
			cout << K6.pop() << endl;
	}
	catch (NoData& e)
	{
		cout << "K6 is empty: " << e.what() << endl;
	}
	cout << endl;

	cout << "Printing stock K7's data: " << endl;
	try
	{
		while (true)
			cout << K7.pop() << endl;
	}
	catch (NoData& e)
	{
		cout << "K7 is empty: " << e.what() << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}
