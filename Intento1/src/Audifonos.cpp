#include "Audifonos.h"
#include <fstream>
Audifonos::Audifonos()
{

}



void Audifonos::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad,string miConexion,string miTier1,string miTier2)//,string miTier3,string miCaracteristica)
{
    fstream readIn;
    readIn.open("Audifonos.txt", ios::app | ios::in );
    readIn<< miCodigo << ' ' << miNombre << ' ' << miCategoria << ' ' << miPrecio << ' ' << miCantidad << ' ' << miConexion << ' ' << miTier1 << ' ' << miTier2 << ' '<<endl;
    readIn.close();
    ifstream readOut;
    string line;
    readOut.open("Audifonos.txt", ios::out );

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
    //tier3=miTier3;
    //caracteristica=miCaracteristica;
}

void Audifonos::getData()
{

    cout                           <<endl
        <<"Codigo: "<<codigo       <<endl
        <<"Nombre: "<<nombre       <<endl
        <<"Categoria: "<<categoria <<endl
        <<"Precio: "<<precio       <<endl
        <<"Cantidad: "<<cantidad   <<endl
        <<"Conexion: "<<conexion   <<endl
        <<"Tier1: "<<tier1         <<endl
        <<"Tier2: "<<tier2         <<endl
                                   <<endl;
}


string Audifonos::getCategoria() { return categoria; }

string Audifonos::getNombre() { return nombre; }

string Audifonos::getCodigo() { return codigo; }

float Audifonos::getPrecio() { return precio; }

int Audifonos::getCantidad() { return cantidad; }
