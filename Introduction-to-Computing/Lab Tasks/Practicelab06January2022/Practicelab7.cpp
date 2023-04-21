#include<iostream>
#include<string>
using namespace std;
int main()
{
	int number,Consonants,digit_words,spaces,vowel_words;
	string Words;
	cout << "please enter a sentences of your on choose: ";
	cout << "\n";
	cin >> Words;
	
	for (number = 0; Words[number] != '\0'; ++number)
	{
		if (Words[number] == 'a' || Words[number] == 'e' || Words[number] == 'i' ||
			Words[number] == 'o'
			|| Words[number] == 'u' || Words[number] == 'A' || Words[number] == 'E' ||
			Words[number] == 'I'
			|| Words[number] == 'O' || Words[number] == 'U')
		{
			++vowel_words;
		}
		else if ((Words[number] >= 'a'&& Words[number] <= 'z') || (Words[number] >= 'A'&&
			Words[number]
			<= 'Z'))
		{
			++Consonants;
		}
		else if (Words[number] >= '0' & Words[number] <= '9')
		{
			++digit_words;
		}
		else if (Words[number] == ' ')
		{			++spaces;		}	}		return 0;
}