/*										Assignment 4

Write a simple function template for predicate function isEqualTo that compares its two arguments of the same type with the equality operator (==) and returns true if they are equal and false otherwise. Use this function template in a program that calls isEqualTo only with a variety of fundamental types. Now write a separate version of the program that calls isEqualTo with a user-defined class type, but does not overload the equality operator. What happens when you attempt to run this program? Now overload the equality operator (with the operator function) operator==.Now what happens when you attempt to run this program?

For user-defined type, you can use this class given below:
Class student
{
	int age;
	double weight;
};

Make its constructor as needed and work on the functionality explained in the task given in original statement.
*/
#include<iostream>
#include<string>
using namespace std;
template <typename type1>
bool isEqualTo(type1 arg1, type1 arg2)
{
	if (arg1 == arg2)
		return true;
	else
		return false;
}
class Person{
private:
	int age;
	char* name;
	int length = 0;
public:
	Person(){

	}
	Person(int age, char* name)
	{
		this->age = age;
	
		while (name[length] != '\0')
			length++ ;
		this->name = new char[length + 1];
		for (int i = 0; i < length; i++)
			this->name[i] = name[i];
	}
	bool operator==(const Person &obj)const
	{
		int check = 1;
		if (age == obj.age){
			for (int i = 0; i < length; i++)
			{
				if (name[i] == obj.name[i])
					check = 1;
				else
					check = 0;
			}
		}
		
		if (check == 1)
			return true;
		else
			return false;

	}
};
int main()
{
	int i1, i2;
	cout << "Enter two integare numbers to compare. "<<endl;
	cout << "integar 1: ";
	cin >> i1;
	cout << "integar 2: ";
	cin >> i2;
	if (isEqualTo<int>(i1, i2) == true)
		cout << i1 << " and " << i2 << " are equal! " << endl;
	else
		cout << i1 << " and " << i2 << " are not equal! " << endl;
	float f1, f2;
	cout << "Enter two float numbers to compare. "<<endl;
	cout << "float 1: ";
	cin >> f1;
	cout << "float 2: ";
	cin >> f2;
	if (isEqualTo<float>(f1, f2) == true)
		cout << f1 << " and " << f2 << " are equal! " << endl;
	else
		cout << f1 << " and " << f2 << " are not equal! " << endl;
		
	char c1, c2;
	cout << "Enter two charactars to compare. "<<endl;
	cout << "charactar 1: ";
	cin >> c1;
	cout << "charactar 2: ";
	cin >> c2;
	if (isEqualTo<char>(c1, c2) == true)
		cout << c1 << " and " << c2 << " are equal! " << endl;
	else
		cout << c1 << " and " << c2 << " are not equal! " << endl;

	string s1, s2;
	cout << "Enter two strings to compare. "<<endl;
	cout << "string 1: ";
	cin >> s1;
	cout << "string 2: ";
	cin >> s2;
	if (isEqualTo<string>(s1, s2) == true)
		cout << s1 << " and " << s2 << " are equal! " << endl;
	else
		cout << s1 << " and " << s2 << " are not equal! " << endl;
	cout << endl;
	cout << "PERSON CLASS EQUALITY CHECK: " << endl;
	Person p(21, "Taaha"), p1(21, "Taaha");
	//It gives error without operator overloading
	if (isEqualTo(p, p1) == true)
		cout << "p and p1 are equal!" << endl;
	else
		cout << "p and p1 are not equal! " << endl;
	system("pause");
	return 0;
}
