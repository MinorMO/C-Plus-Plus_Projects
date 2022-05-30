

#include <iostream>
#include <iomanip>
#include <string.h>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

using namespace std;
///Declaración de prototipos.
void Mostrar_Arreglo(const char*[]);
int Seleccionar_Equipos(int&,string&,const char*[],int&,string&,bool&);
string Validar_Equipo_Casa(int,string&,const char*[]);
string Validar_Equipo_Visita(int,string&,const char*[]);
void Metodo_General_Control_Cada_Serie(string,int&,string,int&,int&,int&,int&);
int Ronda_Normal(string,int&,string,int&);
int Ronda_Penales(int,int,string,int&,string,int&);
void Lanzamiento_Moneda_Azar ( string, string,int&);
int Asigna_Valor_Aleatorio_Moneda(int&);
string Determinar_Ganador(int,int,string&,string,string,int,int,int);
void Mostrar_Ganador(char*,string);
bool Repetir_ciclo(bool&);

int main()
{

    /// Permite que el programa interprete bien las tildes y cambia la apariencia y el nombre del archivo en consola.
    setlocale(LC_ALL,"Spanish");
    system("color B4");
    system(" title DECISOR DE PARTIDOS DE FUTBOL MEDIANTE EL MODO IDA Y VUELTA");

    ///Declaración de variables.
//Declaración de un arreglo de punteros.
    const char *Equipos[] = {"Alajualense","CS Herediano","Guadalupe","Pérez Zeledón","Santos Guápiles", "AD Grecia","Deportivo Saprissa", "CS Cartaginés","San Carlos","Limón","Jicaral Sercoba","Sporting San José"};
    char*Ptr_Equipo_Ganador; //Declaración de un puntero tipo char.
    int Num_Casa, Num_Visita;
    int Contador_Contador_Goles_Penales_E1=0;
    int Cont_Goles_Penales_E1=0;
    int Contador_Goles_Penales_E1=0;
    int Cont_Goles_Penales_E2=0;
    bool Repetir=false;
    bool Ingresar_Equipos=true;
    char Salir;
    int Moneda;
    string E_Casa;
    string E_Visita;
    string Equipo_Ganador;

// Estructura que maneja la repetición del Código.
    do
    {
        Mostrar_Arreglo(Equipos); // Llama a la función que muestra el arreglo de punteros.
        Seleccionar_Equipos(Num_Casa,E_Casa,Equipos,Num_Visita,E_Visita,Ingresar_Equipos); // Llama a la función que se encarga de seleccionar los Equipos.
        Metodo_General_Control_Cada_Serie(E_Casa,Contador_Contador_Goles_Penales_E1,E_Visita,Cont_Goles_Penales_E1,Contador_Goles_Penales_E1,Cont_Goles_Penales_E2,Moneda); // Llama a la función que se encarga de controlar las rondas que deben jugarse.
        Determinar_Ganador(Contador_Contador_Goles_Penales_E1,Cont_Goles_Penales_E1,Equipo_Ganador,E_Casa,E_Visita,Contador_Goles_Penales_E1,Cont_Goles_Penales_E2,Moneda); // Llama a la función que determina el ganador de la serie, dependiendo las diferentes rondas jugadas.
        Mostrar_Ganador(Ptr_Equipo_Ganador,Equipo_Ganador); // Llama a la funcion encargada de mostrar el recuadro con el equipo ganador.
        Repetir_ciclo(Repetir); // Llama a la función que se encarga de controlar la si se juega evalúa otra serie o no.

// Inicialización por si se evalúa otra serie.
        Contador_Contador_Goles_Penales_E1=0;
        Cont_Goles_Penales_E1=0;
        Contador_Goles_Penales_E1=0;
        Cont_Goles_Penales_E2=0;
        Moneda=0;
    }
    while (Repetir==true);
    return 0;
}// Fin del main.


