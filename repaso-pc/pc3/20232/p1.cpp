#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

void copiar (int* &arr, int* &newArr, int index) {
    for (int i = 0; i < index; i++) {
        *(newArr + i) = *(arr + i);
    }
}

int lectura (bool* arr, int limite) {
    int ind, contador = 0;
    do {
        cin >> ind;
        if (ind == -1) {
            return contador;
        }

        if (ind < limite && ind >= 0) {
            if (!arr[ind]) { // Solo si no estaba marcada ya
                arr[ind] = true;
                contador++;
            }
        } else {
            cout << "Fila incorrecta, vuelva a ingresar";
        }

    } while (true);

}

void eliminarFilas (int** &matrix, bool* filas, int rows, int** &submatrix, int cols){
    int j = 0;
    for (int i = 0; i < rows; i++) {
        if (!filas[i]) {
            copiar (matrix[i], submatrix[j], cols);
            j++;
        }
    }
}

void eliminarColumnas (int** &matrix, bool* columnas, int rows, int** &submatrix, int cols){
    for (int i = 0; i < rows; i++) {
        int k = 0;
        for (int j = 0; j < cols; j++) {
            if (!columnas[j]) {
                *(*(submatrix + i) + k) = *(*(matrix + i) + j);
                k++;
            }
        }
    }
}

void crear (int** &matrix, int rows, int cols) {
    matrix = new int* [rows];

    for (int j = 0; j < rows; j++) {
        matrix[j] = new int [cols];
    }
}

void destruir (int** &matrix, int rows) {
    for (int j = 0; j < rows; j++) {
        delete matrix[j];
        matrix[j] = nullptr;
    }

    delete[] matrix;
    matrix = nullptr;
}

void inicializar (int** &matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(*(matrix + i) + j) = rand() % 9 + 1;
        }
    }
}

void imprimir (int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << left << setw(4) << *(*(matrix + i) + j);
        }
        cout << endl;
    }
}

int main() {
    srand(time(NULL));
    
    cout << "Ingrese el numero de filas: ";
    int filas;
    cin >> filas;

    

    cout << "Ingrese el numero de columnas: ";
    int columnas;
    cin >> columnas;
    
    int** matrix = nullptr;
    crear (matrix, filas, columnas);
    inicializar (matrix, filas, columnas);
    cout << "\nMatriz original:" << endl;
    imprimir (matrix, filas, columnas);


    bool* Filas = new bool[10];
    bool* Cols = new bool[10];

    cout << "Ingrese las filas a eliminar (o -1 para terminar):" << endl;
    int filasEliminadas = lectura (Filas, filas);
    int nuevasFilas = filas - filasEliminadas;

    int** submatrix = nullptr;
    crear (submatrix, nuevasFilas, columnas);
    eliminarFilas (matrix, Filas, filas, submatrix, columnas);

    cout << "Ingrese las columnas a eliminar (o -1 para terminar):" << endl;
    int eliminados = lectura (Cols, columnas);
    int nuevasCols = columnas - eliminados;

    int** newSubmatrix = nullptr;
    crear (newSubmatrix, nuevasFilas, nuevasCols);
    eliminarColumnas (submatrix, Cols, nuevasFilas, newSubmatrix, columnas);

    cout << "\nMatriz final:" << endl;
    imprimir (newSubmatrix, nuevasFilas, nuevasCols);

    destruir (newSubmatrix, nuevasFilas);
    destruir (submatrix, nuevasFilas);
    destruir (matrix, filas);

    delete[] Filas;
    delete[] Cols;

    return 0;    


}