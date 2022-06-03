
/* Proyecto Final
Servicio de Transporte Turismo_Tico S.A
Autor: Minor Marin Obando.
Fecha: 8 de Agosto del 2021.*/

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <string.h>
#include <ctime>
#include <sstream>
#include <iterator>
#include <stdlib.h>

#include <math.h>
//para el tamaño máximo del arreglo char para la conversión de hexadecimal a decimal
#define ARRAY_SIZE  8
//Para manejo de colores
#define blanco 15
#define amarillo 14
#define verdeclaro 10

using namespace std;
//prototipos
bool VerificarArchivo();
void menu_inicio();
void gotoxy(int,int );
void Crear_Archivo();
void Leer_Archivo();
void Opc_Turismo();
void Opc_Persona();
void Opc_Genero();
void Opc_Peticiones();
void fechas();
void conver_hexa_a_decimal(string);
void crear_llenar_archivo();
void completar_marco_reporte();
void marco_menu_analisis();
void menu_analisis();
void accion_realizar_analisis();
void marco();
void marco_segundo_menu();
void menu_turismo();
void menu_tipo_persona();
void menu_genero();
void marco_peticiones();
void menu_peticiones();
void reporte_final();
void conver_string_a_entero_fecha();
void opcion_menu_inicio();
void Crear_Archivo_Temporal();
void t(int );
void gt(int, int, int );
string FECHA_ACTUAL(string&,string&);
bool No_repetir_peticiones(bool[10]);
//Declaracion de variables globales
bool bloqueo_opcion2=false;
long long decimal = 0, base = 1;
bool exit1=false;
string FechaActual;
string fecha_hex;
string fecha;
string dia2;
string mes2;
string anno2;
string T_Turismo="";
string T_Persona="";
string T_Genero="";
string T_Peticiones="";
string a_fecha="";
//int cant_peticiones=0;
int opcion_menu;
int opcion_turismo;
int opcion_tipo_persona;
int opcion_genero;
int opcion_peticiones;
int opcion_menu_analisis;
int dia;
int mes;
int anno;
int total_lineas_reporte=0;
int Fecha_Decimal;
// declaricon arreglos
string tipo_turismo[]= {"vol","pla","mon","avt","rap"};
string tipo_persona[]= {"pen","nin","ado","adu","dis"};
string genero[]= {"fe","ma","otr"};
string peticiones[]= {"sin","wc","aic","sir","asi","rap","veg","sgl","css","tra"};
int main()
{
    /// Permite que el programa interprete bien las tildes y cambia la apariencia y el nombre del archivo en consola.
    //setlocale(LC_ALL,"");
    //system("color B4");
    system(" title Servicio de Transporte Turismo_Tico S.A");

//char salir = 'n';

    while(exit1==false)
    {
        FECHA_ACTUAL(fecha,FechaActual);//función que extrae la hora actual del sistema
        marco();
        menu_inicio();
        opcion_menu_inicio();
        system("cls");

    }
    return 0;
}

///funciones para el manejo de colores de texto
void t(int n)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),n);
}
void gt(int x, int y, int n)
{
    gotoxy(x,y);
    t(n);
}
///    ///   ///    ///     ///    ///     ///


//función que despliega en pantalla el marco de menú de inicio
void marco()
{
/// Rutina suministrada por el Profesor ALEXANDER JESUS ANGELINI MORA en la sesión virtual 3 y adaptada para este programa.
    fflush(stdin);//Sirve para limpiar buffer.
//declaración de variables locales.
    int i=5;
    int j=5;
//Muestra un mensaje de cargando mientras se va creando el cuadro;
    gt(28,23,blanco);
    printf("Cargando, Espere por favor.");
    t(blanco);
    Sleep(5);
//Esta rutina lo que hace es crear el marco que se muestra en consola.
    for (i=10; i<80; i++)
    {
        Sleep(5);
        //escuadra esquina
        gotoxy(10,5);
        printf("%c",218);// los números después de %C son simbolos
        gotoxy(80,5);
        printf("%c",191);
        //líneas verticales
        gotoxy(i,5);
        printf("%c",196);
        gotoxy(i,22);
        printf("%c",196);
        gotoxy(i,13);
        printf("%c",196);

//líneas horizontales
        if (i%2==0)
        {
            if (j<21)
            {
                j++;
                gotoxy(10,j);
                printf("%c",179);
                gotoxy(80,j);
                printf("%c",179);
            }
        }
    }
    gotoxy(10,5);
    printf("%c",218);
    gotoxy(80,5);
    printf("%c",191);

//escuadra esquinas abajo
    gotoxy(80,22);
    printf("%c",217);
    gotoxy(10,22);
    printf("%c",192);

//uniones línea medio
    gotoxy(10,13);
    printf("%c",195);
    gotoxy(80,13);
    printf("%c",180);
    gt(28,23,blanco);
    printf("                           ");
}

//función que despliega en pantalla el menú de inicio;
void menu_inicio()
{
    gotoxy(32,8);
    t(14);
    printf("Programa de An%clisis",160);
    t(15);
    gotoxy(29,10);
    cout<<"Transporte Turismo Tico S.A";
    gotoxy(25,15);
    cout<<"1.";
    gotoxy(29,15);
    cout<<"Ingreso de Datos de Pasajeros";
    gotoxy(25,18);
    cout<<"2.";
    gotoxy(29,18);
    printf("An%clisis administrativo",160);
    //cout<<"análisis administrativo";
    gotoxy(25,21);
    t(10);
    printf("3.");
    gotoxy(29,21);
    t(10);
    printf("Salir");
    t(15);
    cout<<endl;
    cout<<endl;
    gotoxy(13,25);
    printf("Ingrese una opci%cn (1/2)? [ ]  (3 para Salir)",162);
    //cout<<"Ingrese una opci%cn (1/2)? [ ]  (3 para salir)";
}

