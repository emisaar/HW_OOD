#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>

#include "Tile.h"

using namespace std;

class Snake : public Tile
{
private:
    char type;
    int movement;

public:
    Snake(/* args */);
    ~Snake();

    virtual char getType();
    virtual void setMovement(int);
    virtual int move(int);
};

Snake::Snake(/* args */)
{
    this->type = 'S';
    this->movement = 3;
}

Snake::~Snake()
{
}

char Snake::getType()
{
    return this->type;
}

void Snake::setMovement(int _movement)
{
    this->movement = _movement;
}

int Snake::move(int _position)
{
    int newPos = _position - movement;
    return newPos;
}

#endif