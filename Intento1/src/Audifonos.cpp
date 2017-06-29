#include "Audifonos.h"
#include <fstream>
Audifonos::Audifonos()
{

}



void Audifonos::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad,string miConexion,string miTier1,string miTier2)//,string miTier3,string miCaracteristica)
{
    string line;
    ofstream readIn;
    readIn.open("Audifonos.txt", ios::app | ios::in );
    if( readIn.is_open() )
    {
        readIn<< miCodigo << ' ' << miNombre << ' ' << miCategoria << ' ' << miPrecio << ' ' << miCantidad << ' ' << miConexion << ' ' << miTier1 << ' ' << miTier2 << ' '<<endl;
        readIn.close();
    }
    else
    {
        cout<<"Error al ingresar a la base de datos\n";
    }
    ifstream readOut;
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
    ifstream readOut;
    string line;
    readOut.open("Audifonos.txt");
    while( getline(readOut,line) )
    {


        cout << line << '\n';



    }
}


string Audifonos::getCategoria() { return categoria; }

string Audifonos::getNombre() { return nombre; }

string Audifonos::getCodigo() { return codigo; }

float Audifonos::getPrecio() { return precio; }

int Audifonos::getCantidad() { return cantidad; }
