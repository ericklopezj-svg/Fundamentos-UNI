#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;


void permutar (int** ptr) {
    for (int j = 0; j < 9; j++) {

        for (int i = 0; i < 9; i++) {
            *(*(ptr + j) + i) = i + 1;
        }

        for (int i = 0; i < 9; i++) {
            int ind = rand() % 9;

            int temp = *(*(ptr + j) + i);
            *(*(ptr + j) + i) = *(*(ptr + j) + ind);
            *(*(ptr + j) + ind) = temp;
        
        }
    }
}

void imprimir (int** ptr) {
    for (int j = 0; j < 9; j++) {
        for (int i = 0; i < 9; i++) {
            cout << left << setw(3) << *(*(ptr + j) + i);
        }
        cout << endl;
    }
}

void desplazar (int &n, int** ptr, int &columna) {
    for (int i = 0; i < 9; i++) {
        
        int indice;
        for (int j = 0; j < 9; j++) {
            if (*(*(ptr + i) + j) == n) {
                indice = j;
                break;
            }
        }
        int desplazamiento = columna - indice;

        int temp[9];
        for (int j = 0; j < 9; j++) {
            *(temp + j) = *(*(ptr + i) + j);
        }

        for (int j = 0; j < 9; j++) {
            int posicionfinal = j + desplazamiento;

            if (posicionfinal < 0) {
                posicionfinal = 9 + posicionfinal; //9 ya que es la longitud de la fila
            } else {
                posicionfinal = posicionfinal % 9; //lo mismo, 9 por la longitud de la fila
            }

            *(*(ptr + i) + posicionfinal) = *(temp + j);
            
        }

    }
}


int main() {
    srand(time(NULL));

    //ASIGNAMOS
    int** ptr = new int* [9];

    for (int i = 0; i < 9; i++) {
        *(ptr + i) = new int [9];
    }

    permutar (ptr);

    cout << "Tablero Inicial:" << endl;
    cout << endl;
    imprimir (ptr);


    int fila, columna;
    do {
        cout << "\nFila inicial (1-9): ";
        cin >> fila;
        cout <<"Columna inicial (1-9): ";
        cin >> columna;

    } while ((fila < 1 || fila > 9) || (columna > 9 || columna < 1));

    int indiceFila = fila - 1, indiceColumna = columna - 1, valorEncontrado = *(*(ptr + indiceFila) + indiceColumna);

    cout << "Valor seleccionado: " << valorEncontrado << endl;

    desplazar (valorEncontrado, ptr, indiceColumna);

    cout << "\nTablero Final:" << endl;
    cout << endl;
    imprimir (ptr);


    //BORRAMOS
    for (int i = 0; i < 9; i++) {
        delete[] *(ptr + i);
    } 

    delete[] ptr;

    return 0;
}