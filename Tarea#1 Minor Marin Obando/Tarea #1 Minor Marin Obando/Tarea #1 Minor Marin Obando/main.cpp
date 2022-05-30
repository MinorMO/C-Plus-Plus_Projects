/* Tarea #1
Eliminacion de bloques por medio de corrimiento!
Autor: Minor Marin Obando
Fecha: 24 de junio del 2021*/

//Librerias usadas
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
// declaraci�n de prototipos de funciones.
void Llenar_Original(int[][9]);
void Llenar_Copia(int[][9],int[][9]);
void Mostrar_Matriz_Original(int[][9]);
void Mostrar_Matriz_Copia(int[][9]);
int Validar_Numero_Ingresado(int,int&,int&);
int Valor_Fila_Columna(int,int&,int&);
void Analizar_Derecha(int,int[][9],int);
void Analizar_Izquierda(int,int[][9],int);
void Convertir_Cero_Num_US (int[][9],int,int);
int Encontrar_Ultimo_Cero(int[][9],int,int&);
void Desplazar_Izquierda(int,int[][9],int);
int Analizar_Matriz_Completa(int[][9],int&);

int main()
{
// Declaraci�n de variables
    int Original[9][9];
    int Copia[9][9];
    int Fila;
    int Columna;
    int Numero;
    int Primer_cero;
    int Salir=1;
    int Fuera_rango=1;
    int Total_Ceros;
    int Ultimo_Cero;

// Personalizaci�n de la consola que mira el usuario
    system("color B4");
    setlocale(LC_ALL,"");
    system(" Title Eliminar Bloques Mediante Corrimento!");

// Funciones que se encargan de llenar y mostrar las matrices "original" y "copia"
    Llenar_Original(Original);
    Llenar_Copia(Original,Copia);
    Mostrar_Matriz_Original(Original);
    Mostrar_Matriz_Copia(Copia);

    while(Salir==1)// Ciclo de repetici�n que se encarga de repetir todo el c�digo hasta que el usuario desee Salir del programa o hasta que digite un n�mero fuera de rango.
    {
//Inicializaci�n de variables dentro del while porque es necesario que su valor se reinicie con cada ciclo del programa.
        Ultimo_Cero=0;
        Fila=0;
        Columna=0;
        Total_Ceros=0;

// Solicita un n�mero al usuario y lo guarda.
        cout <<"Digite la posici�n donde desea �niciar (0 para Salir!): ";
        cin>>Numero;

// Manda a llamar a la funci�n que determina si el n�mero ingresado es v�lido o si es el n�mero centinela de salida.
        Validar_Numero_Ingresado(Numero,Salir,Fuera_rango);
// Si el n�mero ingresado por el usuario esta fuera de rango muestra el siguiente mensaje y finaliza el programa.
        if (Fuera_rango==0){
            cout<<"valor "<<Numero<< " fuera de rango!"<<endl;
            cout<< "Chao!"<<endl;}

// Llamado de las funciones necesarias para realizar las modificaciones de la matriz "Copia".
        Valor_Fila_Columna(Numero,Fila,Columna);
        Analizar_Derecha(Columna,Copia,Fila);
        Analizar_Izquierda(Columna,Copia,Fila);
        Convertir_Cero_Num_US(Copia,Fila,Columna);
        Encontrar_Ultimo_Cero(Copia,Fila,Ultimo_Cero);
        Desplazar_Izquierda(Ultimo_Cero,Copia,Fila);

/*Si el usuario digita un n�mero v�lido o diferente del centinela entonces se cumple
 la condici�n del if y se limpia la pantalla mostrando de nuevo la matriz original y la matriz copia*/
        if (Fuera_rango==1 && Salir==1){
            system("cls");
            Mostrar_Matriz_Original(Original);
            Mostrar_Matriz_Copia(Copia);
        }

/* llama a la funci�n que se encarga de determinar si la matriz esta completa de ceros
lo cual hace que se cumpla la condici�n del if mostrando el siguiente mensaje y finalizando el programa*/
        Analizar_Matriz_Completa(Copia,Total_Ceros);
        if (Total_Ceros==81){
            cout << "\nMatriz completa de ceros!"<< endl;
            cout << "Chao!"<<endl;
            Salir=0;
        }
    }//Fin del while.
    return EXIT_SUCCESS;
} // Aqui termina el Main.


