#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include "Coloring.h"
using namespace std;
class Labirint
{
private:
	char player;
	int point;
	int x, y;
	static const int x2 = 17, y2 = 43;
	char map[x2][y2];
	/////////////////////////////////////////////
	void GameOver()
	{
		system("mode con cols=78 lines=19");
		red
		cout << R"(  ______      ___       ___  ___   ____      _____   _     _   ____   ____
 /  ___/     /   |     /   |/   | |  __|    /  _  \ | |   / / | ___| |  _ \
 | |        / /| |    / /|   /| | | |___    | | | | | |  / /  | |__  | |_| |
 | |  _    / __  |   / / |__/ | | |  ___|   | | | | | | / /   | __|  |  _ /
 | |_| |  / /  | |  / /       | | | |____   | |_| | | |/ /    | |___ | | \ \
 \_____/ /_/   |_| /_/        |_| |______|  \_____/ |___/     |_____||_|  \_\ 

)";
		def
		Restart();
	}
	/////////////////////////////////////////////
	void YouWin(clock_t t0)
	{
		system("mode con cols=60 lines=19");
		clock_t t1 = clock();
		cout << "Time: " << (int)(t1 - t0) / CLOCKS_PER_SEC << " seconds" << endl;
		green
		cout << R"(  _     _   _____   _   _    _         _   _   _ __     _
 \ \   / / /  _  \ | | | |  | |   _   | | | | | |\ \   | |
  \ \_/ /  | | | | | | | |  | |  / \  | | | | | | \ \  | |
   \   /   | | | | | | | |  | | / _ \ | | | | | |  \ \ | |
    | |    | |_| | | |_| |  | |/ / \ \| | | | | |   \ \| |
    |_|    \_____/ \_____/  \___/   \___/ |_| |_|    \_|_|

)";
		def
		Restart();
	}
	//////////////////////////////////////////////
	int Restart()
	{
		cout << "Want to try again?" << endl;
		cout << "1 - Yes\n2 - No" << endl;
		int d;
		cout << "Please select: ";
		cin >> d;
		switch (d)
		{
		case 1:
		{
			system("cls");
			this->x = 1;	this->y = 1;
			PlayGame();
		}break;
		case 2:
		{
			cout << "OK, Good Bye" << endl;
			exit(0);
		}break;
		default:
			cout << "Incorrect number" << endl;
			break;
		}

	}
	//////////////////////////////////////////////
	void Show(int point)
	{
		for (int i = 0; i < x2; i++)
		{
			for (int j = 0; j < y2 - 1; j++)
			{
				if (map[i][j] == '@')
				{
					orange
					cout << map[i][j];
					def
				}
				else if (map[i][j] == '#')
				{
					red
						cout << map[i][j];
					def
				}
				else if (map[i][j] == player)
				{
					cyan
						cout << map[i][j];
					def
				}
				else
				{
					blue
					cout << map[i][j];
					def
				}
				
			}
			cout << endl;
		}
		cout << "Point: " << point << "/19" << endl;
	}
	//////////////////////////////////////////////
	int MoveRight(int x, int y, int point, clock_t t0)
	{
		system("cls");
		if (map[x][y + 1] == '*')
		{
		}
		else if (map[x][y + 1] == '#')
		{
			map[x][y] = ' ';
			GameOver();
			return 0;
		}
		else if (map[x][y + 1] == 'F')
		{
			system("cls");
			YouWin(t0);
			return 0;
		}
		else if (map[x][y + 1] == '@')
		{
			map[x][y] = ' ';
			map[x][++y] = player;
			this->point = point + 1;
		}
		else {
			map[x][y] = ' ';
			map[x][++y] = player;
		}
		this->x = x;
		this->y = y;
		Show(this->point);
	}

	int MoveLeft(int x, int y, int point, clock_t t0)
	{
		system("cls");
		if (map[x][y - 1] == '*' || map[x][y - 1] == '|')
		{
		}
		else if (map[x][y - 1] == '#')
		{
			map[x][y] = ' ';
			GameOver();
			clock_t t1 = clock();
			cout << "Time: " << (int)(t1 - t0) / CLOCKS_PER_SEC << " seconds" << endl;
			return 0;
		}
		else if (map[x][y - 1] == 'F')
		{
			system("cls");
			
			YouWin(t0);
			return 0;
		}
		else if (map[x][y - 1] == '@')
		{
			map[x][y] = ' ';
			map[x][--y] = player;
			this->point = point + 1;
		}
		else
		{
			map[x][y] = ' ';
			map[x][--y] = player;
		}
		this->x = x;
		this->y = y;
		Show(this->point);
	}

	int MoveUp(int x, int y, int point, clock_t t0)
	{
		system("cls");
		if (map[x - 1][y] == '*')
		{
		}
		else if (map[x - 1][y] == '#')
		{
			map[x][y] = ' ';
			GameOver();
			return 0;
		}
		else if (map[x - 1][y] == 'F')
		{
			system("cls");
			YouWin(t0);
			return 0;
		}
		else if (map[x - 1][y] == '@')
		{
			map[x][y] = ' ';
			map[--x][y] = player;
			this->point = point + 1;
		}
		else {
			map[x][y] = ' ';
			map[--x][y] = player;
		}
		this->x = x;
		this->y = y;
		Show(this->point);
	}

	int MoveDown(int x, int y, int point, clock_t t0)
	{
		system("cls");
		if (map[x + 1][y] == '*')
		{
		}
		else if (map[x + 1][y] == '#')
		{
			map[x][y] = ' ';
			GameOver();
			return 0;
		}
		else if (map[x + 1][y] == 'F')
		{
			system("cls");
			YouWin(t0);
			return 0;
		}
		else if (map[x + 1][y] == '@')
		{
			map[x][y] = ' ';
			map[++x][y] = player;
			this->point = point + 1;
		}
		else {
			map[x][y] = ' ';
			map[++x][y] = player;
		}
		if (point == 19) { map[15][34] = ' '; }
		this->x = x;
		this->y = y;
		Show(this->point);
	}

	void Save()
	{
		int x, y;
		ofstream ofs("Save.txt");
		for (int i = 0; i < 17; i++)
		{
			for (int j = 0; j < 43; j++)
			{
				if (map[i][j] == '$')
				{
					ofs << ' ';
					x = i;	y = j;
				}
				else
				{
					ofs << map[i][j];
				}
			}
		}
		ofs << endl;
		ofs << x << endl;;
		ofs << y << endl;
		ofs << this->point<<endl;
		ofs.close();
		PlayGame();
	}

	void Load()
	{
		char symvol;
		ifstream in1("Save.txt");
		for (int i = 0; i < 17; i++)
		{
			for (int j = 0; j < 43; j++)
			{
				in1.get(symvol);
				map[i][j] = symvol;
			}
		}
		in1 >> this->x;
		in1 >> this->y;
		in1 >> this->point;
		in1.close();
		PlayGame();
	}

	int PlayGame()
	{
		system("mode con cols=44 lines=20");
		map[x][y] = player;
		clock_t t0 = clock();
		Show(point);
		for (;;)
		{
			int d = _getch();
			if (d == 100 || d == 97 || d == 119 || d == 115 || d == 112)
			{
				switch (d)
				{
				case 100: // d
				{
					MoveRight(x, y, point, t0);
				}break;
				case 97: // a
				{
					MoveLeft(x, y, point, t0);
				}break;
				case 119: // w
				{
					MoveUp(x, y, point, t0);
				}break;
				case 115: // s
				{
					MoveDown(x, y, point, t0);
				}break;
				case 112: // s
				{
					Menu();
				}break;
				default:
					cout << "\nError404\n" << endl;
					return 0;
					break;
				}
			}
		}
	}

