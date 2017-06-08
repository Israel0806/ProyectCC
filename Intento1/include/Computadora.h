#ifndef COMPUTADORA_H
#define COMPUTADORA_H
#include "Producto.h"

class Computadora : public Producto
{
    private:
        string tipo;
    public:
        Computadora();
        void setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad,string miTipo);
};

#endif // COMPUTADORA_H
