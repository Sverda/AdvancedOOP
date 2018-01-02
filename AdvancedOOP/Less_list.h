#pragma once
#include "Grater_Queue.h"

template <class T>
struct Less_List
{
	bool operator() (const T& x, const T& y) const
	{
		return x < y;
	}
};

template<>
struct Less_List<String_Queue>
{
	bool operator() (const String_Queue& x, const String_Queue& y) const
	{
		return x.top().length() < y.top().length();
	}
};