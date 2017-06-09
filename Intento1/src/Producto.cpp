#include "Producto.h"
#include <iostream>
using namespace std;

Producto::Producto()
{}

void Producto::setData(string miNombre, float miPrecio, string miCategoria, string miCodigo, int miCantidad)
{
    nombre=miNombre;
    precio=miPrecio;
    categoria=miCategoria;
    codigo=miCodigo;
    cantidad=miCantidad;
}

void Producto::getData() {}

string Producto::getCategoria() { return categoria; }

string Producto::getNombre() { return nombre; }

string Producto::getCodigo() { return codigo; }

float Producto::getPrecio() { return precio; }

int Producto::getCantidad() { return cantidad; }
