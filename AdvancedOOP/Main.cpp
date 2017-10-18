#include<fstream>
#include<iostream>
#include"TexValidator.h"
using namespace std;

void main()
{
	string fname = "List2.txt";
	ifstream file;
	TexValidator valid;

	file.open(fname);
	valid.Validate(file);
	file.close();
}