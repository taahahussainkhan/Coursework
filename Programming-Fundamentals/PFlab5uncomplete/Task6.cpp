#include<iostream>
using namespace std;
void check(char name[],int);
int main()
{
	char name[20] = { '\0' };
	cout << "Enter name: ";
	cin.getline(name, 19);
	check(name, 20);
	
}
void check(char name[], int)
{
	int vowel = 0;

	cout << "Vowel at index: ";
	for (int i = 0; i < 20; i++)
	{
		if ((name[i] == 'a' || name[i] == 'A') || (name[i] == 'e' || name[i] == 'E')
			|| (name[i] == 'i' || name[i] == 'I') || (name[i] == 'o'
			|| name[i] == 'O') || (name[i] == 'u' || name[i] == 'U'))
		{
			cout << i<<" ";
			vowel++;
		}
	
	}
	cout << "\nTotal Vowels: " << vowel << endl;
	
}