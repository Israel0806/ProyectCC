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
