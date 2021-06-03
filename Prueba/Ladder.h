#ifndef LADDER_H_INCLUDE
#define LADDER_H_INCLUDE

#include <iostream>
#include "Tile.h"

using namespace std;

class Ladder: public Tile
{
    private:
        char type;
        int move;
    public:
        Ladder();
        int Moves(int pos);
        char getType();
        void setMoves(int move);
};

Ladder::Ladder() //Default
{
    this->type = 'L';
    this->move = 3;
}

int Ladder::Moves(int pos) //Bonus
{
    return pos+this->move;
}

char Ladder::getType() //Type
{
    return this->type;
}

void Ladder::setMoves(int move) //Customize
{
    this->move = move;
}

#endif