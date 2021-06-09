#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <ctime>
#include <stdlib.h>

#include "Tile.h"
#include "Snake.h"
#include "Normal.h"
#include "Ladder.h"
#include "InvalidConfigurationException.h"

using namespace std;

class Board
{
private:
    int numTiles;
    int numSnakes;
    int numLadders;
    int numTurns;
    int reward;
    int penalty;

public:
    Tile *board1[50];
    Board();
    ~Board();

    void setTiles(int);
    void setSnakes(int);
    void setLadders(int);
    void setMaxTurns(int);

    void setReward(int);
    void setPenalty(int);

    int getTiles();
    int getMaxTurns();

    void configure();
    void createBoard();
};

Board::Board()
{
    this->numTiles = 30;
    this->numSnakes = 3;
    this->numLadders = 3;
    this->numTurns = 15;
    this->reward = 3;
    this->penalty = 3;
}

Board::~Board()
{
}

void Board::setTiles(int _numTiles)
{
    this->numTiles = _numTiles;
}

void Board::setSnakes(int _numSnakes)
{
    this->numSnakes = _numSnakes;
}

void Board::setLadders(int _numLadders)
{
    this->numLadders = _numLadders;
}

void Board::setMaxTurns(int _numTurns)
{
    this->numTurns = _numTurns;
}

void Board::setReward(int _numReward)
{
    this->reward = _numReward;
}

void Board::setPenalty(int _numPenalty)
{
    this->penalty = _numPenalty;
}

int Board::getTiles()
{
    return this->numTiles;
}

int Board::getMaxTurns()
{
    return this->numTurns;
}

void Board::configure()
{
    int numTiles;
    int numSnakes;
    int numLadders;
    int numTurns;
    int reward;
    int penalty;

    cout << "\nEnter the settings for the game." << endl;
    try
    {
    cout << "Tiles: " << endl;
    cin >> numTiles;
    if (numTiles <= 1)
    {
        throw InvalidConfigurationException(1,numTiles);
    }

    setTiles(numTiles);

    cout << "Snakes: " << endl;
    cin >> numSnakes;
    if(numSnakes < 0)
    {
        throw InvalidConfigurationException(2,numSnakes);
    }

    setSnakes(numSnakes);

    cout << "Ladders: " << endl;
    cin >> numLadders;
    if(numLadders < 0)
    {
        throw InvalidConfigurationException(3,numLadders);
    }

    setLadders(numLadders);

    cout << "Turns: " << endl;
    cin >> numTurns;
    if(numTurns < 1)
    {
        throw InvalidConfigurationException(4,numTurns);
    }

    setMaxTurns(numTurns);

    cout << "Enter the penalty: " << endl;
    cin >> penalty;
    if (penalty < 1)
    {
        throw InvalidConfigurationException(5,penalty);
    }

    setPenalty(penalty);
    
    cout << "Enter the reward: " << endl;
    cin >> reward;
    if (reward < 1)
    {
        throw InvalidConfigurationException(6,reward);
    }

    setReward(reward);

    }catch(const exception& msj)
    {
        cout << msj.what() << endl;
        cout << -1 << endl;
        exit(-1);
    }
}

void Board::createBoard()
{
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
            tiles[randomL] = 'L';
            counterL++;
        }
    }

    for (int pos = 0; pos < numTiles; pos++)
    {
        if (tiles[pos] == 'N')
        {
            board1[pos] = new Normal();
        }
        else if (tiles[pos] == 'S')
        {
            board1[pos] = new Snake();
            board1[pos]->setMovement(this->penalty);
        }
        else if (tiles[pos] == 'L')
        {
            board1[pos] = new Ladder();
            board1[pos]->setMovement(this->reward);
        }
    }

    //print the board with the settings
    // for (int i = 0; i < numTiles; i++)
    // {
    //     cout << tiles[i] << " ";
    // }
}

#endif