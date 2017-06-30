#ifndef AUDIFONOS_H
#define AUDIFONOS_H
#include "Producto.h"

class Audifonos : public Producto
{
private:
    string conexion,tier1,tier2;
    //Singleton
    static Audifonos* instance;
    Audifonos();
public:
    static Audifonos* getInstance();

    void setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad,string miConexion,string miTier1,string miTier2);//,string miTier3,string miCaracteristica);
    void getData();
    string getCategoria();
    string getNombre(string miCodigo);
    string getCodigo();
    float getPrecio(string miCodigo);
    int getCantidad(string miCodigo);

    void getProducto(string miCodigo);
    void modifyCantidad(string miCodigo, int stock);
};



#endif // AUDIFONOS_H
