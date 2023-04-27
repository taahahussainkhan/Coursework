#pragma once
#include "Stack.h"

template <class T>
class MyStack :public Stack<T>
{
public:
	void push(T);		//addValue
	T Sum();
	MyStack(int s);
	bool isFull();
};

template <class T>
bool MyStack<T>::isFull()
{
	return Stack<T>::currentSize == Stack<T>::maxSize;
}

template <class T>
MyStack<T>::MyStack(int s) :Stack<T>(s)
{

}

template <class T>
void MyStack<T>::push(T v)
{
	if (isFull())
		cout << "Stack is Full" << endl;

	else
	{
		Stack<T>::arr[Stack<T>::currentSize] = v;
		Stack<T>::currentSize++;
	}
}


template <class T>
T MyStack<T>::Sum()
{
	int sum = 0;
	for (int i = 0; i < Stack<T>::currentSize; i++)
	{
		sum += Stack<T>::arr[i];
	}
	return sum;
}