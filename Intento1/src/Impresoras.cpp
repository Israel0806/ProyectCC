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

string Impresoras::getNombre(string miCodigo)
{
    ifstream readOut;
    readOut.open("Impresoras.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo >> caracteristicas >> tamanho )
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

string Impresoras::getCodigo()
{
    return codigo;
}

float Impresoras::getPrecio()
{
    return precio;
}

int Impresoras::getCantidad(string miCodigo)
{
    ifstream readOut;
    readOut.open("Impresoras.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo >> caracteristicas >> tamanho )
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

Impresoras* Impresoras::instance=0;

Impresoras* Impresoras::getInstance()
{
    if (instance == 0)
        instance = new Impresoras();
    return instance;
}


void Impresoras::getProducto(string miCodigo)
{
    ifstream readOut;
    readOut.open("Impresoras.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo >> caracteristicas >> tamanho )
        {
            if(codigo==miCodigo)
            {
                cout<< "Datos del Producto:"                <<endl
                    <<"Codigo: "<<codigo                    <<endl
                    <<"Nombre: "<<nombre                    <<endl
                    <<"Categoria: "<<categoria              <<endl
                    <<"Precio: $"<<precio                   <<endl
                    <<"Stock: "<<cantidad                   <<endl
                    <<"Tipo: "<<tipo                        <<endl
                    <<"Caracteristica: "<<caracteristicas   <<endl
                    <<"Tamanho: "<<tamanho                  <<endl<<endl<<endl;
                break;
            }
        }
    readOut.close();
    }
}


void Impresoras::modifyCantidad(string miCodigo, int stock)
{
        ifstream readOut;
        readOut.open("Impresoras.txt");
        ofstream readIn;
        readIn.open("temp.txt");
        while ( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo >> caracteristicas >> tamanho )
        {
            if ( miCodigo != codigo)
            {
                readIn<< codigo << ' ' << nombre << ' ' << categoria << ' ' << precio << ' ' << cantidad << ' ' << tipo << ' ' << caracteristicas << ' ' << tamanho <<endl;            }
            else
            {
                readIn<< codigo << ' ' << nombre << ' ' << categoria << ' ' << precio << ' ' << stock << ' ' << tipo << ' ' << caracteristicas << ' ' << tamanho <<endl;            }
    }
    readIn.close();
    readOut.close();
    remove("Impresoras.txt");
    rename("temp.txt","Impresoras.txt");
    cout <<endl<<endl<<endl;
}
