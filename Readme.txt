La carpeta contiene los siguientes archivos:
    ==========================================
    -Readme.txt : Este archivo.
    -Audifonos.txt: Este archivo contiene los datos de los audifonos.
    -Computadora.txt: Este archivo contiene los datos de las computadoras.
    -Impresoras.txt: Este archivo contiene los datos de las impresoras.
    -Software.txt: Este archivo contiene los datos de los softwares.
    -TV.txt: Este archivo contiene los datos de las televisiones.
    -Clientes.txt: Este archivo contiene los datos de los clientes.
    -codigos.txt: Este archivo contiene los datos de los codigos de cada tipo de producto.
    -CodCliente.txt: Este archivo contiene los datos de los codigos de los clientes.

===============================================================================================
Versión =======================================================================================
===============================================================================================

Base de datos==================================================================================

Versión 1.0 29-06-2017
    -Version alfa

Version 1.1 29-06-2017
    -Opcion 5 terminada.

Version 1.2 30-06-2017
    -Retoques

===============================================================================================
Patrones de diseño=============================================================================
===============================================================================================
Singleton:
    ===========================================================================================
    - Genera una sola instancia de una clase 
    - Requiere de una instancia estatica --->  "static Singleton* instance;"
    - Requiere de un constructor privado --->  "private: Singleton();
    - Requiere de una funcion estatica que llame 
      a la instancia "getInstance()"     --->  "static Singleton* getInstance()"

Command:
    ============================================================================================
    - Tiene como objetivo encapsular una petición como un objeto,
      de modo que puedan parametrizarse otros objetos con distintas peticiones o colas de peticiones 
      y proporcionar soporte para realizar operaciones que puedan deshacerse.
    - Requiere de una interfaz comando que sera una ---> " class Command;"
      clase abstracta ---> interfaz que expone el método genérico "execute()".
    - Requiere de un Receiver ---> es el objeto que implementa la funcionalidad real. 
      Alguno de sus métodos será encapsulado por "Command.execute()".
    - Requiere de una clase encargada de invocar el método "Command.execute()". 
      Posee una referencia (o varias) a Command, y su método SetCommand le permite cambiar su funcionalidad en tiempo de ejecución. 
      Ofrecerá también un método que invoque el método "Command.Execute()" que, a su vez, invocará "Receiver.MetodoAEncapsular()".


===============================================================================================
Menu de opciones===============================================================================
===============================================================================================

 Opcion 1:
    =======================
    - Se ingresa los datos del cliente y se llama a la funcion "setData" de la clase cliente.
    - Se ingresa el cliente registrado en una cola para un posterior uso,
      dentro de esta funcion se ingresara a "Clientes.txt" donde se almacenara todos los clientes ingresados.

 Opcion 2:
    =======================
    - Se ingresa los datos del producto y se llama a la funcion "setData" de la clase correspondiente,
      dentro de esta funcion se ingresara a un txt para asi guardar al producto dependiendo de su categoria.

 Opcion 3:
    =======================
    - Se mostrara las categorias y permitira al usuario visualizar los productos de una determinada categoria,
      se llamara a la funcion "getData".

 Opcion 4:
    =======================
    - El usuario ingresara un codigo a buscar y se pasara a mostrar en pantalla todos sus datos,
      estos datos dependen de la categoria, se llamara a la funcion "getProducto" dependiendo de la categoria.

 Opcion 5:
    =======================
    - Permitira la venta de un producto, solicitara el codigo de un cliente(lo verificara mediante la funcion "verifyCode") 
      para tramitar su venta y que pueda salir de la tienda y sacado de la cola, en cuanto al producto pedira cuantos 
      productos desea comprar y pedira por cada producto su codigo y si pedira cuanto desea comprar(si existe el codigo) 
      y consultara a la base de datos para verificar su stock, tramitando asi la compra.

 Nota:
    =======================
    - Los codigos de los clientes y de los productos seran generados automaticamente y no 
      ingresados por el usuario. 

Limitaciones conocidas:
     ======================
     -No se pueden ingresar mas de 9 productos de una sola categoria debido a limitaciones de txt.
     -Debido al uso de txt como base de datos, el ordenamiento pasa a ser muy complejo.
     
================================================================================
Bugs ===========================================================================
================================================================================
     -A encontrar...




