#pragma once

template<typename T, int size>
class Stack {
	T stackData[size];
	int top;
public:
	Stack() : top(0) {}
	void push(const T& i) 
	{
		stackData[top++] = i;
	}
	T pop() 
	{
		return stackData[--top];
	}
};