#pragma once
#include <string>
#include <queue>
#include <ctype.h>
#include "Grater_Queue.h"
using namespace std;

template <class T> struct Grater_Queue
{
	bool operator() (const T& x, const T& y) const
	{
		return x > y;
	};
	typedef T first_argument_type;
	typedef T second_argument_type;
	typedef bool result_type;
};

template <> struct Grater_Queue<std::string>
{
	bool operator()(const std::string& x, const std::string& y) const
	{
		bool x_is_first = false;
		for (int i = x.length() - 1; i >= 0; i--)
		{
			char lower_x = x[i];
			char lower_y = y[i];

			if (lower_x >= -1 && lower_x <= 255)
			{
				if (isalnum(x[i]) && isalpha(x[i]) && !isdigit(x[i]))
				{
					lower_x = tolower(lower_x);
				}
			}
			else
			{
				continue;
			}

			if (lower_y >= -1 && lower_y <= 255)
			{
				if (isalnum(x[i]) && isalpha(y[i]) && !isdigit(y[i]))
				{
					lower_y = tolower(lower_y);
				}
			}
			else
			{
				continue;
			}

			if (lower_x != lower_y)
			{
				x_is_first = lower_x < lower_y;
			}
		}
		return x_is_first;
	}
};

using String_Queue = std::priority_queue<std::string, std::vector<std::string>, Grater_Queue<std::string>>;