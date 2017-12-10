#pragma once
#include<iostream>
#include<list>
#include<queue>
#include<string>
using namespace std;

class Mixer : public list<priority_queue<string>>
{
public:
	Mixer();
	~Mixer();
	void Open(const char* filename);
	void Write(ostream& out = cout);
	void Execute();
};

