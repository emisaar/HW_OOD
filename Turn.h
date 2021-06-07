#ifndef TURN_H
#define TURN_H

#include <iostream>
#include <ctime>
#include <stdlib.h>

class Turn
{
private:
    int actualTurn;

public:
    Turn();
    ~Turn();

    int getTurn();
    void setTurn(int);

    int increaseTurn();

    friend ostream &operator<<(ostream &out, Turn const &z)
    {
        out << z.actualTurn;
        return out;
    }
};

Turn::Turn()
{
    this->actualTurn = 1;
}

Turn::~Turn()
{
}

int Turn::getTurn()
{
    return this->actualTurn;
}

void Turn::setTurn(int _turn)
{
    this->actualTurn = _turn;
}

int Turn::increaseTurn()
{
    int turn = getTurn() + 1;
    return turn;
}

#endif