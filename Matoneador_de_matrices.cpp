#include <iostream>

using namespace std;

int get_matriz(float matriz[50][50]);
void mostrar_matriz(float matriz[50][50], int filas, int columnas);
void matrizXescalar();
void suma();
void resta();
void determinante2x2();
void tutorial_ejemplo();

void titulo();
void menu();


int main(){

    titulo();
    menu();
    cout << "\nSuerte con tu examen ;)" << endl;
	return 0;
}

void titulo(){
    cout << endl;
    cout <<"     /|    //| |     // | |  /__  ___/   //   ) )     /|    / /     //   / /     // | |     //    ) )     //   ) )     //   ) )           //    ) )     //   / /           /|    //| |     // | |  /__  ___/     //   ) )       / /        //   ) )     //   / /     //   ) )" << endl;
    cout <<"    //|   // | |    //__| |    / /      //   / /     //|   / /     //____       //__| |    //    / /     //   / /     //___/ /           //    / /     //____             //|   // | |    //__| |    / /        //___/ /       / /        //           //____       ((       " << endl;
    cout <<"   // |  //  | |   / ___  |   / /      //   / /     // |  / /     / ____       / ___  |   //    / /     //   / /     / ___ (            //    / /     / ____             // |  //  | |   / ___  |   / /        / ___ (        / /        //           / ____          \\     " << endl;
    cout <<"  //  | //   | |  //    | |  / /      //   / /     //  | / /     //           //    | |  //    / /     //   / /     //   | |           //    / /     //                 //  | //   | |  //    | |  / /        //   | |       / /        //           //                 ) )  " << endl;
    cout <<" //   |//    | | //     | | / /      ((___/ /     //   |/ /     //____/ /    //     | | //____/ /     ((___/ /     //    | |          //____/ /     //____/ /          //   |//    | | //     | | / /        //    | |    __/ /___     ((____/ /    //____/ /    ((___ / /   " << endl;
}
void menu()
{
    int eleccion;
    cout << "\nEscoga la operacion que quiera realizar\n" << endl;
    cout << "1) Calcular determinante de matriz 2x2" << endl;
    cout << "2) Suma de matrices" << endl;
    cout << "3) Resta de matrices" << endl;
    cout << "4) Multiplicacion por un escalar" << endl;

    do
    {
        cout << "Introduce la operacion que quieras realizar: "; cin >> eleccion;

        switch (eleccion) {

        case 1:
            determinante2x2();
            break;

        case 2:
            suma();
            break;

        case 3:
            resta();
            break;

        case 4:
            matrizXescalar();
            break;

        default:
        cout << "Error! usa un número entre 1 y 4 para acceder a una de las funciones del programa" << endl;
        }
    }while(eleccion < 0 || eleccion > 4);

}

void mostrar_matriz(float matriz[50][50], int filas, int columnas)
{
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            cout << matriz[i][j] << "\t";
        }
        cout << "\n";
    }

}
void matrizXescalar(){
    float matriz[50][50];
    float escalar;
    cout << "Introduzca el numero escalar por el cual multiplicar la matriz" << endl;
    cin >> escalar;

    int filas;
    int columnas;

    tutorial_ejemplo();

    do{
       cout << "Introduzca el numero de filas de la matriz: " << endl; cin >> filas;
       cout << "Introduzca el numero de columnas de la matriz: " << endl; cin >> columnas;
    }while(filas < 0 || columnas < 0);

    cout << "Dimension de la matriz: " << filas << "x"<< columnas <<endl;
    for (int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            //gotoxy(j*20, 23+i);
            cout << "Elemento " << "[" << i + 1 << "]" << "[" << j + 1 << "]:";
            cin >> matriz[i][j];
        }
        cout << "\n";
    }
    cout << "Matriz inicial: " << endl;
    mostrar_matriz(matriz, filas, columnas);


    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            matriz[i][j] *= escalar;
        }
    }
    cout << "\nMatriz resultado: " << endl;
    mostrar_matriz(matriz, filas, columnas);
}