//Funcion que maneja las acciones a realizar del menú de inicio
void opcion_menu_inicio()
{
    // variables para el manejo del switch
    bool exit_menu_analisis=false;
    char Salir_menu_princ='N';
    bool exit2=false;
    bool Nuevo_Pasajero=false;
    //bool sal=false;
    bool exit_peticiones=false;
    //declaración de variables para manejo de repeticiones de las peticiones del usuario.
    bool repetir[10];
    char otra_peticion;
    char Otro_Pasajero;
    //Para llenar el vector bool con false en cada casilla
    for (int i=0; i<10; i++)
    {
        repetir[i]=false;
    }
    //Solicita al usuario ingresar una opción del menú principal
    gotoxy(40,25);
    cin>>opcion_menu;
    system("cls");//Limpia pantalla













//Para determinar que acción realizar según lo que escogió el usuario
    switch (opcion_menu)
    {
    case 1://Opcion de Ingreso de datos de las Personas.
//automáticamente cuando el usuario entra a la opción de ingreso de datos habilita la opción 1 del menú administrativo.
        bloqueo_opcion2=true;//El cual es el proceso de archivo.


        while (Nuevo_Pasajero==false)
        {
            system("cls");
            marco_segundo_menu();//Despliega el marco del menú de ingreso de datos
            menu_turismo();//Despliega el menú de Turismo.
            menu_tipo_persona();//Despliega el menú de Tipo de Persona
            menu_genero();// Despliega el menú de Tipo Genero.

            gotoxy(16,28);
            cin>>opcion_turismo;//Solicita una opción al usuario con respecto al Tipo de Turismo
            gotoxy(36,28);
            cin>>opcion_tipo_persona;// Solicita una opción al usuario con respecto al Tipo de Persona
            gotoxy(78,28);
            cin>>opcion_genero;// Solicita una opción al usuario con respecto al Tipo de Genero
            system("cls");//Limpio pantalla
            Opc_Turismo();//función que determina la opción de Tipo Turismo que escogió el usuario
            Opc_Persona();//función que determina la opción de Tipo Persona que escogió el usuario
            Opc_Genero();// función que determina la opción de Tipo Genero que escogió el usuario

            marco_peticiones();//Despliega el Marco de Peticiones
            menu_peticiones(); // Despliega el menú de Peticiones

            while (exit_peticiones==false)// Para el Manejo de las peticiones
            {
                gotoxy(30,28);
                cout<<"[ ] Opcion ";
                gotoxy(31,28);
                cin>>opcion_peticiones; // Le solicito al Usuario una opción de las peticiones

                No_repetir_peticiones(repetir);// Llama a la función que determina que el usuario no haya escogido una opción repetida

// Solicita al usuario si desea hacer otra petición
                gotoxy(25,30);
                cout<<"Desea hacer otra peticiones S/N [ ]";
                gotoxy(58,30);
                cin>>otra_peticion;
                otra_peticion=toupper(otra_peticion);//Convierto en mayúscula el carácter que digito el usuario.

                if (otra_peticion=='N')
                {
                    exit_peticiones=true;
                    Crear_Archivo_Temporal();//Llama a la función que crea un archivo temporal donde se van a ir guardando los datos ingresados por el usuario
                    T_Peticiones="";
                }
// Limpia la variable por si el usuario desea ingresar a los datos de otra persona
                gotoxy(25,30);//Estas líneas es para Limpiar los espacios usados en consola con el gotoxy
                cout<<"                                                  ";
                gotoxy(25,28);
                cout<<"                        ";

            }

// Solicita al Usuario si desea ingresar un nuevo pasajero
            gotoxy(25,30);
            cout<<"Desea Ingresar Otro Pasajero S/N [ ]";
            gotoxy(59,30);
            cin>>Otro_Pasajero;

            Otro_Pasajero=toupper(Otro_Pasajero); // convierte la opción ingresada en mayúscula

            if (Otro_Pasajero=='N')// si se cumple esta condición habilita que se finalice el while de las repeticiones de las peticiones
                Nuevo_Pasajero=true;
            if (Otro_Pasajero=='S') // si desea ingresar otro usuario se bloquea el while que muestra los menús y marcos para que los vuelva a mostrar
            {
                exit_peticiones=false;
//Para llenar el vector bool con false en cada casilla dado a que se va a ingresar otro pasajero
                for (int i=0; i<10; i++)
                {
                    repetir[i]=false;
                }
            }

        }
//Limpia espacios usados en pantalla por gotoxy
        gotoxy(0,28);
        cout<<"                                                          ";
        gotoxy(25,30);
        cout<<"                                       ";

//Desplegar un mensaje que le recuerda al usuario que debe procesar el archivo primero para generar el reporte actualizado
        gotoxy(40,28);
        cout<<"RECUERDE!!";
        gotoxy(10,29);
        printf("Debe ir al men%c administrativo y procesar el Archivo Opci%cn[1]",163,162);
        gotoxy(10,30);
        cout<<"Para que se guarden los datos en el registro.";
        gotoxy(25,32);
        system("pause");
        gotoxy(25,30);
        cout<<"                                       ";
        gotoxy(31,28);
        cout<<" ";
        break; // sale del caso 1

    case 2:

        system("cls"); // limpia pantalla
        marco_menu_analisis();//Llama a la función que despliega el marco del menú de análisis
        menu_analisis();// Llama a la función que despliega el menú de análisis administrativo

        while (exit_menu_analisis==false)// while que maneja la repetición de las opciones ingresadas
        {
            gotoxy (36,21);
            cin>>opcion_menu_analisis;// solicita una opción al usuario

            switch (opcion_menu_analisis)// para determinar que acción realizar
            {
            case 1://Procesamiento de archivo
                if (bloqueo_opcion2==true) // si esta condición se cumple
                {
                    crear_llenar_archivo();//Llama a la función que crea y llena el archivo del registro de datos ingresados

                }
                else//el usuario debe ingresar primero datos si desea entrar a la opción 1 (procesamiento de archivo)
                {
                    gotoxy(32,25); //Despliega mensaje
                    cout<<" Debe Ingresar datos primero"<<endl;
                    gotoxy (36,21);
                    cout<<" ";
                    gotoxy(32,26);
                    system("pause");
                    gotoxy(32,25);
                    cout<<"                                              ";
                    gotoxy(32,26);
                    cout<<"                                              } ";
                }
                break;
            case 2://reporte final de los datos guardados
                system("cls");
                reporte_final();//Llama a la función que Despliega el marco del reporte final

                if (VerificarArchivo()==true){//Verifica si hay un archivo para generar el reporte
                    Leer_Archivo();// Llama a la función que en pantalla el reporte final
                    gotoxy(30,total_lineas_reporte+28);//Muestra que el reporte fue finalizado
                    cout<<"REPORTE FINALIZADO";
                } else{
                    gotoxy(30,total_lineas_reporte+25);
                    cout<<("No hay Registros");

                }



                //Estructura que maneja si el usuario desea volver al menú principal
                while (Salir_menu_princ!='S')
                {
                    gotoxy(30,total_lineas_reporte+30);
                    printf("Desea volver al Men%c Principal? Presione ""S"" [ ]",163);
                    gotoxy(74,total_lineas_reporte+30);
                    cin>>Salir_menu_princ;
                    Salir_menu_princ=toupper(Salir_menu_princ);
                    if (Salir_menu_princ=='S')
                    {
                        exit_menu_analisis=true;
                    } else {
                        gotoxy(30,total_lineas_reporte+30);
                        cout<<("Debe ingresar unicamente [S]                 ");
                        gotoxy(30,total_lineas_reporte+31);
                        system("pause");
                    }
                    gotoxy(30,total_lineas_reporte+30);
                    cout<<"                                                    ";
                    gotoxy(67,total_lineas_reporte+31);
                    cout<<"                                                    ";
                }
                break;

            case 3:
                //Estructura que sale de la aplicación
                exit_menu_analisis=true;
                break;
            }
            gotoxy (36,21);
            cout<<" ";
        }
        break;

    case 3:
        exit1=true;
        system("cls");
        cout<<"salir";
        break;
    }

}

