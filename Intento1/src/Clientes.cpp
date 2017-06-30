#include "Clientes.h"
#include <iostream>
using namespace std;


Clientes::Clientes() { }

void Clientes::setData(string miNombre, string miDireccion, int miEdad, char miSexo, float miCapital, int miCodigo)// cambiar a char el sexo jejeje
{
        codigo=miCodigo;
        nombre=miNombre;
        direccion=miDireccion;
        edad=miEdad;
        sexo=miSexo;
        capital=miCapital;
}

float Clientes::getCapital(string miCodigo)
{
    string pCodigo;
    ifstream readOut;
    readOut.open("Clientes.txt", ios::out);
    if(readOut.is_open())
    {
        while( readOut >> pCodigo >> nombre >> direccion >> edad >> sexo >> capital )
        {
            if(pCodigo==miCodigo)
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
    return capital;
}

// Se verifica el codigo dentro de la opcion 5
bool Clientes::verifyCode(string code)
{
    string miCodigo;
    bool verify=false;
    ifstream readOut;
    readOut.open("Clientes.txt");
    while (readOut >> miCodigo >> nombre >> direccion >> edad >> sexo >> capital )
    {
        if(miCodigo==code)
            verify=true;
    }
    return verify;
}
