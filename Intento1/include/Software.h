#ifndef SOFTWARE_H
#define SOFTWARE_H
#include "Producto.h"
#include <fstream>
class Software : public Producto
{

    private:
        string tier1,tier2;
        Software();
        static Software* instance;
    public:
        static Software* getInstance();
        void setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad, string miTier1, string miTier2);
        void getData();
        string getCategoria();
        string getNombre(string miCodigo);
        string getCodigo();
        float getPrecio(string miCodigo);
        int getCantidad(string miCodigo);
        void getProducto(string codigo);
        void modifyCantidad(string miCodigo, int stock);
};

#endif // SOFTWARE_H
