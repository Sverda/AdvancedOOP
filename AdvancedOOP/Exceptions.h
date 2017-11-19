#pragma once

class Overflow : public std::exception
{
	char opis[100];
public:
	Overflow(const char* o) { strcpy_s(opis, o); }
	const char* what() const throw() { return opis; }; // "const throw()" promises this function don't throw anything
};

class NoData : public std::exception
{
	char opis[100];
public:
	NoData(const char* o) { strcpy_s(opis, o); }
	const char* what() const throw() { return opis; };
};
