#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include"Template.h"
#include"Dane.h"
#define SIZE 3
using namespace std;


void raport(Tablica<Dane, SIZE> &tab, string filename, ios_base::fmtflags ioflag);
int main()
{
	string filename;
	filename = "file.txt";
	//cin >> filename;

	Tablica<Dane, SIZE> dane;
	for (int i = 0; i < SIZE; i++)
	{
		dane[i].id = i;
		strcpy(dane[i].nazwa, "name");
		dane[i].pojemn = i;
		dane[i].temp = i * 10;
	}

	raport(dane, filename, ios::out);

	return 0;
}

void raport(Tablica<Dane, SIZE> &tab, string filename, ios_base::fmtflags ioflag)
{
	if (ioflag != ios::out)
		return;
	fstream stream;
	stream.open(filename, ioflag);
	//time
	time_t now = time(0);
	tm *gmtm = gmtime(&now);
	char* dt = asctime(gmtm);
	//formatting
	//stream.setf(ios::right);
	stream.width(40);
	stream << dt << "\n\n";
	stream << getenv("COMPUTERNAME");
	stream << "\n+------+----------+-------+------+" << endl;
	stream << "| ID | nazwa | temp. |pojemn|" << endl;
	stream << "+------+----------+-------+------+" << endl;
	Dane last;
	last.pojemn = 0;
	last.temp = 0;
	strcpy(last.nazwa, " ");
	last.id = 0;
	for (int i = 0; i < SIZE; i++)
	{
		stream << tab[i];
		last += tab[i];
	}
	stream << "+------+----------+-------+------+" << endl;
	stream << last;
	stream << "+------+----------+-------+------+" << endl;
	stream.close();
}