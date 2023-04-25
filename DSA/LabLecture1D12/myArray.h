#pragma once
#include "Array.h"

class myArray : public Array {

private:
	int temp;

public:
	myArray();
	void addValue(int);
	int removeValue();
	void display();
	void setValue(int v); //setter
	int getValue(); //getter

};

myArray::myArray() {

	maxSize = 10;
	currentSize = 0;
	arr = new int[maxSize];
}

void myArray::display() {

	for (int i = 0; i < currentSize;i++) {
		cout << arr[i]<<endl;
	}
	
}

int myArray::removeValue() {
	int myVal = arr[currentSize-1];
	currentSize--;
	cout << "value has been removed";


	return myVal;
}

void myArray::addValue(int value) {

	arr[currentSize] = value;
	currentSize++;
	cout << "Value has been added";
}

void myArray::setValue(int v) {
	temp = v;
}

int myArray::getValue() {

	return temp;
}
