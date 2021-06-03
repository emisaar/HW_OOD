#ifndef BOARD_H_INCLUDE
#define BOARD_H_INCLUDE
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include "Player.h"

using namespace std;

class Board
{
protected:
    int numTiles;
    int numSnakes;
    int numLadders;

public:
    Board(int tiles, int snakes, int ladders);
    ~Board();
};

Board::Board(int numTiles, int numSnakes, int numLadders)
{
    this->numTiles = numTiles;
    this->numSnakes = numSnakes;
    this->numLadders = numLadders;

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
}

Board::~Board()
{
}

#endif