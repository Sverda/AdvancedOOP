#pragma once
#include <cassert>

using namespace std;

template<typename T> class Content
{
	enum { ssize = 100 };
	T stack[ssize];
	int top;
public:
	Content() : top(0) {}
	void push(T i);
	T pop();
	int rozmiar() { return top; }

	class iterator 
	{
		Content& s;
		int index;
	public:
		iterator(Content& is) : s(is), index(0) {}
		iterator(Content& is, bool) : s(is), index(s.top) {}

		T operator++();
		T operator++(int);
		T& operator*() const { return s.stack[index]; }
		iterator& operator=(const iterator& rv);
	};
	iterator begin() { return iterator(*this); }
	iterator end() { return iterator(*this, true); }

	friend class iterator;
};

template <typename T> void Content<T>::push(T i)
{
	assert(top < ssize);
	stack[top++] = i;
}

template <typename T> T Content<T>::pop()
{
	assert(top > 0);
	return stack[--top];
}

template <typename T> T Content<T>::iterator::operator++()
{
	// Prefix
	assert(index < s.top);
	return s.stack[++index];
}

template <typename T> T Content<T>::iterator::operator++(int)
{
	// Postfix
	assert(index < s.top);
	return s.stack[index++];
}

template <typename T> typename Content<T>::iterator& Content<T>::iterator::operator=(const iterator& rv)
{
	s = rv.s;
	index = rv.index;
	return *this;
}

