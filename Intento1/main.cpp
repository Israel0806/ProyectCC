#include <iostream>
#include<stdlib.h>
#include <vector>
#include <string.h>

#include <algorithm>
#include <iterator>

#include "Clientes.h"
#include "Producto.h"
#include "Audifonos.h"
#include "Impresoras.h"
#include "Software.h"
#include "TV.h"
#include "Computadora.h"






//A1023
//I102
using namespace std;




/* de char a int

#include <stdlib.h>
char a[]={'1','2','3'};
int b=atoi(a);
cout<<b+2;


burbuja:
for(int i=0;i<f2;i++)
{
    for(int j=0;j<f2;j++)
    {
        if(strcmp(producto2[i],producto2[j])<0)
        {

        }
    }
}

*/
//Declaracion de instancias
Clientes clientes[20];
Computadora computadoras[20];
Audifonos audifonos[20];
Software software[20];
TV Tv[20];
Impresoras impresoras[20];
/*vector <Clientes *> clientes;
vector <Computadora *> computadoras;*/



vector <Producto *> productos;


/*





*/






void printMenu();
void printCategorias();
void printComponentes();
void ordenAlfabetico(string categoria,vector<Producto *> productos);
void ordenPrecio(string categoria,vector<Producto *> productos);

void comprobar2Op(int &x);
void comprobar3Op(int &x);
void comprobar4Op(int &x);
void comprobar5Op(int &x);
void comprobar6Op(int &x);
void comprobar8Op(int &x);

