#include "stdafx.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;
const int height = 20, width = 10;
const int N = 10, M = 13;

void setMap(char **k, int x, int y);
void printMap(char **m, int ks, int topscore);
void printscore(int ikf, int scr);
void printrecord(int ikf, int topscore);
void clearscreen();
void dvig(char **a);
void add_car(char **a);
void dvig_car(char **a, bool c, bool* cr);
void haste(char **a, int &aa, bool c, bool* cr, int topscore);
bool preright(char**a);
bool preleft(char**a);
void MoveLeft(char**a, int x, int &y);
void MoveRight(char**a, int x, int &y);
void crushleft(char**a);
void crushright(char**a);
int MainMenu(int & SPEED);
char **setMenu();
void printMenu(char **a);
void RecordsMenu();
void GameOver(int *s);
void records(int score);
void blink(char **a, int p);
void blinkSpeed(char **a, int p);
int speedMenu();
char **setSpeedMenu();

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int speed = 65;


	char** map = new char*[height + 4];

	for (int i = 0; i<height + 4; i++)
		map[i] = new char[width];
	while (MainMenu(speed) == 0)
	{

		int x = 20, y = 3;
		setMap(map, x, y);
		char move;
		int kscore = 0;
		bool coordinat = 0;
		bool crush = 0;
		int top;
		ifstream rin("records.txt");
		rin >> top;
		rin.clear();
		rin.close();
		system("cls");
		while (true)
		{
			if (crush == 1)
				break;
			else
			{
				clearscreen();
				printMap(map, kscore, top);
				if (kscore % 10 == 0)
					add_car(map);
				Sleep(speed);
				if (_kbhit()) {
					move = _getch();

					if ((move == 'd' && y < width - 5) || (move == 'D' && y < width - 5))
					{
						coordinat = 1;
						if (preright(map) == 0)
						{
							crushleft(map);
							break;
						}
						MoveRight(map, x, y);

					}

					if ((move == 'a' && y > width - 5) || (move == 'A' && y > width - 5))
					{
						coordinat = 0;
						if (preleft(map) == 0)
						{
							crushright(map);
							break;
						}
						MoveLeft(map, x, y);
					}
					if (move == VK_SPACE)
						haste(map, kscore, coordinat, &crush, top);
				}
				if (_kbhit()) {
					move = _getch();
					if (move == VK_SPACE)
						haste(map, kscore, coordinat, &crush, top);
				}
				dvig_car(map, coordinat, &crush);
				kscore++;
				dvig(map);
			}
		}
		clearscreen();
		GameOver(&kscore);
		system("cls");
	}

	delete[] map;
	return 0;
}
void MoveLeft(char**a, int x, int &y)
{
	a[x + 1][y + 1] = ' ';
	a[x + 3][y + 1] = ' ';
	a[x][y] = ' ';
	a[x + 1][y] = ' ';
	a[x + 2][y] = ' ';
	a[x + 1][y - 1] = ' ';
	a[x + 3][y - 1] = ' ';
	a[x + 1][y - 4] = '*';
	a[x + 3][y - 4] = '*';
	a[x][y - 3] = '*';
	a[x + 1][y - 3] = '*';
	a[x + 2][y - 3] = '*';
	a[x + 1][y - 2] = '*';
	a[x + 3][y - 2] = '*';
	for (int q = 1; q >= -2; q--)
		for (int z = -3; z <= 0; z++)
			a[x - z][y - q] = ' ';
	y -= 3;
}
void MoveRight(char**a, int x, int &y)
{
	for (int u = 2; u >= -1; u--)
		a[x + 3][y - u] = ' ';
	a[x + 1][y - 1] = ' ';
	a[x + 3][y - 1] = ' ';
	a[x][y] = ' ';
	a[x + 1][y] = ' ';
	a[x + 2][y] = ' ';
	a[x + 1][y + 1] = ' ';
	a[x + 3][y + 1] = ' ';
	a[x + 1][y + 2] = '*';
	a[x + 3][y + 2] = '*';
	a[x][y + 3] = '*';
	a[x + 1][y + 3] = '*';
	a[x + 2][y + 3] = '*';
	a[x + 1][y + 4] = '*';
	a[x + 3][y + 4] = '*';
	y += 3;
}
void blink(char **A, int p)
{
	int N = 10;
	int M = 13;
	int c = 6;

	if (!_kbhit()) {
		switch (p)
		{
		case 0:

			if (!_kbhit()) {
				A[N / 9][M / c + 1] = '>';

				clearscreen();
				printMenu(A);
				if (!_kbhit()) {
					Sleep(350);
					A[N / 9][M / c + 1] = ' ';
					A[N / 9][M / c + 2] = ' ';
					A[N / 9][M / c + 3] = ' ';
					A[N / 9][M / c + 4] = ' ';
					A[N / 9][M / c + 5] = ' ';
					A[N / 9][M / c + 6] = ' ';
					clearscreen();
					printMenu(A);
					Sleep(350);
					A[N / 9][M / c + 2] = 'S';
					A[N / 9][M / c + 3] = 'T';
					A[N / 9][M / c + 4] = 'A';
					A[N / 9][M / c + 5] = 'R';
					A[N / 9][M / c + 6] = 'T';
				}
			}
			A[N / 9][M / c + 1] = ' ';




			break;
		case 2:

			if (!_kbhit())
			{
				A[N / 9 + 4][M / c + 1] = '>';

				clearscreen();
				printMenu(A);
				if (!_kbhit()) {
					Sleep(350);
					A[N / 9 + 4][M / c + 1] = ' ';
					A[N / 9 + 4][M / c + 2] = ' ';
					A[N / 9 + 4][M / c + 3] = ' ';
					A[N / 9 + 4][M / c + 4] = ' ';
					A[N / 9 + 4][M / c + 5] = ' ';
					A[N / 9 + 4][M / c + 6] = ' ';
					A[N / 9 + 4][M / c + 7] = ' ';
					A[N / 9 + 4][M / c + 8] = ' ';
					clearscreen();
					printMenu(A);
					Sleep(350);
					A[N / 9 + 4][M / c + 2] = 'R';
					A[N / 9 + 4][M / c + 3] = 'E';
					A[N / 9 + 4][M / c + 4] = 'C';
					A[N / 9 + 4][M / c + 5] = 'O';
					A[N / 9 + 4][M / c + 6] = 'R';
					A[N / 9 + 4][M / c + 7] = 'D';
					A[N / 9 + 4][M / c + 8] = 'S';
				}

			}

			A[N / 9 + 4][M / c + 1] = ' ';
			break;
		case 1:
			if (!_kbhit())
			{
				A[N / 9 + 2][M / c + 1] = '>';

				clearscreen();
				printMenu(A);
				if (!_kbhit()) {
					Sleep(350);
					A[N / 9 + 2][M / c + 1] = ' ';
					A[N / 9 + 2][M / c + 2] = ' ';
					A[N / 9 + 2][M / c + 3] = ' ';
					A[N / 9 + 2][M / c + 4] = ' ';
					A[N / 9 + 2][M / c + 5] = ' ';
					A[N / 9 + 2][M / c + 6] = ' ';
					clearscreen();
					printMenu(A);
					Sleep(350);
					A[N / 9 + 2][M / c + 2] = 'S';
					A[N / 9 + 2][M / c + 3] = 'P';
					A[N / 9 + 2][M / c + 4] = 'E';
					A[N / 9 + 2][M / c + 5] = 'E';
					A[N / 9 + 2][M / c + 6] = 'D';
				}
			}
			A[N / 9 + 2][M / c + 1] = ' ';
			break;
		case 3:
			if (!_kbhit())
			{
				A[N / 9 + 6][M / c + 1] = '>';

				clearscreen();
				printMenu(A);
				if (!_kbhit()) {
					Sleep(350);
					A[N / 9 + 6][M / c + 1] = ' ';
					A[N / 9 + 6][M / c + 2] = ' ';
					A[N / 9 + 6][M / c + 3] = ' ';
					A[N / 9 + 6][M / c + 4] = ' ';
					A[N / 9 + 6][M / c + 5] = ' ';
					clearscreen();
					printMenu(A);
					Sleep(350);
					A[N / 9 + 6][M / c + 2] = 'E';
					A[N / 9 + 6][M / c + 3] = 'X';
					A[N / 9 + 6][M / c + 4] = 'I';
					A[N / 9 + 6][M / c + 5] = 'T';
				}


			}
			A[N / 9 + 6][M / c + 1] = ' ';
			break;
		}
	}
	A[N / 9 + 6][M / c + 1] = ' ';
	A[N / 9 + 2][M / c + 1] = ' ';
	A[N / 9 + 4][M / c + 1] = ' ';
	A[N / 9][M / c + 1] = ' ';

}
void blinkSpeed(char **A, int p)
{
	int N = 10;
	int M = 13;
	int c = 6;

	if (!_kbhit()) {
		switch (p)
		{
		case 0:

			if (!_kbhit()) {
				A[N / 9][M / c + 1] = '>';

				clearscreen();
				printMenu(A);
				if (!_kbhit()) {
					Sleep(350);
					A[N / 9][M / c + 1] = ' ';
					A[N / 9][M / c + 2] = ' ';
					A[N / 9][M / c + 3] = ' ';
					A[N / 9][M / c + 4] = ' ';
					A[N / 9][M / c + 5] = ' ';
					clearscreen();
					printMenu(A);
					Sleep(350);
					A[N / 9][M / c + 2] = 'E';
					A[N / 9][M / c + 3] = 'A';
					A[N / 9][M / c + 4] = 'S';
					A[N / 9][M / c + 5] = 'Y';
				}
			}
			A[N / 9][M / c + 1] = ' ';




			break;
		case 1:

			if (!_kbhit())
			{
				A[N / 9 + 2][M / c + 1] = '>';

				clearscreen();
				printMenu(A);
				if (!_kbhit()) {
					Sleep(350);
					A[N / 9 + 2][M / c + 1] = ' ';
					A[N / 9 + 2][M / c + 2] = ' ';
					A[N / 9 + 2][M / c + 3] = ' ';
					A[N / 9 + 2][M / c + 4] = ' ';
					A[N / 9 + 2][M / c + 5] = ' ';
					A[N / 9 + 2][M / c + 6] = ' ';
					A[N / 9 + 2][M / c + 7] = ' ';
					clearscreen();
					printMenu(A);
					Sleep(350);
					A[N / 9 + 2][M / c + 2] = 'M';
					A[N / 9 + 2][M / c + 3] = 'E';
					A[N / 9 + 2][M / c + 4] = 'D';
					A[N / 9 + 2][M / c + 5] = 'I';
					A[N / 9 + 2][M / c + 6] = 'U';
					A[N / 9 + 2][M / c + 7] = 'M';
				}

			}

			A[N / 9 + 2][M / c + 1] = ' ';
			break;
		case 2:
			if (!_kbhit())
			{
				A[N / 9 + 4][M / c + 1] = '>';

				clearscreen();
				printMenu(A);
				if (!_kbhit()) {
					Sleep(350);
					A[N / 9 + 4][M / c + 1] = ' ';
					A[N / 9 + 4][M / c + 2] = ' ';
					A[N / 9 + 4][M / c + 3] = ' ';
					A[N / 9 + 4][M / c + 4] = ' ';
					A[N / 9 + 4][M / c + 5] = ' ';
					clearscreen();
					printMenu(A);
					Sleep(350);
					A[N / 9 + 4][M / c + 2] = 'H';
					A[N / 9 + 4][M / c + 3] = 'A';
					A[N / 9 + 4][M / c + 4] = 'R';
					A[N / 9 + 4][M / c + 5] = 'D';
				}
			}
			A[N / 9 + 4][M / c + 1] = ' ';
			break;
		case 3:
			if (!_kbhit())
			{
				A[N / 9 + 6][M / c + 1] = '>';

				clearscreen();
				printMenu(A);
				if (!_kbhit()) {
					Sleep(350);
					A[N / 9 + 6][M / c + 1] = ' ';
					A[N / 9 + 6][M / c + 2] = ' ';
					A[N / 9 + 6][M / c + 3] = ' ';
					A[N / 9 + 6][M / c + 4] = ' ';
					A[N / 9 + 6][M / c + 5] = ' ';
					A[N / 9 + 6][M / c + 6] = ' ';
					A[N / 9 + 6][M / c + 7] = ' ';
					A[N / 9 + 6][M / c + 8] = ' ';
					clearscreen();
					printMenu(A);
					Sleep(350);
					A[N / 9 + 6][M / c + 2] = 'E';
					A[N / 9 + 6][M / c + 3] = 'X';
					A[N / 9 + 6][M / c + 4] = 'T';
					A[N / 9 + 6][M / c + 5] = 'R';
					A[N / 9 + 6][M / c + 6] = 'E';
					A[N / 9 + 6][M / c + 7] = 'M';
					A[N / 9 + 6][M / c + 8] = 'E';
				}


			}
			A[N / 9 + 6][M / c + 1] = ' ';
			break;
		}
	}
	A[N / 9 + 6][M / c + 1] = ' ';
	A[N / 9 + 2][M / c + 1] = ' ';
	A[N / 9 + 4][M / c + 1] = ' ';
	A[N / 9][M / c + 1] = ' ';

}
void setMap(char **k, int x, int y)
{
	for (int i = 0; i<height + 4; i++)
	{
		for (int j = 0; j<width; j++)
		{

			if (j == 0 || j == width - 1)
				k[i][j] = '#';
			else
				k[i][j] = ' ';

		}
	}
	for (int i = 0; i < height + 2; i++)
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
bool preright(char**a)
{
	if (a[height][5] == '*')
		return 0;
	for (int j = height + 3; j > height - 1; j--)
		if (a[j][6] == '*')
			return 0;
}
bool preleft(char**a)
{
	if (a[height][4] == '*')
		return 0;
	for (int j = height + 3; j > height - 1; j--)
		if (a[j][3] == '*')
			return 0;
}
void printrecord(int ikf, int topscore)
{
	string s2 = " T O P:";
	string sp = "  + + + + + + + + + +";
	switch (ikf)
	{
	case 7:cout << sp; break;
	case 8:cout << "  +" << s2 << ' ' << topscore;
		if (topscore < 10)cout << "         +";
		else
			if (topscore < 100) cout << "       +";
			else
				if (topscore < 1000) cout << "      +";
				else
					if (topscore < 10000) cout << "     +";
		break;
	case 9:cout << sp; break;
	}
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
void printMap(char **m, int ks, int topscore)
{
	for (int i = 4; i<height + 4; i++)
	{
		for (int j = 0; j<width; j++)
		{
			cout << m[i][j];
		}
		printrecord(i, topscore);
		printscore(i, ks);
		cout << endl;
	}
	printline();
}
void dvig(char **a)
{
	char last = a[height + 3][0];
	for (int i = height + 3; i>0; i--)
		a[i][0] = a[i - 1][0];
	a[0][0] = last;
	last = a[height + 3][width - 1];
	for (int i = height + 3; i>0; i--)
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
char **setMenu()
{
	char ** A = new char *[N];
	for (int i = 0; i < N; i++)
		A[i] = new char[M];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			A[i][j] = ' ';
	int c = 6;
	A[N / 9][M / c] = ' ';
	A[N / 9][M / c + 1] = ' ';
	A[N / 9][M / c + 2] = 'S';
	A[N / 9][M / c + 3] = 'T';
	A[N / 9][M / c + 4] = 'A';
	A[N / 9][M / c + 5] = 'R';
	A[N / 9][M / c + 6] = 'T';
	A[N / 9 + 4][M / c] = ' ';
	A[N / 9 + 4][M / c + 1] = ' ';
	A[N / 9 + 4][M / c + 2] = 'R';
	A[N / 9 + 4][M / c + 3] = 'E';
	A[N / 9 + 4][M / c + 4] = 'C';
	A[N / 9 + 4][M / c + 5] = 'O';
	A[N / 9 + 4][M / c + 6] = 'R';
	A[N / 9 + 4][M / c + 7] = 'D';
	A[N / 9 + 4][M / c + 8] = 'S';
	A[N / 9 + 2][M / c] = ' ';
	A[N / 9 + 2][M / c + 1] = ' ';
	A[N / 9 + 2][M / c + 2] = 'S';
	A[N / 9 + 2][M / c + 3] = 'P';
	A[N / 9 + 2][M / c + 4] = 'E';
	A[N / 9 + 2][M / c + 5] = 'E';
	A[N / 9 + 2][M / c + 6] = 'D';
	A[N / 9 + 6][M / c] = ' ';
	A[N / 9 + 6][M / c + 1] = ' ';
	A[N / 9 + 6][M / c + 2] = 'E';
	A[N / 9 + 6][M / c + 3] = 'X';
	A[N / 9 + 6][M / c + 4] = 'I';
	A[N / 9 + 6][M / c + 5] = 'T';
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == 0 || i == N - 1)
				A[i][j] = '*';
			else
				if (j == 0 || j == M - 1)
					A[i][j] = '*';

		}

	}
	return A;


}
char **setSpeedMenu()
{
	char ** A = new char *[N];
	for (int i = 0; i < N; i++)
		A[i] = new char[M];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			A[i][j] = ' ';
	int c = 6;
	A[N / 9][M / c] = ' ';
	A[N / 9][M / c + 1] = ' ';
	A[N / 9][M / c + 2] = 'E';
	A[N / 9][M / c + 3] = 'A';
	A[N / 9][M / c + 4] = 'S';
	A[N / 9][M / c + 5] = 'Y';
	A[N / 9][M / c + 6] = ' ';
	A[N / 9 + 2][M / c] = ' ';
	A[N / 9 + 2][M / c + 1] = ' ';
	A[N / 9 + 2][M / c + 2] = 'M';
	A[N / 9 + 2][M / c + 3] = 'E';
	A[N / 9 + 2][M / c + 4] = 'D';
	A[N / 9 + 2][M / c + 5] = 'I';
	A[N / 9 + 2][M / c + 6] = 'U';
	A[N / 9 + 2][M / c + 7] = 'M';
	A[N / 9 + 2][M / c + 8] = ' ';
	A[N / 9 + 4][M / c] = ' ';
	A[N / 9 + 4][M / c + 1] = ' ';
	A[N / 9 + 4][M / c + 2] = 'H';
	A[N / 9 + 4][M / c + 3] = 'A';
	A[N / 9 + 4][M / c + 4] = 'R';
	A[N / 9 + 4][M / c + 5] = 'D';
	A[N / 9 + 4][M / c + 6] = ' ';
	A[N / 9 + 6][M / c] = ' ';
	A[N / 9 + 6][M / c + 1] = ' ';
	A[N / 9 + 6][M / c + 2] = 'E';
	A[N / 9 + 6][M / c + 3] = 'X';
	A[N / 9 + 6][M / c + 4] = 'T';
	A[N / 9 + 6][M / c + 5] = 'R';
	A[N / 9 + 6][M / c + 6] = 'E';
	A[N / 9 + 6][M / c + 7] = 'M';
	A[N / 9 + 6][M / c + 8] = 'E';
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == 0 || i == N - 1)
				A[i][j] = '*';
			else
				if (j == 0 || j == M - 1)
					A[i][j] = '*';

		}

	}
	return A;
}
void RecordsMenu()
{
	system("cls");
	int n = 5;
	int* data = new int[n];
	ifstream rin("records.txt");
	for (int i = 0; i < n; i++)
		rin >> data[i];
	rin.clear();
	rin.close();
	char ** A = new char *[N];
	for (int i = 0; i < N; i++)
		A[i] = new char[M];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			A[i][j] = ' ';
	int c = 6;
	int x = data[0];
	int xk = 4;
	int l = 0;
	while (x > 0)
	{
		A[N / 9 + 2 * l][M / c + xk] = (x % 10) + '0';
		x /= 10;
		xk++;
		if (x == 0)
		{
			switch (xk - 4)
			{
			case 2:
				char tmp1;
				tmp1 = A[N / 9 + 2 * l][M / c + xk - 2];
				A[N / 9 + 2 * l][M / c + xk - 2] = A[N / 9 + 2 * l][M / c + xk - 1];
				A[N / 9 + 2 * l][M / c + xk - 1] = tmp1;
				break;
			case 3:
				char tmp2;
				tmp2 = A[N / 9 + 2 * l][M / c + xk - 1];
				A[N / 9 + 2 * l][M / c + xk - 1] = A[N / 9 + 2 * l][M / c + xk - 3];
				A[N / 9 + 2 * l][M / c + xk - 3] = tmp2;
				break;
			case 4:
				char tmp3;
				tmp3 = A[N / 9 + 2 * l][M / c + xk - 1];
				A[N / 9 + 2 * l][M / c + xk - 1] = A[N / 9 + 2 * l][M / c + xk - 4];
				A[N / 9 + 2 * l][M / c + xk - 4] = tmp3;
				tmp3 = A[N / 9 + 2 * l][M / c + xk - 2];
				A[N / 9 + 2 * l][M / c + xk - 2] = A[N / 9 + 2 * l][M / c + xk - 3];
				A[N / 9 + 2 * l][M / c + xk - 3] = tmp3;
				break;
			default: break;
			}
			l++;
			if (l == 6)
				break;
			xk = 4;
			x = data[l];
		}

	}
	for (int i = 0; i < 5; i++)
	{
		A[N / 9 + 2 * i][M / c + 2] = i + 1 + '0';
		A[N / 9 + 2 * i][M / c + 3] = '.';
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == 0 || i == N - 1)
				A[i][j] = '*';
			else
				if (j == 0 || j == M - 1)
					A[i][j] = '*';

		}

	}
	printMenu(A);

	delete[]data;
	delete[]A;
	_gettch();
}
int speedMenu()
{
	int P = 0;
	int c = 6;
	char **A = setSpeedMenu();
	printMenu(A);
	bool G = true;
	char tt;
	while (G == true)
	{
		blinkSpeed(A, P);
		if (_kbhit())
		{
			tt = _gettch();
			switch (tt)
			{
			case 's':
				if (P < 3)
					P++;
				else P = 0;
				switch (P)
				{
				case 0:
					A[N / 9][M / c + 1] = '>';
					clearscreen();
					printMenu(A);
					break;
				case 1:
					A[N / 9 + 2][M / c + 1] = '>';
					clearscreen();
					printMenu(A);
					break;
				case 2:
					A[N / 9 + 4][M / c + 1] = '>';
					clearscreen();
					printMenu(A);
					break;
				case 3:
					A[N / 9 + 6][M / c + 1] = '>';
					clearscreen();
					printMenu(A);
					break;
				default:
					break;

				}
				break;

			case 'w':
				if (P > 0)
					P--;
				else P = 3;
				switch (P)
				{
				case 0:
					A[N / 9][M / c + 1] = '>';
					clearscreen();
					printMenu(A);
					break;
				case 1:
					A[N / 9 + 2][M / c + 1] = '>';
					clearscreen();
					printMenu(A);
					break;
				case 2:
					A[N / 9 + 4][M / c + 1] = '>';
					clearscreen();
					printMenu(A);
					break;
				case 3:
					A[N / 9 + 6][M / c + 1] = '>';
					clearscreen();
					printMenu(A);
					break;
				default:
					break;

				}
				break;
			case VK_RETURN:
				G = false;
				break;
			default:

				break;
			}
		}

	}
	for (int i = 0; i < N; i++)
		delete[] A[i];
	delete[] A;
	switch (P)
	{
	case 0:
		return 85;
		break;
	case 1:
		return 65;
		break;
	case 2:
		return 40;
		break;
	case 3:
		return 25;
		break;
	default:
		break;
	}

}
void dvig_car(char **a, bool c, bool* cr)
{
	if (c == 0)
	{
		for (int j = height + 3; j > height - 1; j--)
		{
			if (a[height - 2][3] == '*') { *cr = 1; crushleft(a); break; }
			for (int i = 5; i < width - 1; i++)
				a[j][i] = a[j - 1][i];
		}
	}
	else
	{
		for (int j = height + 3; j > height - 1; j--)
		{
			if (a[height - 2][6] == '*') { *cr = 1; crushright(a); break; }
			for (int i = 2; i < width / 2; i++)
				a[j][i] = a[j - 1][i];
		}
	}


	for (int j = height - 1; j >0; j--)
		for (int i = 2; i < width - 1; i++)
			a[j][i] = a[j - 1][i];
	for (int i = 2; i < width - 1; i++)
		a[0][i] = ' ';

}
int MainMenu(int & SPEED)
{
	int P = 0;
	int c = 6;
	char **A = setMenu();
	printMenu(A);
	bool G = true;
	char tt;
	while (G == true)
	{
		blink(A, P);
		if (_kbhit())
		{
			tt = _gettch();
			switch (tt)
			{
			case 's':
				if (P < 3)
					P++;
				else P = 0;
				switch (P)
				{
				case 0:
					A[N / 9][M / c + 1] = '>';
					clearscreen();
					printMenu(A);
					break;
				case 1:
					A[N / 9 + 2][M / c + 1] = '>';
					clearscreen();
					printMenu(A);
					break;
				case 2:
					A[N / 9 + 4][M / c + 1] = '>';
					clearscreen();
					printMenu(A);
					break;
				case 3:
					A[N / 9 + 6][M / c + 1] = '>';
					clearscreen();
					printMenu(A);
					break;
				default:
					break;

				}
				break;

			case 'w':
				if (P > 0)
					P--;
				else P = 3;
				switch (P)
				{
				case 0:
					A[N / 9][M / c + 1] = '>';
					clearscreen();
					printMenu(A);
					break;
				case 1:
					A[N / 9 + 2][M / c + 1] = '>';
					clearscreen();
					printMenu(A);
					break;
				case 2:
					A[N / 9 + 4][M / c + 1] = '>';
					clearscreen();
					printMenu(A);
					break;
				case 3:
					A[N / 9 + 6][M / c + 1] = '>';
					clearscreen();
					printMenu(A);
					break;
				default:
					break;

				}
				break;
			case VK_RETURN:
				if (P == 1)
				{
					clearscreen();
					SPEED = speedMenu();
				}
				else
					if (P == 2)
					{
						clearscreen();
						RecordsMenu();
					}
					else
						G = false;
				break;
			default:

				break;
			}
		}

	}
	for (int i = 0; i < N; i++)
		delete[] A[i];
	delete[] A;
	if (P == 3)
		return 1;
	return 0;


}
void records(int score)
{
	int n = 5;
	int* data = new int[n];
	ifstream rin("records.txt");
	for (int i = 0; i < n; i++)
		rin >> data[i];
	if (data[n - 1] < score)
		data[n - 1] = score;
	else
	{
		rin.clear();
		rin.close();
		return;
	}
	rin.clear();
	rin.close();
	for (int i = n - 2; i > -1; i--)
	{
		if (data[i + 1] > data[i])
		{
			int z = data[i];
			data[i] = data[i + 1];
			data[i + 1] = z;
		}
		else break;
	}
	ofstream rout("records.txt");
	for (int i = 0; i < n; i++)
		rout << data[i] << ' ';
	rout.close();
	delete[]data;
}
void haste(char **a, int &aa, bool c, bool* cr, int ts)
{
	for (int i = 0; i < 5; i++)
	{


		dvig(a);
		dvig_car(a, c, cr);
		aa++;
		if (aa % 10 == 0)
			add_car(a);
		if (*cr == 1)
		{
			Sleep(1000);
			break;
		}
		clearscreen();
		printMap(a, aa, ts);
	}
}
void GameOver(int *s)
{
	system("cls");
	int scr = *s;
	cout << "****************\n*              *\n*              *\n*              *\n*              *\n*              *\n*              *\n*              *\n* !GAME OVER!  *\n*              *\n*              *\n*              *\n* !SCORE: " << *s << '!';
	if (scr < 10)cout << "   *";
	else
		if (scr < 100) cout << "  *";
		else
			if (scr < 1000) cout << " *";
			else
				if (scr<10000) cout << "*";
				else
					scr = 0;

	cout << "\n*              *\n*              *\n*              *\n*              *\n*              *\n*              *\n*              *\n*              *\n****************\n";
	records(*s);
	_gettch();
}
void crushright(char**a)
{
	char**tmp = new char*[4];
	for (int i = 0; i < 4; i++)
		tmp[i] = new char[3];
	int k = height + 3, f = 7;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tmp[i][j] = a[k][f];
			f--;
		}
		f = 7;
		k--;
	}
	int kf = 2;
	while (kf > 0)
	{
		for (k = height; k < height + 4; k++)
		{
			for (f = 5; f < 8; f++)
				a[k][f] = ' ';
		}
		clearscreen();
		for (int i = 4; i < height + 4; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cout << a[i][j];
			}
			cout << endl;
		}

		printline();
		Sleep(500);
		kf--;
		k = height + 3;
		f = 7;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				a[k][f] = tmp[i][j];
				f--;
			}
			f = 7;
			k--;
		}
		clearscreen();
		for (int i = 4; i < height + 4; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cout << a[i][j];
			}
			cout << endl;
		}

		printline();
		Sleep(500);
	}
	delete[] tmp;

}
void crushleft(char**a)
{
	char**tmp = new char*[4];
	for (int i = 0; i < 4; i++)
		tmp[i] = new char[3];
	int k = height + 3, f = 4;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tmp[i][j] = a[k][f];
			f--;
		}
		f = 4;
		k--;
	}
	int kf = 2;
	while (kf > 0)
	{

		for (k = height; k < height + 4; k++)
		{
			for (f = 2; f < 5; f++)
				a[k][f] = ' ';
		}
		clearscreen();
		for (int i = 4; i < height + 4; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cout << a[i][j];
			}
			cout << endl;
		}

		printline();
		Sleep(500);
		kf--;
		k = height + 3;
		f = 4;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				a[k][f] = tmp[i][j];
				f--;
			}
			f = 4;
			k--;
		}
		clearscreen();
		for (int i = 4; i < height + 4; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cout << a[i][j];
			}
			cout << endl;
		}

		printline();
		Sleep(500);
	}
	delete[] tmp;

}
void printMenu(char **a)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << a[i][j] << " ";

		}
		cout << endl;

	}
}