#include "TV.h"

TV::TV()
{

}

void TV::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miCalidad, string miCaracteristicas,string mipantallaTy, float miTam)
{
fstream readIn;
    readIn.open("Computadora.txt", ios::app | ios::in );
    readIn<< miCodigo << ' ' << miNombre << ' ' << miCategoria << ' ' << miPrecio << ' ' << miCantidad << ' ' << miCalidad << ' ' << miCaracteristicas << ' ' << mipantallaTy << ' ' << miTam <<endl;
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

void TV::getData()
{
    cout                                      <<endl
        <<"Codigo: "<<codigo                  <<endl
        <<"Nombre: "<<nombre                  <<endl
        <<"Categoria: "<<categoria            <<endl
        <<"Precio: "<<precio                  <<endl
        <<"Cantidad: "<<cantidad              <<endl
        <<"Calidad: "<<calidad                <<endl
        <<"Caracteristica: "<<caracteristicas <<endl
        <<"Tipo de pantalla: "<<pantallaTy    <<endl
        <<"Tamanho de pantalla: "<<tam        <<endl
                                              <<endl;
}

string TV::getCategoria()
{
    return categoria;
}

string TV::getNombre()
{
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

int TV::getCantidad()
{
    return cantidad;
}
