#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int circle, rectangle, triangle, cylinder;
	cout << "1.Area of Circle" << endl;
	cout << "2.Area of Rectangle" << endl;
	cout << "3.Area of Triangle" << endl;
	cout << "4.Area of Cylinder" << endl;
	int choice;
	cout << endl;
	cout << endl;
	cout << "Enter your choice" << endl;
	cin >> choice;
	
	if (choice == 1 || choice == 2)
	{

		if (choice == 1)
		{
			int radius;
			cout << "Enter Radius : ";
			cin >> radius;
			cout << "Area of Circle = " << 3.14159*radius*radius << endl;
		}
		if (choice == 2)
		{
			int length, width;
			cout << "Enter Length : ";
			cin >> length;
			cout << "Enter Width : ";
			cin >> width;
			cout << "Area of Rectangle = " << length*width << endl;
		}
		else
		{
			cout << "Invalid Choice Try Again....!!!" << endl;
		}
	}
	if (choice == 3 || choice == 4)
	{
		if (choice == 3)
		{
			int s, a, b, c;
			cout << "Enter 1st angle : ";
			cin >> a;
			cout << "Enter 2nd angle : ";
			cin >> b;
			cout << "Enter 3rd angle : ";
			cin >> c;
			s = a + b + c / 2;


			cout << "Area of Triangle = " << sqrt(s*(s - a) *(s - b) *(s - c)) << endl;
		}
		if (choice == 4)
		{
			int rad, height;
			cout << "Enter Radius : ";
			cin >> rad;
			cout << "Enter Hieght : ";
			cin >> height;
			cout << "Area of Cylinder = " << 2 * 3.14159*rad*height + 2 * 3.14159*rad*rad << endl;
		}
		else
		{
			cout << "Invalid Choice Try Again....!!!" << endl;
		}
	}
	

	return 0;

}