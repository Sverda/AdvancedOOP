#pragma once
#include <string>
using namespace std;

class RpnCalc
{
private:
	string equation;
	double result;
	void calculate();
public:
	RpnCalc();
	~RpnCalc();
};

