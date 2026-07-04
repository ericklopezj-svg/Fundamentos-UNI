#include <iostream>
#include <iomanip>
using namespace std;

int contadorCeros (float* fila, int m) {
    int contador = 0;
    for (int i = 0; i < m; i++) {
        if (fila[i] == 0) {
            contador++;
        }
    }

    return contador;

}


void ordenarFilas (float** &matrix, int n, int m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (contadorCeros(*(matrix + i), m) > contadorCeros(*(matrix + i + 1), m)) {
                float* temp = *(matrix + i);
                *(matrix + i) = *(matrix + i + 1);
                *(matrix + i + 1) = temp;
            }
        }
    }
}


int pivote(float* fila, int m) {
    for (int i = 0; i < m; i++) {
        if (fila[i] != 0) {
            return i;
        }
    }

    return -1; //la fila es nula
}


void elminacionGaussiana (float** &matrix, int n, int m) {
    for (int i = 0; i < n; i++) { //creo que deberia de terminar en n - 2, o sea < n - 1
        int columnaPivote = pivote(*(matrix + i), m);

        if (columnaPivote == -1) {
            continue;
        }

        int pivote = *(*(matrix + i) + columnaPivote);
        for (int j = i + 1; j < n; j++) {
            float temp = *(*(matrix + j) + columnaPivote); //elemento debajo del pivote

            if (temp == 0) {
                continue;
            }

            float factor = temp / pivote;
            for (int k = columnaPivote; k < m; k++) { //operamos a toda la fila actual, desde Pivote ya que a la izquierda de este ya son 0
                matrix[j][k] -= matrix[i][k] * factor;
            }

        }

    }

    ordenarFilas(matrix, n, m);
    
}

int rangoMatrix (float** matrix, int n, int m) {
    int filasNoNulas = 0;
    for (int i = 0; i < n; i++) {
        if (contadorCeros(*(matrix + i), m) != m) {
            filasNoNulas++;
        }
    }

    return filasNoNulas;

}


void lecturaMatrix (float** &matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> *(*(matrix + i) + j);
        }
    }

}

void imprimirMatrix (float** matrix, int n, int m) {
    cout << left << fixed << setprecision(2);
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            cout << setw(8) << *(*(matrix + i) + j);
        }
        cout << endl;
    }

}


int main() {
    cout << "Ingrese numero de filas y columnas: ";
    int n, m;
    cin >> n >> m;


    float** matrix = new float*[n];
    for (int i = 0; i < n; i++) {
        *(matrix + i) = new float[m];
    }
    cout << "\nIngrese la matriz:" << endl;
    lecturaMatrix(matrix, n, m);

    elminacionGaussiana(matrix, n, m);

    cout << "\nMatriz en forma escalonada:" << endl;
    imprimirMatrix(matrix, n, m);

    cout << "\nRango de la matriz: " << rangoMatrix(matrix, n, m);

    return 0;

    
}