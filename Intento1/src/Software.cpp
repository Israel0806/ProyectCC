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