//función que crea un archivo temporal para ir guardado los datos ingresados de los pasajeros
void Crear_Archivo_Temporal()
{
    ofstream Archivo; // crea el archivo
    Archivo.open("Archivo.txt",ios::out |ios::app); // abre el archivo, y si ya hay algo guardado en él trabaja sobre la siguiente línea

//Estructura de control de excepciones por si el archivo no se abre desplegar el mensaje de error
    try
    {
        if (Archivo.fail())
        {
            throw "No encontró el archivo";
            exit(1);
        }
    }
    catch (const char* dato)
    {
        cout << dato << endl;
        exit(1);
    }
//Guarda en el archivo los datos ingresados
    Archivo<<T_Turismo<< "&"<<T_Persona<<"&"<<T_Genero<<"&"<<hex<<dia<<"&"<<hex<<mes<<"&"<<hex<<anno<<"&"<<T_Peticiones<<"\n";
    Archivo.close(); // cierra el archivo

}

//función que despliega el marco del menú de análisis administrativo
/// Rutina suministrada por el Profesor ALEXANDER JESUS ANGELINI MORA en la sesión virtual 3 y adaptada para este programa.
void marco_menu_analisis()
{
    //declaración de variables globales
    int i=5;
    int j=5;
    gt(28,23,blanco);
    printf("Cargando, Espere por favor.");
    t(blanco);
    Sleep(5);
// los números después de %C son símbolos del Código ASCII
    for (i=10; i<80; i++)
    {
        Sleep(5);
//Escuadra esquinas
        gotoxy(10,5);
        printf("%c",218);
        gotoxy(80,5);
        printf("%c",191);
//líneas Horizontales
        gotoxy(i,5);
        printf("%c",196);
        gotoxy(i,22);
        printf("%c",196);
        gotoxy(i,13);
        printf("%c",196);

//líneas Verticales
        if (i%2==0)
        {
            if (j<21)
            {
                j++;
                gotoxy(10,j);
                printf("%c",179);
                gotoxy(80,j);
                printf("%c",179);
            }
        }
    }
    gotoxy(10,5);
    printf("%c",218);
    gotoxy(80,5);
    printf("%c",191);

//Escuadra Esquinas Abajo
    gotoxy(80,22);
    printf("%c",217);
    gotoxy(10,22);
    printf("%c",192);

//Uniones líneas del medio
    gotoxy(10,13);
    printf("%c",195);
    gotoxy(80,13);
    printf("%c",180);
    gt(28,23,blanco);
    printf("                           ");
}

//función que despliega el menú del menú de análisis administrativo
void menu_analisis()
{
    cout<<(" ");
    gotoxy(32,8);
    t(14);
    printf("Programa de An%clisis",160);
    t(15);
    gotoxy(29,10);
    cout<<"Transporte Turismo Tico S.A";
    gotoxy(32,15);
    cout<<" 1. Procesar Archivo";
    gotoxy(32,17);
    cout<<" 2. Reporte del Archivo";
    gotoxy(32,19);
    cout<<" 3. Salir";
    gotoxy (35,21);
    printf("[ ] Opci%cn",162);

}

