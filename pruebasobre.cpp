#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class avion
{
private:
    string tipo_avion; //tus atributos que pueden ser de cualquier tipo
    int numero_de_vuelo;

public:
    avion();
    void set_tipo_avion(string); //para poder actializar lo que vayas a imprimir
    void set_numero_vuelo(int);
    //Operator << Overloading (Este operador te ayuda a imprimir como tu quieras los datos (atributos) de tu clase de una forma determianada)
    friend ostream &operator<<(ostream &out, avion const &p)
    {
        out << "Hola, estas volando en un: " << p.tipo_avion << " con numero deu vuelo: " << p.numero_de_vuelo << endl;
        return out;
    }
};

avion::avion()
{
    this->tipo_avion = "AIRBUS 380";
    this->numero_de_vuelo = 2331;
}

void avion::set_tipo_avion(string vuelo)
{
    this->tipo_avion = vuelo;
}
void avion::set_numero_vuelo(int num)
{
    this->numero_de_vuelo = num;
}

int main()
{

    avion avion1;           //Solo necesitas crear un objeto de la clase
    cout << avion1 << endl; //De esta forma llamas al operador y lo imprimes. Cuando se imprime se imprime de la misma forma de como lo hiciste en la sobrecarga de operador <<

    avion1.set_tipo_avion("Boeing 737"); //puede actualizar los datos y si le pones otra ves que te imprima el objeto te lo dara de la misma forma de como hiciste la sobrecarga
    avion1.set_numero_vuelo(3442);
    cout << avion1 << endl; //ESTE COUT SE PUEDE HACER TAMBIEN PARA IMPRIMIRLO EN UN TXT, SOLO PONES EL NOMBRE DE TU ARCHIVO :  fileout << avion1 << endl;

    avion1.set_tipo_avion("Boeing 300-600");
    avion1.set_numero_vuelo(12312);
    cout << avion1 << endl;

    //Ya se pudieron darse cuenta que si actualizan los datos puede imprimir, por lo tanto para in ciclo funciona igual mientras actualicen los datos de salida :)

    return 0;
}
