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
int main()
{
	int x = 8, y = 6;
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
		move = _getch();
		if (move == 'w'  && x>1)
		{
			map[x + 1][y + 2] = ' ';
			map[x + 1][y + 1] = ' ';
			map[x][y] = ' ';
			map[x + 2][y - 2] = ' ';
			map[x + 2][y - 1] = ' ';
			map[x + 2][y + 2] = ' ';
			map[x + 2][y + 1] = ' ';
			map[x + 1][y] = ' ';
			map[x + 2][y] = ' ';
			map[x + 1][y - 1] = ' ';
			map[x + 3][y] = ' ';
			map[x + 4][y] = ' ';
			map[x + 1][y + 1] = ' ';
			map[x + 3][y - 1] = ' ';
			map[x + 3][y + 1] = ' ';
			map[--x][y] = '*';
			map[x + 1][y] = '*';
			map[x + 2][y] = '*';
			map[x + 1][y - 1] = '*';
			map[x + 1][y + 1] = '*';
			map[x + 3][y - 1] = '*';
			map[x + 3][y + 1] = '*';
		}
		if (move == 's' && x<height - 6)
		{
			map[x][y] = ' ';
			map[x + 2][y - 2] = ' ';
			map[x + 2][y - 1] = ' ';
			map[x + 2][y + 2] = ' ';
			map[x + 2][y + 1] = ' ';
			map[x + 1][y + 2] = ' ';
			map[x + 1][y + 1] = ' ';
			map[x + 1][y] = ' ';
			map[x + 2][y] = ' ';
			map[x + 1][y - 1] = ' ';
			map[x + 1][y + 1] = ' ';
			map[x + 3][y - 1] = ' ';
			map[x + 3][y + 1] = ' ';
			map[++x][y] = ' ';
			map[x + 3][y] = '*';
			map[x + 4][y] = '*';
			map[x + 2][y] = '*';
			map[x + 1][y - 1] = '*';
			map[x + 1][y + 1] = '*';
			map[x + 3][y - 1] = '*';
			map[x + 3][y + 1] = '*';
		}
		if (move == 'd' && y<width - 5)
		{
			map[x + 1][y + 2] = ' ';
			map[x + 1][y + 1] = ' ';
			map[x][y] = ' ';
			map[x + 2][y - 2] = ' ';
			map[x + 2][y - 1] = ' ';
			map[x + 1][y] = ' ';
			map[x + 2][y] = ' ';
			map[x + 1][y - 1] = ' ';
			map[x + 3][y] = ' ';
			map[x + 4][y] = ' ';
			map[x + 1][y + 1] = ' ';
			map[x + 3][y - 1] = ' ';
			map[x + 3][y + 1] = ' ';
			map[x][++y] = ' ';
			map[x + 1][y] = ' ';
			map[x + 2][y + 2] = '*';
			map[x + 2][y + 1] = '*';
			map[x + 2][y] = '*';
			map[x + 1][y - 1] = '*';
			map[x + 1][y + 1] = '*';
			map[x + 3][y - 1] = '*';
			map[x + 3][y + 1] = '*';
		}

		if (move == 'a' && y>3)
		{
			map[x + 1][y + 2] = ' ';
			map[x + 1][y + 1] = ' ';
			map[x][y] = ' ';
			map[x + 1][y] = ' ';
			map[x + 2][y] = ' ';
			map[x + 1][y - 1] = ' ';
			map[x + 3][y] = ' ';
			map[x + 4][y] = ' ';
			map[x + 1][y + 1] = ' ';
			map[x + 3][y - 1] = ' ';
			map[x + 3][y + 1] = ' ';
			map[x][--y] = ' ';
			map[x + 1][y] = ' ';
			map[x + 2][y - 2] = '*';
			map[x + 2][y - 1] = '*';
			map[x + 2][y] = '*';
			map[x + 1][y - 1] = '*';
			map[x + 1][y + 1] = '*';
			map[x + 3][y - 1] = '*';
			map[x + 3][y + 1] = '*';
		}
		kscore++;
	}
	return 0;
}

void setMap(char **k, int x, int y)
{
	for (int i = 0; i<height; i++)
	{
		for (int j = 0; j<width; j++)
		{
			if (i == 0 || i == height - 1)
			{
				k[i][j] = ' ';
				if (i == 0 && (j == 0 || j == 9))k[i][j] = '#';
				if (i == height - 1 && (j == 0 || j == 9))k[i][j] = '#';
			}
			else
				if (j == 0 || j == width - 1)
					k[i][j] = '#';
				else
					k[i][j] = ' ';

		}
	}

	bool f = false;
	for (int i = 0; i < height - 1; i++)
	{

		if (i % 4 == 0 && i != 0) f = true;
		if (f == true)
		{
			k[i][0] = ' '; k[i + 1][9] = ' ';
			f = false;
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