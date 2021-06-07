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
    int option;
    int gameMenu;
    Board b1;
    Player *players[10];

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
    cout << "Welcome to Snakes & Ladders Game" << endl;
    cout << "Authors:\n- Sofía Margarita Hernández Muñoz A01655084 \nEmiliano Saucedo Arriola A01659258" << endl;

    cout << "...Menu..." << endl;
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
    gameMode();

    for (int i = 1; i <= numPlayers; i++)
    {
        players[i - 1] = new Player(i, 1);
    }

    cout << "\nGame mode menu." << endl;
    cout << "1. Manual mode." << endl;
    cout << "2. Auto mode." << endl;
    cout << "Enter an option: ";
    cin >> gameMenu;
    while ((gameMenu != 1) && (gameMenu != 2))
    {
        // Check if the gameMenu is valid
        cout << "Invalid operation. Please press 1 or 2: ";
        cin >> gameMenu;
    }

    /* LOGICA DEL JUEGO */
    char userIn = '-';
    int counterPlayers = 0;
    int counterTurns = 0;

    while (userIn != 'E')
    {
        if (gameMenu == 1)
        {
            cout << "Press C to continue next turn or E to end the game: ";
            cin >> userIn;

            while ((userIn != 'C') && (userIn != 'E'))
            {
                // Check if the gameMenu is valid
                cout << "Invalid operation. Please press C to continue next turn or E to end the game: ";
                cin >> userIn;
            }
        }
        else if (gameMenu == 2)
        {
            if (getTurn() < b1.getMaxTurns())
            {
                userIn = 'C';
            }
        }

        if (userIn == 'C')
        {
            // Set positions for the players
            int actualPos = players[counterPlayers]->getPosition();
            int valueDice = players[counterPlayers]->rollDice();
            int newPos = actualPos + valueDice;

            // The position is set to 30 when it is more than 30
            if (newPos >= b1.getTiles())
            {
                newPos = b1.getTiles();
            }

            // The position is set to 1 when it is less than 0
            if (newPos <= 0)
            {
                newPos = 1;
            }

            if (b1.board1[newPos - 1]->getType() == 'N')
            {
                cout << getTurn() << " " << counterPlayers + 1 << " " << valueDice << " "
                     << newPos << " " << b1.board1[newPos - 1]->getType() << " "
                     << b1.board1[newPos - 1]->getMovement() << endl;

                //newPos_ = b1.board1[newPos - 1]->move(newPos);
                players[counterPlayers]->setPosition(b1.board1[newPos - 1]->move(newPos));
                counterTurns += 1;
                counterPlayers += 1;
            }
            else if (b1.board1[newPos - 1]->getType() == 'S')
            {
                Snake s1;
                s1.setMovement(b1.penalty);
                s1.setPositionSC(newPos);
                s1 = s1 + s1;

                cout << getTurn() << " " << counterPlayers + 1 << " " << valueDice << " "
                     << newPos << " " << b1.board1[newPos - 1]->getType() << " "
                     << s1.getPositionSC() << endl;

                players[counterPlayers]->setPosition(b1.board1[newPos - 1]->move(newPos));
                counterTurns += 1;
                counterPlayers += 1;
            }
            else if (b1.board1[newPos - 1]->getType() == 'L')
            {
                Ladder l1;
                l1.setMovement(b1.reward);
                l1.setPositionSC(newPos);
                l1 = l1 + l1;

                cout << getTurn() << " " << counterPlayers + 1 << " " << valueDice << " "
                     << newPos << " " << b1.board1[newPos - 1]->getType() << " "
                     << l1.getPositionSC() << endl;

                players[counterPlayers]->setPosition(b1.board1[newPos - 1]->move(newPos));
                counterTurns += 1;
                counterPlayers += 1;
            }

            if (counterPlayers == numPlayers)
            {
                counterPlayers = 0;
            }

            if (counterTurns == numPlayers)
            {
                setTurn(increaseTurn());
                counterTurns = 0;
            }

            if (getTurn() >= b1.getMaxTurns())
            {
                cout << "The maximum number of turns has been reached..." << endl;
                break;
            }

            if (players[counterPlayers]->getPosition() == b1.getTiles())
            {
                cout << "-- GAME OVER --" << endl;
                cout << "Player " << counterPlayers + 1 << " is the winner!!!" << endl;
                break;
            }
        }
        else
        {
            // If the user enters 'E' the game stop
            cout << "Thanks for playing!!!" << endl;
            break;
        }
    }
}

#endif