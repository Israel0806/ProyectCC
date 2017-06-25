#include "Impresoras.h"

Impresoras::Impresoras()
{

}


void Impresoras::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miTipo, string miCaracteristica,string miTamanho)
{
    fstream readIn;
    readIn.open("Impresoras.txt", ios::app | ios::in );
    readIn<< miCodigo << ' ' << miNombre << ' ' << miCategoria << ' ' << miPrecio << ' ' << miCantidad << ' ' << miTipo << ' ' << miCaracteristica << ' ' << miTamanho <<endl;
    readIn.close();
    ifstream readOut;
    string line;
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
    cout                                      <<endl
        <<"Codigo: "<<codigo                  <<endl
        <<"Nombre: "<<nombre                  <<endl
        <<"Categoria: "<<categoria            <<endl
        <<"Precio: "<<precio                  <<endl
        <<"Cantidad: "<<cantidad              <<endl
        <<"tipo: "<<tipo                      <<endl
        <<"Caracteristica: "<<caracteristicas <<endl
        <<"tamanho: "<<tamanho                <<endl
                                              <<endl;
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
