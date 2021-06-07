#include <iostream>
using namespace std;

#include "Tile.h"
#include "Normal.h"
#include "Snake.h"
#include "Ladder.h"

int main()
{
    Ladder l1;
    l1.setPositionSC(6);
    l1 = l1 + l1;
    cout << l1.getPositionSC() << endl;

    Snake s1;
    s1.setPositionSC(6);
    s1 = s1 + s1;
    cout << s1.getPositionSC() << endl;

    return 0;
}