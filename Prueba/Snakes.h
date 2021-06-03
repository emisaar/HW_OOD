#ifndef SNAKES_H_INCLUDE
#define SNAKES_H_INCLUDE

#include <iostream>
#include "Tile.h"

using namespace std;

class Snakes: public Tile
{
    private:
        char type;
        int move;
    public:
        Snakes();
        int Moves(int pos);
        char getType();
        void setMoves(int move);
};

Snakes::Snakes() //Default
{
    this->type = 'S';
    this->move = 3;
}

int Snakes::Moves(int pos) //Penalty
{
    return pos-this->move;
}

char Snakes::getType() //Type
{
    return this->type;
}

void Snakes::setMoves(int move) //Customize
{
    this->move = move;
}

#endif