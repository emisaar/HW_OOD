#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdbool.h>
using namespace std;
void escribir();
void lectura();
int main()
{
    // escribir();
    lectura();

    return 0;
}

void lectura()
{
    char matriz[20][1];            // ABRES UNA MATRIZ
    ifstream fp("inputSnake.txt"); // LE ASIGNAS A IFSTREAM LA VARIABLE FP

    for (int j = 0; j < 20; j++) //NO IMPORTA EL LARGO DE LA LECTURA
    {
        fp >> matriz[0][j]; // LE ASIGNAS LOS VALORES DE FP A LA MATRIZ
    }

    //cout << matriz[0][2] << endl;

    char opcion = 'J';
    while (opcion != 'E')
    {
        for (int a = 0; a < 20; a++) //NO IMPORTA EL LARGO DE ARCHIVO PUEDES PONER QUE LEA HASTA 50, PORQUE TU CODIGO CUANDO ENCUENTRA UNA E SE DEBE BREAKEAR

        {
            opcion = matriz[0][a]; // EJEMPLO:
            if (opcion == 'C')
            {                           //          C
                cout << "HOLA" << endl; //          C
                                        //          E
            }
            else if (opcion == 'E')
            { //     EN ESTE EJEMPLO HAY 3 CARCATERES EN TU TXT, PERO PUEDES LEERLO HASTA 20 CARACTERES (SI QUIERES) Y NO VA A IMPORTAR PORQUE TU CODIGO CUANDO LEE EL E SE DEBE CERRAR.
                cout << "ADIOS" << endl;
                break;
            }
        }
    }
}