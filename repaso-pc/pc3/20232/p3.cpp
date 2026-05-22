#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Campo {
    int matrix[2][2];
    int suma;
};

void inicializarCampo (Campo &c1) {
    int suma = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c1.matrix[i][j] = rand() % 5 + 1;
            suma += c1.matrix[i][j];
        }
    }

    c1.suma = suma;
}

void imprimirMatriz (Campo*** table, int filas, int cols) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {

            cout << "Matriz A[" << i << "][" << j << "] (suma = " << (**(*(table + i) + j)).suma << ")" << 
            "Direccion de memeoria de B: " << *(*(table + i) + j) << endl;


            //OPCION 1
            for (int k = 0; k < 4; k++) { //ya que en Campo es un array estatico, en memoria se guarda linealmente
                int* ptrlineal = *( (*(*(table + i) + j)) -> matrix );
                cout << "B[" << k/2 << "][" << k % 2 << "] = " << *(ptrlineal + k) << "  ";
            }
            cout << "\n";

            //OPCION 2
            /*for (int l = 0; l < 2; l++) {
                for (int m = 0; m < 2; m++) {
                    cout << "B[" << l << "][" << m << "] = " << (*(*(table + i) + j)) -> matrix[l][m];
                }
                cout << endl;
            }*/

            
        }
    }
}

void mayorSuma (Campo*** table, int filas, int cols) {
    int maximo = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            int valor = (*(*(table + i) + j)) -> suma; 

            if (maximo < valor) {
                maximo = valor;
            }
        }
    }

    cout << "\nLa mayor suma de elementos de B es " << maximo << ", y se encuentra en:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            int valor = (*(*(table + i) + j)) -> suma; 

            if (valor == maximo) {
                cout << "Matriz A[" << i << "][" << j << "]. Valor de suma = " << valor << ". Direccion de memoria de B: " 
                << (*(*(table + i) + j)) -> matrix;
            }
        }
    }

}

int main() {
    srand(time(NULL));

    cout << "Numero de filas de A: ";
    int filas;
    cin >> filas;

    cout << "Numero de columnas de A: ";
    int cols;
    cin >> cols;

    Campo*** ptr = new Campo** [filas];
    for (int i = 0; i < filas; i++) {
        ptr[i] = new Campo* [cols];
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            ptr[i][j] = new Campo();
            inicializarCampo (*(ptr[i][j]));
        }
    }

    imprimirMatriz (ptr, filas, cols);
    mayorSuma (ptr, filas, cols);

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            delete ptr[i][j];
        }

        delete[] ptr[i];
    }

    delete[] ptr;

    return 0;

}