void suma(){

    float matriz[50][50];
    float matriz2[50][50];

    int filas;
    int columnas;

    tutorial_ejemplo();

    do{
       cout << "Introduzca el numero de filas de las dos matrices : " << endl; cin >> filas;
       cout << "Introduzca el numero de columnas de las dos matrices: " << endl; cin >> columnas;
    }while(filas < 0 || columnas < 0);

    cout << "Dimension de la matriz: " << filas << "x"<< columnas << "\n" << endl;
    cout << "Elementos de la primera matriz " << endl;
    for (int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cout << "Elemento " << "[" << i + 1 << "]" << "[" << j + 1 << "]:";
            cin >> matriz[i][j];
        }
        cout << "\n";
    }
    cout << "Primera matriz: " << endl;
    mostrar_matriz(matriz, filas, columnas);

    cout << "\nElementos de la segunda matriz " << endl;
    for (int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cout << "Elemento " << "[" << i + 1 << "]" << "[" << j + 1 << "]:";
            cin >> matriz2[i][j];
        }
        cout << "\n";
    }
    cout << "Segunda matriz: " << endl;
    mostrar_matriz(matriz2, filas, columnas);

    cout << "\nMatriz resultado: " << endl;
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            matriz[i][j] += matriz2[i][j];
        }
    }
    mostrar_matriz(matriz, filas, columnas);
}
void resta(){
    float matriz[50][50];
    float matriz2[50][50];

    int filas;
    int columnas;

    tutorial_ejemplo();

    do{
       cout << "Introduzca el numero de filas de las dos matrices : " << endl; cin >> filas;
       cout << "Introduzca el numero de columnas de las dos matrices: " << endl; cin >> columnas;
    }while(filas < 0 || columnas < 0);

    cout << "Dimension de la matriz: " << filas << "x"<< columnas << "\n" << endl;
    cout << "Elementos de la primera matriz " << endl;
    for (int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cout << "Elemento " << "[" << i + 1 << "]" << "[" << j + 1 << "]:";
            cin >> matriz[i][j];
        }
        cout << "\n";
    }
    cout << "Primera matriz: " << endl;
    mostrar_matriz(matriz, filas, columnas);

    cout << "\nElementos de la segunda matriz " << endl;
    for (int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cout << "Elemento " << "[" << i + 1 << "]" << "[" << j + 1 << "]:";
            cin >> matriz2[i][j];
        }
        cout << "\n";
    }
    cout << "Segunda matriz: " << endl;
    mostrar_matriz(matriz2, filas, columnas);

    cout << "\nMatriz resultado: " << endl;
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            matriz[i][j] -= matriz2[i][j];
        }
    }
    mostrar_matriz(matriz, filas, columnas);
}

void determinante2x2()
{
    int diagonal_principal = 1;
    int diagonal_secundaria = 1;
    int determinante = 0;

    float matriz[50][50];

    tutorial_ejemplo();

    cout << "Dimension de la matriz: " << 2 << "x"<< 2 <<endl;
    for (int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << "Elemento " << "[" << i + 1 << "]" << "[" << j + 1 << "]:";
            cin >> matriz[i][j];
        }
        cout << "\n";
    }
    cout << "Matriz inicial: " << endl;
    mostrar_matriz(matriz, 2, 2);

    for (int i = 0;  i < 2; i++){
        for (int j = 0; j < 2; j++){
            if (i == j){
                diagonal_principal *= matriz[i][j];
            }
            if (i != j){
                diagonal_secundaria *= matriz[i][j];
            }
        }
        cout << endl;

    }
    determinante = diagonal_principal - diagonal_secundaria;
    cout << "Determinante: " << determinante << endl;
}

void tutorial_ejemplo()
{
    cout << "\nMatriz de ejemplo para la organizacion de los elementos de la matriz" << endl;
    cout << "| a[1][1]    a[1][2]   a[1][3]   ... |" << endl;
    cout << "| a[2][1]    a[2][2]   a[2][3]   ... |" << endl;
    cout << "| a[3][1]    a[3][2]   a[3][3]   ... |" << endl;
    cout << "\n";
}
