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
