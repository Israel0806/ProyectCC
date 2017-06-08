#ifndef CLIENTES_H
#define CLIENTES_H
#include <iostream>
using namespace std;

class Clientes
{
    private:
        char sexo;
        string nombre,direccion,preferencia;
        int edad;
        //string nombre,direccion,preferencia,sexo;
        //int edad;
    public:
        Clientes();
        void setData(char miNombre[], string miDireccion, int miEdad, char miSexo);
        void getData(int a);
        /*void ChangeName();
        void ChangeDirec();
        void ChangePref();
        void ChangeEdad();*/
};

#endif // CLIENTES_H