// Método que se encarga de mostrar los equipos a través de un arreglo de punteros.
void Mostrar_Arreglo(const char*Equipos[]){

    cout <<setw(70)<<" -------------------------------------------------"<<endl;
    cout <<setw(70)<<"[-- LISTADO DE Equipos DE PRIMERA DIVISIÓN / CR --]"<<endl;
    cout <<setw(70)<<" -------------------------------------------------"<<endl;

    for(int i = 0; i<12; i++){
        cout<< setw(35)<<"["<<i+1<<"] - ";
        cout <<Equipos[i]<<endl;}
}


//Método que se encarga de la selección de los Equipos por parte del usuario.
int Seleccionar_Equipos(int&Num_Casa,string&E_Casa,const char*Equipos[],int&Num_Visita,string&E_Visita,bool&Ingresar_Equipos){
    bool Habilitar_Equip=true;

// Estructura de repetición, por si el número ingresado está fuera del rango aceptado.
    while (Habilitar_Equip==true)
    {
        cout<<"\nEscoja el nombre del equipo 1 [casa]:"; // Solicita el primer equipo.
        cin>> Num_Casa;

// Si esta condición se cumple, es porque el usuario ingresó un número fuera del rango aceptado.
        if (Num_Casa<=0||Num_Casa>12){
            cout << setw(70)<<"\nEl numero no es valido, por favor ingrese un numero valido"<<endl;}// Muestra el mensaje de error, para luego volver a pedirle que ingrese un numero valido.

// Si esta condición se cumple es porque el usuario ingresó un número válido.
        if (Num_Casa>0&&Num_Casa<=12){
            Validar_Equipo_Casa(Num_Casa,E_Casa,Equipos);//Llama a la función que se encarga de validar el primer equipo escogido por el usuario.
            cout<<"\nNombre del equipo 1: "<<E_Casa<<endl;
            Habilitar_Equip=false;// Habilita la solicitud y validación del equipo 2.
        }
    }// Fin del while

// Estructura de repetición por si el número ingresado está fuera del rango aceptado.
    while(Habilitar_Equip==false)
    {
        cout<<"\nEscoja el nombre del equipo 2 [visita]:";// Solicita el segundo equipo
        cin>> Num_Visita;

// Si esta condición se cumple, es porque el usuario ingresó un número fuera del rango aceptado.
        if (Num_Visita<=0||Num_Visita>12){
            cout << "El numero no es valido, por favor ingrese un numero valido"<<endl;}// muestra el mensaje de error, para luego volver a pedirle que ingrese un numero valido.

// Si esta condición se cumple, es porque el usuario volvió a escoger al mismo equipo, y eso no está permitido por lo cual le despliega el siguiente mensaje, y debe volver a escoger otro equipo.
        if (Num_Visita==Num_Casa){
            cout<< "No puede digitar 2 veces el mismo equipo"<<endl;}

// Si esta condición se cumple es porque el usuario ingreso un número valido.
        if (Num_Visita>0&&Num_Visita<13&&Num_Visita!=Num_Casa){
            Validar_Equipo_Visita(Num_Visita,E_Visita,Equipos);//Llama a la función que se encarga de validar el segundo equipo escogido por el usuario.
            cout<<"\nNombre del equipo 2: "<<E_Visita<<endl;
            Habilitar_Equip=true;}  // para finalizar el while.
    }//fin del while

    system("Pause");// Solicita que se presione una cualquier tecla para continuar.
    system("cls");// limpia pantalla.

    return Num_Casa,Num_Visita;// Retorna los números correspondientes a los Equipos seleccionados por el usuario.
}

//Método que determina el primer equipo escogido por el usuario.
string Validar_Equipo_Casa(int Num_Casa,string& E_Casa,const char*Equipos[]){
    int contador=0;
    for (int i=0; i<12; i++){
        contador++; // Por cada ciclo del "for" la variable contador incrementa en 1.
        if (contador==Num_Casa){// cuando contador es igual al numero digitado por el usuario.
            E_Casa=Equipos[i]; // Guarda en la variable E_Casa el nombre del equipo que se encuentra en esa posición del arreglo.
            break;}
    }
    return E_Casa; //Retorna el nombre del primer equipo.
}

