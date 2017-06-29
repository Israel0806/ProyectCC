#ifndef CLIENTES_H
#define CLIENTES_H
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Clientes
{
    private:
        char sexo;
        string nombre,direccion;
        int edad,codigo;
        float capital;
    public:
        Clientes();
        void setData(string miNombre, string miDireccion, int miEdad, char miSexo, float miCapital, int miCodigo);

        string getNombre() { return nombre; }
        string getDireccion() { return direccion; }
        char getSexo() { return sexo; }
        float getCapital() { return capital; }
        int getEdad() { return edad; }
        int getCodigo() { return codigo; }
};

template<class T>
class Queue : public Clientes
{
public:
    /*T pop()
    {
        T first=items.front();
        items.pop_back();
        return first;
    }*/
    void push(Clientes &c)
    {
        ofstream readIn;
        readIn.open("Clientes.txt", ios::app | ios::in);
        readIn << c.getCodigo() << ' ' << c.getNombre() << ' ' << c.getDireccion() << ' ' << c.getEdad() << ' ' << c.getSexo() << ' ' << c.getCapital() <<endl;
        readIn.close();
        ifstream readOut;
        readOut.open("Clientes.txt");
        string line;
        while( getline(readOut,line) )
            cout<< line<< '\n';
        readOut.close();
    }

    friend ostream& operator<<(ostream &o, Queue<T> &c)
    {
        string line,nombre,codigo,direccion,edad,sexo,capital;
        int i=1;
        ifstream readOut;
        readOut.open("Clientes.txt", ios::out );
        if(readOut.is_open())
        {
            o<<"ingreso al while\n\n";
            while( getline(readOut,line) )
            {
                //o<<"\n\ningreso\n\n";
                readOut >> codigo >> nombre >> direccion >> edad >> sexo >> capital;
                o   <<"\n\n line: "<<line           <<endl<<endl
                    << "Datos del cliente "<<i<<":" <<endl
                    <<"Codigo: "<<codigo            <<endl
                    <<"Nombre: "<<nombre            <<endl
                    <<"Direccion: "<<direccion      <<endl
                    <<"Edad: "<<edad                <<endl
                    <<"Sexo: "<<sexo                <<endl
                    <<"Capital: $"<<capital         <<endl;
                i++;
            }
        }
        else
        {
            cout<<"No se pudo ingresar a la base de datos"<<endl;
        }
        readOut.close();
        return o;
    }
};


#endif // CLIENTES_H
