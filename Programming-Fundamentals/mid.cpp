#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ofstream fout1,fout2,fout3,fout4;
	fout1.open("id.txt");
	fout2.open("name.txt");
	fout3.open("num.txt");
	fout4.open("mail.txt");
	ifstream fin;
	string id,id1,name,name1,name2,num,num1,mail,mail1;
	fin.open("user.txt");
	while(!fin.eof())
	{
		fin>>id;
		fin>>id1;
		fout1<<id1<<endl;
		fin>>name;
		fin>>name1;
		fin>>name2;
		fout2<<name1<<" "<<name2<<endl;
		fin>>num;
		fin>>num1;
		fout3<<num1<<endl;
		fin>>mail;
		fin>>mail1;
		fout4<<mail1<<endl;
	}
}

