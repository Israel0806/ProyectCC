#ifndef COMPUTADORA_H
#define COMPUTADORA_H
#include "Producto.h"
#include "fstream"
class Computadora : public Producto
{
    private:
        string tipo;
        Computadora();
        static Computadora * instance;
    public:
        static Computadora* getInstance();
        void setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad,string miTipo);
        void getData();
        string getCategoria();
        string getNombre(string miCodigo);
        string getCodigo();
        float getPrecio(string miCodigo);
        int getCantidad(string miCodigo);
        void getProducto(string codigo);
        void modifyCantidad(string miCodigo, int stock);
};

#endif // COMPUTADORA_H
