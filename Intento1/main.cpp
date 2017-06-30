#include <iostream>
#include<stdlib.h>
#include <vector>
#include <string.h>

#include <algorithm>
#include <iterator>
#include <fstream>


#include "Menu.h"


using namespace std;


void MostrarCodigo(string categoria);
void MostrarNombre(string categoria);
void MostrarProducto();

/*int arr[]={1,2}

int *ptr=arr;

int temp;
temp=*ptr;
*ptr=*(ptr+1);
*(ptr+1)=temp;*/

// outpu  ptr=2  ptr+1=1


//Variables globales
//int p0,p1,p2,p3,p4,p5; //Contador de cada tipo de producto, codigo     pasado a menu.h


int main()
{
    //Declaracion de instancias
    system("Title Proyecto Base de Datos");


    //Declaracion de comandos
    Opcion *opcion= new Opcion;

    // concrete Command objects
    Opcion1 *op1=new Opcion1(opcion);
    Opcion2 *op2=new Opcion2(opcion);
    Opcion3 *op3=new Opcion3(opcion);
    Opcion4 *op4=new Opcion4(opcion);
    Opcion5 *op5=new Opcion5(opcion);

    // invoker objects
    Menu *menu=new Menu;

    // execute

    do
    {
        printMenu(); cin>>op;
        comprobar6Op(op);
        switch(op)
            {
            case 1:
                {
                menu->setComando(op1);
                menu->buttonPressed();
                break;
                }
            case 2:
                {
                menu->setComando(op2);
                menu->buttonPressed();
                break;
                }
            case 3:
                {
                menu->setComando(op3);
                menu->buttonPressed();
                break;
                }
            case 4:
                {
                menu->setComando(op4);
                menu->buttonPressed();
                break;
                }
            case 5:
                {
                //Realiza la venta de un producto
                menu->setComando(op5);
                menu->buttonPressed();
                break;
                }
            case 6:
                {
                //Termina el programa
                break;
                }
            }
        /*system("pause");
        system("cls");*/
    }
    while(op!=6);
    delete opcion;
    delete menu;
    delete op1;
    delete op2;
    delete op3;
    delete op4;
     delete op5;
    return 0;
}




/*void MostrarCodigo(string categoria);
void MostrarNombre(string categoria);
void MostrarProducto();


void ordenPrecio(string categoria,vector<Producto *> productos)
{
    vector<int> pos;
    int i=0,x=0;
    for(;i<int(productos.size());i++)

        if(productos[i]->getCategoria()==categoria)
        {
            pos.push_back(i);
        }
    }
    vector <int>temp=pos;
    for(i=0;i<int(pos.size());i++)
    {
        for(int j=0;j<int(pos.size());j++)
        {
            //if(strcmp(producto2[i],producto2[j])<0)
            if(productos[i]->getPrecio()>productos[j]->getPrecio())
            {
                int p1;
                p1=temp[i];
                temp[i]=temp[j];
                temp[j]=p1;
            }
        }
    }
    pos=temp;

    i=0;
    for(;i<int(pos.size());i++,x++)
        productos[(pos[x])]->getData();
}*/







