#ifndef TV_H
#define TV_H
#include "Producto.h"
#include <fstream>
class TV : public Producto
{
    private:
        //int codigo; // letra,calidad,caracteristicas,tipo del pantalla, tamaño
        float tam;
        string caracteristicas,pantallaTy,calidad;
        TV();
        static TV* instance;
    public:
        static TV* getInstance();
        void setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miCalidad, string miCaracteristicas,string mipantallaTy, float miTam);
        void getData();
        string getCategoria();
        string getNombre(string miCodigo);
        string getCodigo();
        float getPrecio();
        int getCantidad(string miCodigo);
        void getProducto(string codigo);
        void modifyCantidad(string miCodigo, int stock);
};

#endif // TV_H
