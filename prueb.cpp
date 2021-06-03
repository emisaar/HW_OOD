#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <stdbool.h>
#include "Board.h"

using namespace std;

int num;
int numTiles;
int numSnakes;

int main()
{
    cin >> numTiles;
    cin >> numSnakes;
    // Create the empty board
    char tiles[numTiles];

    // Create random numbers and save them in an array
    int snakeList[numSnakes];
    for (int s = 0; s < numSnakes; s++)
    {
        srand(time(NULL));
        snakeList[s] = 1 + rand() % (numSnakes - 1);
    }

    for (int i = 1; i <= numTiles; i++)
    {
        for (int index = 0; index < numTiles; index++)
        {
            if (i == snakeList[index])
            {
                tiles[i] = 'S';
            }
        }
    }

    cout << tiles;
}
