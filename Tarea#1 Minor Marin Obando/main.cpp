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
int validar_numero_ingresado(int&,int&,int&);
int valor_fila_columna(int,int&,int&);
void Analizar_Derecha(int,int[][9],int);
void Analizar_Izquierda(int,int[][9],int);
void Convertir_cero_num_us (int[][9],int,int);
int Encontrar_ultimo_cero(int[][9],int,int&);
void Desplazar_izquierda(int,int[][9],int);
int Analizar_matriz_completa(int[][9],int&);

int main()
{
// declaraci�n de variables
    int Original[9][9];
    int Copia[9][9];
    int fila,columna, filas;
    int numero;
    int primer_cero;
    int salir=1;
    int fuera_rango=1;
    int total_ceros;
    int ultimo_cero;

// personalizaci�n de la consola que mira el usuario
    system("color B4");
    setlocale(LC_ALL,"");
    system(" Title Eliminar Bloques Mediante Corrimento!");

// funciones que se encargan de llenar y mostrar las matrices "original" y "copia"
    Llenar_Original(Original);
    Llenar_Copia(Original,Copia);
    Mostrar_Matriz_Original(Original);
    Mostrar_Matriz_Copia(Copia);

    while(salir==1)// ciclo de repetici�n que se encarga de repetir todo el C�digo hasta que el usuario desee salir del programa o hasta que digite un numero fuera de rango.
    {
//inicializaci�n de variables dentro del while porque es necesario que su valor se reinicie con cada ciclo del programa.
        ultimo_cero=0;
        fila=0;
        columna=0;
        total_ceros=0;

// solicita un numero al usuario y lo guarda.
        cout <<"Digite la posici�n donde desea �niciar (0 para salir!): ";
        cin>>numero;

// manda a llamar a la funci�n que determina si el n�mero ingresado es v�lido o si es el n�mero centinela de salida.
        validar_numero_ingresado(numero,salir,fuera_rango);
// si el n�mero ingresado por el usuario esta fuera de rango muestra el siguiente mensaje y finaliza el programa.
        if (fuera_rango==0){
            cout<<"valor "<<numero<< " fuera de rango!"<<endl;
            cout<< "Chao!"<<endl;}

// llamado de las funciones necesarias para realizar las modificaciones de la matriz "Copia".
        valor_fila_columna(numero,fila,columna);
        Analizar_Derecha(columna,Copia,fila);
        Analizar_Izquierda(columna,Copia,fila);
        Convertir_cero_num_us(Copia,fila,columna);
        Encontrar_ultimo_cero(Copia,fila,ultimo_cero);
        Desplazar_izquierda(ultimo_cero,Copia,fila);

/*si el usuario digita un numero valido o diferente del centinela entonces se cumple
 la condici�n del if y se limpia la pantalla mostrando de nuevo la matriz original y la matriz copia*/
        if (fuera_rango==1 && salir==1){
            system("cls");
            Mostrar_Matriz_Original(Original);
            Mostrar_Matriz_Copia(Copia);
        }

/* llama a la funci�n que se encarga de determinar si la matriz esta completa de ceros
lo cual hace que se cumpla la condici�n del if mostrando el siguiente mensaje y finalizando el programa*/
        Analizar_matriz_completa(Copia,total_ceros);
        if (total_ceros==81){
            cout << "\nMatriz completa de ceros!"<< endl;
            cout << "Chao!"<<endl;
            salir=0;
        }
    }//fin del while.
    return EXIT_SUCCESS;
} // aqui termina el Main.


/// Declaracion de las funciones

// funci�n que llena la matriz original.
void Llenar_Original(int Original[][9]){
    srand (time(0));
    for (int i = 0; i<=8; i++){//llena la matriz original
        for (int j =0; j<=8; j++){
            Original[i][j]=(1+rand()%2);
        }
    }
}

//funci�n que llena la matriz copia.
void Llenar_Copia(int Original[][9],int Copia[][9]){
    for (int i = 0; i<=8; i++){// llena la copia
        for (int j =0; j<=8; j++){
            Copia[i][j]= Original[i][j];
        }
    }
}

//funci�n que muestra la matriz original.
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

//funci�n que muestra la matriz copia.
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

//funci�n que valida si el n�mero ingresado por el usuario est� dentro del rango o si es el n�mero de salida del programa.
int validar_numero_ingresado(int&num_us,int&fin,int&F_rango){
    if (num_us==0){ // si el n�mero digitado es igual al valor centinela entonces la variable fin se le asigna el valor 0.
        fin=0;}
    if (num_us>81||num_us<0){ // si el n�mero digitado esta fuera de estos rangos entonces
        F_rango=0; // la variable F_rango pasa a valer 0.
        fin=0;} // y la variable fin pasa a valer 0.
    return fin,F_rango;
}

