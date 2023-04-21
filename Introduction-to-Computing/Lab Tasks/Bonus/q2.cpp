#include<iostream>
#include<ctime>

using namespace std;
int main()
{
	int x=1;
	int y=1;
	while (x<3)
	{
		cout << "*****"<<endl;
		while (y<4)
		{
			cout << "*   *" << endl;
			y++;
		}
		x++;
	}

	return 0;
}



/*
#include<iostream>
#include<ctime>

using namespace std;
int main()
{
int y=1;
for (int x=1;x<3;x++;)
{
cout << "*****"<<endl;
while (y<4)
{
cout << "*   *" << endl;
y++;
}
}

return 0;
}
*/