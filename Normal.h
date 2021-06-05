#ifndef NORMAL_H
#define NORMAL_H

#include <iostream>

#include "Tile.h"

using namespace std;

class Normal : public Tile
{
private:
    char type;
    int movement;

public:
    Normal(/* args */);
    ~Normal();

    virtual char getType();
    virtual void setMovement(int);
    virtual int move(int);
};

Normal::Normal(/* args */)
{
    this->type = 'N';
    this->movement = 0;
}

Normal::~Normal()
{
}

char Normal::getType()
{
    return this->type;
}

void Normal::setMovement(int _movement)
{
    this->movement = _movement;
}

int Normal::move(int _position)
{
    return _position;
}

#endif