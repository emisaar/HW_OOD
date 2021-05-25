#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

class Dice
{
    public:
    int num, moves;
    Dice();
    void roll();

};

Dice::Dice()
{
    this->num = 6;
}

void Dice::roll() 
{
    srand(time(NULL));
    moves = rand()%this->num;
    cout << moves << endl;
}