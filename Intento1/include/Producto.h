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

        virtual void setData()=0;
        virtual void getData()=0;
        virtual string getCategoria()=0;
        virtual string getNombre()=0;
        virtual string getCodigo()=0;
        virtual float getPrecio()=0;
        virtual int getCantidad()=0;

};

#endif // PRODUCTO_H
