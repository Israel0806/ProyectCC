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

string Audifonos::getNombre(string miCodigo)
{
    ifstream readOut;
    readOut.open("Audifonos.txt", ios::out);
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> conexion >> tier1 >> tier2 )
        {
            if(codigo==miCodigo)
            {
                break;
            }
        }
        readOut.close();
    }
    else
    {
        cout<<"No se pudo accesar a la base de datos"<<endl;
    }
    return nombre;
}

string Audifonos::getCodigo() { return codigo; }

float Audifonos::getPrecio() { return precio; }

int Audifonos::getCantidad(string miCodigo)
{
    ifstream readOut;
    readOut.open("Audifonos.txt", ios::out);
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> conexion >> tier1 >> tier2 )
        {
            if(codigo==miCodigo)
            {
                break;
            }
        }
        readOut.close();
    }
    else
    {
        cout<<"No se pudo accesar a la base de datos"<<endl;
    }
    return cantidad;
}

Audifonos* Audifonos::instance=0;

Audifonos* Audifonos::getInstance()
{
    if (instance == 0)
        instance = new Audifonos();
    return instance;
}

void Audifonos::getProducto(string miCodigo)
{
    ifstream readOut;
    readOut.open("Audifonos.txt", ios::out);
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> conexion >> tier1 >> tier2 )
        {
            if(codigo==miCodigo)
            {
                cout<< "Datos del Producto:"        <<endl
                    <<"Codigo: "<<codigo            <<endl
                    <<"Nombre: "<<nombre            <<endl
                    <<"Categoria: "<<categoria      <<endl
                    <<"Precio: $"<<precio           <<endl
                    <<"Stock: "<<cantidad           <<endl
                    <<"Conexion: "<<conexion        <<endl
                    <<"Tier1: "<<tier1              <<endl
                    <<"Tier2: "<<tier2              <<endl<<endl<<endl;
                break;
            }
        }
        readOut.close();
    }
    else
    {
        cout<<"No se pudo accesar a la base de datos"<<endl;
    }
}


void Audifonos::modifyCantidad(string miCodigo, int stock)
{
        ifstream readOut;
        readOut.open("Audifonos.txt");
        ofstream readIn;
        readIn.open("temp.txt");
        while ( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> conexion >> tier1 >> tier2 )
        {
            if ( miCodigo != codigo)
            {
                readIn<< codigo << ' ' << nombre << ' ' << categoria << ' ' << precio << ' ' << cantidad << ' ' << conexion << ' ' << tier1 << ' ' << tier2 << ' '<<endl;
            }
            else
            {
                readIn<< codigo << ' ' << nombre << ' ' << categoria << ' ' << precio << ' ' << stock << ' ' << conexion << ' ' << tier1 << ' ' << tier2 << ' '<<endl;
            }
    }
    readIn.close();
    readOut.close();
    remove("Audifonos.txt");
    rename("temp.txt","Audifonos.txt");
    cout <<endl<<endl<<endl;
}

