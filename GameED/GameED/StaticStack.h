#pragma once
#define DEFAULTSIZE 10;

template <class T>
class StaticStack
{
public:
	StaticStack();
	StaticStack(int);

	~StaticStack();

	bool push(T);
	T pop();

	bool isFull();
	bool isEmpty();

	T getTop();

private:
	T * node;
	int top;
	int max;
};

