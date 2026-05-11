#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <time.h>
using namespace std;

int sum2DArray (int* arr, int rows, int cols) {
    int suma = 0;
    for (int i = 0; i < rows * cols; i++) {
        suma += *(arr + i);
        
    }
    return suma;
}

double average2DArray (int* arr, int rows, int cols) {
    int sumatotal = sum2DArray (arr, rows, cols);

    return 1.0 * sumatotal / (rows * cols);
}

int findMax (int* arr, int rows, int cols) {
    int maximo = 0, indice;
    for (int i = 0; i < rows * cols; i++) {
        if (maximo < *(arr + i)) {
            maximo = *(arr + i);
            indice = i;
        }
    }

    return indice;
}

int findMin (int* arr, int rows, int cols) {
    int minimo = 1000, indice;
    for (int i = 0; i < rows * cols; i++) {
        if (minimo > *(arr + i)) {
            minimo = *(arr + i);
            indice = i;
        }
    }

    return indice;
}

int sumRow (int* arr, int row, int cols) {
    int suma = 0;
    for (int i = row * cols; i < (row + 1) * cols; i++) {
        suma += *(arr + i);
    }
    return suma;
}

int sumMainDiagonal (int* arr, int size) {
    int col = sqrt(size), suma = 0;
    for (int i = 0; i <= size; i += (col + 1)) {
        suma += *(arr + i);
    }

    return suma;
}

int main() {
    srand(time(NULL));
    int n = rand() % 8 + 3;
    int matrix[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(*(matrix + i) + j) = rand() % 9 + 1;
            cout << left << setw(4) << *(*(matrix + i) + j);
        }
        cout << endl;
    }

    cout << "\nSuma total de elementos del arreglo: " << sum2DArray (&matrix[0][0], n, n);
    cout << "\nPromedio de los elementos del arreglo: " << average2DArray (&matrix[0][0], n, n);
    int indice = findMax (&matrix[0][0], n, n);
    cout << "\nValor maximo enocntrado en el arreglo: " << *((*(matrix + 0) + 0) + indice);
    indice = findMin (&matrix[0][0], n, n);
    cout << "\nValor minimo encontrado en el arreglo: " << *((*(matrix + 0) + 0) + indice);
    int fila = rand() % n;
    cout << "\nSuma de los elementos de la fila " << fila << ": " << sumRow ((*(matrix + 0) + 0), fila, n);
    cout << "\nSuma de lo elementos en la diagonal principal del arreglo: " << sumMainDiagonal ((*(matrix + 0) + 0), n * n);

    return 0;   
}