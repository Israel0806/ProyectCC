#include "Software.h"

Software::Software()
{

}

void Software::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miTier1, string miTier2)
{
    nombre=miNombre;
    precio=miPrecio;
    categoria=miCategoria;
    codigo=miCodigo;
    Tier1=miTier1;
    Tier2=miTier2;
}

void Software::getData()
{
    cout                           <<endl
        <<"Codigo: "<<codigo       <<endl
        <<"Nombre: "<<nombre       <<endl
        <<"Categoria: "<<categoria <<endl
        <<"Precio: "<<precio       <<endl
        <<"Cantidad: "<<cantidad   <<endl
        <<"Tier1: "<<Tier1         <<endl
        <<"Tier2: "<<Tier2         <<endl
                                   <<endl;
}

string Software::getCategoria()
{
    return categoria;
}

string Software::getNombre()
{
    return nombre;
}

string Software::getCodigo()
{
    return codigo;
}

float Software::getPrecio()
{
    return precio;
}

int Software::getCantidad()
{
    return cantidad;
}
