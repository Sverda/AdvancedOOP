#include"TexValidator.h"
#include"Tags.h"
#include<fstream>
#include<iostream>
#include"Stack.h"
#include"NoOpenTagException.h"
#include"NoCloseTagException.h"
#include"NoMatchedTagException.h"
#include"NoItemTagException.h"


TexValidator::TexValidator()
{
	line = 0;
}


TexValidator::~TexValidator()
{
}

void TexValidator::Validate(ifstream &file)
{
	const int size = 100;
	char tag[size];
	string firsTag;
	try
	{
		//handling first and last tags
		while (file.getline(tag, size))
		{
			if (firsTag == "")
			{
				if (tag == Tags::OpenTagEnum || tag == Tags::OpenTagItem)
				{
					firsTag = tag;
					continue;
				}
				throw NoOpenTagException();
			}
			string line = tag;
			if (line.find(Tags::ItemTag) != string::npos)
			{
				continue;
			}
			else if (line.find("\\i") != string::npos)
			{
				throw NoItemTagException();
			}
			texTags.push(tag);
		}
		if (texTags.top() == Tags::OpenTagEnum)
		{
			if (texTags.top() != Tags::EndTagEnum)
			{
				EmptyStack();
				throw NoCloseTagException();
			}
		}
		else if (texTags.top() == Tags::OpenTagItem)
		{
			if (texTags.top() != Tags::EndTagItem)
			{
				EmptyStack();
				throw NoCloseTagException();
			}
		}
		else
		{
			texTags.pop();
		}
		//handling rest tags
		while (!texTags.empty())
		{
			string last = texTags.top();
			texTags.pop();
			if (texTags.empty())
			{
				throw NoCloseTagException();
			}
			string first = texTags.top();
			texTags.pop();
			if (last == Tags::EndTagEnum && first != Tags::OpenTagEnum)
			{
				throw NoMatchedTagException();
			}
			if (last == Tags::EndTagItem && first != Tags::OpenTagItem)
			{
				throw NoMatchedTagException();
			}
		}

	}
	catch (NoOpenTagException)
	{
		cout << "NoOpenTag" << endl;
	}
	catch (NoCloseTagException)
	{
		cout << "NoCloseTag" << endl;
	}
	catch (NoMatchedTagException)
	{
		cout << "NoMatchedTag" << endl;
	}
	catch (NoItemTagException)
	{
		cout << "NoItemTag" << endl;
	}
}

void TexValidator::EmptyStack()
{
	while (!texTags.empty())
	{
		texTags.pop();
	}
}

void TexValidator::AnalyzeTag(ifstream &file)
{

}
