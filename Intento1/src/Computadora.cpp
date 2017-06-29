#include "Computadora.h"
#include <string.h>
#include<stdlib.h>
Computadora::Computadora()
{

}
void Computadora::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad,string miTipo)
{
    string line;
    ofstream readIn;
    readIn.open("Computadora.txt", ios::app | ios::in );
    if( readIn.is_open() )
    {
        readIn << miCodigo << ' ' << miNombre << ' ' << miCategoria << ' ' << miPrecio << ' ' << miCantidad << ' ' << miTipo <<endl;
        cout<<"Se ingresaron los datos correctamente:\n\n";
        readIn.close();
    }
    else
    {
        cout<<"Error al ingresar a la base de datos\n";
    }
    ifstream readOut;
    readOut.open("Computadora.txt", ios::out );
    if (readOut.is_open())
      {
        while ( getline (readOut,line) )
        {
          cout << line << '\n';
        }
      }
    else
    {
        cout<<"No se pudo ingresar a la base de datos\n";
    }
    readOut.close();
}

void Computadora::getData()
{
    ifstream readOut;
    readOut.open("Computadora.txt");
    string line;
    while( getline(readOut,line) )
    {
        cout << line << '\n';
    }
}


string Computadora::getCategoria()
{
    ifstream readOut;
    readOut.open("Computadora.txt", ios::out );
    readOut >> codigo >> nombre >> categoria >> precio >> cantidad >> tipo;
    return categoria;
}

string Computadora::getNombre()
{
    ifstream readOut;
    readOut.open("Computadora.txt", ios::out );
    readOut >> codigo >> nombre >> categoria >> precio >> cantidad >> tipo;
    return nombre;
}

string Computadora::getCodigo()
{
    return codigo;
}

float Computadora::getPrecio()
{
    return precio;
}

int Computadora::getCantidad()
{
    return cantidad;
}
