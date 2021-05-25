#include <iostream>
using namespace std;

class Player
{
    public:
        int player;
        Player(int player);
};

Player::Player(int player)
{
    this->player = player;
}