//Método que determina el segundo equipo escogido por el usuario.
string Validar_Equipo_Visita(int Num_Visita,string& E_Visita,const char*Equipos[]){
    int contador=0;
    for (int i=0; i<12; i++){
        contador++;// Por cada ciclo del "for" la variable contador incrementa en 1.
        if (contador==Num_Visita){// cuando contador es igual al numero digitado por el usuario
            E_Visita=Equipos[i];// Guarda en la variable E_Visita el nombre del equipo que se encuentra en esa posición del arreglo.
            break;}
    }
    return E_Visita; //Retorna el nombre del segundo equipo.
}

// Método que despliega en pantalla la ronda normal de ida y vuelta y guarda los goles digitados por el usuario.
int Ronda_Normal(string E_Casa,int&Contador_Contador_Goles_Penales_E1,string E_Visita,int&Cont_Goles_Penales_E1){
    bool seguir = false;
    int Marcador1,Marcador2;
//Muestra en pantalla el siguiente encabezado.
    cout<<endl;
    cout<<setw(70)<< "------------------------------------------------------"<<endl;
    cout<< setw(18)<<"[--"<<setw (31)<<"RONDA  NORMAL"<<setw(22)<<"--]"<<endl;
    cout<< setw(70)<<" ------------------------------------------------------"<<endl;
    cout << endl;
// Estructura que me permite controlar si la ronda es de ida o vuelta.
    for (int i=0; i<2; i++){

// Estructura de repetición que no termina hasta que el usuario digite los goles entre el rango permitido.
        while (seguir==false)
        {
            cout<<endl;
            cout << setw(45)<<": : : : :  RONDA  DE" << (i==0? " IDA" : " VUELTA")<< ": : : : :"<< endl; // Expresión condicional que controla con base al ciclo “for” si la roda es de ida o vuelta.
            cout<< endl;
            cout <<setw(45)<<"Ingrese marcador para equipo " << E_Casa<< " para ronda #" <<i+1<< "  =    "; // Solicita al usuario ingresar los goles para el primer equipo.
            cin >>Marcador1;
            if ( Marcador1<0 || Marcador1>15){ //Este condicional se encarga de que los goles marcados estén en el rango permitido.
                cout <<setw(45)<<"Error, los goles deben estar entre un rango de 1 a 15"<< endl;} //Si la condición se cumple despliega el siguiente mensaje, para volver a solicitarle un valor permitido.

            if (i==1&&(Marcador1>=0&&Marcador1<=15)){ //Si se cumple esta condición es porque el primer equipo está de visita, y porque los goles marcados están en el rango aceptado.
                Contador_Contador_Goles_Penales_E1=Contador_Contador_Goles_Penales_E1+(Marcador1*2);} // Cuando un equipo está de visita los goles valen el doble para dicho equipo.

            if (i==0&&(Marcador1>=0&&Marcador1<=15)){ // Si se cumple esta condición es porque el primer equipo está en casa, y porque los goles marcados están en el rango aceptado.
                Contador_Contador_Goles_Penales_E1=Marcador1;} //Cuando un equipo está en casa los goles no valen el doble.

            if  (Marcador1>=0 && Marcador1<=15){ // Si se cumple esta condición es porque los goles están en el rango aceptado.
                seguir=true;} // Por eso se habilita que el ciclo while finalice y habilita el próximo while.
        } // Fin del while

//Estructura de repetición que no termina hasta que el usuario digite los goles entre el rango permitido.
        while (seguir==true)
        {
            cout <<setw(45)<<"Ingrese marcador para equipo " <<E_Visita<< " para ronda #" <<i+1<< "  =   "; // Solicita al usuario ingresar los goles para el segundo equipo.
            cin >> Marcador2;
            if (Marcador2<0 || Marcador2>15){ //Este condicional se encarga de que los goles marcados estén en el rango permitido.
                cout <<setw(45)<<"Error, los goles deben estar entre un rango de 1 a 15"<< endl;}

            if (i==0&&(Marcador2>=0&&Marcador2<=15)){ //Si se cumple esta condición es porque el segundo equipo está de visita, y porque los goles marcados están en el rango aceptado.
                Cont_Goles_Penales_E1=Cont_Goles_Penales_E1+(Marcador2*2);} // Cuando un equipo está de visita los goles valen el doble para dicho equipo.

            if (i==1&&(Marcador2>=0&&Marcador2<=15)){ // Si se cumple esta condición es porque el segundo equipo está en casa, y porque los goles marcados están en el rango aceptado.
                Cont_Goles_Penales_E1=Cont_Goles_Penales_E1+Marcador2;} //Cuando un equipo está en casa los goles no valen el doble.
            if  (Marcador2>=0 && Marcador2<=15){ // Si se cumple esta condición es porque los goles están en el rango aceptado.
                seguir=false;} // Por eso se habilita que el ciclo while finalice lo cual habilita el próximo while cuando el ciclo for avance para entrar en la ronda de vuelta.
        } //Fin del while.
    } //Fin del ciclo for.

    return Contador_Contador_Goles_Penales_E1, Cont_Goles_Penales_E1; // Retorna los goles marcados por ambos Equipos en la ronda normal.
}

