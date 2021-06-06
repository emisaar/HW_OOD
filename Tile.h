#ifndef TILE_H
#define TILE_H

#include <iostream>

using namespace std;

class Tile
{
private:
    char type;
    int movement;

public:
    Tile();
    ~Tile();

    virtual char getType() = 0;
    virtual int getMovement() = 0;
    virtual void setMovement(int) = 0;
    virtual int move(int) = 0;
};

Tile::Tile()
{
    this->type = '-';
    this->movement = 0;
}

Tile::~Tile()
{
}

#endif