//función que controla las repeticiones de las peticiones del usuario
bool No_repetir_peticiones(bool repetir[10])
{

    switch(opcion_peticiones)
    {
    case 1:
        if (repetir[0]==false) // si esta condición se habilita significa que no ha ingresado esta opción previamente
        {
            Opc_Peticiones();//Llama a la función que determina la opción escogida por el usuario
            repetir[0]=true;
        }// y bloque esta opción para que no la puedan volver escoger hasta que se vuelva a ingresar un nuevo pasajero
        else   // sino se cumple el error despliega en pantalla el mensaje de error y limpia algunas áreas en pantalla usadas por la función gotoxy
        {
            gotoxy(25,30);
            cout<<"No puede ingresar la misma petición más de una vez"<<endl;
            gotoxy(25,31);
            system("pause");// le indica al usuario que debe presionar cualquier tecla para continuar
            gotoxy(25,30);
            cout<<"                                                          ";
            gotoxy(25,31);
            cout<<"                                                          ";
        }
        break;
    // Toda esta estructura se repite para los siguientes casos de witch, únicamente cambia el caso dependiendo de la opción que digito el usuario

    case 2:
        if (repetir[1]==false)
        {
            Opc_Peticiones();
            repetir[1]=true;
        }
        else
        {
            gotoxy(25,30);
            cout<<"No puede ingresar la misma petición más de una vez"<<endl;
            gotoxy(25,31);
            system("pause");
            gotoxy(25,30);
            cout<<"                                                          ";
            gotoxy(25,31);
            cout<<"                                                          ";
        }
        break;
    case 3:
        if (repetir[2]==false)
        {
            Opc_Peticiones();
            repetir[2]=true;
        }
        else
        {
            gotoxy(25,30);
            cout<<"No puede ingresar la misma petición más de una vez"<<endl;
            gotoxy(25,31);
            system("pause");
            gotoxy(25,30);
            cout<<"                                                          ";
            gotoxy(25,31);
            cout<<"                                                          ";
        }
        break;
    case 4:
        if (repetir[3]==false)
        {
            Opc_Peticiones();
            repetir[3]=true;
        }
        else
        {
            gotoxy(25,30);
            cout<<"No puede ingresar la misma petición más de una vez"<<endl;
            gotoxy(25,31);
            system("pause");
            gotoxy(25,30);
            cout<<"                                                          ";
            gotoxy(25,31);
            cout<<"                                                          ";
        }
        break;
    case 5:
        if (repetir[4]==false)
        {
            Opc_Peticiones();
            repetir[4]=true;
        }
        else
        {
            gotoxy(25,30);
            cout<<"No puede ingresar la misma petición más de una vez"<<endl;
            gotoxy(25,31);
            system("pause");
            gotoxy(25,30);
            cout<<"                                                          ";
            gotoxy(25,31);
            cout<<"                                                          ";
        }
        break;
    case 6:
        if (repetir[5]==false)
        {
            Opc_Peticiones();
            repetir[5]=true;
        }
        else
        {
            gotoxy(25,30);
            cout<<"No puede ingresar la misma petición más de una vez"<<endl;
            gotoxy(25,31);
            system("pause");
            gotoxy(25,30);
            cout<<"                                                          ";
            gotoxy(25,31);
            cout<<"                                                          ";
        }
        break;
    case 7:
        if (repetir[6]==false)
        {
            Opc_Peticiones();
            repetir[6]=true;
        }
        else
        {
            gotoxy(25,30);
            cout<<"No puede ingresar la misma petición más de una vez"<<endl;
            gotoxy(25,31);
            system("pause");
            gotoxy(25,30);
            cout<<"                                                          ";
            gotoxy(25,31);
            cout<<"                                                          ";
        }
        break;
    case 8:
        if (repetir[7]==false)
        {
            Opc_Peticiones();
            repetir[7]=true;
        }
        else
        {
            gotoxy(25,30);
            cout<<"No puede ingresar la misma petición más de una vez"<<endl;
            gotoxy(25,31);
            system("pause");
            gotoxy(25,30);
            cout<<"                                                          ";
            gotoxy(25,31);
            cout<<"                                                          ";
        }
        break;;
    case 9:
        if (repetir[8]==false)
        {
            Opc_Peticiones();
            repetir[8]=true;
        }
        else
        {
            gotoxy(25,30);
            cout<<"No puede ingresar la misma petición más de una vez"<<endl;
            gotoxy(25,31);
            system("pause");
            gotoxy(25,30);
            cout<<"                                                          ";
            gotoxy(25,31);
            cout<<"                                                          ";
        }
        break;
    case 10:
        if (repetir[9]==false)
        {
            Opc_Peticiones();
            repetir[9]=true;
        }
        else
        {
            gotoxy(25,30);
            cout<<"No puede ingresar la misma petición más de una vez"<<endl;
            gotoxy(25,31);
            system("pause");
            gotoxy(25,30);
            cout<<"                                                          ";
            gotoxy(25,31);
            cout<<"                                                          ";
        }
        break;
    }
    return repetir;// retorna los valores guardados en el vector de repetir
}

// Funcion que permite mostrar en pantalla el texto en una ubicación especifica
/// Rutina suministrada por el Profesor ALEXANDER JESUS ANGELINI MORA en la sesión virtual 1
void gotoxy(int x,int y)///que trabaja con punteros inteligentes
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

