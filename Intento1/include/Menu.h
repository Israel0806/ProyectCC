#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <map>

#include "Clientes.h"
#include "Producto.h"
#include "Audifonos.h"
#include "Impresoras.h"
#include "Software.h"
#include "TV.h"
#include "Computadora.h"

using namespace std;

//Declaracion de funciones
void comprobar2Op(int &x);
void comprobar3Op(int &x);
void comprobar4Op(int &x);
void comprobar5Op(int &x);
void comprobar6Op(int &x);
void comprobar8Op(int &x);
void printMenu();
void printCategorias();
void printComponentes();

//Variables globales
int p0,p1,p2,p3,p4,p5;
int op,cat,lo;
int edad,cantidad;
float precio,capital;
string direccion,tipo,categoria;
char nombre[30],sexo;

//Clase normal
Clientes clientes;
//Clases Singleton
Computadora* computadoras = Computadora::getInstance();
Audifonos *audifonos = Audifonos::getInstance();
Software *software = Software::getInstance();
TV *Tv = TV::getInstance();
Impresoras *impresoras = Impresoras::getInstance();
Queue<Clientes*> Cola;



// Command Interface
class Comando
{
public:
    virtual void execute()=0;
    virtual ~Comando() {}
};

// Receiver Class
class Opcion
{
public:
    void op1()
    {
        cout<<"Se ingreso a la opcion 1\n\n";
        ifstream readOut;
        readOut.open("CodCliente.txt", ios::out );

        ofstream Modify;
        Modify.open("CodCliente.txt", ios::in);
        if (readOut.is_open())
          {
            int a=0;
            string line;
            while ( getline (readOut,line) )
            {
                a+=line.size()+1;
                if(line=="codigos")
                {
                    getline(readOut,line);
                    a+=line.size();
                    p0=atoi(line.c_str());
                    p0++;
                    cout << p0 << '\n';
                    Modify.seekp(a);
                    Modify <<p0;
                    Modify.close();
                    readOut.close();
                    break;
                }
            }
          }
        else
        {
            cout<<"error\n";
        }

        //datos del cliente
        cout<<"\nDatos del cliente "<<p0<<": \n\n";
        cout<<"Ingrese el nombre: "; cin>>nombre;
        cout<<"Ingrese la direccion: "; cin>>direccion;
        cout<<"Ingrese la edad: "; cin>>edad;
        cout<<"Ingrese el sexo: "; cin>>sexo;
        cout<<"Ingrese su capital: "; cin>>capital;
        cout<<endl<<endl;
        string nom=nombre;


        clientes.setData(nom,direccion,edad,sexo,capital,p0);
        Cola.push(clientes);
        cout<<Cola;
    }
    void op2()
    {
        printCategorias(); cin>>cat;
        comprobar5Op(cat);
        switch(cat)
        {
            case 1:
                {
                    char *au=new char[3]; //codigo
                    int *r=new int;

                    string cod,nomb;
                    au[0]='A';

                    string tier1,tier2,conexion;

                    cout<<"\n\nIngrese el Nombre del Producto: ";
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

                    (*r==1)? tier1="Auricular_pasivo":tier1="Auricular_activo";
                    //au++;
                    cout<<"1. Auriculares abiertos"<<endl
                        <<"2. Auriculares cerrados"<<endl<<endl;
                        cin>>*r;
                    comprobar2Op(*r);

                        (*r==1)? tier2="Auriculares_abiertos":tier2="Auriculares_cerrados";
                    //au++;

                    cout<<"1. Conexion wireless"<<endl
                        <<"2. Conexion alambrica"<<endl<<endl;
                        cin>>*r;
                    comprobar2Op(*r);
                        (*r==1)? conexion="Conexion_wireless":conexion="Conexion_alambrica";
                    //au--;



                    ifstream readOut;
                    readOut.open("codigos.txt", ios::out );

                    ofstream Modify;
                    Modify.open("codigos.txt", ios::in);

                    if (readOut.is_open())
                      {
                        int a=0;
                        string line;
                        while ( getline (readOut,line) )
                        {
                            a+=line.size()+1;
                            if(line=="codigo1")
                            {
                                getline(readOut,line);
                                a+=line.size();
                                p1=atoi(line.c_str());
                                p1++;
                                cout << p1 << '\n';
                                Modify.seekp(a);
                                Modify <<p1;
                                Modify.close();
                                break;
                            }
                        }
                      }
                    else
                    {
                        cout<<"error\n";
                    }
                    readOut.close();

                    au[1]='0'+p1;
                    au[2]='\0';
                    cod=au;

                    cout<<"\n\n\ncodigo: "<<cod<<endl<<endl;


                    audifonos->setData(nomb,precio,"Audifonos",cod,cantidad,conexion,tier1,tier2);
                    //productos[(int(productos.size()))]->getData();
                    delete r;
                    delete [] au;
                    break;
                }
            case 2:
                {
                 //Computadoras
                    //char *au= new char [4];
                    char *comp= new char[3]; //codigo
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
                        componente="Fuente"; break;
                    case 2:
                        componente="CPU"; break;
                    case 3:
                        componente="Memoria-RAM"; break;
                    case 4:
                        componente="HDD"; break;
                    case 5:
                        componente="GPU"; break;
                    case 6:
                        componente="MotherBoard"; break;
                    case 7:
                        componente="Case"; break;
                    case 8:
                        componente="Perifericos"; break;
                    }

                    ifstream readOut;
                    readOut.open("codigos.txt", ios::out );

                    ofstream Modify;
                    Modify.open("codigos.txt", ios::in);

                    if (readOut.is_open() and Modify.is_open())
                      {
                        int a=0;
                        string line;
                        while ( getline (readOut,line) )
                        {
                            a+=line.size()+1;
                            if(line=="codigo2")
                            {
                                getline(readOut,line);
                                a+=line.size();
                                p2=atoi(line.c_str());
                                p2++;
                                cout << p2 << '\n';
                                Modify.seekp(a+2);
                                Modify <<p2;
                                Modify.close();
                                break;
                            }
                        }
                        readOut.close();
                      }
                    else
                    {
                        cout<<"error\n";
                    }

                    comp[1]='0'+p2;
                    comp[2]='\0';
                    //comp--;
                    cod=comp;

                    computadoras->setData(nomb,precio,"Computadoras",cod,cantidad,componente);
                    //productos.push_back(&computadoras[p2]);
                   // computadoras[p].getData();
                    delete r;
                    delete [] comp;
                    break;
                }
            case 3:
                {
                    char *imp=new char[3]; //codigo
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

                    (*r==1)? caracteristica="Blanco_y_negro" :caracteristica="A_color";

                    cout<<"\n1.Impresion laser\n"
                        <<"2. Impresion por cartucho"<<endl;
                        cin>>*r;
                    comprobar2Op(*r);

                    (*r==1)? tipo="Impresion_laser":tipo="Impresion_por_cartucho";

                    ifstream readOut;
                    readOut.open("codigos.txt", ios::out );

                    ofstream Modify;
                    Modify.open("codigos.txt", ios::in);

                    if (readOut.is_open() and Modify.is_open())
                      {
                        int a=0;
                        string line;
                        while ( getline (readOut,line) )
                        {
                            a+=line.size()+1;
                            if(line=="codigo3")
                            {
                                getline(readOut,line);
                                a+=line.size()+1;
                                p3=atoi(line.c_str());
                                p3++;
                                cout << p3 << '\n';
                                Modify.seekp(a+2);
                                Modify <<p3;
                                Modify.close();
                                break;
                            }
                        }
                        readOut.close();
                      }
                    else
                    {
                        cout<<"error\n";
                    }

                    imp[1]='0'+p3;
                    imp[2]='\0';

                    //comp--;
                    cod=imp;

                    /*while(caracteristicas[i]!=NULL)
                        carac[i]=caracteristicas[i];*/

                    impresoras->setData(nomb, precio, "Impresoras", cod, cantidad, tipo, caracteristica, tamanho);
                    //computadoras[p3].getData();
                    delete r;
                    delete[] imp;
                    break;
                }
            case 4:
                {
                    //software

                    char *soft=new char[3]; //codigo
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
                                (*r==1)? tier2="Contabilidad_de_empresas" : (*r==2)? tier2="Contabilidad_personal" : tier2="Distribucion_de_sueldos";
                                break;
                        case 4:
                            cout<<"1. Antivirus"<<endl
                                <<"2. Antimalware"<<endl
                                <<"3. Parental control"<<endl;
                                cin>>*r;
                                comprobar3Op(*r);
                                (*r==1)? tier2="Antivirus" : (*r==2)? tier2="Antimalware" : tier2="Parental_control";
                                break;

                    }

                    ifstream readOut;
                    readOut.open("codigos.txt", ios::out );

                    ofstream Modify;
                    Modify.open("codigos.txt", ios::in);

                    if (readOut.is_open())
                      {
                        int a=0;
                        string line;
                        while ( getline (readOut,line) )
                        {
                            a+=line.size()+1;
                            if(line=="codigo4")
                            {
                                getline(readOut,line);
                                a+=line.size();
                                p4=atoi(line.c_str());
                                p4++;
                                cout << p4 << '\n';
                                Modify.seekp(a+6);
                                Modify <<p4;
                                Modify.close();
                                break;
                            }
                        }
                    readOut.close();
                      }
                    else
                    {
                        cout<<"error\n";
                    }


                    soft[1]='0'+p4;
                    soft[2]='\0';

                    cod=soft;

                    software->setData(nomb,precio,"software",cod,cantidad,tier1,tier2);
                    //computadoras[p4].getData();
                    delete r;
                    delete[] soft;
                    break;
                }
            case 5:
                {
                    //television

                    char *tele=new char[3]; //codigo
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
                    (*r==1)? calidad="HD" : (*r==2)? calidad="Ultra_HD" : calidad="Ultra_HD_4K";

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


                    ifstream readOut;
                    readOut.open("codigos.txt", ios::out );

                    ofstream Modify;
                    Modify.open("codigos.txt", ios::in);

                    if (readOut.is_open())
                      {
                        int a=0;
                        string line;
                        while ( getline (readOut,line) )
                        {
                            a+=line.size()+1;
                            if(line=="codigo5")
                            {
                                getline(readOut,line);
                                a+=line.size()+1;
                                p5=atoi(line.c_str());
                                p5++;
                                cout << p5 << '\n';
                                Modify.seekp(a+7);
                                Modify <<p5;
                                Modify.close();
                                break;
                            }
                        }
                      }
                    else
                    {
                        cout<<"error\n";
                    }
                    readOut.close();

                    tele[1]='0'+p5;
                    tele[2]='\0';

                    cod=tele;

                    Tv->setData(nomb,precio,"television",cod,cantidad,calidad,caracteristicas,pantallaTy,tam);
                    //computadoras[p5].getData();
                    delete r;
                    delete[] tele;
                    break;
                }
        }
    }
    void op3()
    {
        //Muestra todos los datos de todos los productos
        printCategorias();
        cin>>lo;
        comprobar5Op(lo);
        cout<<endl;
        switch(lo)
        {
             case 1:
                {
                    audifonos->getData();
                    break;
                }
             case 2:
                {
                    computadoras->getData();
                    break;
                }
             case 3:
                {
                    impresoras->getData();
                    break;
                }
             case 4:
                {
                    software->getData();
                    break;
                }
             case 5:
                {
                    Tv->getData();
                    break;
                }
        }
    }
    void op4()
    {
        cout<<endl;
        char* cod = new char[3];
        cout<<"Ingrese el codigo del producto a buscar: "; cin>>cod;
        cout<<endl;
        string codigo=cod;
        switch(cod[0])
        {
            case 'A': audifonos->getProducto(codigo);    break;
            case 'C': computadoras->getProducto(codigo); break;
            case 'I': impresoras->getProducto(codigo);   break;
            case 'S': software->getProducto(codigo);     break;
            case 'T': Tv->getProducto(codigo);           break;
            default: cout<<"No existe el codigo del producto"<<endl; break;
        }
    }
    void op5()
    {
        int compra;
        vector <int> precios;
        map <int,int> stocks;
        vector <int> compras;
        string codCliente;
        char codProducto[3];
        int num;

        cout<<"Ingrese el Codigo del Cliente: "; cin>>codCliente;
        if( clientes.verifyCode(codCliente))
        {
            cout<<endl<<"Cuantos productos desea adquirir"<<endl; cin>>num;
            for(int i=0;i<num;i++)
            {
                cout<<endl<<"Ingrese el codigo del producto "<<i+1<<": ";
                cin>>codProducto;
                string cod=codProducto;
                switch(codProducto[0])
                {
                    case 'A':
                        {
                        stocks.insert ( pair<int,int>(i,audifonos->getCantidad(codProducto)));
                        cout<<endl
                            <<"Nombre: "<<audifonos->getNombre(cod)<<endl<<endl
                            <<"Ingrese la cantidad a comprar: "; cin>>compra;
                        while(compra>stocks[i])
                        {
                            cout<<"No existe el stock suficiente, ingresa otra cantidad menor o igual a "<<stocks[i] <<":"<<endl;
                            cin>>compra;
                        }
                        precios.push_back( audifonos->getPrecio(codProducto) );
                        compras.push_back(compra);
                        stocks[i]-=compras[i];
                        int stock=stocks[i];
                        audifonos->modifyCantidad(cod,stock);
                        break;
                        }
                    case 'C':
                        {

                        stocks.insert ( pair<int,int>(i,computadoras->getCantidad(codProducto)));
                        cout<<endl
                            <<"Nombre: "<<computadoras->getNombre(cod)<<endl<<endl;
                        cout<<"Ingrese la cantidad a comprar: "; cin>>compra;
                        while(compra>stocks[i])
                        {
                            cout<<"No existe el stock suficiente, ingresa otra cantidad menor o igual a "<<stocks[i] <<":"<<endl;
                            cin>>compra;
                        }
                        precios.push_back( computadoras->getPrecio(codProducto) );
                        compras.push_back(compra);
                        stocks[i]-=compras[i];
                        int stock=stocks[i];
                        computadoras->modifyCantidad(cod,stock);

                        break;
                        }
                    case 'I':
                        {
                        precios.push_back( impresoras->getPrecio(codProducto) );
                        stocks.insert ( pair<int,int>(i,impresoras->getCantidad(codProducto)));
                        cout<<endl
                            <<"Nombre: "<<impresoras->getNombre(cod)<<endl<<endl;
                        cout<<"Ingrese la cantidad a comprar: "; cin>>compra;
                        while(compra>stocks[i])
                        {
                            cout<<"No existe el stock suficiente, ingresa otra cantidad menor o igual a "<<stocks[i] <<":"<<endl;
                            cin>>compra;
                        }
                        compras.push_back(compra);
                        stocks[i]-=compras[i];
                        int stock=stocks[i];
                        impresoras->modifyCantidad(cod,stock);

                        break;
                        }
                    case 'S':
                        {
                        precios.push_back( software->getPrecio(codProducto) );
                        stocks.insert ( pair<int,int>(i,software->getCantidad(codProducto)));
                        cout<<endl
                            <<"Nombre: "<<software->getNombre(cod)<<endl<<endl;
                        cout<<"Ingrese la cantidad a comprar: "; cin>>compra;
                        while(compra>stocks[i])
                        {
                            cout<<"No existe el stock suficiente, ingresa otra cantidad menor o igual a "<<stocks[i] <<":"<<endl;
                            cin>>compra;
                        }
                        compras.push_back(compra);
                        stocks[i]-=compras[i];
                        int stock=stocks[i];
                        software->modifyCantidad(cod,stock);

                        break;
                        }
                    case 'T':
                        {
                        precios.push_back( Tv->getPrecio(codProducto) );
                        stocks.insert ( pair<int,int>(i,Tv->getCantidad(codProducto)));
                        cout<<endl
                            <<"Nombre: "<<Tv->getNombre(cod)<<endl<<endl;
                        cout<<"Ingrese la cantidad a comprar: "; cin>>compra;
                        while(compra>stocks[i])
                        {
                            cout<<"No existe el stock suficiente, ingresa otra cantidad menor o igual a "<<stocks[i] <<":"<<endl;
                            cin>>compra;
                        }
                        compras.push_back(compra);
                        stocks[i]-=compras[i];
                        int stock=stocks[i];
                        Tv->modifyCantidad(cod,stock);

                        break;
                        }
                    default:
                        cout<<"No existe el codigo del producto"<<endl;
                        break;
                }
            }
            float boleta=0;
            for(int i=0;i<num;i++)
                boleta+= stocks[i]*precios[i];
            if( boleta<clientes.getCapital(codCliente) )
            {
                cout<<"clientes.getCapital(codCliente): "<<clientes.getCapital(codCliente)<<endl;
                cout<<"El total a pagar es: $"<<boleta<<endl<<endl;
                cout<<"Gracias por comprar en nuestra tienda, vuelva pronto!"<<endl;
            }
            else
                cout<<"No cuenta con el dinero suficiente para la transaccion"<<endl;
            Cola.pop(codCliente);
        }
        else
        {
            cout<<"Codigo No Existente"<<endl;
        }
    }
};

