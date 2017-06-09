#include "TV.h"

TV::TV()
{

}

void TV::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miCalidad, string miCaracteristicas,string mipantallaTy, float miTam)
{
    nombre=miNombre;
    precio=miPrecio;
    categoria=miCategoria;
    codigo=miCodigo;
    calidad=miCalidad;
    pantallaTy=mipantallaTy;
    tam=miTam;
    caracteristicas=miCaracteristicas;
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