//Método que se encarga de implementar la ronda de penales, por si los 2 Equipos quedan empatados en la ronda normal.
int Ronda_Penales(int Contador_Contador_Goles_Penales_E1,int Cont_Goles_Penales_E1,string E_Casa,int&Contador_Goles_Penales_E1,string E_Visita,int&Cont_Goles_Penales_E2){
        bool seguir=false;
        int Marcador11,Marcador22;

//Si esta condición se cumple es porque hubo empate.
    if (Contador_Contador_Goles_Penales_E1==Cont_Goles_Penales_E1)
    {
        cout<<"\nHan establecido un empate! deben ir a serie de PENALES!"<<endl; //Muestra en pantalla que hubo un empate.
        system("pause"); // Solicita que se presione cualquier tecla para continuar con la ronda penales.
        system("cls"); //Limpia la pantalla.

//Muestra el encabezado de la ronda de penales.
        cout<<endl;
        cout<<setw(70)<< " ------------------------------------------------------"<<endl;
        cout<< setw(18)<<"[--"<<setw (31)<<"RONDA  PENALES"<<setw(22)<<"--]"<<endl;
        cout<<setw(70)<<" ------------------------------------------------------"<<endl;
        cout << endl;

//Estructura de repetición para las 5 rondas de penales.
        for (int i=0; i<5; i++){
                cout<<endl;
                cout <<setw(38)<<": : : :  RONDA  " <<i+1 << " DE LOS PENALES : : : : :"<< endl; //Despliega en pantalla en que ronda de los penales se encuentra.
                cout<<endl;

//Estructura de repetición por si el número ingresado por el usuario esta fuera del rango aceptado.
            while (seguir==false)
            {
                cout <<setw(46)<<"Ingrese marcador para equipo " << E_Casa<< " para ronda #" <<i+1<< " : "; // Solicita al usuario ingresar lo goles en esa ronda para el primer equipo.
                cin >>Marcador11;
                if ( Marcador11<0 || Marcador11>1){ // Si esta condición se cumple es porque el usuario digitó un número que no se encuentra en el rango permitido.
                    cout <<setw(46)<<"Error, los goles deben estar entre un rango de 0 a 1"<< endl;} // Se despliega el mensaje de error, para posterior volver a ingresar un número que se encuentre en el rango permitido.

                if  (Marcador11>=0 && Marcador11<=1){ // Si se cumple esta condición es porque el número digitado está en el rango aceptado.
                    Contador_Goles_Penales_E1=Contador_Goles_Penales_E1+Marcador11; // Se utiliza este contador para llevar la suma de los goles del primer equipo.
                    seguir=true;} // Se habilita que finalice el while y que se habilite el próximo while.
            }

//Estructura de repetición por si el número ingresado por el usuario esta fuera del rango aceptado.
            while (seguir==true)
            {
                    cout <<setw(46)<<"Ingrese marcador para equipo " <<E_Visita<< " para ronda #" <<i+1<< " : ";// Solicita al usuario ingresar lo goles en esa ronda para el segundo equipo.
                    cin >> Marcador22;

                    if (Marcador22<0 || Marcador22>1){ // Si esta condición se cumple es porque el usuario digitó un número que no se encuentra en el rango permitido.
                        cout <<setw(46)<<"Error, los goles deben estar entre un rango de 0 a 1"<< endl;} // Se despliega el mensaje de error, para posterior volver a ingresar un número que se encuentre en el rango permitido.

                    if  (Marcador22>=0 && Marcador22<=1){ // Si se cumple esta condición es porque el número digitado está en el rango aceptado.
                        Cont_Goles_Penales_E2=Cont_Goles_Penales_E2+Marcador22; // Se utiliza este contador para llevar la suma de los goles del primer equipo.
                        seguir=false;} // Se habilita que el ciclo while finalice, lo cual habilita el próximo while cuando el ciclo for avance para entrar en la siguiente ronda de penales.
            }

/// Condiciones para que gane el primer equipo.
// Si el primer equipo hizo 3 goles y el segundo equipo hizo 0-matemáticamente gana el equipo 1.
            if (Contador_Goles_Penales_E1==3&&Cont_Goles_Penales_E2==0){
                break;}

// Si están en la 4° ronda y el primer equipo hizo más de 3 goles y el segundo menos de 3, matemáticamente gana el equipo 1.
            if (i==3&&Contador_Goles_Penales_E1>3&&Cont_Goles_Penales_E2<3){
                break;}

// Si están en la 4° ronda y el primer equipo hizo 2 o más goles, y el segundo equipo hizo menos de 2, matemáticamente gana el equipo 1.
            if (i==3&&Contador_Goles_Penales_E1>=2&&Cont_Goles_Penales_E2<2){
                break;}

// Si están en la última ronda y el primer equipo hizo más goles que el segundo equipo, automáticamente, gana el primer equipo.
            if (i==4&&Contador_Goles_Penales_E1>Cont_Goles_Penales_E2){
                break;}


/// Condiciones para que gane el segundo equipo.
// Si el segundo equipo hizo 3 goles y el primer equipo hizo 0, matemáticamente gana el equipo 1.
            if (Cont_Goles_Penales_E2==3&&Contador_Goles_Penales_E1==0){
                break;}

// Si están en la 4° ronda y el segundo equipo hizo más de 3 goles y el primero menos de 3, matemáticamente gana el equipo 1.
            if (i==3&&Cont_Goles_Penales_E2>3&&Contador_Goles_Penales_E1<3){
                break;}

// Si están en la 4° ronda y el segundo equipo hizo 2 o más goles, y el primer equipo hizo menos de 2, matemáticamente gana el equipo 1.
            if (i==3&&Cont_Goles_Penales_E2>=2&&Contador_Goles_Penales_E1<2){
                break;}

// Si están en la última ronda y el segundo equipo hizo más goles que el primer equipo, automáticamente, gana el primer equipo.
            if (i==4&&Cont_Goles_Penales_E2>Contador_Goles_Penales_E1){
                break;}

        }// Fin del for.
    }//Fin del if.

    return Contador_Goles_Penales_E1,Cont_Goles_Penales_E2;// Retorna los goles anotados por ambos Equipos.
}