// Funcion que muestra en pantalla el marco de ingreso de datos de pasajeros
/// Rutina suministrada por el Profesor ALEXANDER JESUS ANGELINI MORA en la sesión virtual 3 y adaptada para este programa.
void marco_segundo_menu()
{
    fflush(stdin);
    int i=5;
    int w=14;
    int j=5;
    gt(28,33,blanco);
    printf("Cargando, Espere por favor.");

    t(blanco);
    Sleep(5);
// los numeros despues de %C son simbolos en codigo ASCII
    for (i=10; i<90; i++)
    {
        Sleep(5);
//escuadras esquinas
        gotoxy(10,5);
        printf("%c",218);
        gotoxy(90,5);
        printf("%c",191);

//uniones arriba
        gotoxy(30,14);
        printf("%c",194);
        gotoxy(73,14);
        printf("%c",194);

//Lineas horizontales
        gotoxy(i,5);
        printf("%c",196);
        gotoxy(i,30);
        printf("%c",196);

        gotoxy(i,14);
        printf("%c",196);

//Lineas verticales
        if (i%2==0)
        {
            if (j<30)
            {
                j++;


                gotoxy(10,j);
                printf("%c",179);
                gotoxy(90,j);
                printf("%c",179);
            }

        }
        if (i%2==0)
        {
            if(w<30)
            {
                w++;
                //Las lineas del medio
                gotoxy(30,w);
                printf("%c",179);
                gotoxy(73,w);
                printf("%c",179);
            }
        }
    }
    gotoxy(10,5);
    printf("%c",218);
    gotoxy(90,5);
    printf("%c",191);

//Escuadra Esquinas Abajo
    gotoxy(90,30);
    printf("%c",217);
    gotoxy(10,30);
    printf("%c",192);


//Uniones lineas medio abajo
    gotoxy(30,30);
    printf("%c",193);
    gotoxy(73,30);
    printf("%c",193);

//uniones linea medio horizontal
    gotoxy(10,14);
    printf("%c",195);
    gotoxy(90,14);
    printf("%c",180);
    gt(28,35,blanco);
    printf("                           ");

//Desplega en pantalla el emcabezado del cuadro
    gotoxy(40,7);
    t(14);
    printf("Programa de An%clisis",160);
    t(15);
    gotoxy(37,9);
    cout<<"Transporte Turismo Tico S.A";
    gotoxy(36,11);
    cout<<"Ingreso de Datos de Pasajeros";
    gotoxy(39,13);
    cout<<"Fecha Actual "<<FechaActual;;
//gotoxy(52,13);
    FechaActual;
    gotoxy(28,33);
    cout<<"                                             ";
}


// Funcion que Desplega en pantalla el menu de turismo
void menu_turismo()
{
    gotoxy(15,15);
    t(10);
    printf("Tipo Turismo");
    t(15);
    gotoxy(15,17);
    cout<<"1. Volcanes";
    gotoxy(15,19);
    cout<<"2. Playa";
    gotoxy(15,21);
    cout<< "3. Montana";
    gotoxy(15,23);
    cout<<"4. Aventura";
    gotoxy(15,25);
    cout<<"5. Rapidos";
    gotoxy(15,28);
    t(10);
    printf("[ ] opci%cn",162);
    t(15);

}


//Funcion que desplega en pantalla el menu de tipo de persona.
void menu_tipo_persona()
{
    gotoxy(35,15);
    t(10);
    printf("Tipo Persona");
    t(15);
    gotoxy(35,17);
    printf("1. Pensionado (65 a%cos en adelante)",164);
    gotoxy(35,19);
    printf("2. Ni%co (a) (0-11 a%cos)",164,164);
    gotoxy(35,21);
    printf("3. Adolecente (12-17 a%cos)",164);
    gotoxy(35,23);
    printf("4. Adulto (18 a%cos en adelante.. ",164);
    gotoxy(35,24);
    printf("Antes de los 65 a%cos)",164);
    gotoxy(35,26);
    cout<<"5. Discapacitado";
    gotoxy(35,28);
    t(10);
    printf("[ ] Opci%cn",162);
    t(15);
}

//Despliega en pantalla el menú de tipo de genero
void menu_genero()
{
    gotoxy(77,15);
    t(3);
    printf("Genero");
    t(15);
    gotoxy(77,18);
    cout<<"1. Femenino";
    gotoxy(77,21);
    cout<<"2. Masculino";
    gotoxy(77,24);
    cout<<"3. Otro";
    gotoxy(77,28);
    t(10);
    printf("[ ] Opci%cn",162);
    t(15);
}

//Funcion que determina el Tipo de turismo
void Opc_Turismo()
{
    for (int i=0; i<5; i++)
    {
        if (opcion_turismo==i+1)
        {
            T_Turismo=tipo_turismo[i];
            break;
        }
    }
}
//función que determina el Tipo de persona
void Opc_Persona()
{
    for (int i=0; i<5; i++)
    {
        if (opcion_tipo_persona==i+1)
        {
            T_Persona=tipo_persona[i];
            break;
        }
    }
}

// función que determina el genero
void Opc_Genero ()
{
    for (int i =0; i<3; i++)
    {
        if (opcion_genero==i+1)
        {
            T_Genero=genero[i];
            break;
        }
    }
}

