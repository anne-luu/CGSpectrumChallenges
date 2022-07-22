#include <iostream>
#include "TTTGame.h"

using namespace std;

int main()
{
    bool quit = false;
    bool validInput = false;

    char input;

    while (!validInput)
    {
        cout << "Choose either 'x' or 'o': ";
        cin >> input;

        if (input == 'o' || input == 'x')
        {
            validInput = true;
        }
        else
            cout << "Invalid input, please try again." << endl;
        
    }

    system("cls");

    TTTGame* game = new TTTGame(input);

    //Draw tic tac toe board
    game->Draw();

    while (!quit)
    {
        cin >> input;

        switch (input)
        {
        case 'w':
        case 'a':
        case 's':
        case 'd':
        case 'x':
        case 'o':
        case 'h':
            cout << "Pressed '" << input << "'" << endl;
            game->EnterInput(input);
            break;
        case 'q':
        default:
            cout << "Quitting" << endl;
            quit = true;
        }

        system("cls");

        game->Draw();

        if (game->HasWon())
        {
            cout << "You win!!" << endl;
            quit = true;
        }
    }

    return 0;
}
