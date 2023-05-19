#include <iostream>

using namespace std;
/* EXPLICACION DE VARIABLES DE AYUDA
A lo largo del codigo, usaremos variables de ayuda como ser 'i', 'j'; que simplemente sirven para denotar la
posicion de las filas y columnas en la matriz dada. 
Si este no es su uso, lo será en bucles del tipo 'for-loop', en donde necesitaremos que 'i' e 'j' se aumenten
para llevar a cabo de manera correcta el codigo
*/

/* EXPLICACION A RASGOS GENERALES DE TIPOS DE VARIABLES
int: Es utilizado para declarar variables enteras. Almacena números enteros, tanto positivos como negativos, sin decimales.
float: Es utilizado para declarar variables de punto flotante de precisión simple. Almacena números reales con decimales de menor precisión.
double: Es utilizado para declarar variables de punto flotante de precisión doble. Almacena números reales con decimales de mayor precisión que float.
void: Es utilizado como un tipo de dato especial que indica ausencia de tipo. Se utiliza en tres contextos principales:
- Como tipo de retorno de una función que no devuelve ningún valor
- Como argumento en una función para indicar que no se pasan parámetros. 
- Para declarar un puntero sin tipo específico. 
*/


//Prototipos de funciones 
int get_matriz(float matriz[50][50]); //Para obtener y guardar la matriz del usuario en su respectiva variable
void mostrar_matriz(float matriz[50][50], int filas, int columnas); //Para mostrar la matriz del usuario en pantalla
void matriz_escalar(); //Para realizar la multiplicacion de una matriz por un escalar
void suma(); //Para realizar la suma entre dos matrices (las matrices tienen que ser del mismo tamaño)
void resta(); //Para realizar la resta entre dos matrices (las matrices tienen que ser del mismo tamaño)
void determinante2x2(); //Para calcular el determinante de una matriz 2x2
void tutorial_ejemplo(); //Para mostrar una matriz de ejemplo, para que el usuario se familiarice
void titulo(); //Para mostrar el titulo en arte ASCII
void menu(); //Para llamar las funciones de las operaciones correspondientes


int main(){
    char restart;
    //Llamar a las funciones correspondientes
    titulo(); //Funcion void que nos muestra el titulo en arte ascii
    do{ //Para repetir el programa si asi lo desea el usuario
    menu(); //En la funcion menu tenemos todas las funciones para las operaciones correspondientes
    cout << "Quieres realizar una nueva operacion? Y/N" << endl; //Se le hace la consulta al usuario
    cin >> restart; 
    } while (restart == 'Y' || restart == 'y'); //Si escoge cualquier otra cosa, el programa termina 
    cout << "\nSuerte con tu examen ;)" << endl;
	return 0;
}

void titulo(){ //En arte ASCII ponemos el titulo, a manera de adorno de nuestro programa
    cout << endl;
    cout << "'       e    e           e      ~~~888~~~   ,88~-_   888b    | 888~~       e      888~-_     ,88~-_   888--_" << endl;
    cout << "'      d8b  d8b         d8b        888     d888   \\  |Y88b   | 888___     d8b     888   \\   d888   \\  888   \\" << endl;
    cout << "'     d888bdY88b       /Y88b       888    88888    | | Y88b  | 888       /Y88b    888    | 88888    | 888   ||"<< endl;
    cout << "'    / Y88Y Y888b     /  Y88b      888    88888    | |  Y88b | 888      /  Y88b   888    | 88888    | 888  //"<< endl;
    cout << "'   /   YY   Y888b   /____Y88b     888     Y888   /  |   Y88b| 888     /____Y88b  888   /   Y888   /  888_//"<< endl; 
    cout << "'  /          Y888b /      Y88b    888      `88_ /   |    Y888 888___ /      Y88b 888_-~     `88_ /   888 \\\\" << endl;
        cout << endl;
    cout << "'  `7MM\"\"\"Yb.   `7MM\"\"\"YMM'"     << endl;
    cout << "'    MM    `Yb.   MM    " << endl;
    cout << "'    MM     `Mb   MM   " << endl;
    cout << "'    MM      MM   MMmmMM'" << endl;
    cout << "'    MM     ,MP   MM" << endl;
    cout << "'    MM    ,dP'   MM" << endl; 
    cout << "'  .JMMmmmdP'   .JMMmmmmMMM'" << endl;
    	cout << endl;
    cout << "'       e    e           e      ~~~888~~~ 888~-_   888  e88~-_  888---  ,d88~~\\" << endl;
    cout << "'      d8b  d8b         d8b        888    888   \\  888 d888   \  888___ 8888'" << endl;
    cout << "'     d888bdY88b       /Y88b       888    888    | 888 8888     888    `Y88b'" << endl;
    cout << "'    / Y88Y Y888b     /  Y88b      888    888   /  888 8888     888     `Y88b,'" << endl;
    cout << "'   /   YY   Y888b   /____Y88b     888    888_-~   888 Y888     888       8888'" << endl;
    cout << "'  /          Y888b /      Y88b    888    888 \\\\   888  \"88_ /  888___  \__88P" << endl;
}