//función que despliega en pantalla el marco de peticiones
/// Rutina suministrada por el Profesor ALEXANDER JESUS ANGELINI MORA en la sesión virtual 3 y adaptada para este programa.
void marco_peticiones()
{
    fflush(stdin);
    int i=5;
    int j=5;

    gt(30,28,blanco);
    printf("Cargando, Espere por favor.");

    t(blanco);
    Sleep(5);
// los números después de %C son símbolos ASCII
    for (i=10; i<85; i++)
    {
        Sleep(5);
        //escuadra esquina
        gotoxy(10,5);
        printf("%c",218);
        gotoxy(85,5);
        printf("%c",191);


        //líneas Horizontales
        gotoxy(i,5);
        printf("%c",196);
        gotoxy(i,26);
        printf("%c",196);

        gotoxy(i,14);
        printf("%c",196);

//líneas Verticales
        if (i%2==0)
        {
            if (j<25)
            {
                j++;
                gotoxy(10,j);
                printf("%c",179);
                gotoxy(85,j);
                printf("%c",179);
            }
        }
    }
    gotoxy(10,5);
    printf("%c",218);
    gotoxy(85,5);
    printf("%c",191);

//escuadraS esquinas abajo
    gotoxy(85,26);
    printf("%c",217);
    gotoxy(10,26);
    printf("%c",192);

//uniones linea medio
    gotoxy(10,14);
    printf("%c",195);
    gotoxy(85,14);
    printf("%c",180);
    gt(30,28,blanco);
    printf("                           ");

//Muestra en pantalla el encabezado
    gotoxy(35,7);
    t(14);
    printf("Programa de An%clisis",160);
    t(15);
    gotoxy(32,9);
    cout<<"Transporte Turismo Tico S.A";
    gotoxy(31,11);
    cout<<"Ingreso de Datos de Pasajeros";
    gotoxy(34,13);
    cout<<"Fecha Actual "<<FechaActual;
}

//Despliega en pantalla el menú de peticiones
void menu_peticiones()
{
    gotoxy(12,15);
    printf("1. Silla para ni%co (a)",164);
    gotoxy(12,17);
    cout<<"2. Servicio sanitario";
    gotoxy(12,19);
    cout<<"3. Aire Acondicionado";
    gotoxy(12,21);
    cout<< "4. Espacio para silla de ruedas";
    gotoxy(12,23);
    cout<<"5. Asistencia para subir y bajar";
    gotoxy(12,24);
    printf("del autob%cs",163);
    gotoxy(58,15);
    printf("6. Rampa en el autob%cs",163);
    gotoxy(58,17);
    cout<< "7. Vegano";
    gotoxy(58,19);
    cout<< "8. Comida sin gluten";
    gotoxy(58,21);
    cout<< "9. Comida sin semillas";
    gotoxy(58,23);
    cout<< "10. Traductor";
}

//función que determina las peticiones ingresadas
void Opc_Peticiones ()
{
    for (int i=0; i<10; i++)
    {
        if (opcion_peticiones==i+1)
        {
            T_Peticiones=T_Peticiones+peticiones[i]+"&";
            break;
        }
    }
}

//función que despliega el marco del reporte final
/// Rutina suministrada por el Profesor ALEXANDER JESUS ANGELINI MORA en la sesión virtual 3 y adaptada para este programa.
void reporte_final()
{
    int i=1;
    int j=5;

    gt(28,23,blanco);
    printf("Cargando, Espere por favor.");

    t(blanco);
    Sleep(5);
// los números después de %C son símbolos
    for (i=1; i<110; i++)
    {
        Sleep(5);
        //escuadra esquina
        gotoxy(1,5);
        printf("%c",218);
        gotoxy(110,5);
        printf("%c",191);


        //líneas horizontales
        gotoxy(i,5);
        printf("%c",196);
        //gotoxy(i,y+1); printf("%c",196);

        gotoxy(i,14);
        printf("%c",196);

//líneas verticales
        if (i%2==0)
        {
            if (j<13)
            {
                j++;
                gotoxy(1,j);
                printf("%c",179);
                gotoxy(110,j);
                printf("%c",179);
            }
        }

    }

//uniones línea medio
    gotoxy(1,14);
    printf("%c",195);
    gotoxy(110,14);
    printf("%c",180);
    gt(28,23,blanco);
    printf("                           ");

//Despliega el encabezado en pantalla
    gotoxy(35,7);
    t(14);
    printf("Programa de An%clisis",160);
    t(15);
    gotoxy(32,9);
    cout<<"Transporte Turismo Tico S.A";
    gotoxy(31,11);
    cout<<"Ingreso de Datos de Pasajeros";
    gotoxy(34,13);
    cout<<"Fecha Actual "<<FechaActual;

}

//función que extrae la hora actual del sistema y la retorna en forma de string para su archivada
string FECHA_ACTUAL(string&fecha,string&FechaActual)
{
    string sep="/";
    time_t t= time(0);
    tm* now = localtime(&t);
    dia=now->tm_mday;
    mes=(now->tm_mon+1);
    anno=(now->tm_year + 1900);
    fecha=to_string(dia)+to_string(mes)+to_string(anno);
    FechaActual=to_string(dia)+sep+to_string(mes)+sep+to_string(anno);
    return fecha,FechaActual;
}



