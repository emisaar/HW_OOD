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
    int position;

public:
    void setPositionSC(int);
    int getPositionSC();

    Ladder operator+(Ladder const &_ladder)
    {
        Ladder nPos;
        nPos.position = this->position + _ladder.movement;
        return nPos;
    }

    Ladder();
    ~Ladder();

    char getType();
    int getMovement();
    void setMovement(int);
    int move(int);
};

Ladder::Ladder()
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

int Ladder::getMovement()
{
    return this->movement;
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

void Ladder::setPositionSC(int _pos)
{
    this->position = _pos;
}

int Ladder::getPositionSC()
{
    return position;
}

#endif