void menu() 
/*En este menu, tenemos las opciones de operaciones matriciales que realizara nuestro programa
Dependiendo del numero que se escoja, se ejecutara un bloque de codigo donde se llamaran otras funciones
*/
{
    int eleccion; //Creamos una variable int para la eleccion del usuario 
    cout << "\nEscoja la operacion que quiera realizar\n" << endl;
    cout << "1) Calcular determinante de matriz 2x2" << endl;
    cout << "2) Suma de matrices" << endl;
    cout << "3) Resta de matrices" << endl;
    cout << "4) Multiplicacion por un escalar" << endl;

    do //Usamos do para repetir la eleccion, en caso de que no se seleccione una opcion entre el rango de las que se ofrece
    {
        cout << "Introduce la operacion que quieras realizar: "; cin >> eleccion;

        switch (eleccion) { //Usamos switch para ejecutar un bloque de codigo en caso de que se elija un 'n' numero.

        case 1: //En caso de que se escoja el numero 1, llamamos a la funcion 'determinante2x2'
            determinante2x2();
            break; //Usamos break para detener switch, porque si no lo usamos, seguiran ejecutandose las demas opciones

        case 2: //En caso de que se escoja el numero 2, llamamos a la funcion 'suma'
            suma();
            break;

        case 3: //En caso de que se escoja el numero 3, llamamos a la funcion 'resta'
            resta();
            break;

        case 4: //En caso de que se escoja el numero 4, llamamos a la funcion 'matrizXescalar'
            matriz_escalar();
            break;

        default: //En caso de no escogerse ningun numero entre 1 y 4, mostramos un error
        cout << "Error! usa un número entre 1 y 4 para acceder a una de las funciones del programa" << endl;
        }
    }while(eleccion <= 0 || eleccion > 4); 
    //Garantizamos que se vuelva a ejecutar esta parte del codigo en caso de que no se escoja un numero entre 1 y 4

}

void mostrar_matriz(float matriz[50][50], int filas, int columnas) 
//Usamos esta funcion para mostrar la matriz 
{
    for (int i = 0; i < filas; i++){ 
        for (int j = 0; j < columnas; j++){ //Doble bucle for-loop, en el que mostramos los elementos de la matriz mientras que 'i' e 'j' sean menores al numero de filas y columnas respectivamente
            cout << matriz[i][j] << "\t"; //La barra invertida seguida de t funciona como la tecla Tab de nuestro teclado
        }
        cout << "\n"; //La barra invertida seguida de n quiere decir salto de linea 
    }

}
void matriz_escalar(){ 
//Usamos esta funcion para realizar la operacion Matriz por escalar
    float matriz[50][50]; //El valor maximo de filas y columnas soportado por nuestro programa es de 50x50
    float escalar; //Declaramos la variable del escalar, de tipo float
    cout << "Introduzca el numero escalar por el cual multiplicar la matriz" << endl; //Pedimos al usuario ingresar el valor del escalar por el que se multiplicara la matriz
    cin >> escalar; //Se lee y almacena el codigo en la variable 'escalar'

    int filas; 
    int columnas;
    //Declaramos las variables filas y columnas, de tipo int(solo numeros enteros) 

    tutorial_ejemplo(); //Mostramos el ejemplo de como se vera su matriz

    do{
       cout << "Introduzca el numero de filas de la matriz: " << endl; cin >> filas; //Pedimos el numero de filas de la matriz
       cout << "Introduzca el numero de columnas de la matriz: " << endl; cin >> columnas; //Pedimos el numero de columnas de la matriz
    }while(filas <= 0 || columnas <= 0); 
    //Bucle do-while para garantizar que el numero de columnas y filas no sea negativo ni igual a cero

    cout << "Dimension de la matriz: " << filas << "x"<< columnas <<endl; //Mostramos al usuario que su matriz consta de 'm' filas por 'n' columnas
    for (int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            //Doble bucle for-loop, para recibir los datos de la matriz mientras 'i' e 'j' no sean mayores al numero de filas y columnas
            cout << "Elemento " << "[" << i + 1 << "]" << "[" << j + 1 << "]:";
            cin >> matriz[i][j]; //Recorremos fila por fila y columna por columna para recoger los datos de la matriz
        }
        cout << "\n";
    }
    cout << "Matriz inicial: " << endl;
    mostrar_matriz(matriz, filas, columnas); //Llamamos a la funcion para que el usuario vea las matrices


    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            //Doble bucle for-loop para multiplicar el escalar por cada uno de los elementos de la matriz ingresada por el usuario
            matriz[i][j] *= escalar;
        }
    }
    cout << "\nMatriz resultado: " << endl;
    mostrar_matriz(matriz, filas, columnas); 
    //Mostramos el resultado de la matriz llamando a la funcion de nombre 'mostrar_matriz'
}

