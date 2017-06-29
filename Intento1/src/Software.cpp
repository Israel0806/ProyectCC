#include "Software.h"

Software::Software()
{

}

void Software::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miTier1, string miTier2)
{
    string line;
    ofstream readIn;
    readIn.open("Software.txt", ios::app | ios::in );
    if( readIn.is_open() )
    {
        readIn<< miCodigo << ' ' << miNombre << ' ' << miCategoria << ' ' << miPrecio << ' ' << miCantidad << ' ' << miTier1 << ' ' << miTier2 <<endl;
        cout<<"Se ingresaron los datos correctamente:\n\n";
        readIn.close();
    }
    else
    {
        cout<<"Error al ingresar a la base de datos\n";
    }
    ifstream readOut;
    readOut.open("Software.txt", ios::out );
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

void Software::getData()
{
    ifstream readOut;
    string line;
    readOut.open("Software.txt");
    while( getline(readOut,line) )
    {
        cout << line << '\n';
    }
}

string Software::getCategoria()
{
    return categoria;
}

string Software::getNombre()
{
    return nombre;
}

string Software::getCodigo()
{
    return codigo;
}

float Software::getPrecio()
{
    return precio;
}

int Software::getCantidad()
{
    return cantidad;
}
