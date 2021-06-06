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
    Normal();
    ~Normal();

    char getType();
    int getMovement();
    void setMovement(int);
    int move(int);
};

Normal::Normal()
{
    this->type = 'N';
    this->movement = 1;
}

Normal::~Normal()
{
}

char Normal::getType()
{
    return this->type;
}

int Normal::getMovement()
{
    return this->movement;
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