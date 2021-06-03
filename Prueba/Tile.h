#ifndef TILE_H_INCLUDE
#define TILE_H_INCLUDE

#include <iostream>

using namespace std;

class Tile
{
    private:
        char type;
        int move; // adjust
    public:
        Tile();
        virtual int Moves(int pos);
        virtual char getType();
        virtual void setMoves();
};

Tile::Tile()
{
    this->type = '-';
    this->move = 0;
}

#endif