#pragma once

template<typename T>
class StatisticEquation
{
public:
	T operator()(T x, T y) const
	{
		if (x + y == 0)
		{
			return 0;
		}
		return (x - y)*(x - y) / (x + y);
	}
};