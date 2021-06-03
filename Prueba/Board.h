#ifndef BOARD_H_INCLUDE
#define BOARD_H_INCLUDE

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Tile.h"
#include "Snakes.h"
#include "Ladder.h"
#include "Normal.h"

using namespace std;

class Board
{
    private:
        int tileN, snakesN, laddersN, penalty, reward, turnsN;
    public:
        Tile *board[200];
        Board();
        Board(int tileN, int snakesN, int laddersN, int penalty, int reward, int turnsN);
        void createBoard();
};

Board::Board()
{
    this->tileN = 30;
    this->snakesN = 3;
    this->laddersN = 3;
    this->penalty = 3;
    this->reward = 3;
    this->turnsN = 15;
}

Board::Board(int tileN, int snakesN, int laddersN, int penalty, int reward, int turnsN)
{
    this->tileN = tileN;
    this->snakesN = snakesN;
    this->laddersN =  laddersN;
    this->penalty = penalty;
    this->reward = reward;
    this->turnsN = turnsN;
}

void Board::createBoard()
{
    char tiles[tileN];

    int counterS = 0;
    int counterL = 0;
    srand(time(NULL));
    for (int i = 0; i < tileN; i++)
    {
        tiles[i] = 'N';
        board[i] = new Normal();
    }

    for (int i = 1; i <= tileN; i++)
    {
        // Create the snakes tiles
        while (counterS < snakesN)
        {
            int randomS = 1 + rand() % (tileN);
            if (tiles[randomS] == 'S')
            {
                continue;
            }
            //cout << randomS << endl;
            tiles[randomS] = 'S';
            board[i] = new Snakes();
            counterS++;
        }

        // Create the ladder tiles
        while (counterL < laddersN)
        {
            int randomL = 1 + rand() % (tileN);
            if (tiles[randomL] == 'L' || tiles[randomL] == 'S')
            {
                continue;
            }
            // cout << "Ladders" << endl;
            // cout << randomL << endl;
            tiles[randomL] = 'L';
            board[i] = new Ladder();
            counterL++;
        }

        //cout << tiles[i];
    }
    for (int p = 0; p < tileN; p++)
    {
        cout << tiles[p] << " ";
    }
}

#endif