//Método que determina y muestra quién fue el ganador en base a un lanzamiento de moneda al azar, por si ambos Equipos quedaron empates en la ronda de penales.
void Lanzamiento_Moneda_Azar (string E_Casa,string E_Visita,int&Moneda){
// Muestra que hubo un empate en penales.
    cout<< "\nHan establecido un empate en roda de PENALES!, deben ir a serie de DADOS! "<<endl;
    system ("pause"); // Espera que el usuario digite cualquier tecla para continuar.
    system ("cls"); //Limpia pantalla

//Muestra el encabezado de la ronda de dados.
    cout<<endl;
    cout<< setw(70)<<"------------------------------------------------------"<<endl;
    cout<<setw(18)<< "[--"<<setw (31)<<"RONDA  DADOS"<<setw(22)<<"--]"<<endl;
    cout<< setw(70)<<" ------------------------------------------------------"<<endl;
    cout << endl;
    cout<< "\nFavor dar enter para aplicar la suerte de los datos a los Equipos";

//Muestra los Equipos participantes que quedaron empatados.
    cout<<"\nEquipo 1: " << E_Casa<< endl;
    cout <<"\nEquipo 2: " << E_Visita<< endl;
    system("pause"); // Espera que el usuario digite cualquier tecla para continuar.
    Asigna_Valor_Aleatorio_Moneda(Moneda); // Llama a la función que se encarga de asignar un numero al azar a la variable moneda.
    cout<<"\nDado :"<<Moneda<<endl; // Muestra el resultado obtenido en la función anterior.
    cout<<endl;
    cout<<endl;

}

