#pragma once

struct Dane {
	int id;
	char nazwa[10];
	double temp;
	double pojemn;

	Dane& operator+=(const Dane& rv) {
		temp += rv.temp;
		pojemn += rv.pojemn;
		return *this;
	};

};


ostream& operator << (ostream & b, const Dane & p)
{
	b << '|';
	b.width(6);
	b.fill('0');
	b.setf(ios::right);
	b << p.id;
	b.unsetf(ios::right);

	b << '|';
	b.width(10);
	b.fill(' ');
	b.setf(ios::left);
	b << p.nazwa;
	b << '|';
	b.unsetf(ios::left);

	b.setf(ios::right);
	b.width(7);
	b.precision(1);
	b.setf(ios::fixed);
	b << p.temp;
	b << '|';

	b.width(6);
	b.precision(0);
	b << p.pojemn;
	b << '|';

	return  b << endl;
}