#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip>
using namespace std;


void imprimir (int a[], int dim) {
    int tam = dim*dim;
    for (int i = 0; i < tam; i++) {
        cout << left;
        cout << setw(5) << a[i];
        if ((i + 1) % dim == 0) {
            cout << endl;
        }
    }
}

void selectionSort (int a[], int dim) {
    int tam = dim*dim;
    for (int i = 0; i < tam; i++) {
        int min = i;

        for (int j = i + 1; j < tam; j++) {
            if (a[j] < a[min]) {
                min = j;
            }     
        }

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

}

int main() {
    srand(time(NULL));

    int dim = 0;
    while (dim < 2 || dim > 8) {
        cout << "Ingrese la dimension de la matriz cuadrada (entre 2 y 8): ";
        cin >> dim;
    }

    //APLANAREMOS LA MATRIZ, ESTO ES LA TRABAJAREMOS COMO UN ARREGLO
    int tam = dim*dim;
    int A[tam];
    
    for (int i = 0; i < tam; i++) {
        A[i] = rand() % 101;
    }

    cout << "Arreglo original:" << endl;
    imprimir (A, dim);
    cout << endl;

    //ordenamos
    selectionSort (A, dim);
    cout << "Arreglo ordenado:" << endl;
    cout << endl;
    imprimir (A, dim);

    return 0;
}