//Método que asigna un numero aleatorio entre 1 y 2 a la variable moneda.
int Asigna_Valor_Aleatorio_Moneda(int&Moneda){
    srand(time(0));
    Moneda = 1+rand() % 2;// Asigna un número aleatorio entre 1 y 2.
    return Moneda; // Retorna el valor al azar entre 1 y 2.
}

//Método que controla las rondas que deben de llevar acabo segun los resultados de cada ronda.
void Metodo_General_Control_Cada_Serie(string E_Casa,int&Contador_Contador_Goles_Penales_E1,string E_Visita,int&Cont_Goles_Penales_E1,int&Contador_Goles_Penales_E1,int&Cont_Goles_Penales_E2,int&Moneda){
    Ronda_Normal(E_Casa,Contador_Contador_Goles_Penales_E1,E_Visita,Cont_Goles_Penales_E1); //Llama a la función que se encarga de la ronda normal.

//Si en la ronda normal ambos Equipos quedaron empatados se cumple la siguiente condición.
    if (Contador_Contador_Goles_Penales_E1==Cont_Goles_Penales_E1){
        Ronda_Penales(Contador_Contador_Goles_Penales_E1,Cont_Goles_Penales_E1,E_Casa,Contador_Goles_Penales_E1,E_Visita,Cont_Goles_Penales_E2); // Como quedaron empatados manda a llamar a la función de la ronda de penales.
// condicional anidado.
// Si en la ronda de penales ambos Equipos empataron se cumple la siguiente condición.
        if (Contador_Goles_Penales_E1==Cont_Goles_Penales_E2){
            Lanzamiento_Moneda_Azar(E_Casa, E_Visita,Moneda);} // Llama a la función que se encarga de lanzar una moneda al azar para determinar el ganador a suerte.
    }//Fin if.
}

//Método que se encarga de determinar el ganador dependiendo de cada ronda.
string Determinar_Ganador (int Contador_Contador_Goles_Penales_E1,int Cont_Goles_Penales_E1,string&Equipo_Ganador,string E_Casa,string E_Visita,int Contador_Goles_Penales_E1,int Cont_Goles_Penales_E2,int Moneda){
// Determina cuál equipo ganó en la ronda normal y despliega un pequeño mensaje con el ganador.
    if (Contador_Contador_Goles_Penales_E1>Cont_Goles_Penales_E1){
        Equipo_Ganador=&E_Casa[0];
        cout<< "\nFelicidades al ganador de esta serie :"<<Equipo_Ganador<<"!!!"<<endl;}
    else if (Cont_Goles_Penales_E1>Contador_Contador_Goles_Penales_E1){
        Equipo_Ganador=&E_Visita[0];
        cout<< "\nFelicidades al ganador de esta serie :"<<Equipo_Ganador<<"!!!"<<endl;}

// Si no hubo ganador en la primera ronda, entonces, determina con base a la ronda de penales cuál fue el ganador, y despliega un pequeño mensaje con el ganador.
    if (Contador_Goles_Penales_E1>Cont_Goles_Penales_E2){
        Equipo_Ganador=&E_Casa[0];
        cout<< "\nFelicidades al ganador de esta serie de PENALES :"<<Equipo_Ganador<<"!!!"<<endl;}
    else if (Cont_Goles_Penales_E2>Contador_Goles_Penales_E1){
        Equipo_Ganador=&E_Visita[0];
        cout<< "\nFelicidades al ganador de esta serie de PENALES :"<<Equipo_Ganador<<"!!!"<<endl;}

// Si en la ronda de penales quedaron empates, entonces, determina con base a una moneda al azar cual equipo es el ganador, y despliega un pequeño mensaje con el ganador.
    if(Moneda==1){
        cout<<"\nFelicidades al ganador de esta serie de dados: " << E_Casa<<endl;
        Equipo_Ganador=&E_Casa[0];}
    else if (Moneda==2){
        cout<<"Felicidades al ganador de esta serie de dados: "<<E_Visita<<endl;
        Equipo_Ganador=&E_Visita[0];}

    return Equipo_Ganador; // Retorna el equipo ganador.
}

