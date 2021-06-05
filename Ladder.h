#ifndef LADDER_H
#define LADDER_H

#include <iostream>

#include "Tile.h"

using namespace std;

class Ladder : public Tile
{
private:
    char type;
    int movement;

public:
    Ladder(/* args */);
    ~Ladder();

    virtual char getType();
    virtual void setMovement(int);
    virtual int move(int);
};

Ladder::Ladder(/* args */)
{
    this->type = 'L';
    this->movement = 3;
}

Ladder::~Ladder()
{
}

char Ladder::getType()
{
    return this->type;
}

void Ladder::setMovement(int _movement)
{
    this->movement = _movement;
}

int Ladder::move(int _position)
{
    int newPos = _position + movement;
    return newPos;
}

#endif