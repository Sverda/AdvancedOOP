#include<iostream>
#include<fstream>
#include<string>
#include "Dice.h"
#include "Stack.h"
#include "WaterTemp.h"
#include "Exceptions.h"
using namespace std;


int main() {
	SzablonStosu<string, 5> K1;
	SzablonStosu<temperatura_wody, 10> K2;
	SzablonStosu<kostka_do_gry, 10> K3;

	// zape�nianie stosu
	ifstream fi("qv-lab4.txt");
	string s;
	try {
		K1.push("Henryk");
		K1.push("Sienkiewicz");
		while (fi) {
			fi >> s;
			K1.push(s);
			fi.seekg(ios::beg);
			fi.clear();
			cout << '*';
		};
	}
	catch (Przepelnienie& e) {
		cout << "K1 gotowy: " << e.what() << endl;
	};
	cout << "Danych na stosie K1: " << K1.zajetosc() << endl;

	K2.push(temperatura_wody());
	K2.push(temperatura_wody(36.6));
	K2.push(40);
	K2.push(71.2);
	cout << "Danych na stosie K2: " << K2.zajetosc() << endl;

	K3.push(kostka_do_gry(3));
	K3.push(kostka_do_gry());
	K3.push(4);
	K3.push(6);
	K3.push(10);
	cout << "Danych na stosie K3: " << K3.zajetosc() << endl;

	// opr�nianie stosu
	try {
		while (true)
			K1.pop();
	}
	catch (BrakDanych& e) {
		cout << "K1 pusty: " << e.what() << endl;
	}
	try {
		while (true)
			K2.pop();
	}
	catch (BrakDanych& e) {
		cout << "K2 pusty: " << e.what() << endl;
	}
	try {
		while (true)
			K3.pop();
	}
	catch (BrakDanych& e) {
		cout << "K3 pusty: " << e.what() << endl;
	}

	system("pause");
	return 0;
}