//función que convertir de hexadecimal a decimal
void conver_hexa_a_decimal(string fecha_hex)
{
    //Inicializo las variables globales decimal y base
    decimal=0;
    base=1;
    //declaración de arreglo de tipo char
    char hexa[ARRAY_SIZE];
    //Toma la fecha que retorne en la función anterior y la copia en el vector hexa
    strcpy(hexa,fecha_hex.c_str());
//declaración de variables locales
    int i = 0, value, length;
    fflush(stdin);// limpio el buffer
    //determina la longitud de hexa
    length = strlen(hexa);
    for(i = length--; i >= 0; i--)
    {
        if(hexa[i] >= '0' && hexa[i] <= '9')  //Si el carácter esta entre 0 y 9
        {



            decimal = decimal+ (hexa[i] - 48) * base; //Toma su valor ASCII y le resta 48, posteriormente, lo multiplica por la base
            base *= 16; // base se multiplica por 16

        }
        else if(hexa[i] >= 'A' && hexa[i] <= 'F')//Si el carácter esta entre A y F
        {
            decimal += (hexa[i] - 55) * base;//Toma su valor ASCII y le resta 55, posteriormente, lo multiplica por la base
            base *= 16;// base se multiplica por 16

        }
        else if(hexa[i] >= 'a' && hexa[i] <= 'f') //Si el carácter esta entre a y f
        {
            decimal += (hexa[i] - 87) * base;//Toma su valor ASCII y le resta 87, posteriormente, lo multiplica por la base
            base *= 16;// base se multiplica por 16
        }

    }
}

//
//función que va copia la información del archivo temporal y la guarda en el archivo de registro
void crear_llenar_archivo()
{
////////////////////////////////////////////////////////////////////////////////
    ofstream Registro; // crea el archivo de registro
    ifstream lectura_archivo; // para abrir el archivo en modo lectura
    string texto;
    lectura_archivo.open("Archivo.txt",ios::in); //abre el archivo temporal para su lectura
    Registro.open("Registro.txt",ios::out |ios::app);// abre el archivo de registro y si hay algo guardado trabaja sobre la siguiente linea

//estructura para el manejo de excepciones
    try
    {
        if (lectura_archivo.fail()||Registro.fail())
        {
            throw "No encontró el archivo";
            exit(1);
        }
    }
    catch (const char* dato)
    {
        cout << dato << endl;
        exit(1);
    }
    //si los archivos se abren correctamente desplegar el siguiente mensaje
    gotoxy(32,24);
    cout << "ABRIENDO ARCHIVO......" ;
    Sleep(1000);

//estructura que extrae la información del archivo temporal y la guarda en el archivo de registro
    while (!lectura_archivo.eof())
    {
        getline(lectura_archivo,texto);// extrae la información del archivo temporal
        Registro<<texto<<"\n";// la guarda en el registro
    }
    // se cierran ambos archivos
    lectura_archivo.close();
    Registro.close();






//despliega el mensaje de que fue procesado exitosamente

    gotoxy(29,26);
    cout<<"ARCHIVO PROCESADO EXITOSAMENTE";
    remove("Archivo.txt");// se borra el archivo temporal


}

bool VerificarArchivo(){

ifstream lectura;//para abrir el archivo de registro
    lectura.open("Registro.txt",ios::in);//abre el archivo en modo lectura
//estructura para el manejo de excepciones
    try
    {
        if (lectura.fail())
        {
            lectura.close();
            return false;
            //throw "No se encontró el archivo";

        }else{
            lectura.close();
            return true;

        }
    }
    catch (const char* dato)
    {
        cout<<dato<<endl;
        exit(1);
    }
}


