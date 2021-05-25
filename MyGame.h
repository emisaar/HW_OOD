#include <iostream>
#include "Player.h"

using namespace std;

class MyGame 
{
    public:
        void start();
};

void MyGame::start()
{
    int diceP1, diceP2;
    int temp1 = 1;
    int temp2 = 1;
    char userIn;
    int turn = 0; 
    int counterEnd = 1;
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


    while(counterEnd<5)
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
            cout << "continue" << endl;
            if (counterEnd%2 != 0)
            {
                // Player's turn
                cout << turn + 1 << endl;
                // Player number
                cout << "Player 1 turn" << endl;
                // Tile before throwing
                cout << "Before" << temp1 << endl;
                // Dice number
                diceP1 = p1->rollDice();
                cout << "Dice: " << diceP1 << endl;
                // Tile symbol
                temp1 += diceP1;
                cout << "Tile: " << tiles[temp1] << endl;
                // New position
                if (tiles[temp1] == 'S')
                {
                    cout << "Penalty -3" << endl;
                    temp1 -= 3;
                    cout << temp1 << tiles[temp1] << endl;
                } else if (tiles[temp1] == 'L')
                {
                    temp1 += 3;
                    cout << temp1 << tiles[temp1] << endl;
                } else{
                    cout << temp1 << tiles[temp1] << endl;
                }
                
            }else{
                // Player's turn
                cout << turn << endl;
                // Player number
                cout << "Player 2 turn" << endl;
                // Tile before throwing
                cout << "Before" << temp2 << endl;
                // Dice number
                diceP2 = p2->rollDice();
                cout << "Dice: " << diceP2 << endl;
                // Tile symbol
                temp2 += diceP2;
                cout << "Tile: " << tiles[temp2] << endl;
                // New position
                if (tiles[temp2] == 'S')
                {
                    temp2 -= 3;
                    cout << temp2 << tiles[temp2] << endl;
                } else if (tiles[temp2] == 'L')
                {
                    temp2 += 3;
                    cout << temp2 << tiles[temp2] << endl;
                } else{
                    cout << temp2 << tiles[temp2] << endl;
                }
            }

        }else{
            cout << "End game" << endl;
            break;
        }
        counterEnd += 1;
    }
}