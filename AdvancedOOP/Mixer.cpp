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
	for (iterator i = this->begin(); i != this->end(); ++i)
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

			if (word.length() == 0)
			{
				continue;
			}

			//check whether there is queue with proper word length
			bool queue_exist = false;
			for (iterator i = this->begin(); i != this->end(); i++)
			{
				String_Queue queue = *i;
				string queue_word = queue.top();

				if (queue_word.length() == word.length())	//proper queue exist
				{
					i->push(word);
					queue_exist = true;
				}
			}
			if (!queue_exist)
			{
				String_Queue new_queue;
				new_queue.push(word);
				this->push_back(new_queue);
			}

		} while (stringstream);
	}

	filestream.close();
}

ostream& operator<<(ostream& os, String_Queue& queue)
{
	os << queue.top().length() << ": ";
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