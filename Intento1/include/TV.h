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
        void getData();
        string getCategoria();
        string getNombre();
        string getCodigo();
        float getPrecio();
        int getCantidad();



};

#endif // TV_H
