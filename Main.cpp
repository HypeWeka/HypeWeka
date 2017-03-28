#include "stdafx.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include <string>
using namespace std;
#define LEFT 1E;
const int height = 20, width = 10;

void setMap(char **k, int x, int y);
void printscore(int ikf, int scr);
void printMap(char **m, int ks);
void clearscreen();
void dvig(char **a);
void add_car(char **a);
void dvig_car(char **a);
int main()
{
	WM_KEYDOWN;
	setlocale(LC_ALL, "Russian");
	int x = 20, y = 3;
	char** map = new char*[height+4];

	for (int i = 0; i<height+4; i++)
		map[i] = new char[width];

	setMap(map, x, y);

	char move;
	int kscore = 0;

	while (true)
	{
		clearscreen();
		printMap(map, kscore);
		dvig_car(map);
		if (kscore % 10 == 0)
			add_car(map);
		Sleep(200);
		if (_kbhit()) {
			move = _getch();

			if ((move == 'd' && y < width - 5) || (move == 'D' && y < width - 5))
			{
				for (int u = 2; u >= -1; u--)
					map[x + 3][y - u] = ' ';
				map[x + 1][y - 1] = ' ';
				map[x + 3][y - 1] = ' ';
				map[x][y] = ' ';
				map[x + 1][y] = ' ';
				map[x + 2][y] = ' ';
				map[x + 1][y + 1] = ' ';
				map[x + 3][y + 1] = ' ';
				map[x + 1][y + 2] = '*';
				map[x + 3][y + 2] = '*';
				map[x][y + 3] = '*';
				map[x + 1][y + 3] = '*';
				map[x + 2][y + 3] = '*';
				map[x + 1][y + 4] = '*';
				map[x + 3][y + 4] = '*';
				y += 3;
			}

			if ((move == 'a' && y > width - 5) || (move == 'A' && y > width - 5))
			{

				map[x + 1][y + 1] = ' ';
				map[x + 3][y + 1] = ' ';
				map[x][y] = ' ';
				map[x + 1][y] = ' ';
				map[x + 2][y] = ' ';
				map[x + 1][y - 1] = ' ';
				map[x + 3][y - 1] = ' ';
				map[x + 1][y - 4] = '*';
				map[x + 3][y - 4] = '*';
				map[x][y - 3] = '*';
				map[x + 1][y - 3] = '*';
				map[x + 2][y - 3] = '*';
				map[x + 1][y - 2] = '*';
				map[x + 3][y - 2] = '*';
				for (int q = 1; q >= -2; q--)
					for (int z = -3; z <= 0; z++)
						map[x - z][y - q] = ' ';
				y -= 3;
			}
		}


		kscore++;
		dvig(map);
	}
	return 0;
}

void setMap(char **k, int x, int y)
{
	for (int i = 0; i<height+4; i++)
	{
		for (int j = 0; j<width; j++)
		{

			if (j == 0 || j == width - 1)
				k[i][j] = '#';
			else
				k[i][j] = ' ';

		}
	}
	for (int i = 0; i < height +2; i++)
	{

		if (i % 4 == 0)
		{
			k[i][0] = ' ';
			k[i + 1][9] = ' ';
		}

	}

	k[x][y] = '*';
	k[x + 1][y] = '*';
	k[x + 2][y] = '*';
	k[x + 1][y - 1] = '*';
	k[x + 1][y + 1] = '*';
	k[x + 3][y - 1] = '*';
	k[x + 3][y + 1] = '*';
}
void printscore(int ikf, int scr)
{
	string s1 = " 61th R O A D  R A C E ";
	string sr = "=======================";
	string s2 = " S C O R E:";
	string sp = "  + + + + + + + + + +";
	switch (ikf)
	{
	case 4:
		cout << ' ' << sr;
		break;
	case 5:
		cout << ' ' << s1;
		break;
	case 6:
		cout << ' ' << sr;
		break;
	case 11:
		cout << sp;
		break;
	case 12:
		cout << "  +" << s2 << ' ' << scr;
		if (scr < 10)cout << "    +";
		else
			if (scr < 100) cout << "   +";
			else
				if (scr < 1000) cout << "  +";
				else
					if (scr < 10000) cout << " +";
					else scr = 0;
					break;
	case 13:
		cout << sp;
		break;
	}
}
void printline()
{
	string s = "==========";
	cout << s;
}
void printMap(char **m, int ks)
{
	for (int i = 4; i<height+4; i++)
	{
		for (int j = 0; j<width; j++)
		{
			cout << m[i][j];
		}
		printscore(i, ks);
		cout << endl;
	}
	printline();
}
void dvig(char **a)
{
	char last = a[height + 3 ][0];
	for (int i = height +3; i>0; i--)
		a[i][0] = a[i - 1][0];
	a[0][0] = last;
	last = a[height +3][width - 1];
	for (int i = height +3; i>0; i--)
		a[i][width - 1] = a[i - 1][width - 1];
	a[0][width - 1] = last;
}
void clearscreen()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void add_car(char **a)
{
	srand(time(0));
	int ran = rand() % 2;
	switch (ran)
	{
	case 0:
		a[0][3] = '*';
		a[1][3] = '*';
		a[2][3] = '*';
		a[1][2] = '*';
		a[1][4] = '*';
		a[3][2] = '*';
		a[3][4] = '*';
		break;
	case 1:
		a[0][6] = '*';
		a[1][6] = '*';
		a[2][6] = '*';
		a[1][5] = '*';
		a[1][7] = '*';
		a[3][5] = '*';
		a[3][7] = '*';
		break;

	}

}
void dvig_car(char **a)
{
	for (int j = height-1; j >0; j--)
		for (int i = 2; i < width - 1; i++)
			a[j][i] = a[j-1][i];
	for (int i = 2; i < width - 1; i++)
		a[0][i] = ' ';

}