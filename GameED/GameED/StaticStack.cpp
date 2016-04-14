#include "StaticStack.h"


template<class T>
StaticStack<T>::StaticStack()
{
	node = new T[DEFAULTSIZE];
	top = -1;
	max = DEFAULTMAX - 1;
}

template<class T>
StaticStack<T>::StaticStack(int size)
{
	node = new T[size];
	top = -1;
	max = size - 1;
}

template<class T>
StaticStack<T>::~StaticStack()
{
	if (node != nullptr)
		delete[] node;
}

template<class T>
bool StaticStack<T>::push(T item)
{
	if (top < size)
	{
		top++;
		node[top] = item;
		return true;
	}
	else
		return false;
}

template<class T>
T StaticStack<T>::pop()
{
	if (top >= 0)
	{
		int temp = top;
		top--;
		return node[temp];
	}
}

template<class T>
bool StaticStack<T>::isFull()
{
	if (top == max)
		return true;
	else
		return false;
}

template<class T>
bool StaticStack<T>::isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

template<class T>
T StaticStack<T>::getTop()
{
	return node[top];
}
