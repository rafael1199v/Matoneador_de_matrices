#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> hola = {};
void titulo();
void menu();

int main(){
    titulo();
    menu();


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
    cout << "Introduce la operacion que quieras realizar: "; cin >> eleccion;
}