void suma(){
//Usamos esta funcion para realizar la suma entre dos matrices, que obligatoriamente tienen el mismo tamaño. Caso contario, no se podria efectuar la operacion
    float matriz[50][50]; 
    float matriz2[50][50];
    //Como una suma consta de dos elementos, declaramos dos matrices de tipo float, para almacenarlas y luego efectuar la operacion

    int filas;
    int columnas;
    //Declaramos las variables filas y columnas, de tipo int(solo numeros enteros) 

    tutorial_ejemplo(); //Mostramos el ejemplo de matriz

    do{
       cout << "Introduzca el numero de filas de las dos matrices : " << endl; cin >> filas;
       cout << "Introduzca el numero de columnas de las dos matrices: " << endl; cin >> columnas;
    }while(filas <= 0 || columnas <= 0); 
    //Bucle do-while para garantizar que el numero de columnas y filas no sea negativo ni igual a cero

    cout << "Dimension de la matriz: " << filas << "x"<< columnas << "\n" << endl; //Mostramos la dimension de la matriz
    cout << "Elementos de la primera matriz " << endl; 
    for (int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            //Usamos doble bucle for-loop para introducir la primer matriz, elemento por elemento
            cout << "Elemento " << "[" << i + 1 << "]" << "[" << j + 1 << "]:";
            cin >> matriz[i][j];
        }
        cout << "\n"; //Salto de linea
    }
    cout << "Primera matriz: " << endl;
    mostrar_matriz(matriz, filas, columnas); 
    //Mostrar la primera matriz llamando a la funcion

    cout << "\nElementos de la segunda matriz " << endl;
    for (int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            //Usamos doble bucle for-loop para introducir la segunda matriz, elemento por elemento
            cout << "Elemento " << "[" << i + 1 << "]" << "[" << j + 1 << "]:";
            cin >> matriz2[i][j];
        }
        cout << "\n";
    }
    cout << "Segunda matriz: " << endl;
    mostrar_matriz(matriz2, filas, columnas);
    //Mostrar la primera matriz llamando a la funcion

    cout << "\nMatriz resultado: " << endl;
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            //Usando de nuevo el doble for-loop, efectuamos la suma de ambas matrices. La suma solo se hace elemento por elemento
            matriz[i][j] += matriz2[i][j];
        }
    }
    mostrar_matriz(matriz, filas, columnas); //Mostramos la matriz resultante de la suma
}
void resta(){
//Usamos esta funcion para realizar la resta entre dos matrices, que obligatoriamente tienen el mismo tamaño. Caso contario, no se podria efectuar la operacion
    float matriz[50][50];
    float matriz2[50][50];
     //Como una resta consta de dos elementos, declaramos dos matrices de tipo float, para almacenarlas y luego efectuar la operacion

    int filas;
    int columnas;
    //Declaramos las variables filas y columnas, de tipo int(solo numeros enteros) 

    tutorial_ejemplo(); //Mostramos el ejemplo de matriz

    do{
       cout << "Introduzca el numero de filas de las dos matrices : " << endl; cin >> filas;
       cout << "Introduzca el numero de columnas de las dos matrices: " << endl; cin >> columnas;
    }while(filas <= 0 || columnas <= 0);
    //Bucle do-while para garantizar que el numero de columnas y filas no sea negativo ni igual a cero

    cout << "Dimension de la matriz: " << filas << "x"<< columnas << "\n" << endl; //Mostramos la dimension de la primera matriz
    cout << "Elementos de la primera matriz " << endl;
    for (int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            //Doble bucle for-loop para ingresar los elementos de la primera matriz
            cout << "Elemento " << "[" << i + 1 << "]" << "[" << j + 1 << "]:";
            cin >> matriz[i][j];
        }
        cout << "\n";
    }
    cout << "Primera matriz: " << endl;
    mostrar_matriz(matriz, filas, columnas);
    //Con la funcion, mostranos la primera matriz de la resta

    cout << "\nElementos de la segunda matriz " << endl;
    for (int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            //Doble bucle for-loop para ingresar los elementos de la segunda matriz
            cout << "Elemento " << "[" << i + 1 << "]" << "[" << j + 1 << "]:";
            cin >> matriz2[i][j];
        }
        cout << "\n";
    }
    cout << "Segunda matriz: " << endl; 
    mostrar_matriz(matriz2, filas, columnas);
    //Mostramos la segunda matriz

    cout << "\nMatriz resultado: " << endl;
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            //Doble bucle for-loop para efectuar la operacion
            matriz[i][j] -= matriz2[i][j];
        }
    }
    mostrar_matriz(matriz, filas, columnas); //Llamamos la funcion para mostrar la matriz resultado de la operacion 
}

