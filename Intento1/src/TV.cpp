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

string TV::getNombre(string miCodigo)
{
    ifstream readOut;
    readOut.open("TV.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> calidad >> caracteristicas >> pantallaTy >> tam )
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

string TV::getCodigo()
{
    return codigo;
}

float TV::getPrecio()
{
    return precio;
}

int TV::getCantidad(string miCodigo)
{
    ifstream readOut;
    readOut.open("TV.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> calidad >> caracteristicas >> pantallaTy >> tam )
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


TV* TV::instance=0;

TV* TV::getInstance()
{
    if (instance == 0)
        instance = new TV();
    return instance;
}

void TV::getProducto(string miCodigo)
{
    ifstream readOut;
    readOut.open("TV.txt");
    if(readOut.is_open())
    {
        while( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> calidad >> caracteristicas >> pantallaTy >> tam )
        {
            if(codigo==miCodigo)
            {

                cout<< "Datos del Producto:"                <<endl
                    <<"Codigo: "<<codigo                    <<endl
                    <<"Nombre: "<<nombre                    <<endl
                    <<"Categoria: "<<categoria              <<endl
                    <<"Precio: $"<<precio                   <<endl
                    <<"Stock: "<<cantidad                   <<endl
                    <<"Calidad: "<<calidad                  <<endl
                    <<"Caracteristica: "<<caracteristicas   <<endl
                    <<"Tipo de Pantalla: "<<pantallaTy      <<endl
                    <<"Tamanho:  \""<<tam                   <<endl<<endl<<endl;
                break;
            }
        }
        readOut.close();
    }
}

void TV::modifyCantidad(string miCodigo, int stock)
{
        ifstream readOut;
        readOut.open("TV.txt");
        ofstream readIn;
        readIn.open("temp.txt");
        while ( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> calidad >> caracteristicas >> pantallaTy >> tam )
        {
            if ( miCodigo != codigo)
            {
                readIn<< codigo << ' ' << nombre << ' ' << categoria << ' ' << precio << ' ' << cantidad << ' ' << calidad << ' ' << caracteristicas << ' ' << pantallaTy << ' ' << tam <<endl;
            }
            else
            {
                readIn<< codigo << ' ' << nombre << ' ' << categoria << ' ' << precio << ' ' << stock << ' ' << calidad << ' ' << caracteristicas << ' ' << pantallaTy << ' ' << tam <<endl;
            }
    }
    readIn.close();
    readOut.close();
    remove("TV.txt");
    rename("temp.txt","TV.txt");
    cout <<endl<<endl<<endl;
}
