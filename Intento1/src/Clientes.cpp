#include "Clientes.h"
#include <iostream>
using namespace std;

Clientes::Clientes()
{}

void Clientes::setData(char miNombre[], string miDireccion, int miEdad, char miSexo)// cambiar a char el sexo jejeje

{
    nombre=miNombre;
    direccion=miDireccion;
    edad=miEdad;
    sexo=miSexo;
    /*listaClienteChar[x][0]=nombre;
    listaClienteChar[x][1]=direccion;
    listaClienteChar[x][2]=preferencia;
    listaClienteChar[x][3]=sexo;
    listaClienteInt[x][0]=edad;
    listaClienteInt[x][1]=x;*/
}

void Clientes::getData(int a)
{
    cout<<"Nombre: "<<nombre<<endl
    <<"Direccion: "<<direccion<<endl
    <<"Preferencias: "<<preferencia<<endl
    <<"Edad: "<<edad<<endl
    <<"Sexo"<<sexo<<endl;
}
