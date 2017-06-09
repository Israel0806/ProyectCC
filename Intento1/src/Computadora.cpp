#include "Computadora.h"

Computadora::Computadora()
{

}
void Computadora::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad,string miTipo)
{
    nombre=miNombre;
    precio=miPrecio;
    categoria=miCategoria;
    codigo=miCodigo;
    cantidad=miCantidad;
    tipo=miTipo;
}

void Computadora::getData()
{
    cout                           <<endl
        <<"Codigo: "<<codigo       <<endl
        <<"Nombre: "<<nombre       <<endl
        <<"Categoria: "<<categoria <<endl
        <<"Precio: "<<precio       <<endl
        <<"Cantidad: "<<cantidad   <<endl
        <<"Tipo: "<<tipo           <<endl
                                   <<endl;

}


string Computadora::getCategoria()
{
    return categoria;
}

string Computadora::getNombre()
{
    return nombre;
}

string Computadora::getCodigo()
{
    return codigo;
}

float Computadora::getPrecio()
{
    return precio;
}

int Computadora::getCantidad()
{
    return cantidad;
}