//funci�n que determina con base al n�mero digitado por el usuario la posici�n exacta en la matriz para guardar la fila y la columna.
int valor_fila_columna(int num_us,int&fila,int&columna){
int contador=0;
// se empieza recorriendo la matriz
    for (int i=0;i<=8;i++){
        for (int j=0;j<=8;j++){
            contador=contador+1; // por cada posici�n que avance el contador va aumentando en 1.
            if (contador==num_us){ //cuando el contador sea igual al n�mero digitado por el usuario// cuando el contador sea igual al n�mero digitado por el usuario.
                fila=i;// guarda en la variable fila el valor que actualmente posee la variable i.
                columna=j; // y guarda en la variable columna el valor que actualmente posee la variable j.
                break; // y finaliza los ciclos for.
            }
        }
    }
    return fila,columna;
}

//funci�n que analiza hacia la derecha si los n�meros son iguales al valor de la posici�n que digito el usuario y de ser as� los convierte en ceros.
void Analizar_Derecha(int columna,int Copia[][9], int fila){

    for(int j=columna; j<9; j++){
        if (j==8) // si la columna es 8 entonces no es necesario analizar hacia la derecha.
            break; // por eso se finaliza el ciclo
//sino se cumple la condici�n anterior entonces verifico si se cumplen las 3 condiciones siguientes porque de no ser as� entonces se sale del ciclo.
//adem�s con la condici�n que sea !=0 me aseguro que el valor en esa posici�n no se haya convertido con anterioridad.
        else if(Copia[fila][columna]==Copia[fila][j+1]&&Copia[fila][columna]!=0){
            Copia[fila][j+1]=0;}
        else break;
    }
}

//funci�n que analiza hacia la izquierda si los n�meros son iguales al valor de la posici�n que digito el usuario y de ser as� los convierte en ceros.
void Analizar_Izquierda(int columna,int Copia[][9], int fila){
    for(int j=columna; j>=0; j--){//analiza a la izquierda
        if (j==0){// si la columna es 0 entonces no es necesario analizar hacia la izquierda.
            break;} // por eso se finaliza el ciclo.
// como en la funci�n anterior sino se cumplen las 3 condiciones se finaliza el ciclo.
        else if(Copia[fila][columna]==Copia[fila][j-1]&&Copia[fila][columna]!=0){
            Copia[fila][j-1]=0;}
        else break;
    }

}

//funci�n que convierte en cero el n�mero que est� en la posici�n que digito el usuario.
void Convertir_cero_num_us (int Copia[][9],int fila,int columna){ // ya habiendo convertido en cero los n�meros iguales a la izquierda y a la derecha solo basta con convertir en cero la posici�n que digito el usuario
    if (Copia[fila][columna]!=0)
        Copia[fila][columna]=0;
}

//funci�n que localiza el ultimo cero en la fila correspondiente a la posici�n que digito el usuario y guarda el numero de la columna en donde lo encontr�.
int Encontrar_ultimo_cero(int Copia[][9],int fila,int&ultimo_cero){
 for (int j=8; j>=0; j--){ // se recorre la fila correspondiente al n�mero digitado por el usuario de derecha a izquierda
        if (Copia[fila][j]==0){
            ultimo_cero=j; // si se cumple el if guarda en la variable "ultimo_cero" el numero de columna donde se encontr� el cero y sale del ciclo
            break;
        }
    }
    return ultimo_cero;
}

//funci�n que toma como base el m�todo burbuja para realizar los desplazamientos hacia la izquierda de los bloques convertidos en ceros.
void Desplazar_izquierda(int ultimo_cero,int Copia[][9],int fila){
int aux; // declara variable auxiliar la cual se utilizar� para guardar datos que se van a mover.
int cont_j=ultimo_cero; // declara el contador j y le asigna en la columna del ultimo cero encontrado en la funci�n anterior.
    for (int j=ultimo_cero-1; j>=0;j--){ // el ciclo empieza una posici�n antes de donde se encontr� el ultimo cero y va retrocediendo.
        if (Copia[fila][j]!=0){
            aux=Copia[fila][cont_j]; //si se cumple el if guarda en la variable Aux el valor que se encuentra en la columna donde se encontr� el ultimo cero en la funci�n anterior
            Copia[fila][cont_j]=Copia[fila][j]; // en la posici�n donde se encontr� el ultimo cero en la funci�n anterior se intercambia con el valor que esta antes de esa posici�n
            Copia[fila][j]=aux;// a la posici�n anterior de donde se encontr� el ultimo cero se le asigna el valor guardado en la variable auxiliar
           cont_j=cont_j-1;// el contador j disminuye en 1 para repetir el ciclo.
        }
    }
}

//funci�n que determina si toda la matriz ya est� completa en ceros para finalizar el programa
int Analizar_matriz_completa(int Copia[][9] ,int&total_ceros){
   for (int i=0;i<9;i++){
    for (int j=0;j<9;j++){
        if(Copia[i][j]==0){
            total_ceros=total_ceros+1;
        }
        else break;
    }
   }
   return total_ceros;
}



