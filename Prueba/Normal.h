#ifndef NORMAL_H_INCLUDE
#define NORMAL_H_INCLUDE

#include <iostream>
#include "Tile.h"

using namespace std;

class Normal: public Tile
{
    private:
        char type;
        int move;
    public:
        Normal();
        int Moves(int pos);
        char getType();
        void setMoves(int move);
};

Normal::Normal() //Default
{
    this->type = 'N';
    this->move = 0;
}

int Normal::Moves(int pos) //Penalty
{
    return pos;
}

char Normal::getType() //Type
{
    return this->type;
}

// void Normal::setMoves(int move) //Customize
// {
//     this->move = move;
// }

#endif