public:
	Labirint() : point(0),x(1),y(1)
	{
		player = '$';
		char symvol;
		ifstream in1("level.txt");
		for (int i = 0; i < 17; i++)
		{
			for (int j = 0; j < 43; j++)
			{
				in1.get(symvol);
				map[i][j] = symvol;
			}
		}
		in1.close();
	}
	void Guid()
	{
		system("mode con cols=78 lines=19");
		green
			cout << R"(|=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|                           |
|        /-----\	    |
|        |_W___|	    |
|        |_____|	    |
|        \-----/	    |
|   /-----\/-----\/-----\   |
|   |_A___||_S___||_D___|   |
|   |_____||_____||_____|   |
|   \-----/\-----/\-----/   |
|                           |
|-=-=-=-=-=Control=-=-=-=-=-|
)";
		red    cout << "|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n|";
		orange cout << "Please select an English keyboard layout and off CapsLock"; red cout << "|" << endl;
		red    cout << "|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n ";
		def
		system("pause");
	}
	void Menu()
	{
		int df;
		system("cls");
		cout << "1 - Start to game" << endl;
		cout << "2 - Back to game" << endl;
		cout << "3 - Save game" << endl;
		cout << "4 - Load game" << endl;
		cout << "5 - Restart" << endl;
		cout << "6 - Exit!" << endl;
		cout << "Select: ";
		cin >> df;
		switch (df)
		{
		case 1:
		{
			PlayGame();
		}break;
		case 2:
		{
			PlayGame();
		}break;
		case 3:
		{
			Save();
		}break;
		case 4:
		{
			Load();
		}break;
		case 5:
		{
			Restart();
		}break;
		case 6:
		{
			exit(0);
		}break;

		default:
			cout << "Error" << endl;
			break;
		}
	}
};

void HideConsoleCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

int main()
{
	HideConsoleCursor();
	Labirint game;
	game.Guid();
	game.Menu();


	return 0;
}