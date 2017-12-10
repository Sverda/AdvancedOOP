#include "Mixer.h"
#include<fstream>
#include<sstream>
#include<string>
#include<queue>
#include "Grater_Queue.h"
#include "Less_List.h"
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
	for(iterator i = this->begin(); i != this->end(); ++i)
	{
		while (!i->empty())
		{
			i->pop();
		}
	}
}

void Mixer::Open(const char* filename)
{
	ifstream filestream;
	filestream.open(filename);

	string sline;
	String_Queue qline;
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

		//<test>
		/*do
		{
			cout << qline.top() << " ";
			qline.pop();
		}
		while (!qline.empty());*/
		//</test>

		this->push_back(qline);

		while (!qline.empty())
			qline.pop();
	}

	filestream.close();
}

ostream& operator<<(ostream& os, String_Queue& queue)
{
	os << queue.size() << ": ";
	while (!queue.empty())
	{
		os << queue.top() << " ";
		queue.pop();
	}
	os << endl;
	return os;
}

void Mixer::Write(ostream& out)
{
	for (iterator i = this->begin(); i != this->end(); ++i)
	{
		out << *i << endl;
	}
}

void Mixer::Execute()
{
	this->sort(Less_List<String_Queue>());
}