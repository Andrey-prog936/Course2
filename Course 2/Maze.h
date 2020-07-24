#pragma once

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
using namespace std;

class Labirint
{
private:
	bool detect = 1;
	char player;
	int point;
	int x, y;
	static const int x2 = 17, y2 = 43;
	char map[x2][y2];
	clock_t t1 = clock();
	/////////////////////////////////////////////
	void GameOver();
	void YouWin(clock_t t0);
	//////////////////////////////////////////////
	void Restart();
	//////////////////////////////////////////////
	void Show(int point);
	//////////////////////////////////////////////
	int MoveRight(int x, int y, int point, clock_t t0);

	int MoveLeft(int x, int y, int point, clock_t t0);

	int MoveUp(int x, int y, int point, clock_t t0);

	int MoveDown(int x, int y, int point, clock_t t0);

	void Save();

	void Load();

	int PlayGame();

	void Console();



public:
	Labirint();
	void Guid();
	void Menu();
};

void HideConsoleCursor();