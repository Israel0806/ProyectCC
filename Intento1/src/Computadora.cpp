#include "Computadora.h"
#include <string.h>
#include<stdlib.h>
Computadora::Computadora()
{

}
//ingresa valores al txt

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

//muestra todos los productos
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

string Computadora::getNombre(string miCodigo)
{
    ifstream readOut;
    readOut.open("Computadora.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo )
        {
            if(codigo==miCodigo)
            {
                    break;
            }
        }
        readOut.close();
    }
    return nombre;
}

string Computadora::getCodigo()
{
    return codigo;
}

float Computadora::getPrecio(string miCodigo)
{
    ifstream readOut;
    readOut.open("Computadora.txt", ios::out);
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo )
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
    return precio;
}

int Computadora::getCantidad(string miCodigo)
{
    ifstream readOut;
    readOut.open("Computadora.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo )
        {
            if(codigo==miCodigo)
            {
                    break;
            }
        }
        readOut.close();
    }
    return cantidad;
}

//singleton
Computadora* Computadora::instance=0;

Computadora* Computadora::getInstance()
{
    if (instance == 0)
        instance = new Computadora();
    return instance;
}

//Muestra un producto segun el codigo ingresado
void Computadora::getProducto(string miCodigo)
{
    ifstream readOut;
    readOut.open("Computadora.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo )
        {
            if(codigo==miCodigo)
            {
                cout<< "Datos del Producto:"        <<endl
                    <<"Codigo: "<<codigo            <<endl
                    <<"Nombre: "<<nombre            <<endl
                    <<"Categoria: "<<categoria      <<endl
                    <<"Precio: $"<<precio           <<endl
                    <<"Stock: "<<cantidad           <<endl
                    <<"Componente: "<<tipo          <<endl<<endl<<endl;
                    break;
            }
        }
        readOut.close();
    }
}


//Modifica la cantidad, usada en la opcion 5
void Computadora::modifyCantidad(string miCodigo, int stock)
{
        ifstream readOut;
        readOut.open("Computadora.txt");
        ofstream readIn;
        readIn.open("temp.txt");
        while ( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo )
        {
            if ( miCodigo != codigo)
            {
                readIn << codigo << ' ' << nombre << ' ' << categoria << ' ' << precio << ' ' << cantidad << ' ' << tipo <<endl;            }
            else
            {
                readIn << codigo << ' ' << nombre << ' ' << categoria << ' ' << precio << ' ' << stock << ' ' << tipo <<endl;            }
        }
    readIn.close();
    readOut.close();
    remove("Computadora.txt");
    rename("temp.txt","Computadora.txt");
    cout <<endl<<endl<<endl;
}


