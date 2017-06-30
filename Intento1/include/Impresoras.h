#ifndef IMPRESORAS_H
#define IMPRESORAS_H
#include "Producto.h"
#include <fstream>
class Impresoras : public Producto
{
    private:
        string tipo,caracteristicas,tamanho;
        Impresoras();
        static Impresoras* instance;
    public:
        static Impresoras* getInstance();
        void setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miTipo, string miCaracteristica, string miTamanho);
        void getData();
        string getCategoria();
        string getNombre(string miCodigo);
        string getCodigo();
        float getPrecio();
        int getCantidad(string miCodigo);
        void getProducto(string codigo);
        void modifyCantidad(string miCodigo, int stock);
};

#endif // IMPRESORAS_H
