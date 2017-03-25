#include "stdafx.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include <string>
using namespace std;

const int height = 20, width = 10;

void setMap(char **k, int x, int y);
void printscore(int ikf, int scr);
void printMap(char **m, int ks);
void clearscreen();
void dvig(char **a);
int main()
{
	setlocale(LC_ALL, "Russian");
	int x = 16, y = 3;
	char** map = new char*[height];

	for (int i = 0; i<height; i++)
		map[i] = new char[width];

	setMap(map, x, y);

	char move;
	int kscore = 0;

	while (true)
	{
		clearscreen();
		printMap(map, kscore);
		Sleep(50);
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

			if ((move == 'a' && y > width - 5) || (move == 'A' && y > width - 5) )
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
	for (int i = 0; i<height; i++)
	{
		for (int j = 0; j<width; j++)
		{

			if (j == 0 || j == width - 1)
				k[i][j] = '#';
			else
				k[i][j] = ' ';

		}
	}
	for (int i = 0; i < height - 2; i++)
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
	case 0:
		cout << ' ' << sr;
		break;
	case 1:
		cout << ' ' << s1;
		break;
	case 2:
		cout << ' ' << sr;
		break;
	case 7:
		cout << sp;
		break;
	case 8:
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
	case 9:
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
	for (int i = 0; i<height; i++)
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
	char last = a[height - 1][0];
	for (int i = height - 1; i>0; i--)
		a[i][0] = a[i - 1][0];
	a[0][0] = last;
	last = a[height - 1][width - 1];
	for (int i = height - 1; i>0; i--)
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