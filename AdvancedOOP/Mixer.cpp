#include "Mixer.h"
#include<fstream>
#include<sstream>
#include<string>
#include<queue>
#include "Grater.h"
using namespace std;


Mixer::Mixer()
{
}

Mixer::Mixer(const char* filename)
{
	Open(filename);
}


Mixer::~Mixer()
{
}

void Mixer::Open(const char* filename)
{
	ifstream filestream;
	filestream.open(filename);

	string sline;
	priority_queue<string, vector<string>, Grater<string>> qline;
	while (!filestream.eof())
	{
		getline(filestream, sline);
		if (sline.empty())
			continue;

		//iterating through each word in line and insert it into queue
		istringstream stringstream(sline);
		do
		{
			string word;
			stringstream >> word;
			qline.push(word);

		} while (stringstream);

		this->push_back(qline);

		while (qline.empty())
			qline.pop();
	}

	filestream.close();
}

void Mixer::Write(ostream& out)
{
}

void Mixer::Execute()
{
}
