#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

class Player
{
    public:
        int player;
        int num, moves;
        Player(int player);
        int playerNum();
        int rollDice();
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
    moves = rand()%num;
    if (moves == 0)
    {
        moves = 1;
    }
    
    return moves;
}
