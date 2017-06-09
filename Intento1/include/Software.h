#ifndef SOFTWARE_H
#define SOFTWARE_H
#include "Producto.h"

class Software : public Producto
{

    private:
        string Tier1,Tier2;
    public:
        Software();
        void setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miTier1, string miTier2);
        void getData();
        string getCategoria();
        string getNombre();
        string getCodigo();
        float getPrecio();
        int getCantidad();

};

#endif // SOFTWARE_H