/// Declaraci�n de las funciones

// Funci�n que llena la matriz original.
void Llenar_Original(int Original[][9]){
    srand (time(0));
    for (int i = 0; i<=8; i++){//llena la matriz original
        for (int j =0; j<=8; j++){
            Original[i][j]=(1+rand()%2);
        }
    }
}

//Funci�n que llena la matriz copia.
void Llenar_Copia(int Original[][9],int Copia[][9]){
    for (int i = 0; i<=8; i++){// llena la copia
        for (int j =0; j<=8; j++){
            Copia[i][j]= Original[i][j];
        }
    }
}

//Funci�n que muestra la matriz original.
void Mostrar_Matriz_Original(int Original[][9]){
     cout <<"\n================ORIGINAL: ==================="<<endl;
     for (int i = 0;i<=8;i++){
        for (int j =0; j<=8;j++){
            cout<< setw(5)<<Original[i][j];
        }
        cout<< "\n";
     }
     cout <<"\n=============================================="<<endl;
}

//Funci�n que muestra la matriz copia.
void Mostrar_Matriz_Copia(int Copia[][9]){
    cout<< "\n==============MODIFICADO: ===================="<<endl;
    for (int i = 0; i<=8; i++){
        for (int j =0; j<=8; j++){
            cout<< setw(5)<<Copia[i][j];
        }
        cout<< "\n";
    }
    cout <<"\n=============================================="<<endl;
}

//Funci�n que valida si el n�mero ingresado por el usuario est� dentro del rango o si es el n�mero de salida del programa.
int Validar_Numero_Ingresado(int Num_us,int&Salir,int&F_rango){
    if (Num_us==0){ // si el n�mero digitado es igual al valor centinela entonces la variable fin se le asigna el valor 0.
        Salir=0;}
    if (Num_us>81||Num_us<0){ // si el n�mero digitado esta fuera de estos rangos entonces
        F_rango=0; // la variable F_rango pasa a valer 0.
        Salir=0;} // y la variable fin pasa a valer 0.
    return Salir,F_rango;
}

//Funci�n que determina con base al n�mero digitado por el usuario la posici�n exacta en la matriz para guardar la Fila y la Columna.
int Valor_Fila_Columna(int Num_us,int&Fila,int&Columna){
int Contador=0;
// Se empieza recorriendo la matriz
    for (int i=0;i<=8;i++){
        for (int j=0;j<=8;j++){
            Contador=Contador+1; // por cada posici�n que avance el contador va aumentando en 1.
            if (Contador==Num_us){ //cuando el contador sea igual al n�mero digitado por el usuario.
                Fila=i;// guarda en la variable Fila el valor que actualmente posee la variable i.
                Columna=j; // y guarda en la variable Columna el valor que actualmente posee la variable j.
                break; // y finaliza los ciclos for.
            }
        }
    }
    return Fila,Columna;
}

//Funci�n que analiza hacia la derecha si los n�meros son iguales al valor de la posici�n que digit� el usuario y de ser as� los convierte en ceros.
void Analizar_Derecha(int Columna,int Copia[][9], int Fila){

    for(int j=Columna; j<9; j++){
        if (j==8) // si la Columna es 8 entonces no es necesario analizar hacia la derecha.
            break; // por eso se finaliza el ciclo
//Sino se cumple la condici�n anterior entonces verifico si se cumplen las 3 condiciones siguientes;  de no ser as� entonces se sale del ciclo.
//adem�s con la condici�n que de !=0 se verifica que el valor en esa posici�n no se haya convertido con anterioridad.
        else if(Copia[Fila][Columna]==Copia[Fila][j+1]&&Copia[Fila][Columna]!=0){
            Copia[Fila][j+1]=0;}
        else break;
    }
}

