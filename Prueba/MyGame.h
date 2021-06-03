#include <iostream>
#include <fstream>
#include <stdbool.h>
//#include "Player.h"
#include "Board.h"
#include "Tile.h"

using namespace std;

class MyGame : public Board, public Tiles
{
protected:
    int diceP1, diceP2;
    int temp1 = 1;
    int temp2 = 1;
    char userIn;
    int turn = 1;
    int counterEnd = 1;
    int gameMode;
    int turns;

public:
    void start();
};

void MyGame::start()
{
    cout << "Snakes & Ladders" << endl;
    // Players are created
    Player *p1 = new Player(1);
    Player *p2 = new Player(2);

    cout << "Do you want a default game mode (0) or customize it (1)?" << endl;
    cin >> gameMode;
    while (gameMode != 0 && gameMode != 1)
    {
        cout << "Invalid option. Press 0 or 1." << endl;
        cin >> gameMode;
    }

    if (gameMode == 0)
    {
        Board b1();
    }
    else
    {
        int tileN, snakesN, laddersN, penalty, reward, turnsN;
        cout << "Enter the number of tiles: ";
        cin >> tileN;
        cout << "Enter the number of snakes: ";
        cin >> snakesN;
        cout << "Enter the number of ladders: ";
        cin >> laddersN;
        cout << "Enter the penalty value: ";
        cin >> penalty;
        cout << "Enter the reward value: ";
        cin >> reward;
        cout << "Enter the number of turns: ";
        cin >> turnsN;

        Board b1(tileN, snakesN, laddersN, penalty, reward, turnsN);
    }

    while (turn <= turns) // Maximum number of shifts is 15
    {
        // Prints the instruction to start the game
        cout << "Press C to continue next turn or E to end the game: ";
        cin >> userIn;

        while ((userIn != 'C') && (userIn != 'E'))
        {
            // Check if the option is valid
            cout << "Invalid operation. Please press C to continue next turn or E to end the game: ";
            cin >> userIn;
        }

        if (userIn == 'C')
        {
            // The game start
            if (counterEnd % 2 != 0)
            {
                // Player's turn
                cout << turn << " ";
                // Player number
                cout << p1->playerNum() << " ";

                // Tile before throwing
                cout << p1->getPos(temp1) << " ";

                // Dice number
                diceP1 = p1->rollDice();
                cout << diceP1 << " ";
                // Tile symbol
                temp1 += diceP1;

                // New position
                if (tiles[temp1] == 'S')
                {
                    //if the tile is a snake the position changes -= 3
                    cout << tiles[temp1] << " ";
                    temp1 = p1->snake(temp1);
                    cout << temp1 << endl;
                }
                else if (tiles[temp1] == 'L')
                {
                    //if the tile is a ladder the position changes += 3
                    cout << tiles[temp1] << " ";
                    temp1 = p1->ladder(temp1);
                    cout << temp1 << endl;
                }
                else
                {
                    // else the tile is normal
                    cout << tiles[temp1] << " " << temp1 << endl;
                }
                // Check position
                if (temp1 >= 30)
                {
                    // If the position is 30 or more the player win
                    cout << "\n-- GAME OVER --" << endl;
                    cout << "Player 1 is the winner!!!" << endl;
                    break;
                }
            }
            else
            {
                // Player's turn
                cout << turn << " ";
                // Player number
                cout << "2 ";
                // Tile before throwing
                cout << p2->getPos(temp2) << " ";
                // Dice number
                diceP2 = p2->rollDice();
                cout << diceP2 << " ";
                // Tile symbol
                temp2 += diceP2;

                // New position
                if (tiles[temp2] == 'S')
                {
                    //if the tile is a snake the position changes -= 3
                    cout << tiles[temp2] << " ";
                    temp2 = p2->snake(temp2);

                    cout << temp2 << endl;
                }
                else if (tiles[temp2] == 'L')
                {
                    //if the tile is a ladder the position changes += 3
                    cout << tiles[temp2] << " ";
                    temp2 = p2->ladder(temp2);

                    cout << temp2 << endl;
                }
                else
                {
                    // else the tile is normal
                    cout << tiles[temp2] << " " << temp2 << endl;
                }

                // Check position
                if (temp2 >= 30)
                {
                    // If the position is 30 or more the player win
                    cout << "\n-- GAME OVER --" << endl;

                    cout << "Player 2 is the winner!!!" << endl;
                    break;
                }
                turn += 1;
            }
        }
        else
        {
            // If the user enters 'E' the game stop
            cout << "Thanks for playing!!!" << endl;
            break;
        }
        counterEnd += 1;
    }
    if (turn >= 15)
    {
        cout << "The maximum number of turns has been reached..." << endl;
    }
}