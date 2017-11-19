#include<iostream>
#include<fstream>
#include<string>
#include "Dice.h"
#include "Stack.h"
#include "WaterTemp.h"
#include "Exceptions.h"
#include "CollarSizeNo.h"
using namespace std;


int main()
{
	StockTemplate<string, 5> K1;
	StockTemplate<WaterTemp, 10> K2;
	StockTemplate<Dice, 10> K3;
	StockTemplate<CollarSizeNo, 10> K4;

	// pushing values to stock
	ifstream fi("qv-lab4.txt");
	string s;
	try
	{
		K1.push("Henryk");
		K1.push("Sienkiewicz");
		while (fi)
		{
			fi >> s;
			K1.push(s);
			fi.seekg(ios::beg);
			fi.clear();
			cout << '*';
		};
	}
	catch (Overflow& e)
	{
		cout << "K1 is ready: " << e.what() << endl;
	}
	cout << "Number of data on stock K1: " << K1.zajetosc() << endl;

	K2.push(WaterTemp());
	K2.push(WaterTemp(36.6));
	K2.push(40);
	K2.push(71.2);
	cout << "Number of data on stock K2: " << K2.zajetosc() << endl;

	K3.push(Dice(3));
	K3.push(Dice());
	K3.push(4);
	K3.push(6);
	K3.push(10);
	cout << "Number of data on stock K3: " << K3.zajetosc() << endl;

	K4.push(CollarSizeNo(39));
	K4.push(CollarSizeNo());
	K3.push(14);
	K3.push(26);
	cout << "Number of data on stock K4: " << K4.zajetosc() << endl;

	// Poping stock
	try
	{
		while (true)
			K1.pop();
	}
	catch (NoData& e)
	{
		cout << "K1 is empty: " << e.what() << endl;
	}
	try
	{
		while (true)
			K2.pop();
	}
	catch (NoData& e)
	{
		cout << "K2 is empty: " << e.what() << endl;
	}
	try
	{
		while (true)
			K3.pop();
	}
	catch (NoData& e)
	{
		cout << "K3 is empty: " << e.what() << endl;
	}
	try
	{
		while (true)
			K4.pop();
	}
	catch (NoData& e)
	{
		cout << "K4 is empty: " << e.what() << endl;
	}

	system("pause");
	return 0;
}
