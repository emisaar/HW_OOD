#include <iostream>
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
    public:
        void start();
};

void MyGame::start()
{
    cout << "Snakes & Ladders" << endl;
    // Players
    Player *p1 = new Player(1);
    Player *p2 = new Player(2);

    // Tiles
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

    // CHECAR EL TABLERO
    // for (int j = 0; j < sizeof(tiles); j++)
    // {
    //     cout << tiles[j];
    // }


    while(turn <= 15)
    {
        cout << "Press C to continue next turn or E to end the game: ";
        cin >> userIn;
        cout << userIn << endl;

        while((userIn != 'C') && (userIn != 'E'))
        {
            cout << "Invalid operation. Please press C to continue next turn or E to end the game: ";
            cin >> userIn;
            cout << userIn << endl; 
        }

        if (userIn == 'C')
        {
            if (counterEnd%2 != 0)
            {
                // Player's turn
                cout << turn << " ";
                // Player number
                cout << p1->playerNum() << " ";

                // Tile before throwing
                cout << p1->getPos(temp1)  << " ";

                // Dice number
                diceP1 = p1->rollDice();
                cout << diceP1 << " ";
                // Tile symbol
                temp1 += diceP1;

                // Check position
                if (temp1 >= 30)
                {
                    cout << "\n-- GAME OVER --" << endl;
                    cout << "Player 1 is the winner!!!" << endl;
                    break;
                }
                // New position
                if (tiles[temp1] == 'S')
                {
                    //temp1 -= 3;
                    cout << tiles[temp1] << " ";
                    temp1 = p1->snake(temp1);
                    cout << temp1 << endl;
                } else if (tiles[temp1] == 'L')
                {
                    //temp1 += 3;
                    cout << tiles[temp1] << " ";
                    temp1 = p1->ladder(temp1);
                    cout << temp1 << endl;
                } else{
                    cout << tiles[temp1] << " " << temp1 << endl;
                }
                
            }else{
                // Player's turn
                cout << turn << " ";
                // Player number
                cout << "2" << " ";
                // Tile before throwing
                cout << p2->getPos(temp2) << " ";
                // Dice number
                diceP2 = p2->rollDice();
                cout << diceP2 << " ";
                // Tile symbol
                temp2 += diceP2;

                // Check position
                if (temp2 >= 30)
                {
                    cout << "\n-- GAME OVER --" << endl;

                    cout << "Player 2 is the winner!!!" << endl;
                    break;
                }
                
                // New position
                if (tiles[temp2] == 'S')
                {
                    //temp2 -= 3;
                    cout << tiles[temp2] << " ";
                    temp2 = p2->snake(temp2);

                    cout << temp2 << endl;
                } else if (tiles[temp2] == 'L')
                {
                    //temp2 += 3;
                    cout << tiles[temp2] << " ";
                    temp2 = p2->ladder(temp2);
                
                    cout << temp2 << endl;
                } else{
                    cout << tiles[temp2] << " " << temp2 << endl;
                }
                turn += 1;
                
            }

        }else{
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