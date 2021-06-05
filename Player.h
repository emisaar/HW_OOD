#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <ctime>

using namespace std;

class Player
{
private:
    int numPlayer;
    int position;

public:
    Player();
    Player(int, int);
    ~Player();

    int getNumPlayer();
    int getPosition();

    void setPosition(int);
    int rollDice();
};

Player::Player()
{
    this->numPlayer = 1;
    this->position = 1;
}

Player::Player(int _numPlayer, int _position)
{
    this->numPlayer = _numPlayer;
    this->position = _position;
}

Player::~Player()
{
}

int Player::getNumPlayer()
{
    return this->numPlayer;
}

int Player::getPosition()
{
    return this->position;
}

void Player::setPosition(int _position)
{
    this->position = _position;
}

int Player::rollDice()
{
    int value = (rand() % 6) + 1;
    return value;
}

#endif