//función que lee el archivo de registro para interpretar sus datos y generar el reporte final
/// Rutina suministrada por el Profesor ALEXANDER JESUS ANGELINI MORA en la sesión virtual 3 y adaptada para este programa.
void Leer_Archivo()
{

    ifstream lectura;//para abrir el archivo de registro
//declaración de variables locales
    string tipoturismo;
    string tipopersona;
    string vgenero;
    string vpeticiones="";
    string vfecha;
    string texto;
    string datos[16];
    string a_fecha;
    string fecha_hex;
    string sep="/";

    int contador=0;
    int posicion=0;
    int x=4;
    int y=16;
    int yy=0;

    lectura.open("Registro.txt",ios::in);//abre el archivo en modo lectura
//estructura para el manejo de excepciones
    try
    {
        if (lectura.fail())
        {
            throw "No se encontró el archivo";
            exit(1);
        }
    }
    catch (const char* dato)
    {
        cout<<dato<<endl;
        exit(1);
    }

    fflush(stdin);//libera el buffer

    while (!lectura.eof()) // se comprueba que existe y tiene datos, entonces se realiza lo siguiente
    {

        getline(lectura,texto);// Se captura el primer dato
        posicion=texto.find("&");// Se busca el primer &
        y++;
        total_lineas_reporte++;
        while ((posicion=texto.find("&"))!=string::npos) // Mientras no sea el fin de la cadena, entonces...
        {

            datos[contador]=texto.find("&");//Se mueve por el vector buscando &
            datos[contador]=texto.substr(0,posicion); // Devuelve caracteres del valor cadena que comienzan desde la posición de caracteres especificada por inicio. El número de caracteres devuelto se especifica en longitud.

            texto.erase(0,posicion+1);// La función devuelve un iterador después del último elemento eliminado.El método erase() se usa para eliminar un elemento de un vector.
            if (contador<6) //si se cumple esta condición se hacen lo siguiente
            {
                if (contador==0) //interpreta el primer dato
                {
                    if (datos[contador]=="vol")
                        tipoturismo="volcan ";
                    if (datos[contador]=="pla")
                        tipoturismo="Playa ";
                    if (datos[contador]=="mon")
                        tipoturismo="Montana ";
                    if (datos[contador]=="avt")
                        tipoturismo="Aventura ";
                    if (datos[contador]=="rap")
                        tipoturismo="Rapidos ";
                    gotoxy(x,y);
                    cout<<tipoturismo;// se muestra en pantalla en una posición especifica
                    x=x+14;
                }

                if (contador==1) //interpreta el segundo dato
                {
                    if (datos[contador]=="pen")
                        tipopersona="Pensionado ";
                    if (datos[contador]=="nin")
                        tipopersona="Nino ";
                    if (datos[contador]=="ado")
                        tipopersona="Adolecente ";
                    if (datos[contador]=="adu")
                        tipopersona="Adulto ";
                    if (datos[contador]=="dis")
                        tipopersona="Discapacitado ";
                    gotoxy(x,y);
                    cout<<tipopersona;
                    x=x+20;
                }

                if (contador==2) //interpreta el tercer dato
                {
                    if (datos[contador]=="fe")
                        vgenero="Femenino ";
                    if (datos[contador]=="ma")
                        vgenero="Masculino ";
                    if (datos[contador]=="otr")
                        vgenero="Otro ";
                    gotoxy(x,y);
                    cout<<vgenero;// se muestra en pantalla en una posición especifica
                    x=x+15;
                }


                if (contador==3) //interpreta el cuarto dato
                {
                    dia2=datos[3];// guardo la fecha en la variable tipo string
                    fecha_hex=dia2;// guardo la fecha en la variable tipo string
                    conver_hexa_a_decimal(fecha_hex);//llamo a la función que me convertir de hexadecimal a decimal
                    a_fecha+=to_string(decimal);//guardo la fecha convertida
                    a_fecha=a_fecha+sep;//guardo la fecha convertida más un separado / para posteriormente mostrarla
                }

                if (contador==4) //interpreta el quinto dato
                {
                    mes2=datos[4];// guardo la fecha en la variable tipo string
                    fecha_hex=mes2;// guardo la fecha en la variable tipo string
                    conver_hexa_a_decimal(fecha_hex);//llamo a la función que me converte de hexadecimal a decimal
                    a_fecha+=to_string(decimal);//guardo la fecha convertida
                    a_fecha=a_fecha+sep;//guardo la fecha convertida más un separado / para posteriormente mostrarla
                }

                if (contador==5) //interpreta el sexto dato
                {
                    anno2=datos[5];// guardo la fecha en la variable tipo string
                    fecha_hex=anno2;// guardo la fecha en la variable tipo string
                    conver_hexa_a_decimal(fecha_hex);//llamo a la función que me convierte de hexadecimal a decimal
                    a_fecha+=to_string(decimal);//guardo la fecha convertida para posteriormente mostrarla
                    gotoxy(x,y);
                    cout<<a_fecha;// se muestra en pantalla en una posición especifica
                    x=x+14;
                    yy=y;
                }
            }//fin if grande

            if (contador==7) //si hay más de una petición se cumple esto, lo cual me permite ir mostrando las peticiones en pantalla, pero hacia abajo
            {
                yy=y+1;
            }
            if (contador>6) //increnta la variable si hay más de unas peticiones
            {
                total_lineas_reporte++;// variable que me permite saber un promedio de cuantas líneas interprete para cerrar el marco del reporte final
            }

            if (contador>=6) //interpreta las peticiones
            {
                if (datos[contador]=="aic")
                    vpeticiones=" Aire Acondic ";
                if (datos[contador]=="sin")
                    vpeticiones=" Silla Ninos";
                if (datos[contador]=="wc")
                    vpeticiones=" Servicio sanitario";
                if (datos[contador]=="sir")
                    vpeticiones=" Espacio para silla de ruedas ";
                if (datos[contador]=="asi")
                    vpeticiones=" Asistencia: subir y bajar del autobús ";
                if (datos[contador]=="rap")
                    vpeticiones=" rampa en el autobús ";
                if (datos[contador]=="veg")
                    vpeticiones=" Vegano";
                if (datos[contador]=="sgl")
                    vpeticiones=" Comida sin gluten ";
                if (datos[contador]=="css")
                    vpeticiones=" comida sin semillas ";
                if (datos[contador]=="tra")
                    vpeticiones=" Traductor";
                gotoxy(x,yy);
                cout<<vpeticiones;// se muestra en pantalla en una posición especifica
                yy++;
            }

            contador++;//contador para ir moviendo el dato por dato
        }
//inicialización de variables para la próxima línea a interpretar
        y=yy;
        x=4;
        contador=0;

        tipoturismo="";
        tipopersona="";
        vgenero="";
        a_fecha="";
        vpeticiones="";
        vpeticiones="";
        dia2="";
        mes2="";
        anno2="";


    } ///fin primer while
    lectura.close();//cierra el archivo

// Muestra las categorías en el reporte final
    gotoxy(2,15);
    cout<<"Tipo turismo";
    gotoxy(18,15);
    cout<<"Tipo persona";
    gotoxy(38,15);
    cout<<"Genero";

    gotoxy(53,15);
    cout<<"Fecha";
    gotoxy(68,15);
    cout <<"Peticiones";

    cout<<endl;
    completar_marco_reporte();//función que me permite cerrar el marco de reporte final




}///

//función que completa el marco de reporte final dependiendo de la cantidad de líneas a interpretar
/// Rutina suministrada por el Profesor ALEXANDER JESUS ANGELINI MORA en la sesión virtual 3 y adaptada para este programa.
void completar_marco_reporte()
{

    int i=1;
    int y=total_lineas_reporte+26;// le asigno el valor aproximado de las líneas que se interpretaron anteriormente
    int j=15;


// los números después de %C son símbolos
    for (i=1; i<110; i++)
    {
        Sleep(5);
        gotoxy(i,y);
        printf("%c",196);

//líneas verticales
        if (i%2==0)
        {
            if (j<y)
            {

                gotoxy(1,j);
                printf("%c",179);
                gotoxy(110,j);
                printf("%c",179);
                j++;
            }
        }

    }


//escuadra esquinas abajo
    gotoxy(110,y);
    printf("%c",217);
    gotoxy(1,y);
    printf("%c",192);


}

