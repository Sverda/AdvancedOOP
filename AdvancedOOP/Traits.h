#pragma once
#include "BaseTraits.h"

template <typename T>
class Traits : public BaseTraits
{
public:
	static const double dolna_granica_przedzialu() { return 0; };
	static const double gorna_granica_przedzialu() { return 0; };
};
