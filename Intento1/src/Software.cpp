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

string Software::getNombre(string miCodigo)
{
    ifstream readOut;
    readOut.open("Software.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tier1 >> tier2 )
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

string Software::getCodigo()
{
    return codigo;
}

float Software::getPrecio(string miCodigo)
{
    ifstream readOut;
    readOut.open("Software.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tier1 >> tier2 )
        {
            if(codigo==miCodigo)
            {
                break;
            }
        }
        readOut.close();
    }
    return precio;
}

int Software::getCantidad(string miCodigo)
{
    ifstream readOut;
    readOut.open("Software.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tier1 >> tier2 )
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


Software* Software::instance=0;

Software* Software::getInstance()
{
    if (instance == 0)
        instance = new Software();
    return instance;
}


void Software::getProducto(string miCodigo)
{
    ifstream readOut;
    readOut.open("Software.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tier1 >> tier2 )
        {
            if(codigo==miCodigo)
            {

                cout<< "Datos del Producto:"        <<endl
                    <<"Codigo: "<<codigo            <<endl
                    <<"Nombre: "<<nombre            <<endl
                    <<"Categoria: "<<categoria      <<endl
                    <<"Precio: $"<<precio           <<endl
                    <<"Stock: "<<cantidad           <<endl
                    <<"Tier1: "<<tier1              <<endl
                    <<"Tier2: "<<tier2              <<endl<<endl<<endl;
                break;
            }
        }
        readOut.close();
    }
}

void Software::modifyCantidad(string miCodigo, int stock)
{
        ifstream readOut;
        readOut.open("Software.txt");
        ofstream readIn;
        readIn.open("temp.txt");
        while ( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tier1 >> tier2 )
        {
            if ( miCodigo != codigo)
            {
                readIn<< codigo << ' ' << nombre << ' ' << categoria << ' ' << precio << ' ' << cantidad << ' ' << tier1 << ' ' << tier2 << ' '<<endl;
            }
            else
            {
                readIn<< codigo << ' ' << nombre << ' ' << categoria << ' ' << precio << ' ' << stock << ' ' << tier1 << ' ' << tier2 << ' '<<endl;
            }
    }
    readIn.close();
    readOut.close();
    remove("Software.txt");
    rename("temp.txt","Software.txt");
    cout <<endl<<endl<<endl;
}
