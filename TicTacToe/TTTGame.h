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
	// My only comment is you don't need to have an array of pointer to TTTCell and have to delete it from the heap
	// You can do TTTCell grid[gridSize][gridSize], and it will create of 2D array of type TTTCell
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

