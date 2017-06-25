#include "Software.h"

Software::Software()
{

}

void Software::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miTier1, string miTier2)
{
    fstream readIn;
    readIn.open("Software.txt", ios::app | ios::in );

    readIn<< miCodigo << ' ' << miNombre << ' ' << miCategoria << ' ' << miPrecio << ' ' << miCantidad << ' ' << miTier1 << ' ' << miTier2 <<endl;
    //readIn.close(); fstream codigos; codigos.open("Codigos.txt",ios::
    ifstream readOut;
    string line;
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
    cout                           <<endl
        <<"Codigo: "<<codigo       <<endl
        <<"Nombre: "<<nombre       <<endl
        <<"Categoria: "<<categoria <<endl
        <<"Precio: "<<precio       <<endl
        <<"Cantidad: "<<cantidad   <<endl
        <<"Tier1: "<<Tier1         <<endl
        <<"Tier2: "<<Tier2         <<endl
                                   <<endl;
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
