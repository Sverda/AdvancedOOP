#pragma once
#include<iostream>
#include<list>
#include<queue>
#include<string>
#include "Grater.h"
using namespace std;

class Mixer : public list<priority_queue<string, vector<string>, Grater<string>>>
{
public:
	Mixer();
	Mixer(const char* filename);
	~Mixer();
	void Open(const char* filename);
	void Write(ostream& out = cout);
	void Execute();
};