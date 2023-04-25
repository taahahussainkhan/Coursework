#pragma once
#include<iostream>
using namespace std;

class Array {
protected:
	int* arr;
	int maxSize;
	int currentSize;

public:
	virtual void addValue(int) = 0; //pure virtual function
	virtual int removeValue() = 0;
	virtual void display()=0;

};