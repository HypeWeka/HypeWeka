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
void add_car(char **a);
void dvig_car(char **a, bool c, bool* cr);
void haste(char **a, int &aa, bool c, bool* cr);
bool preright(char**a);
bool preleft(char**a);
void GameOver(int *s);
void crushleft(char**a);
void crushright(char**a);

int main()
{
	
	MainMenu();
	if (MainMenu==0)
	{
	return 0;
	}
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int x = 20, y = 3;
	char** map = new char*[height + 4];

	for (int i = 0; i<height + 4; i++)
		map[i] = new char[width];

	setMap(map, x, y);

	char move;
	int kscore = 0;
	bool coordinat = 0;
	bool crush = 0;
	while (true)
	{
		if (crush == 1)
			break;
		else
		{
			clearscreen();
			printMap(map, kscore);
			if (kscore % 10 == 0)
				add_car(map);
			Sleep(80);
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
					coordinat = 0;
					if (preleft(map) == 0)
					{
						crushright(map);
						break;
					}
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
				if (move == VK_SPACE)
					haste(map, kscore, coordinat, &crush);
			}
			if (_kbhit()) {
				move = _getch();
				if (move == VK_SPACE)
					haste(map, kscore, coordinat, &crush);
			}
			dvig_car(map, coordinat, &crush);
			kscore++;
			dvig(map);
		}
	}
	clearscreen();
	GameOver(&kscore);
	delete[] map;
	return 0;
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
	for (int i = 4; i<height + 4; i++)
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

int MainMenu()
{
	setlocale(0, "");
	srand(unsigned(time(NULL)));
	int N, M;
	char P;
	//cout << "Введите размер матрицы: ";
	N = 20;
	M = 10;
	char ** A = new char *[N];
	for (int i = 0; i < N; i++)
		A[i] = new char[M];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			A[i][j] = 256;

	A[N / 9][M / 9] = '1';
	A[N / 9][M / 9 + 1] = '.';
	A[N / 9][M / 9 + 2] = 83;
	A[N / 9][M / 9 + 3] = 'T';
	A[N / 9][M / 9 + 4] = 'A';
	A[N / 9][M / 9 + 5] = 'R';
	A[N / 9][M / 9 + 6] = 'T';
	A[N / 9 + 4][M / 9] = '0';
	A[N / 9 + 4][M / 9 + 1] = '.';
	A[N / 9 + 4][M / 9 + 2] = 'E';
	A[N / 9 + 4][M / 9 + 3] = 'X';
	A[N / 9 + 4][M / 9 + 4] = 'I';
	A[N / 9 + 4][M / 9 + 5] = 'T';
	A[N / 9 + 2][M / 9] = '2';
	A[N / 9 + 2][M / 9 + 1] = '.';
	A[N / 9 + 2][M / 9 + 2] = 'S';
	A[N / 9 + 2][M / 9 + 3] = 'P';
	A[N / 9 + 2][M / 9 + 4] = 'E';
	A[N / 9 + 2][M / 9 + 5] = 'E';
	A[N / 9 + 2][M / 9 + 6] = 'D';






	//вывод матрицы
	//cout << "Вот Ваша матрица:" << endl << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}

	cout << endl;
	for (int i = 0; i < N; i++)
		delete[] A[i];
	delete[] A;
	//getch();
	bool G = true;

	do
	{
		P = _getch();
		if (P == '1')
		{
			return 1;
			G = false;
		}
		if (P == '0')
		{
			return 0;
			G = false;
		}

		//Вставить сюда функцию меню сложности
	

	} 
	while (G==true);
	

}

void haste(char **a, int &aa, bool c, bool* cr)
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
		printMap(a, aa);
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
