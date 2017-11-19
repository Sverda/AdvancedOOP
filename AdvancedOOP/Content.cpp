#pragma once
#include <cassert>
#include "Item.cpp"
using namespace std;

template<typename T> class Content
{
	Item<T>* head;
	Item<T>* next;
	int top;
public:
	Content() :top(0) { head = nullptr; next = nullptr; }
	~Content() { delete head; }
	void push(T i);
	T pop();
	int rozmiar() { return top; }

	class iterator
	{
		Content& s;
		int index;
	public:
		iterator(Content& is) : s(is), index(0) 
		{
		}
		iterator(Content& is, bool) : s(is), index(s.top) 
		{
		}

		T operator++();	// Prefix
		T operator++(int);	// Postfix
		T& operator*() const;
		iterator& operator=(const iterator& rv);
		bool operator==(const iterator& rv) const;
		bool operator!=(const iterator& rv) const;
		void ResetToEnd() { index = s.top; }
		void ResetToBegin() { index = 0; }
	};
	iterator begin() { return iterator(*this); }
	iterator end() { return iterator(*this, true); }

	friend class iterator;
};

template <typename T> void Content<T>::push(T i)
{
	//assert(top < rozmiar());
	if (head == nullptr)
	{
		head = new Item<T>(i);
		next = head;
	}
	else
	{
		next->next = new Item<T>(i);
		next = next->next;
	}
	top++;
}

template <typename T> T Content<T>::pop()
{
	//assert(top > 0);
	top--;
	Item<T>* pom = next;
	next = head;
	// finding pre-last element
	while (next->next != nullptr)
	{
		if (next->next->next == nullptr)
		{
			next = next->next;
			next->next = nullptr;
			break;
		}
		next = next->next;
	}
	return pom;
}

// Iterator's methods

template <typename T> T Content<T>::iterator::operator++()
{
	// Prefix
	//assert(index < s.top);
	index++;
	Item<T>* item = s.head;
	for (int i = 0; i < index - 1; i++)
	{
		item = item->next;
	}
	return item->value;
}

template <typename T> T Content<T>::iterator::operator++(int)
{
	// Postfix
	//assert(index < s.top);
	index++;
	Item<T>* item = s.head;
	for (int i = 0; i < index - 1; i++)
	{
		item = item->next;
	}
	return item->value;
}

template <typename T> typename Content<T>::iterator& Content<T>::iterator::operator=(const iterator& rv)
{
	s = rv.s;
	index = rv.index;
	return *this;
}

template <typename T> T& Content<T>::iterator::operator*() const
{
	Item<T>* item = s.head;
	for (int i = 0; i < index; i++)
	{
		item = item->next;
	}
	return item->value;
}

template <typename T> bool Content<T>::iterator::operator==(const iterator& rv) const
{
	return index == rv.index;
}

template <typename T> bool Content<T>::iterator::operator!=(const iterator& rv) const
{
	return index != rv.index;
}