#include "Maze.h"
#include "Coloring.h"
void Labirint::GameOver()
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

void Labirint::YouWin(clock_t t0)
{
	system("mode con cols=61 lines=19");
	cout << "Time: " << ((int)(t1 - t0) / CLOCKS_PER_SEC) * -1 << " seconds" << endl;
	green
		cout << R"(  _     _   _____   _   _     _         _   _   _ __     _
 \ \   / / /  _  \ | | | |   | |   _   | | | | | |\ \   | |
  \ \_/ /  | | | | | | | |   | |  / \  | | | | | | \ \  | |
   \   /   | | | | | | | |   | | / _ \ | | | | | |  \ \ | |
    | |    | |_| | | |_| |   | |/ / \ \| | | | | |   \ \| |
    |_|    \_____/ \_____/   \___/   \___/ |_| |_|    \_|_|

)";
	def
		Restart();
}

void Labirint::Restart()
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
		cls;
		this->x = 1;	this->y = 1;
		this->t1 = clock();
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

void Labirint::Show(int point)
{
	for (int i = 0; i < x2; i++)
	{
		for (int j = 0; j < y2 - 1; j++)
		{
			if (map[i][j] == '@')
			{
				orange	cout << map[i][j];	def
			}
			else if (map[i][j] == '#')
			{
				red	cout << map[i][j];	def
			}
			else if (map[i][j] == 'F')
			{
				green	cout << map[i][j];	def
			}
			else if (map[i][j] == player)
			{
				cyan	cout << map[i][j];	def
			}
			else if (map[i][j] == '|')
			{
				if (point >= 19)
					map[i][j] = ' ';
				blue	cout << map[i][j];	def
			}
			else
			{
				blue	cout << map[i][j];	def
			}

		}
		cout << endl;
	}
	cout << "\t\tPoint: " << point << "/19" << endl;
}

int Labirint::MoveRight(int x, int y, int point, clock_t t0)
{
	cls;
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
		cls;
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

int Labirint::MoveLeft(int x, int y, int point, clock_t t0)
{
	cls;
	if (map[x][y - 1] == '*' || map[x][y - 1] == '|')
	{
	}
	else if (map[x][y - 1] == '#')
	{
		map[x][y] = ' ';
		GameOver();
		return 0;
	}
	else if (map[x][y - 1] == 'F')
	{
		cls;
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

int Labirint::MoveUp(int x, int y, int point, clock_t t0)
{
	cls;
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
		cls;
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

int Labirint::MoveDown(int x, int y, int point, clock_t t0)
{
	cls;
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
		cls;
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
	this->x = x;
	this->y = y;
	Show(this->point);
}

void Labirint::Save()
{
	int x, y;
	ofstream ofs("Save.txt");
	for (int i = 0; i < this->x2; i++)
	{
		for (int j = 0; j < this->y2; j++)
		{
			if (map[i][j] == player)
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
	ofs << this->point << endl;
	ofs.close();
	PlayGame();
}

void Labirint::Load()
{
	char symvol;
	ifstream in1("Save.txt");
	for (int i = 0; i < this->x2; i++)
	{
		for (int j = 0; j < this->y2; j++)
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

int Labirint::PlayGame()
{
	system("mode con cols=44 lines=20");
	if (detect)
	{
		cout << "Enter the symbol you want to play: ";
		cin >> player; detect = 0; cls;
	}
	map[x][y] = player;
	clock_t t0 = clock();
	Show(point);
	t1 = 0;
	for (;;)
	{
		int d = _getch();
		if (d == 100 || d == 97 || d == 119 || d == 115 || d == 112 || d == 96)
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
			case 112: // p
			{
				Menu();
			}break;
			case 96: // ~
			{
				Console();
			}break;
			default:
				cout << "\nError404\n" << endl;
				return 0;
				break;
			}
		}
	}
}

void Labirint::Console()
{
	cls;
	green
		cout << "\t\tConsole" << endl;
	red cout << "\t\t\t\tq - quit" << endl;
	green
		string action;
	int da = 11;

	do
	{
		cout << "~:";
		cin >> action;
		if (action == "breakleft")		//	breakleft  --- break the wall on the left
			da = 0;
		if (action == "breakright")		//	breakright --- break the wall on the right
			da = 1;
		if (action == "breakup")		//	breakup    --- break the wall on the up
			da = 2;
		if (action == "breakdown")		//	breakdown  --- break the wall on the left
			da = 3;
		if (action == "addpoint")		//	addpoint   --- get 999 points
			da = 4;
		if (action == "q" || action == "Q")
			da = 8;

		switch (da)
		{
		case 8:
		{
			PlayGame();
		}break;
		case 0:
		{
			if (map[x][y - 1] == '*')
				map[x][y - 1] = ' ';
		}break;
		case 1:
		{
			if (map[x][y + 1] == '*')
				map[x][y + 1] = ' ';
		}break;
		case 2:
		{
			if (map[x - 1][y] == '*')
				map[x - 1][y] = ' ';
		}break;
		case 3:
		{
			if (map[x + 1][y] == '*')
				map[x + 1][y] = ' ';
		}break;
		case 4:
		{
			this->point = 999;
		}break;
		default:
			cout << "~:Wrong command" << endl;
			break;
		}
	} while (action != "q");

}

Labirint::Labirint() : point(0), x(1), y(1)
{
	player = '$';
	char symvol;
	ifstream in1("level.txt");
	for (int i = 0; i < this->x2; i++)
	{
		for (int j = 0; j < this->y2; j++)
		{
			in1.get(symvol);
			map[i][j] = symvol;
		}
	}
	in1.close();
}

void Labirint::Guid()
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

void Labirint::Menu()
{
	int df = 0;
	do
	{
		cls;
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
		case 96:
		{
			Console();
		}break;

		default:
			cout << "Error" << endl;
			break;
		}
	} while (df != 6);

}
////////////////////////////////////
void HideConsoleCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}