#ifndef MYGAME_H
#define MYGAME_H

#include <iostream>
#include <ctime>
#include <stdlib.h>

#include "Board.h"
#include "Player.h"

using namespace std;

class MyGame
{
private:
    int numPlayers;
    int actualTurn;
    Board b1;

    int getTurn();

    void setTurn(int);
    void setNumPlayers(int);

    int increaseTurn();
    void createPlayers();
    void gameMode();

public:
    MyGame();
    ~MyGame();

    void start();
};

MyGame::MyGame()
{
    this->numPlayers = 2;
    this->actualTurn = 1;
}

MyGame::~MyGame()
{
}

int MyGame::getTurn()
{
    return this->actualTurn;
}

void MyGame::setTurn(int _turn)
{
    this->actualTurn = _turn;
}

void MyGame::setNumPlayers(int _players)
{
    this->numPlayers = _players;
}

int MyGame::increaseTurn()
{
    int turn = getTurn() + 1;
    return turn;
}

void MyGame::createPlayers()
{
    int numPlayers;
    cout << "Number of players: " << endl;
    cin >> numPlayers;
    setNumPlayers(numPlayers);
}

void MyGame::gameMode()
{
    int option;
    cout << "\nMenu" << endl;
    cout << "1. Default game." << endl;
    cout << "2. Custom game." << endl;
    cout << "Enter an option: ";
    cin >> option;

    if (option == 1)
    {
        b1.createBoard();
    }
    else if (option == 2)
    {
        b1.configure();
        createPlayers();
        b1.createBoard();
    }
}

void MyGame::start()
{
    Player *players[numPlayers];
    int option;

    gameMode();

    for (int i = 1; i <= numPlayers; i++)
    {
        players[i - 1] = new Player(i, 1);
    }

    cout << "\nGame mode menu." << endl;
    cout << "1. Manual mode." << endl;
    cout << "2. Auto mode." << endl;
    cout << "Enter an option: ";
    cin >> option;

    /* LOGICA DEL JUEGO */
    char userIn;
    int counterPlayers = 0;

    while (getTurn() < b1.getMaxTurns())
    {
        if (option == 1)
        {
            cout << "Press C to continue next turn or E to end the game: ";
            cin >> userIn;

            while ((userIn != 'C') && (userIn != 'E'))
            {
                // Check if the option is valid
                cout << "Invalid operation. Please press C to continue next turn or E to end the game: ";
                cin >> userIn;
            }
        }
        else if (option == 2)
        {
            userIn = 'C';
        }

        if (userIn == 'C')
        {
            // Set positions for the players
            int actualPos = players[counterPlayers]->getPosition();
            int valueDice = players[counterPlayers]->rollDice();
            int newPos = actualPos + valueDice;
        }
    }
}

#endif