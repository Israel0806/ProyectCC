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
        void getData();
        string getCategoria();
        string getNombre();
        string getCodigo();
        float getPrecio();
        int getCantidad();

};

#endif // COMPUTADORA_H
