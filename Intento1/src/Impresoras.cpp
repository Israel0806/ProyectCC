#include "Impresoras.h"

Impresoras::Impresoras()
{

}


void Impresoras::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miTipo, string miCaracteristica,string miTamanho)
{
    nombre=miNombre;
    precio=miPrecio;
    categoria=miCategoria;
    codigo=miCodigo;
    cantidad=miCantidad;
    tipo=miTipo;
    caracteristicas=miCaracteristica;
    tamanho=miTamanho;

}

void Impresoras::getData()
{
    cout                                      <<endl
        <<"Codigo: "<<codigo                  <<endl
        <<"Nombre: "<<nombre                  <<endl
        <<"Categoria: "<<categoria            <<endl
        <<"Precio: "<<precio                  <<endl
        <<"Cantidad: "<<cantidad              <<endl
        <<"tipo: "<<tipo                      <<endl
        <<"Caracteristica: "<<caracteristicas <<endl
        <<"tamanho: "<<tamanho                <<endl
                                              <<endl;
}

string Impresoras::getCategoria()
{
    return categoria;
}

string Impresoras::getNombre()
{
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

int Impresoras::getCantidad()
{
    return cantidad;
}
