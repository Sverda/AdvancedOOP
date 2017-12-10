#pragma once
#include <string>
#include <queue>
#include "Grater_Queue.h"

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
		return x.size() < y.size();
	}
};

using String_Queue = std::priority_queue<std::string, std::vector<std::string>, Grater_Queue<std::string>>;