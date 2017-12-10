#pragma once
#include<iostream>
#include<list>
#include<queue>
#include<string>
#include "Grater_Queue.h"
using namespace std;

class Mixer : public list<String_Queue>
{
public:
	Mixer();
	Mixer(const char* filename);
	~Mixer();
	void Open(const char* filename);
	void Write(ostream& out = cout);
	void Execute();
};