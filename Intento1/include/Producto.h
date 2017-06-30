#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
using namespace std;

class Producto
{
    protected:
        float precio;
        string codigo,nombre,categoria;
        int cantidad;
    public:
        virtual void setData() {}
        virtual void getData()=0;
        virtual string getCategoria()=0;
        virtual string getNombre() {}
        virtual string getCodigo()=0;
        virtual float getPrecio() {}
        virtual int getCantidad() {}
        virtual void getProducto() {}
};

#endif // PRODUCTO_H
