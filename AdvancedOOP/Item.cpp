#pragma once

template<typename T> class Item
{
public:
	Item(T _value) :value(_value), next(nullptr) {}
	~Item()
	{
		delete next;
	}
	T value;
	Item<T>* next;
	Item& operator=(const Item& rv)
	{
		value = rv.value;
	}
};