//Funci�n que analiza hacia la izquierda si los n�meros son iguales al valor de la posici�n que digit� el usuario y de ser as� los convierte en ceros.
void Analizar_Izquierda(int Columna,int Copia[][9], int Fila){
    for(int j=Columna; j>=0; j--){//analiza a la izquierda
        if (j==0){// si la Columna es 0 entonces no es necesario analizar hacia la izquierda.
            break;} // por eso se finaliza el ciclo.
// como en la funci�n anterior sino se cumplen las 3 condiciones se finaliza el ciclo.
        else if(Copia[Fila][Columna]==Copia[Fila][j-1]&&Copia[Fila][Columna]!=0){
            Copia[Fila][j-1]=0;}
        else break;
    }

}

//Funci�n que convierte en cero el n�mero que est� en la posici�n que digit� el usuario.
void Convertir_Cero_Num_US (int Copia[][9],int Fila,int Columna){ // ya habiendo convertido en cero los n�meros iguales a la izquierda y a la derecha solo basta con convertir en cero la posici�n que digit� el usuario
    if (Copia[Fila][Columna]!=0)
        Copia[Fila][Columna]=0;
}

//Funci�n que localiza el ultimo cero en la Fila correspondiente a la posici�n que digito el usuario y guarda el n�mero de la Columna en donde lo encontr�.
int Encontrar_Ultimo_Cero(int Copia[][9],int Fila,int&Ultimo_Cero){
 for (int j=8; j>=0; j--){ // se recorre la Fila correspondiente al n�mero digitado por el usuario de derecha a izquierda
        if (Copia[Fila][j]==0){
            Ultimo_Cero=j; // si se cumple el if guarda en la variable "Ultimo_Cero" el n�mero de Columna donde se encontr� el cero y sale del ciclo
            break;
        }
    }
    return Ultimo_Cero;
}

//Funci�n que toma como base el m�todo burbuja para realizar los desplazamientos hacia la izquierda de los bloques convertidos en ceros.
void Desplazar_Izquierda(int Ultimo_Cero,int Copia[][9],int Fila){
int Aux; // declara variable auxiliar la cual se utilizar� para guardar datos que se van a mover.
int Cont_J=Ultimo_Cero; // declara el contador j y le asigna en la Columna del �ltimo cero encontrado en la funci�n anterior.
    for (int j=Ultimo_Cero-1; j>=0;j--){ // el ciclo empieza una posici�n antes de donde se encontr� el �ltimo cero y va retrocediendo.
        if (Copia[Fila][j]!=0){
            Aux=Copia[Fila][Cont_J]; //si se cumple el if guarda en la variable Aux el valor que se encuentra en la Columna donde se encontr� el ultimo cero en la funci�n anterior
            Copia[Fila][Cont_J]=Copia[Fila][j]; // en la posici�n donde se encontr� el �ltimo cero en la funci�n anterior se intercambia con el valor que esta antes de esa posici�n
            Copia[Fila][j]=Aux;// a la posici�n anterior de donde se encontr� el �ltimo cero se le asigna el valor guardado en la variable auxiliar
           Cont_J=Cont_J-1;// el contador j disminuye en 1 para repetir el ciclo.
        }
    }
}

//Funci�n que determina si toda la matriz ya est� completa en ceros para finalizar el programa
int Analizar_Matriz_Completa(int Copia[][9] ,int&Total_Ceros){
   for (int i=0;i<9;i++){
    for (int j=0;j<9;j++){
        if(Copia[i][j]==0){
            Total_Ceros=Total_Ceros+1;
        }
        else break;
    }
   }
   return Total_Ceros;
}


