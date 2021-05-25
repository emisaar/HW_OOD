#include <iostream>
#include "Player.h"
#include "Dice.h"

using namespace std;

class MyGame 
{
    public:
        void start();
};

void MyGame::start()
{
    string userIn;
    int counterEnd = 0;
    cout << "Snakes & Ladders" << endl;
    Player *p1 = new Player(1);
    Player *p2 = new Player(2);

    while(counterEnd<5)
    {
        cout << "Press C to continue next turn or E to end the game: ";
        cin >> userIn;
        cout << userIn << endl;

        while((userIn != "C") && (userIn != "E"))
        {
            cout << "Invalid operation. Please press C to continue next turn or E to end the game: ";
            cin >> userIn;
            cout << userIn << endl; 
        }

        if (userIn == "C")
        {
            cout << "continue" << endl;
        }else{
            cout << "End game" << endl;
            break;
        }
        counterEnd += 1;
    }
}
    

    
    
    
    
/*
    while (userIn != "E")
    {
        while(userIn != "C" || userIn != "E")
        {
            cout << "Press C to continue next turn or E to end the game: ";
            cin >> userIn;
            cout << userIn << endl;
        }

        if (userIn == "C")
        {
            cout << "Next turn" << endl;
        }
        
        else
        {
            cout << "You decided to Quit." << endl;
            break;
        }
    }

}
*/