void determinante2x2()
{
    int diagonal_principal = 1;
    int diagonal_secundaria = 1;
    //Damos un valor inicial a las diagonales: si se pusiera cero o se dejara vacio, el determinante saldria cero, sea cualquiera el numero que pongamos dentro de la matriz
    float determinante = 0;
    //Creamos la variable determinante de tipo int para 

    float matriz[50][50]; //Damos un valor maximo al numero de columnas de la matriz, que es de tipo float

    tutorial_ejemplo(); //Mostramos la matriz de ejemplo

    cout << "Dimension de la matriz: " << 2 << "x"<< 2 <<endl; //Por ahora, nuestro programa solo es capaz de calcular determinantes de 2x2, por lo tanto, mostramos al usuario la dimension
    for (int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            //Ingresamos los elementos de la matriz
            cout << "Elemento " << "[" << i + 1 << "]" << "[" << j + 1 << "]:";
            cin >> matriz[i][j];
        }
        cout << "\n"; //Salto de linea

    }
    cout << "Matriz inicial: " << endl;
    mostrar_matriz(matriz, 2, 2); //Mostramos la matriz inicial (2x2)

    for (int i = 0;  i < 2; i++){
        for (int j = 0; j < 2; j++){
            if (i == j){ //Si la fila tiene el mismo valor que la columna, se multiplica la diagonal principal por el elemento [i,j] de la matriz   
                diagonal_principal *= matriz[i][j];
            }
            if (i != j){ //Si la fila no tiene el mismo valor que la columna, se multiplica la diagonal secundaria por el elemento [i,j] de la matriz
                diagonal_secundaria *= matriz[i][j];
            }
        }
        cout << endl;

    }
    determinante = diagonal_principal - diagonal_secundaria;
    cout << "Determinante: " << determinante << endl;
    //Mostramos el determinante al usuario 
}

void tutorial_ejemplo() 
//Esta funcion describe y muestra una matriz de ejemplo de como se organizaran los elementos de la matriz
{
    cout << "\nMatriz de ejemplo para la organizacion de los elementos de la matriz" << endl;
    cout << "| a[1][1]    a[1][2]   a[1][3]   ... |" << endl;
    cout << "| a[2][1]    a[2][2]   a[2][3]   ... |" << endl;
    cout << "| a[3][1]    a[3][2]   a[3][3]   ... |" << endl;
    cout << "\n";
}
