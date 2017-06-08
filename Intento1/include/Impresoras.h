#ifndef IMPRESORAS_H
#define IMPRESORAS_H
#include "Producto.h"

class Impresoras : public Producto
{
    private:
        string tipo,caracteristicas,tamanho;
    public:
        Impresoras();
        void setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miTipo, string miCaracteristica, string miTamanho);

};

#endif // IMPRESORAS_H
