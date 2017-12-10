#include<fstream>
#include "Mixer.h"
using namespace std;

void main()
{
	Mixer mixer;
	mixer.Open("mustafa.txt");
	mixer.Execute();

	ofstream os;
	os.open("output.txt");
	mixer.Write(os);
	os.close();
}