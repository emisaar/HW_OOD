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
    int position;

public:
    void setPositionSC(int);
    int getPositionSC();

    Snake operator+(Snake const &_snake)
    {
        Snake nPos;
        nPos.position = this->position - _snake.movement;
        return nPos;
    }

    Snake();
    ~Snake();

    char getType();
    int getMovement();
    void setMovement(int);
    int move(int);
};

Snake::Snake()
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

int Snake::getMovement()
{
    return this->movement;
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

void Snake::setPositionSC(int _pos)
{
    this->position = _pos;
}

int Snake::getPositionSC()
{
    return position;
}

#endif