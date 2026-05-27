#include <iostream>
#include <iomanip>
using namespace std;

void crearMemoria (int matriz[][5], int** &ptr, int filas, int cols) {
    ptr = new int* [filas];

    for (int i = 0; i < filas; i++) {

        int contador = 0;
        for (int j = 0; j < cols; j++) {
            if (matriz[i][j] == 0) {
                contador++;
            }
        }

        if (contador == cols) {
            *(ptr + i) = nullptr;
            continue;
        }

        *(ptr + i) = new int[cols];

        for (int j = 0; j < cols; j++) {
            *(*(ptr + i) + j) = matriz[i][j];
        }

    }
}


void sumarMatrices (int** A, int** B, int** &S, int filas, int cols) {
    S = new int* [filas];

    for (int i = 0; i < filas; i++) {

        if (A[i] == nullptr) {

            if (B[i] == nullptr) {
                S[i] = nullptr;
            } else {
                S[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    S[i][j] = B[i][j];
                }
            }

        } else {

            if (B[i] == nullptr) {
                S[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    S[i][j] = B[i][j];
                }
            } else {
                S[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    S[i][j] = A[i][j] + B[i][j];
                }
            }

        }


    }


}

void imprimir (int** matrix, int filas, int cols) {
    for (int i = 0; i < filas; i++) {

        if (*(matrix + i) == nullptr) {
            for (int j = 0; j < cols; j++) {
                cout << left << setw(4) << "0";
            }
            cout << endl;
            continue;
        }

        for (int j = 0; j < cols; j++) {
            cout << left << setw(4) << *(*(matrix + i) + j);
        }
        cout << endl;
    }

}

void borrarMemoria (int** &matrix, int filas) {
    for (int i = 0; i < filas; i++) {
        delete[] matrix[i]; 
    }

    delete[] matrix;

}

int main() {
    int matrizA[][5] = {{7, 5, 4, 0, 1}, {0, 0, 0, 0, 0}, {6, 3, 9, 8, 2}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    int matrizB[][5] = {{1, 2, 3, 4, 5}, {0, 0, 0, 0, 0}, {5, 6, 7, 8, 9}, {0, 0, 0, 0, 0}, {1, 2, 3, 4, 5}};

    int filas = sizeof(matrizA) / sizeof(matrizA[0]);
    int cols = sizeof(matrizA[0]) / sizeof(matrizA[0][0]);

    int** ptrA = nullptr;
    int** ptrB = nullptr;
    crearMemoria (matrizA, ptrA, filas, cols);
    crearMemoria (matrizB, ptrB, filas, cols);

    int** suma = nullptr;
    sumarMatrices (ptrA, ptrB, suma, filas, cols);

    cout << "\nMatriz A" << endl;
    imprimir (ptrA, filas, cols);

    cout << "\nMatriz B" << endl;
    imprimir (ptrB, filas, cols);

    cout << "Matriz Suma" << endl;
    imprimir (suma, filas, cols);

    borrarMemoria (ptrA, filas);
    borrarMemoria (ptrB, filas);
    borrarMemoria (suma, filas);

    return 0;

}