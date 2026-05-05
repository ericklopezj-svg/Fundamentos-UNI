#include <iostream>
using namespace std;

void imprimir (int** ptr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << *(*(ptr + i) + j);
        }
        cout << endl;
    }
}

void explorar (int** ptr, int iActual, int jActual, int n, int m) {
    if (iActual < 0 || iActual >= n || jActual < 0 || jActual >= m || ptr[iActual][jActual] == 1) { //CASO BASE
        return;
    }

    ptr[iActual][jActual] = 1;

    explorar (ptr, iActual - 1, jActual, n, m);
    explorar (ptr, iActual + 1, jActual, n, m);
    explorar (ptr, iActual, jActual - 1, n, m);
    explorar (ptr, iActual, jActual + 1, n, m);
}

int recorrido (int** ptr, int n, int m) {
    int zonas = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ptr[i][j] == 0) {
                zonas++;
                explorar (ptr, i, j, n, m); 
            }
        }
    }

    return zonas;
}

int main() {
    cout << "Ingrese el numero de filas: ";
    int filas;
    cin >> filas;
    cout << "Ingrese el numero de columnas: ";
    int columnas;
    cin >> columnas;
    
    int** matrix = new int* [filas];
    for (int i = 0; i < filas; i++) {
        matrix[i] = new int[columnas];
    }

    cout << "Ingrese los valores del mapa:" << endl;
    for (int i = 0; i < filas; i++) {
        cout << "Fila " << i + 1;
        for (int j = 0; j < columnas; j++) {
            cin >> *(*(matrix + i) + j);
        }
        cout << endl;
    }

    imprimir (matrix, filas, columnas); 

    int zonasTotales = recorrido (matrix, filas, columnas);

    imprimir (matrix, filas, columnas);

    cout << "Numero de regiones transitables conectadas: " << zonasTotales;
    
    for (int i = 0; i < filas; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;

}