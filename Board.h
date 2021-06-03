#ifndef BOARD_H_INCLUDE
#define BOARD_H_INCLUDE
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include "Player.h"
#include "Tiles.h"

using namespace std;

class Board
{
private:
    int numTiles;
    int numSnakes;
    int numLadders;

public:
    Board(int tiles, int snakes, int ladders);
    Board();
};

Board::Board(int numTiles, int numSnakes, int numLadders)
{
    this->numTiles = numTiles;
    this->numSnakes = numSnakes;
    this->numLadders = numLadders;

    // Create the empty board
    char tiles[numTiles];

    int counterS = 0;
    int counterL = 0;
    srand(time(NULL));
    for (int i = 0; i < numTiles; i++)
    {
        tiles[i] = 'N';
    }

    for (int i = 1; i <= numTiles; i++)
    {
        // Create the snakes tiles
        while (counterS < numSnakes)
        {
            int randomS = 1 + rand() % (numTiles);
            if (tiles[randomS] == 'S')
            {
                continue;
            }
            //cout << randomS << endl;
            tiles[randomS] = 'S';
            counterS++;
        }

        // Create the ladder tiles
        while (counterL < numLadders)
        {
            int randomL = 1 + rand() % (numTiles);
            if (tiles[randomL] == 'L' || tiles[randomL] == 'S')
            {
                continue;
            }
            // cout << "Ladders" << endl;
            // cout << randomL << endl;
            tiles[randomL] = 'L';
            counterL++;
        }

        //cout << tiles[i];
    }
}

Board::Board()
{
    this->numTiles = 30;
    this->numSnakes = 3;
    this->numLadders = 3;
}

#endif