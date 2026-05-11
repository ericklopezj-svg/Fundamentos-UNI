#include <iostream>
#include <iomanip>
using namespace std;

void created (int** &ptr, const int &n) {
    ptr = new int* [n];
    for (int i = 0; i < n; i++) {
        ptr[i] = new int [n];
    }

}

void deleted (int** &ptr, const int & n) {
    for (int i = 0; i < n; i++) {
        delete[] ptr[i];
    }

    delete[] ptr;
}

void input (int** ptr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nFila " << i + 1 << endl;
        for (int j = 0; j < n; j++) {
            cin >> ptr[i][j];
        }
    }
}

void output (int** ptr, int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << left << setw(4) << ptr[i][j];
        }
        cout << endl;
    }
}


int selection (int** ptr, int n) {
    int contador, maximo = 0;
    int filaMaxima;
    for (int i = 0; i < n; i++) {
        contador = 0;
        for (int j = 0; j < n; j++) {
            if (ptr[i][j] == 0) {
                contador++;
            }
        }

        if (maximo < contador) {
            maximo = contador;
            filaMaxima = i;
        }
    }

    if (maximo == n) {
        return -1;
    } else {
        return filaMaxima;
    }
    
}

int determinante (int** ptr, int n) {
    if (n == 1) { //CASO BASE
        return **ptr;
    }

    int flag = selection (ptr, n);
    if (flag == -1) {
        return 0; //determinante nulo
    }

    int** temp;
    created (temp, n - 1); //creo espacio para mi submatriz 

    int suma = 0, ix, jx;
    for (int j = 0; j < n; j++) { //recorre la fila FLAG seleccionada
        ix = 0;
        for (int f = 0; f < n; f++) {
            if (f != flag) {
                jx = 0;
                for (int c = 0; c < n; c++) {
                    if (c != j) {
                        temp[ix][jx] = ptr[f][c];
                        jx++;
                    }
                }
                ix++;
            }    
        }
        int sgnCofactor = flag + j;
        if (sgnCofactor % 2 == 0) {
            sgnCofactor = 1;
        } else {
            sgnCofactor = -1;
        }
        suma += sgnCofactor * ptr[flag][j] * determinante (temp, n - 1);
        
    }

    deleted (temp, n - 1);

    return suma;

}

int main() {
    int n;
    
    do {
        cout << "Ingrese el tamaño (maximo 10): ";
        cin >> n;
    } while (n > 10);

    int** filas = nullptr;
    created (filas, n);

    cout << "Ingrese los elementos de la matriz:" << endl;
    input (filas, n);

    output (filas, n);

    int det = determinante (filas, n);

    cout << "Determinante = " << det;

    deleted (filas, n);

    return 0;

}