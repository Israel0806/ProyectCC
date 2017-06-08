#ifndef TV_H
#define TV_H
#include "Producto.h"

class TV : public Producto
{
    private:
        //int codigo; // letra,calidad,caracteristicas,tipo del pantalla, tamaño
        float tam;
        string caracteristicas,pantallaTy,calidad;
    public:
        TV();
        void setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miCalidad, string miCaracteristicas,string mipantallaTy, float miTam);
//        getTv(char miCodigo[]);



};

#endif // TV_H
