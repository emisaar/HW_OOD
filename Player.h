#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Tiles.h"

using namespace std;

class Player
{
public:
    int player;
    int num, moves;
    Player(int);
    int playerNum();
    int rollDice();

    int getPos(int);

    int snake(int);
    int ladder(int);
};

Player::Player(int player)
{
    this->player = player;
}

int Player::playerNum()
{
    return this->player;
}

int Player::rollDice()
{
    num = 6;
    srand(time(NULL));
    moves = rand() % num;
    if (moves == 0)
    {
        moves = 1;
    }

    return moves;
}

int Player::getPos(int temp)
{
    return temp;
}

int Player::snake(int temp)
{
    return temp -= 3;
}

int Player::ladder(int temp)
{
    return temp += 3;
}
