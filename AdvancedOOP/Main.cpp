#include<iostream>
#include "Mixer.h"
using namespace std;

void main()
{
	Mixer mixer;
	mixer.Open("mustafa.txt");
	mixer.Execute();
	mixer.Write();
}