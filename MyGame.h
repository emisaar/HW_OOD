// VERSION PRUEBA SOFI
#include <iostream>
#include <fstream>
#include <stdbool.h>
#include "Player.h"

using namespace std;

class MyGame
{
protected:
    int diceP1, diceP2;
    int temp1 = 1;
    int temp2 = 1;
    char userIn;
    int turn = 1;
    int counterEnd = 1;
    int mode; // ACTUALIZAR UML
    // Matrix to save the characters from the txt
    char matriz[14][1];
    int check;

public:
    void start();
    void readFIle();
};

void MyGame::start()
{
    cout << "Snakes & Ladders" << endl;
    // Players are created
    Player *p1 = new Player(1);
    Player *p2 = new Player(2);

    // Tiles are created
    char tiles[30];
    for (int i = 1; i <= 30; i++)
    {
        // Fill the tiles
        if (i == 5 || i == 17 || i == 28)
        {
            tiles[i] = 'S';
        }
        else if (i == 8 || i == 13 || i == 26)
        {
            tiles[i] = 'L';
        }
        else
        {
            tiles[i] = 'N';
        }
    }

    // Menu to choose how to play
    cout << "Press 1 to play manually or 2 to play with a .txt file: ";
    cin >> mode;

    if (mode == 2)
    {
        ifstream fp("inputSnake.txt"); // Reads the file

        for (int j = 0; j < 14; j++)
        {
            // The data is saved in their corresponding position
            fp >> matriz[0][j];
        }
        check = 2;
    }

    while (turn <= 15) // It limits to play up to 15 turns
    {
        if (check == 2)
        {
            cout << "Press C to continue next turn or E to end the game: \n";

            userIn = matriz[0][turn - 1];
        }
        else
        {
            cout << "Press C to continue next turn or E to end the game: " << endl;
            cin >> userIn;
            while ((userIn != 'C') && (userIn != 'E'))
            {
                // Check if the option is valid
                cout << "Invalid operation. Please press C to continue next turn or E to end the game: ";
                cin >> userIn;
            }
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
                    if (temp1 >= 30)
                    {
                        cout << "N 30" << endl;
                    }
                    else
                    {
                        cout << tiles[temp1] << " " << temp1 << endl;
                    }
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
                    if (temp2 >= 30)
                    {
                        cout << "N 30" << endl;
                    }
                    else
                    {
                        cout << tiles[temp2] << " " << temp2 << endl;
                    }
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