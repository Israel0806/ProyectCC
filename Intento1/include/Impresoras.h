#ifndef IMPRESORAS_H
#define IMPRESORAS_H
#include "Producto.h"
#include <fstream>
class Impresoras : public Producto
{
    private:
        string tipo,caracteristicas,tamanho;
    public:
        Impresoras();
        void setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miTipo, string miCaracteristica, string miTamanho);
        void getData();
        string getCategoria();
        string getNombre();
        string getCodigo();
        float getPrecio();
        int getCantidad();

};

#endif // IMPRESORAS_H
