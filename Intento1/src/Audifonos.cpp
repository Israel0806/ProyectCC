#include "Audifonos.h"

Audifonos::Audifonos()
{

}



void Audifonos::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad,string miConexion,string miTier1,string miTier2)//,string miTier3,string miCaracteristica)
{
    nombre=miNombre;
    precio=miPrecio;
    categoria=miCategoria;
    cantidad=miCantidad;
    codigo=miCodigo;
    conexion=miConexion;
    tier1=miTier1;
    tier2=miTier2;
    //tier3=miTier3;
    //caracteristica=miCaracteristica;
}

void Audifonos::getData()
{
    cout<<"Codigo: "<<codigo<<endl
        <<"Nombre: "<<nombre<<endl
        <<"Categoria: "<<categoria<<endl
        <<"Precio: "<<precio<<endl
        <<"Cantidad: "<<cantidad<<endl
        <<"Conexion: "<<conexion<<endl
        <<"Tier1: "<<tier1<<endl
        <<"Tier2: "<<tier2<<endl;
}
