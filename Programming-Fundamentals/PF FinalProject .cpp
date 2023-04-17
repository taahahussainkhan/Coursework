#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;
char username[30];
const int row = 20;
const int col = 25;
char dynamic[row][col];
char bullet = 186;
char enemy = 157;
int  life = 3, kills = 0, score = 0, countenimies = 0;
int  level = 01;
bool gameplay = 1 , one_time = 1 ;
int  changeclr = 1;
int  posx[20];
int  posy[20];
int  x = 0;
int  y = 0;
int  tries = 01;
int  scorerange[50]={0};
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void welcome();
void instructions();
void hideCursor();
void frame();
void printing();
void birthofaliens(int level);
void rgb();
void movealiens(int level);
void fire(int row, int mov);
void movementupdate(int& horizon, int& mov);
void dead();
void reset();
void gameover();
void reset1();
void champion();
int largest(int arr[], int n);
void record(char name[],int score);
int main()
{
	welcome();
	system("cls");
	if(one_time)
	{
		instructions();
	    _getch();
	    system("cls");
        cout << "Please enter your name first \n";
	    cin.getline(username,30);
	}
	system("cls");
	hideCursor();
	frame();
	//spaceship placement
	dynamic[row - 2][col / 2] = 143;
	printing();
	int mov;
	int  horizon = col / 2;
	mov = horizon;
	birthofaliens(level);
	printing();
	while (gameplay)
	{	
		char key = _getch();
		switch (key)
		{
			case 75:
			if (mov <= 1)
				break;
			if (mov == 2)
				rgb();
			mov--;
			break;	
		    case 77:
			if (mov >= col - 2)
				break;
			if (mov >= col - 3)
				rgb();
			mov++;
			break;
		    case 32:
			Beep(1500, 100);
			if (level > 4)
				movealiens(level);
			fire(row, mov);
			movealiens(level);
			break;
		}
		// for movement of spaceship
		movementupdate(horizon, mov);
		printing();
		dead();
		if ((countenimies == 0) && level<=5)
		{	
			level += 1;
			reset();
			birthofaliens(level);
		}
		if (life < 1)
		{	
			scorerange[tries-1]=score;
			gameplay = false;
			system("cls");
			gameover();
			cout << "Your score is " << score;
			char temp;
			cout << "\nDO YOU WANT TO PLAY AGAIN\nENTER 'Y' IF YES OR 'N' IF NO \n";
			cin>>temp;
			if (temp == 'y' || temp == 'Y')
			{
				tries++;
				system("cls");	 

				gameplay = true;
				one_time = false;
				reset1();
				main();
			}
			else
			{
				scorerange[tries-1]=score;
			    record(username,largest(scorerange, tries));	
			}
		}
		if (level > 5)
		{
			scorerange[tries-1]=score;	
			tries++;
			char temp;
			gameplay = false;
			system("cls");
			champion();
			cout << "\nDO YOU WANT TO PLAY AGAIN\nENTER 'Y' IF YES OR 'N' IF NO \n";
			cin >> temp;
			if (temp == 'y' || temp == 'Y')
			{
				system("cls");
				gameplay = true;
				one_time = false;
				reset1();
				main();
			}
			else
			{
				scorerange[tries-1]=score;
			    record(username,largest(scorerange, tries));
			}
		}
	}
}
void welcome()
{
	char name[] = { "SPACESHOOTER" };
	SetConsoleCursorPosition(hStdOut, { 0 , 7 });
	for (int i = 0; i < 12; i++)
	{
		Beep(400, 70);
		cout << "\t\t\t\t\t" << name[i] << "\n";
		rgb();
		Sleep(300);
	}
}
void instructions()
{
	ifstream inFile;
	inFile.open("Instruction.txt");
	char typer;
	while(!inFile.eof())
	{
		inFile.get(typer);
		
		if(!inFile.eof())
		{
			if(typer==32)
			    rgb();
			if(typer!=32)
			    Beep(303,100);
			cout<<typer;
		}
	}
	cout<<endl;
	inFile.close();	
}
void hideCursor()
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &cci);
}
void frame()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == 0)
				dynamic[i][j] = 178;

			else if (i == row - 1)
				dynamic[i][j] = 178;
			else if (j == 0)
				dynamic[i][j] = 178;
			else  if (j == col - 1)
				dynamic[i][j] = 178;
			else if (i == row - 4)
				dynamic[i][j] = '.';
			else
				dynamic[i][j] = 32;
		}
	}
}
void printing()
{
	SetConsoleCursorPosition(hStdOut, { 24 , 0 });
	cout << char(143) << char(143) << char(143) << " S p A c E  S h o O t E r: " << char(143) << char(143) << char(143) << endl;
	cout << "S c O r E  " << score << endl;
	cout << "T O T A L   K I L L S    " << kills << endl;
	cout << "T O T A L   L I v e s    " << life << endl;
	cout << "L E V E L                " << level << endl;
	SetConsoleCursorPosition(hStdOut, { 0 , 7 });
	for (int i = 0; i < row; i++)
	{
		cout << "\t";
		cout << "\t";
		cout << "\t";
		for (int j = 0; j < col; j++)
		{
			cout << dynamic[i][j];
		}
		cout << endl;
	}
}
void birthofaliens(int level)
{
	for (int j = 0; j < level + 2; j++)
	{
		countenimies = level + 2;
		x = rand() % 5 + 2;
		y = rand() % (col - 4) + 2;
		dynamic[x][y] = enemy;
		posx[j] = x;
		posy[j] = y;
	}
}
void rgb()
{
	SetConsoleTextAttribute(hStdOut, changeclr);
	changeclr += 1;
	if (changeclr > 15)
		changeclr = 1;
}
void movealiens(int level)
{
	for (int j = 0; j < level + 2; j++)
	{
		int prev;
		prev = posx[j];
		if ((dynamic[prev][posy[j]] != 32) && (posx[j] < row - 4))
		{
			posx[j] += 1;
			dynamic[posx[j]][posy[j]] = enemy;
			dynamic[prev][posy[j]] = 32;
		}
	}
}
void fire(int row, int mov)
{
	for (int i = row - 3; i >= 0; i--)
	{
		dynamic[i][mov] = bullet;
		if (i + 1 != row - 2)
		{
			dynamic[i + 1][mov] = 32;
		}
		//touching condition
		if ((dynamic[i - 1][mov] == enemy))

		{
			score += 10;
			kills += 1;
			countenimies -= 1;
			Beep(300,100);
			printing();
			dynamic[i - 1][mov] = char(176);
			Sleep(50);
			printing();
			Sleep(50);
			rgb();
			dynamic[i - 1][mov] = 32;
			dynamic[i][mov] = 32;
			printing();
			dynamic[row - 4][mov] = '.';
			break;
		}
		if(dynamic[row - 5][mov]==bullet)
		{
			dynamic[row - 4][mov] = '.';
			printing();
		}
		if (i == 0)
		{	
			dynamic[i][mov] = 178;
			rgb();
			Beep(300, 100);
		}
		printing();
	}
}
void movementupdate(int& horizon, int& mov)//spaceship update
{
	dynamic[row - 2][horizon] = char(32);
	dynamic[row - 2][mov] = char(143);
	horizon = mov;
}
void dead()
{
	for (int i = 0; i < col; i++)
	{
		if (dynamic[row - 4][i] == enemy)
		{
			life -= 1;
			countenimies -= 1;
			dynamic[row - 4][i] = '.';
		}
	}
}
void reset()
{
	for (int i = 0; i < 20; i++)
	{
		posx[i] = 0;
		posy[i] = 0;
	}
}
void gameover()
{
	char name[] = { " GAME OVER " };
	SetConsoleCursorPosition(hStdOut, { 0 , 7 });
	for (int i = 0; i < 11; i++)
	{
		if (name[i] != 32)
		     Beep(400,70);
		cout << "\t\t\t\t\t" << name[i] << "\n";
		Sleep(300);
		rgb();
	}
	system("cls");	
}
void reset1()
{
	life = 3, kills = 0, score = 0, countenimies = 0;
	level = 1;
}
void champion()
{
	cout << "YOU ARE A CHAMP\n" ;
	cout << "You completed all the levels of the game\n";
	cout << "YOUR TOTAL SCORE IS " << score;
}
int largest(int arr[], int n)
{
    int i; 
    // Initialize maximum element
    int max = arr[0]; 
    // Traverse array elements
    // from second and compare
    // every element with current max
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void record(char name[],int score)
{
	ofstream file;
	file.open("Record.txt",ios::app );
	file << username << "\t" << score << "\n";
	file.close();
}
