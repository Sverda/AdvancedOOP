#pragma once
#include <string>

template <class T> struct Grater 
{
	bool operator() (const T& x, const T& y) const 
	{
		return x > y;
	};
	typedef T first_argument_type;
	typedef T second_argument_type;
	typedef bool result_type;
};

template <> struct Grater<std::string>
{
	bool operator()(const std::string& x, const std::string& y) const
	{
		return x.size() < y.size();
	}
};