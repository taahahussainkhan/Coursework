//Taaha Hussain Khan
//L1F21BSCS0917
//D12
#include <iostream>
#define SIZE 25
using namespace std;
template<class type>
class Queue
{
protected:
	type* arr;
	int currentSize;
	int maxSize;
public:
	Queue(int s)
	{
		currentSize = 0;
		maxSize = s;
		arr = new type[maxSize];
	}
	virtual void enQueue(type) = 0;
	virtual type deQueue() = 0;
};

template<class type>
class myQueue : public Queue<type>
{
public:
	myQueue(int s) : Queue<type>(s)
	{
		//Already values
		Queue<type>::arr[0] = 10;
		Queue<type>::arr[1] = 9;
		Queue<type>::arr[2] = 30;
		Queue<type>::arr[3] = 45;
		Queue<type>::arr[4] = 50;
		Queue<type>::arr[5] = 100;
		Queue<type>::arr[6] = 56;

	}
	virtual void enQueue(type value)
	{
		this->arr[this->currentSize] = value;
		this->currentSize++;
	}
	virtual type deQueue()
	{
		if (this->currentSize == 0) {
			cout << "The Queue is empty!!!"<<endl;
		}
		type t = this->arr[0];
		for (int i = 0; i < this->currentSize - 1; i++)
		{
			this->arr[i] = this->arr[i + 1];
		}
		this->currentSize--;
		return t;
	}
	int getCurrentSize()
	{
		return this->currentSize;
	}
	void display()
	{
		cout << "Queue : ";
		for (int i = 0; i < this->currentSize; i++)
		{
			cout << this->arr[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	myQueue <int> obj(SIZE);
	obj.enQueue(45);
	obj.enQueue(100);
	obj.enQueue(95);
	obj.enQueue(78);
	obj.enQueue(88);
	obj.enQueue(35);
	obj.enQueue(36);

	bool found = false;
	while (obj.getCurrentSize() > 0)
	{
		if (obj.deQueue() == 88)
		{
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "Element not found"<<endl;
	}
	obj.display();
	cout << "Current Size of the Queue: " << obj.getCurrentSize() << endl;
	return 0;
}
