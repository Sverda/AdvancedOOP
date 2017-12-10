#include<iostream>
#include "Mixer.h"
using namespace std;

void Main()
{
	Mixer mixer;
	mixer.Open("mustafa.txt");
	mixer.Execute();
	mixer.Write();
}