// Método que se encarga de mostrar el recuadro del ganador, a través de una matriz y recorriendo un puntero de tipo char para pasarlo a mayúsculas.
void Mostrar_Ganador(char*Ptr_Equipo_Ganador,string Equipo_Ganador){
/// Declaración de variables locales de la función.
    int longitud=0;
    char ganador[5][100];
    int resta=0;
    int contadorr=0;
    int suma=0;
    int ii=0;///cambiar contador

// Asigna al puntero el equipo ganador.
    Ptr_Equipo_Ganador=&Equipo_Ganador[0];

// Cuenta cuántos carácteres tiene el nombre del equipo ganador, y guarda esa cantidad en la variable longitud.
    longitud=strlen(Ptr_Equipo_Ganador);

// A las 100 columnas de la matriz se le resta la longitud de caracteres del equipo ganador y se divide entre 2 para centrar el nombre del equipo ganador en la matriz.
    resta=(100-longitud)/2; // El resultado se guarda en la variable resta.

    if (resta%2!=0){// Si el número guardado en resta es impar se debe aumentar en 1 para centrar bien el nombre en la matriz.
        resta=resta+1;}

// Luego se guarda el valor de la suma de la resta más la longitud.
    suma=resta+longitud;

// Se empieza a recorrer la matriz para llenarla.
    for (int i=0; i<5; i++){
        for (int j=0; j<100; j++){

            if (i<2){ // En las primeras 2 filas se llena únicamente con '='.
                ganador[i][j]='=';}

            if (i==2&&contadorr<resta){ //Si se cumple la condición es porque está en la tercera fila y porque el contador es menor a lo guardado en la variable resta.
                contadorr++; // Contador empieza a incrementar por cada ciclo del segundo for, solo si se cumple la condicion.
                ganador[i][j]='=';} // Sigue llenando con '=', al inicio de esta fila

// Cuando el contador sea mayor o igual a la resta y sea menor a la suma entonces es cuando se debe de empezar a recorrer el puntero mientras se le asigna a la matriz y se va pasando a mayúscula.
            if (contadorr>=resta&&contadorr<suma){
                ganador[i][j]=toupper(*(Ptr_Equipo_Ganador+ii));
                ii++;} // Este contador es para ir recorriendo el puntero, carácter por carácter.

            if (i==2&&j>=suma-1){ // cuando la variable i sea igual a 2 y j sea mayor o igual a suma-1 significa que ya se terminó de asignar al ganador en esa fila de la matriz por ende se va a seguir llenando la matriz con '='.
                ganador[i][j]='=';}

            if (i>2){ // Cuando avance a la siguiente fila esta condición se cumple y se termina de llenar la matriz con '='.
                ganador[i][j]='=';}
        } // Fin del segundo for.
    } // Fin del primer for.

// Despliega en pantalla lo que se almacenó previamente en la matriz con el equipo ganador.
    for(int i=0; i<5; i++){
        for (int j=0; j<100; j++){
            cout <<ganador[i][j];}
        cout<<endl;
    }
}

//Método que se encarga de repetir el ciclo, por si el usuario desea volver a realizar otra serie.
bool Repetir_ciclo(bool&Repetir){
    char Salir;
    cout<<"Desea volver a evaluar una serie (S/N)? :"; // Solicita que si desea evaluar otra serie.
    cin>>Salir;
    Salir=toupper(Salir); // Convierte el char digitado por el usuario a mayúscula y se lo asigna a la variable salir.

// Dependiendo de que digitó el usuario,  una de las condiciones se va a cumplir.
    if (Salir=='S')
        Repetir=true;
    if (Salir=='N')
        Repetir=false;
    system("cls");// Limpia pantalla.
    return Repetir;// Retorna la decisión del usuario.
}
