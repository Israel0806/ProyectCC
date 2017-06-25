#include "Computadora.h"

Computadora::Computadora()
{

}
void Computadora::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad,string miTipo)
{
    fstream readIn;
    readIn.open("Computadora.txt", ios::app | ios::in );
    readIn<< miCodigo << ' ' << miNombre << ' ' << miCategoria << ' ' << miPrecio << ' ' << miCantidad << ' ' << miTipo <<endl;
    readIn.close();
    ifstream readOut;
    string line;
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
    cout                           <<endl
        <<"Codigo: "<<codigo       <<endl
        <<"Nombre: "<<nombre       <<endl
        <<"Categoria: "<<categoria <<endl
        <<"Precio: "<<precio       <<endl
        <<"Cantidad: "<<cantidad   <<endl
        <<"Tipo: "<<tipo           <<endl
                                   <<endl;

}


string Computadora::getCategoria()
{
    return categoria;
}

string Computadora::getNombre()
{
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
