#ifndef TILES_H_INCLUDE
#define TILES_H_INCLUDE
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Tiles
{
public:
    virtual int snake(int) = 0;
    virtual int ladder(int) = 0;
};

#endif