int main()
{
    //Declaracion de instancias
    Clientes clientes[20];
    Computadora computadoras[20];
    Audifonos audifonos[20];
    Software software[20];
    TV Tv[20];
    Impresoras impresoras[20];
    /*vector <Clientes *> clientes;
    vector <Computadora *> computadoras;*/



    vector <Producto *> productos;
    /*for(int y=0; y<20; y++) //Queda pendiente mejorar el push back
    {
        productos.push_back(&computadoras[y]);
        productos.push_back(&audifonos[y]);
        productos.push_back(&software[y]);
        productos.push_back(&Tv[y]);
        productos.push_back(&impresoras[y]);
    }*/

    //Declaracion de variables
    int p1=0,p2=0,p3=0,p4=0,p5=0; //Contador de cada tipo de producto, codigo

    int op,c=0,p=0,cat,lo;
    int edad,cantidad;
    float precio;
    string direccion,tipo,categoria;
    char nombre[20],sexo;
    do
    {
        printMenu(); cin>>op;
        comprobar6Op(op);
        switch(op)
            {
            case 1:
                {
                //datos del cliente
                cout<<"\nDatos del cliente "<<c+1<<": \n\n";
                cout<<"Ingrese el nombre: "; cin>>nombre;
                cout<<"Ingrese la direccion: "; cin>>direccion;
                cout<<"Ingrese la edad: "; cin>>edad;
                //cout<<"Ingrese las preferencias: "; cin>>preferencia;
                cout<<"Ingrese el sexo: "; cin>>sexo;

                //Coloca los datos del cliente en un array(por ahora)
                clientes[c].setData(nombre,direccion,edad,sexo);
                c++; //actualiza numero de cliente(codigo)
                break;
                }
            case 2:
                {

                printCategorias(); cin>>cat;
                comprobar5Op(cat);
                switch(cat)
                {
                    case 1:
                        {
                            //char *au= new char [4];
                           /* char au[4]; //codigo
                            int *r=new int;

                            string cod,nomb;
                            au[0]='A';

                            string tier1,tier2,conexion;

                            cout<<"Ingrese el Nombre del Producto: ";
                            cin>>nombre;
                            nomb=nombre;

                            cout<<"Ingresar precio: ";
                            cin>>precio;

                            cout<<"Ingrese Cantidad: ";
                            cin>>cantidad;



                            cout<<"\n1. Auricular pasivo"<<endl
                                <<"2. Auricular activo"<<endl<<endl;
                                cin>>*r;
                            comprobar2Op(*r);

                            (*r==1)? au[1]='0':au[1]='1';
                            (*r==1)? tier1="Auricular pasivo":tier1="Auricular activo";
                            //au++;
                            cout<<"1. Auriculares abiertos"<<endl
                                <<"2. Auriculares cerrados"<<endl<<endl;
                                cin>>*r;
                            comprobar2Op(*r);

                                (*r==1)? au[2]='0':au[2]='1'; //if statement
                                (*r==1)? tier2="Auriculares abiertos":tier2="Auriculares cerrados";
                            //au++;

                            cout<<"1. Conexion wireless"<<endl
                                <<"2. Conexion alambrica"<<endl<<endl;
                                cin>>*r;
                            comprobar2Op(*r);
                                (*r==1)? au[3]='0':au[3]='1';
                                (*r==1)? conexion="Conexion wireless":conexion="Conexion alambrica";
                            //au--;
                            cod=au;
                            audifonos[p1].setData(nomb,precio,"Audifonos",cod,cantidad,conexion,tier1,tier2);
                            productos.push_back(&audifonos[p1]);
                            //productos[(int(productos.size()))]->getData();
                            p1++;
                            delete r;
                            break;
                            */

                            char au[2]; //codigo
                            int *r=new int;

                            string cod,nomb;
                            au[0]='A';

                            string tier1,tier2,conexion;

                            cout<<"Ingrese el Nombre del Producto: ";
                            cin>>nombre;
                            nomb=nombre;

                            cout<<"Ingresar precio: ";
                            cin>>precio;

                            cout<<"Ingrese Cantidad: ";
                            cin>>cantidad;



                            cout<<"\n1. Auricular pasivo"<<endl
                                <<"2. Auricular activo"<<endl<<endl;
                                cin>>*r;
                            comprobar2Op(*r);

                            (*r==1)? tier1="Auricular pasivo":tier1="Auricular activo";
                            //au++;
                            cout<<"1. Auriculares abiertos"<<endl
                                <<"2. Auriculares cerrados"<<endl<<endl;
                                cin>>*r;
                            comprobar2Op(*r);

                                (*r==1)? tier2="Auriculares abiertos":tier2="Auriculares cerrados";
                            //au++;

                            cout<<"1. Conexion wireless"<<endl
                                <<"2. Conexion alambrica"<<endl<<endl;
                                cin>>*r;
                            comprobar2Op(*r);
                                (*r==1)? conexion="Conexion wireless":conexion="Conexion alambrica";
                            //au--;

                            au[1]='0'+p1;

                            cod=au;
                            audifonos[p1].setData(nomb,precio,"Audifonos",cod,cantidad,conexion,tier1,tier2);
                            productos.push_back(&audifonos[p1]);
                            //productos[(int(productos.size()))]->getData();
                            p1++;
                            delete r;
                            break;




                        }
                    case 2:
                        {
                         //Computadoras
                            //char *au= new char [4];
                            char comp[2]; //codigo
                            int *r=new int;

                            string cod,nomb;
                            comp[0]='C';

                            string componente;

                            cout<<"Ingrese el Nombre del Producto: ";
                            cin>>nombre;
                            nomb=nombre;

                            cout<<"Ingresar precio: ";
                            cin>>precio;

                            cout<<"Ingrese Cantidad: ";
                            cin>>cantidad;



                            cout<<"\n1. Componente"<<endl;
                            printComponentes();
                            cin>>*r;
                            comprobar8Op(*r);

                            switch(*r)
                            {
                            case 1:
                                comp[1]=0;
                                componente="Fuente";
                            case 2:
                                comp[1]=1;
                                componente="CPU";
                            case 3:
                                comp[1]=2;
                                componente="Memoria RAM";
                            case 4:
                                comp[1]=3;
                                componente="HDD";
                            case 5:
                                comp[1]=4;
                                componente="GPU";
                            case 6:
                                comp[1]=5;
                                componente="MotherBoard";
                            case 7:
                                comp[1]=6;
                                componente="Case";
                            case 8:
                                comp[1]=7;
                                componente="Perifericos";
                            }

                            comp[1]='0'+p2;

                            //comp--;
                            cod=comp;

                            computadoras[p2].setData(nomb,precio,"Computadoras",cod,cantidad,tipo);
                            productos.push_back(&computadoras[p2]);
                           // computadoras[p].getData();
                            p2++;
                            delete r;
                            break;
                        }
                    case 3:
                        {
                            char imp[2]; //codigo
                            int *r=new int;

                            string cod,nomb;
                            imp[0]='I';
                            //void setData(string miNombre, float miPrecio,
                            //string miCategoria, s
                            //tring miCodigo, int miCantidad,
                            //string miTipo, string miCaracteristica[]);


                            string caracteristica,tamanho,tipo;


                            cout<<"Ingrese el Nombre del Producto: ";
                            cin>>nombre;
                            nomb=nombre;

                            cout<<"Ingresar precio: ";
                            cin>>precio;

                            cout<<"Ingrese Cantidad: ";
                            cin>>cantidad;

                            cout<<"Ingrese el tamanho de impresion\n";
                            cin>>tamanho;

                            cout<<"\n\nCaracteristica: "<<endl
                                <<"1. Blanco y negro"   <<endl
                                <<"2. A color"          <<endl;

                            cin>>*r;
                            comprobar2Op(*r);

                            (*r==1)? caracteristica="Blanco y negro" :caracteristica="A color";

                            cout<<"\n1.Impresion laser\n"
                                <<"2. Impresion por cartucho"<<endl;
                                cin>>*r;
                            comprobar2Op(*r);

                            (*r==1)? tipo="Impresion laser":tipo="Impresion por cartucho";


                            imp[1]='0'+p3;

                            //comp--;
                            cod=imp;

                            /*while(caracteristicas[i]!=NULL)
                                carac[i]=caracteristicas[i];*/

                            impresoras[p3].setData(nomb, precio, "Impresoras", cod, cantidad, tipo, caracteristica, tamanho);
                            productos.push_back(&impresoras[p3]);
                            //computadoras[p3].getData();
                            p3++;
                            delete r;
                            break;
                        }
                    case 4:
                        {
                            //software

                            char soft[2]; //codigo
                            int *r=new int;

                            string cod,nomb;
                            soft[0]='S';

                            string tier1, tier2;

                            cout<<"Ingrese el Nombre del Producto: ";
                            cin>>nombre;
                            nomb=nombre;

                            cout<<"Ingresar precio: ";
                            cin>>precio;

                            cout<<"Ingrese Cantidad: ";
                            cin>>cantidad;

                            cout<<"1. Educacion" <<endl
                                <<"2. Diseño"    <<endl
                                <<"3. Finanzas"  <<endl
                                <<"4. Seguridad" <<endl;
                            cin>>*r;
                            comprobar4Op(*r);

                            (*r==1)? tier1="Educacion" : (*r==2)? tier1="Diseño" : (*r==3)? tier1="Finanzas" : tier1="Seguridad";

                            switch(*r)
                            {
                                case 1:
                                    cout<<"1. Lenguaje"<<endl
                                        <<"2. Tipeo"<<endl
                                        <<"3. Ninhos"<<endl;
                                        cin>>*r;
                                        comprobar3Op(*r);
                                        (*r==1)? tier2="Lenguaje" : (*r==2)? tier2="Tipeo" : tier2="Ninhos";
                                        break;
                                case 2:
                                    cout<<"1. CAD"<<endl
                                        <<"2. Photography"<<endl
                                        <<"3. Ilustracion"<<endl;
                                        cin>>*r;
                                        comprobar3Op(*r);
                                        (*r==1)? tier2="CAD" : (*r==2)? tier2="Photography" : tier2="Ilustracion";
                                        break;
                                case 3:
                                    cout<<"1. Contabilidad de empresas"<<endl
                                        <<"2. Contabilidad personal"<<endl
                                        <<"3. Distribucion de sueldos"<<endl;
                                        cin>>*r;
                                        comprobar3Op(*r);
                                        (*r==1)? tier2="Contabilidad de empresas" : (*r==2)? tier2="Contabilidad personal" : tier2="Distribucion de sueldos";
                                        break;
                                case 4:
                                    cout<<"1. Antivirus"<<endl
                                        <<"2. Antimalware"<<endl
                                        <<"3. Parental control"<<endl;
                                        cin>>*r;
                                        comprobar3Op(*r);
                                        (*r==1)? tier2="Antivirus" : (*r==2)? tier2="Antimalware" : tier2="Parental control";
                                        break;

                            }

                            soft[1]='0'+p4;

                            cod=soft;

                            software[p4].setData(nomb,precio,"software",cod,cantidad,tier1,tier2);
                            productos.push_back(&software[p4]);
                            //computadoras[p4].getData();
                            p4++;
                            break;
                        }
                    case 5:
                        {
                            //television

                            char tele[2]; //codigo
                            int *r=new int;

                            string cod,nomb;
                            tele[0]='T';

                            cout<<"Ingrese el Nombre del Producto: ";
                            cin>>nombre;
                            nomb=nombre;

                            cout<<"Ingresar precio: ";
                            cin>>precio;

                            cout<<"Ingrese Cantidad: ";
                            cin>>cantidad;


                            string calidad, caracteristicas, pantallaTy; //Caracteristica pasar a array
                            float tam;

                            cout<<"Calidad"        <<endl
                                <<"1. HD"          <<endl
                                <<"2. Ultra HD"    <<endl
                                <<"3. Ultra HD 4K" <<endl;
                                cin>>*r;
                            comprobar3Op(*r);
                            (*r==1)? calidad="HD" : (*r==2)? calidad="Ultra HD" : calidad="Ultra HD 4K";

                            cout<<"Caracteristicas" <<endl
                                <<"1. Curvado"      <<endl
                                <<"2. Smart"        <<endl;
                                cin>>*r;
                                comprobar2Op(*r);
                                (*r==1)? caracteristicas="Curvado" : caracteristicas="Smart" ;

                            cout<<"Tipo de pantalla"<<endl
                                <<"1. LED"          <<endl
                                <<"2. LCD"          <<endl
                                <<"3. OLED"         <<endl;
                                cin>>*r;
                                comprobar3Op(*r);
                            (*r==1)? pantallaTy="LED" : (*r==2)? pantallaTy="LCD"  : pantallaTy="OLED" ;


                            cout<<"Ingrese el tamanho en pulgadas"<<endl;
                            cin>>tam;

                            tele[1]='0'+p5;

                            cod=tele;

                            Tv[p5].setData(nomb,precio,"television",cod,cantidad,calidad,caracteristicas,pantallaTy,tam);
                            productos.push_back(&Tv[p5]);
                            //computadoras[p5].getData();
                            p5++;
                            break;
                        }
                }





                //Datos del producto
                /*cout<<"\nDatos del producto "<<y+1<<": \n\n";
                cout<<"Ingrese el nombre: "; cin>>nombre;
                cout<<"Ingrese la categoria del producto: "; cin>>tipo;
                cout<<"Ingrese la cantidad: "; cin>>cantidad;
                cout<<"Ingrese el precio: "; cin>>precio;*/
                //Coloca los datos del producto en un array(por ahora)
                //productos.setData(nombre,tipo,cantidad,precio,y);

                p++;//Actualiza numero de producto(codigo)
                break;
                }
            case 3:
                //Muestra todos los datos de todos los productos
                //productos.getAllData(y);

                printCategorias();
                cin>>lo;
                comprobar5Op(lo);
                (lo==1)? categoria="Audifonos" : (lo==2)? categoria="Computadoras" : (lo==3)? categoria="Impresoras" : (lo==4)? categoria="Software" : categoria="Television";
                switch(lo)
                {

                     case 1:

                         {

                            cout<<"1. Por Precio: "<<endl;
                            cout<<"2. Por Orden Alfabetico: "<<endl;
                            cin>>lo;
                            comprobar2Op(lo);
                            switch(lo)
                            {
                                case 1: ordenPrecio(categoria, productos); break;

                                case 2: ordenAlfabetico(categoria, productos); break;
                            }
                            break;
                         }
                     case 2:
                        {

                            cout<<"1. Por Precio: "<<endl;
                            cout<<"2. Por Orden Alfabetico: "<<endl;
                            cin>>lo;
                            comprobar2Op(lo);
                            switch(lo)
                            {
                                case 1: ordenPrecio(categoria, productos); break;

                                case 2: ordenAlfabetico(categoria, productos); break;
                            }
                            break;
                        }
                     case 3:
                        {

                            cout<<"1. Por Precio: "<<endl;
                            cout<<"2. Por Orden Alfabetico: "<<endl;
                            cin>>lo;
                            comprobar2Op(lo);
                            switch(lo)
                            {
                                case 1: ordenPrecio(categoria, productos); break;

                                case 2: ordenAlfabetico(categoria, productos); break;
                            }
                            break;
                        }
                     case 4:
                        {

                            cout<<"1. Por Precio: "<<endl;
                            cout<<"2. Por Orden Alfabetico: "<<endl;
                            cin>>lo;
                            comprobar2Op(lo);
                            switch(lo)
                            {
                                case 1: ordenPrecio(categoria, productos); break;

                                case 2: ordenAlfabetico(categoria, productos); break;
                            }
                            break;
                        }
                     case 5:
                        {
                            cout<<"1. Por Precio: "<<endl;
                            cout<<"2. Por Orden Alfabetico: "<<endl;
                            cin>>lo;
                            comprobar2Op(lo);
                            switch(lo)
                            {
                                case 1: ordenPrecio(categoria, productos); break;

                                case 2: ordenAlfabetico(categoria, productos); break;
                            }
                            break;
                        }
                }



                break;
            case 4:
                {
                string lo;
                vector <string> nombres;
                //Busca un producto en especifico
                cout<<"Ingrese el nombre: "<<endl;
                cin>>lo;
                for(unsigned i=0;i<productos.size();i++)
                {
                    nombres.push_back(productos[i]->getNombre());
                }

<<<<<<< HEAD
                vector<string>:: iterator it = find(nombres.begin(),nombres.end(),lo);
                if(it!=nombres.end())
                {
                    for(unsigned i=0;i<productos.size();i++)
                    {
                        if(productos[i]->getNombre()==*it)
                            productos[i]->getData();
                    }
                }
                else
                {
                    cout<<"Producto no encontrado"<<endl<<endl;



                }

                cout<<"Ingrese el Codigo: "<<endl;
                cin>>lo;

                vector<string>codigos;

                for(unsigned i=0;i<productos.size();i++)
                {
                  codigos.push_back(productos[i]->getCodigo());
                }
                vector<string>:: iterator pitochu = find(codigos.begin(),codigos.end(),lo);
                if(pitochu!=codigos.end())
                {
                    for(unsigned i=0;i<productos.size();i++)
                    {
                        if(productos[i]->getCodigo()==*pitochu)
                            productos[i]->getData();
                    }
                }
                else
                {
                    cout<<"Producto no encontrado"<<endl;
                }
=======
>>>>>>> 0bd6ce0d35d95729731f8b48b025805029e32341
                break;
                }




            case 5:

                //Realiza la venta de un producto





                break;
            case 6:
                //Termina el programa
                break;
            //default:
                //cout<<"Ingrese opcion correcta\n";

            }
        cout<<endl;
        system("pause");
        system("cls");
    }
    while(op!=6);
    return 0;
}

