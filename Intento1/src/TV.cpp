#include "TV.h"

TV::TV()
{

}

void TV::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miCalidad, string miCaracteristicas,string mipantallaTy, float miTam)
{
    string line;
    ofstream readIn;
    readIn.open("TV.txt", ios::app | ios::in );
    if( readIn.is_open() )
    {
        readIn<< miCodigo << ' ' << miNombre << ' ' << miCategoria << ' ' << miPrecio << ' ' << miCantidad << ' ' << miCalidad << ' ' << miCaracteristicas << ' ' << mipantallaTy << ' ' << miTam <<endl;
        cout<<"Se ingresaron los datos correctamente:\n\n";
        readIn.close();
    }
    else
    {
        cout<<"Error al ingresar a la base de datos\n";
    }
    ifstream readOut;
    readOut.open("TV.txt", ios::out );
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

void TV::getData()
{
    ifstream readOut;
    string line;
    readOut.open("TV.txt");
    while( getline(readOut,line) )
    {
        cout << line << '\n';
    }
}

string TV::getCategoria()
{
    return categoria;
}

string TV::getNombre()
{
    return nombre;
}

string TV::getCodigo()
{
    return codigo;
}

float TV::getPrecio()
{
    return precio;
}

int TV::getCantidad()
{
    return cantidad;
}
