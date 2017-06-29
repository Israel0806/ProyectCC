#include "Impresoras.h"

Impresoras::Impresoras()
{

}


void Impresoras::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miTipo, string miCaracteristica,string miTamanho)
{
    string line;
    ofstream readIn;
    readIn.open("Impresoras.txt", ios::app | ios::in );
    if( readIn.is_open() )
    {
        readIn<< miCodigo << ' ' << miNombre << ' ' << miCategoria << ' ' << miPrecio << ' ' << miCantidad << ' ' << miTipo << ' ' << miCaracteristica << ' ' << miTamanho <<endl;
        cout<<"Se ingresaron los datos correctamente:\n\n";
        readIn.close();
    }
    else
    {
        cout<<"Error al ingresar a la base de datos\n";
    }
    ifstream readOut;
    readOut.open("Impresoras.txt", ios::out );
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

void Impresoras::getData()
{
    ifstream readOut;
    string line;
    readOut.open("Impresoras.txt");
    while( getline(readOut,line) )
    {
        cout << line << '\n';
    }
}

string Impresoras::getCategoria()
{
    return categoria;
}

string Impresoras::getNombre()
{
    return nombre;
}

string Impresoras::getCodigo()
{
    return codigo;
}

float Impresoras::getPrecio()
{
    return precio;
}

int Impresoras::getCantidad()
{
    return cantidad;
}
