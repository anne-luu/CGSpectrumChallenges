#include "TTTGame.h"

TTTGame::TTTGame(char input)
	:cursorVisibility(true)
	,playerInput(input)
{
	//Initialize array to ' '
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			grid[i][j] = new TTTCell();

	(*grid[1][1]).displayValue = '@';

	//Initialize current cursor position to be the center
	cursor.x = 1;
	cursor.y = 1;

	if (playerInput == 'o')
		opponentInput = 'x';
	else
		opponentInput = 'o';
}

void TTTGame::Draw()
{
	cout << "Use w,a,s,d key to move '@' cursor. Press " << playerInput << " to enter value." << endl;
	cout << "-------" << endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << "|" << grid[i][j]->displayValue;

		cout << "|" << endl;
	}

	cout << "-------" << endl;
}

void TTTGame::MoveCursor(WASD key, int increment)
{
	if (key == WASD::W || key == WASD::S)
	{
		if (cursor.y + increment >= 0 && cursor.y + increment < 3)
		{
			(*grid[cursor.y][cursor.x]).displayValue = (*grid[cursor.y][cursor.x]).value;
			cursor.y += increment;
			(*grid[cursor.y][cursor.x]).displayValue = '@';
		}
	}
	else if (key == WASD::A || key == WASD::D)
	{
		if (cursor.x + increment >= 0 && cursor.x + increment < 3)
		{
			(*grid[cursor.y][cursor.x]).displayValue = (*grid[cursor.y][cursor.x]).value;
			cursor.x += increment;
			(*grid[cursor.y][cursor.x]).displayValue = '@';
		}
	}

	cout << "X: " << cursor.x << " Y: " << cursor.y << endl;
}

void TTTGame::XOInput(char xoInput)
{
	//Check if current cell has a value
	if ((*grid[cursor.y][cursor.x]).value == ' ')
	{
		if (xoInput == 'x')
			(*grid[cursor.y][cursor.x]).value = 'x';
		else if (xoInput == 'o')
			(*grid[cursor.y][cursor.x]).value = 'o';
	}
}

void TTTGame::ToggleCursorVisibility()
{
	if (cursorVisibility)
		(*grid[cursor.y][cursor.x]).displayValue = (*grid[cursor.y][cursor.x]).value;
	else
		(*grid[cursor.y][cursor.x]).displayValue = '@';

	//Flip boolean
	cursorVisibility = !cursorVisibility;
}

void TTTGame::EnterInput(char input)
{
	switch (input)
	{
	case 'w':
		MoveCursor(WASD::W, -1);
		break;
	case 'a':
		MoveCursor(WASD::A, -1);
		break;
	case 's':
		MoveCursor(WASD::S, 1);
		break;
	case 'd':
		MoveCursor(WASD::D, 1);
		break;
	case 'x':
	case 'o':
		XOInput(input);
		break;
	case 'h':
		ToggleCursorVisibility();
		break;
	}
}