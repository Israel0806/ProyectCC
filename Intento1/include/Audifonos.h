#ifndef AUDIFONOS_H
#define AUDIFONOS_H
#include "Producto.h"

class Audifonos : public Producto
{
private:
    //int cantidad;
    string conexion,tier1,tier2;//,tier3,caracteristica;
   // string codigo; Tier1 conexion Tier 2
public:
    Audifonos();
    void setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad,string miConexion,string miTier1,string miTier2);//,string miTier3,string miCaracteristica);
    void getData();
};



#endif // AUDIFONOS_H
