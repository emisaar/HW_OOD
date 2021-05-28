// MyGame.h
// Emiliano Saucedo Arriola A01659258
// Sofía Ma. Hernández Muñoz A01655084
// MyGame class

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Player
{
public:
    int player; // Player number
    int num; // Dice number of faces
    int moves; // Number of moves according to the dice
    Player(int); // Constructor
    int playerNum(); // Method that returns player's number
    int rollDice(); // Method that makes the dice roll

    int getPos(int); // Method that return the current position
    int snake(int); // Method that penalize the player
    int ladder(int); // Method that helps to move forward
};

Player::Player(int player)
{
    this->player = player;
}

int Player::playerNum()
{
    return this->player;
}

int Player::rollDice()
{
    num = 6;
    srand(time(NULL)); // Random number using time
    moves = rand() % num; // Random number betwen 0-num
    if (moves == 0) // If dice returns 0, change the value to 1
    {
        moves = 1;
    }

    return moves;
}

int Player::getPos(int temp)
{
    return temp;
}

int Player::snake(int temp)
{
    return temp -= 3;
}

int Player::ladder(int temp)
{
    return temp += 3;
}