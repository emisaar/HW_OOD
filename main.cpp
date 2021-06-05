#include <iostream>
using namespace std;

#include "Board.h"

int main()
{
    Board *b1 = new Board();
    b1->configure();
    b1->createBoard();

    return 0;
}