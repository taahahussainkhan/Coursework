#include<iostream>
#include<string>
using namespace std;
int main()
{


	string s = "*";
	string i = "**";
	int y = 1;
	int z = 16;
	int w = 31;

		while (y<z)
		{
			int x = 1;
			while (x<=w)
			{
				cout << " ";
				x++;
			}
			cout << s << endl;
			s = s + i;
			y++;
			w--;
		}
		int a = 1;
		int b = 10;
		int c = 25;
		string ss = "*************";
		string ii = "**";
		while (a<b)
		{
			int x = 1;
			while (x <= c)
			{
				cout << " ";
				x++;
			}
			cout << ss << endl;
			ss = ss + ii;
			a++;
			c--;
		}
		
		int ad = 1;
		int be = 10;
		int cf = 25;
		string sss = "*************";
		string iii = "**";
		while (ad<be)
		{
			int x = 1;
			while (x <= cf)
			{
				cout << " ";
				x++;
			}
			cout << sss << endl;
			sss = sss + iii;
			ad++;
			cf--;
		}
		string g="                            *******";
		int u=1;
		while (u<6)
		{

			cout << g<<endl;
			u++;
		}
	
	return 0;
}