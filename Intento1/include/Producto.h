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
        Producto();
        virtual void setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad);
        virtual void getData();
        virtual string getCategoria();
        virtual string getNombre();
        virtual string getCodigo();
        virtual float getPrecio();
        virtual int getCantidad();

};

#endif // PRODUCTO_H
