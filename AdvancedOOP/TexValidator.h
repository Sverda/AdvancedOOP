#pragma once
#include<string>
#include<stack>
using namespace std;

class TexValidator
{
private:
	int line;
	stack<string> texTags;
public:
	TexValidator();
	~TexValidator();
	void Validate(ifstream &file);
	void EmptyStack();
	void AnalyzeTag(ifstream &file);
};

