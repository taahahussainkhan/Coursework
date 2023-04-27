#pragma once
#include <iostream>
using namespace std;

template <class T>
class Stack
{
protected:
	T* arr;
	int maxSize;
	int currentSize;
public:
	virtual void push(T) = 0; // push Value
	virtual bool isFull() = 0;
	T Sum();
	Stack(int);
};

template <class T>
Stack<T>::Stack(int s)
{
	arr = new T[s];
	currentSize = 0;
	maxSize = s;
}