void printMenu()
{
    cout<<"\t\t\t\t\t\t Menu de opciones"<<endl     //Ponerle nombre en vez menu de opciones
        <<" 1.Ingresar cliente"  <<endl
        <<" 2.Ingresar producto" <<endl
        <<" 3.Lista de productos"<<endl
        <<" 4.Buscar producto"   <<endl
        <<" 5.Vender producto"   <<endl
        <<" 6.Salir"             <<endl
        <<"Ingrese una opcion"   <<endl;
}

void printCategorias()
{
    /*system("cls");*/
    cout<<"\n\n 1. Audifonos "   <<endl
        <<" 2. Computadoras "    <<endl
        <<" 3. Impresoras "      <<endl
        <<" 4. Software "        <<endl
        <<" 5. Television "      <<endl
        <<"\nIngrese una opcion" <<endl;


}

void printComponentes(){

    cout<<"Componentes"    <<endl
        <<"1. Fuente"      <<endl
        <<"2. CPU"         <<endl
        <<"3. Memoria RAM" <<endl
        <<"4. HDD"         <<endl
        <<"5. GPU"         <<endl
        <<"6. MotherBoard" <<endl
        <<"7. Case"        <<endl
        <<"8. Perifericos" <<endl
                           <<endl;


}





void ordenPrecio(string categoria,vector<Producto *> productos)
{
    vector<int> pos;
    int i=0,x=0;
    for(;i<int(productos.size());i++)
    {
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
}



void ordenAlfabetico(string categoria,vector<Producto *> productos)
{
/*    vector<int> pos;
    vector<int>::iterator it;
    int i=0;
    for(int f=0; int(f<productos.size());f++)
    {
        it = find(productos.begin(),productos.end(),categoria);
        if(it==categoria)
            {
                it=i++;
                pos.push_back(it);
            }
    }
    int *point=&pos;
    for(int i=0;i<pos.size();i++)
    {
        cout<<"asds\n";
    }*/

    vector<int> pos;
    int i=0,x=0;
    for(;i<int(productos.size());i++)
    {
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
            if(productos[i]->getNombre()>productos[j]->getNombre())
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
}



void comprobar2Op(int &x){

while(x!=1 && x!=2)
    {
    cout<<"Opcion Incorrecta\n";
    cin>>x;
    }

}

void comprobar3Op(int &x){

while(x!=1 && x!=2 && x!=3)
    {
    cout<<"Opcion Incorrecta\n";
    cin>>x;
    }
}

void comprobar4Op(int &x){

while(x!=1 && x!=2 && x!=3 && x!=4)
    {
    cout<<"Opcion Incorrecta\n";
    cin>>x;
    }

}

void comprobar5Op(int &x){

while(x!=1 && x!=2 && x!=3 && x!=4 && x!=5)
    {
    cout<<"Opcion Incorrecta\n";
    cin>>x;
    }

}

void comprobar6Op(int &x){

while(x!=1 && x!=2 && x!=3 && x!=4 && x!=5 && x!=6)
    {
    cout<<"Opcion Incorrecta\n";
    cin>>x;
    }

}


void comprobar8Op(int &x){

while(x!=1 && x!=2 && x!=3 && x!=4 && x!=5 && x!=6 && x!=7 && x!=8)
    {
    cout<<"Opcion Incorrecta\n";
    cin>>x;
    }

}




