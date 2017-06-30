#include <iostream>
#include<stdlib.h>
#include <vector>
#include <string.h>

#include <algorithm>
#include <iterator>
#include <fstream>

#include "Menu.h"


using namespace std;

int main()
{

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
