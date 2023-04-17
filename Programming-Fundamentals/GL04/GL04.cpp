#include<iostream>
#include<fstream>//According to my understanding of the question!
using namespace std;
void  sizeoffile(ifstream &, int &);
int* dynamic_memory(int);
void read(ifstream &, int*, int);
int frequency(int*, int);
void delete_element(int *, int);
void deallocate(int*);
void console(int *, int);
int main()
{
	int fa,size=0;
	ifstream fin("data.txt");
	while (!fin.eof())
	{
		fin >> fa;
		size++;
	}
	int* data = NULL;
	data = new int[size];
	sizeoffile(fin, size);
	read(fin, data, size);
	frequency(data, size);
	console(data, size);
	
}
void  sizeoffile(ifstream &, int &size)
{
	int fa;
	ifstream fin("data.txt");
	while (!fin.eof())
	{
		fin >> fa;
		size++;
	}
}
int* dynamic_memory(int size)
{

	int* data = NULL;
	data = new int[size];
	return data;
}
void read(ifstream &fin, int* data, int size)
{
	fin.open("data.txt");
	int* size1;
	size1 = dynamic_memory(size);
	for (int i = 0; i < size;i++)
	{
		fin >> data[i];
	}

}
int frequency(int* data, int size)
{
	int found = 0;
	ifstream fin("data.txt");
	read(fin, data, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (data[i] == data[j])
				found++;
		}
	}
	if (found == 0)
		delete_element(data, size);
	return found;
}
void delete_element(int *data, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size;)
		{
			if (data[i] != data[j])
			{
				data[i] = data[i + 1];
			}
		}

	}
	deallocate(data);
}
void deallocate(int* data)
{
	
}
void console(int *data, int size)
{
	ifstream fin("data.txt");
	//for (int i = 0; i < size;i++)
	//cout << data[i] << endl;

}