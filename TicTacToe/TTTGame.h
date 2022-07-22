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

constexpr int gridSize = 3;

class TTTGame
{
	Position cursor;
	TTTCell* grid[gridSize][gridSize];
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

