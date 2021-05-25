#include <iostream>

using namespace std;

int main()
{
    int turn = 0; // Para saber si es el jugador 1 o 2
    char tiles[30];
    for (int i = 0; i < 30; i++)
    {
        // Fill the tiles
        if (i == 5 || i == 17 || i == 28)
        {
            tiles[i] = 'S';
        }
        else if (i == 8 || i == 13 || i == 26)
        {
            tiles[i] = 'L';
        }
        else
        {
            tiles[i] = 'N';
        }
    }

    // CHECAR EL TABLERO
    // for (int j = 0; j < sizeof(tiles); j++)
    // {
    //     cout << tiles[j];
    // }

    return 0;
}
