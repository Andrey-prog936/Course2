#pragma once

HANDLE colr = GetStdHandle(STD_OUTPUT_HANDLE);
#define def SetConsoleTextAttribute(colr, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
#define green SetConsoleTextAttribute(colr,FOREGROUND_GREEN);
#define orange SetConsoleTextAttribute(colr,FOREGROUND_GREEN | FOREGROUND_RED);
#define red SetConsoleTextAttribute(colr,FOREGROUND_RED);
#define blue SetConsoleTextAttribute(colr,FOREGROUND_BLUE);
#define cyan SetConsoleTextAttribute(colr,FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);