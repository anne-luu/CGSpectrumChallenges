#pragma once
#include<iostream>
#include<iomanip>
#include "TTTCell.h"

using namespace std;

struct Position
{
	int x;
	int y;
};

enum class WASD : unsigned short
{
	W,
	A,
	S,
	D
};

class TTTGame
{
	Position cursor;
	TTTCell* grid[3][3];
	bool cursorVisibility;
	const char playerInput;
	char opponentInput;
	bool won;

public:
	TTTGame(char input);
	void Draw();
	void MoveCursor(WASD key, int increment);
	void XOInput(char xoInput);
	void ToggleCursorVisibility();
	void EnterInput(char input);
	bool CheckWin(bool forPlayer);

	//Getter
	bool HasWon()
	{
		return won;
	}
};

