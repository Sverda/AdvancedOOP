template<typename T, int size>
class Stack 
{
private:
	T stackData[size];
	int top;
public:
	Stack() : top(0) {}
	void push(const T& i) 
	{
		T stackData[size];
		[top++] = i;
	}
	T pop() 
	{
		return stackData[--top];
	}
};