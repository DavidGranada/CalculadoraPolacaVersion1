#pragma once
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	_COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(hConsole, pos);
}