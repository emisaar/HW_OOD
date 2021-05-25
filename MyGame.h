#ifndef MYGAME_H
#define MYGAME_H

#include <iostream>
using namespace std;

class MyGame
{
private:
    char tiles[30] = "N";

public:
    MyGame();
    ~MyGame();

    void start();
};

void MyGame::start()
{
    // Lógica del juego
}

#endif