// Command for entering op1
class Opcion1 : public Comando
{
private:
    Opcion* pOpcion;
public:
    Opcion1(Opcion *opcion) : pOpcion(opcion) {}
    void execute() { pOpcion->op1(); }
    ~Opcion1() {}
};

// Command for entering op2
class Opcion2 : public Comando
{
private:
    Opcion* pOpcion;
public:
    Opcion2(Opcion *opcion) : pOpcion(opcion) {}
    void execute() { pOpcion->op2(); }
    ~Opcion2() {}
};

class Opcion3 : public Comando
{
private:
    Opcion* pOpcion;
public:
    Opcion3(Opcion *opcion) : pOpcion(opcion) {}
    void execute() { pOpcion->op3(); }
    ~Opcion3() {}
};

class Opcion4 : public Comando
{
private:
    Opcion* pOpcion;
public:
    Opcion4(Opcion *opcion) : pOpcion(opcion) {}
    void execute() { pOpcion->op4(); }
    ~Opcion4() {}
};

class Opcion5 : public Comando
{
private:
    Opcion* pOpcion;
public:
    Opcion5(Opcion *opcion) : pOpcion(opcion) {}
    void execute() { pOpcion->op5(); }
    ~Opcion5() {}
};

// Invoker
// Stores the ConcreteCommand object
class Menu
{
private:
    Comando *pCmd;
public:
    void setComando(Comando *Cmd) { pCmd=Cmd; }
    void buttonPressed() { pCmd->execute(); }
    ~Menu() {}
};

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

void printMenu()
{
    system("pause");
    system("cls");
    cout<<"\t\t\t\t\t\t Menu de opciones\n"<<endl     //Ponerle nombre en vez menu de opciones
        <<" 1.Ingresar cliente"  <<endl
        <<" 2.Ingresar producto" <<endl
        <<" 3.Lista de productos"<<endl
        <<" 4.Buscar producto"   <<endl
        <<" 5.Vender producto"   <<endl
        <<" 6.Salir\n"           <<endl
        <<"Ingrese una opcion: ";
}

void printCategorias()
{
    /*system("cls");*/
    cout<<"\n 1. Audifonos "   <<endl
        <<" 2. Computadoras "    <<endl
        <<" 3. Impresoras "      <<endl
        <<" 4. Software "        <<endl
        <<" 5. Television\n "    <<endl
        <<"Ingrese una opcion: ";


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

#endif // MENU_H
