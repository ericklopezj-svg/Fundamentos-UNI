#include <iostream>
using namespace std;

//colocamos const para avisarle que no vamos a cambiar el valor de n, solo es lectura, entonce me deja ponerle alias a un valor fantasma
bool primo (const int &n) {
    int contador = 0;
    for (int i = n; i >= 1; i--) {
        int p = n % i;

        if (p == 0) {
            contador++;
        }
    }

    if (contador <= 2) {
        return true;    
    } else {
        return false;
    }
}

void matriz (int a, int limite, int &orden, int p[][2]) {
    if (a == limite) {
        return;
    }

    if (primo (a) && a + 2 <= limite) {
        if (primo(a + 2)) { //y aqui esta el valor fantasma, no se puede referenciar a un a + 2 que esta flotando, para eso el const
            *(*(p + orden)) = a;
            *(*(p + orden) + 1) = a + 2;

            orden++;
        }
    }

    matriz (a + 1, limite, orden, p);
}

void imprimir (int (*ptr)[2], int n) {
    for (int i = 0; i < n; i++) {
        cout << *(*(ptr + i)) << " - " << *(*(ptr + i) + 1) << endl;
    }
}

int contar (const int &inferior, int &limite, int &contador) { //no sirve aqui, ya que esto cuenta en total, pero yo quiero contar gemelos
    if (inferior > limite) {
        return contador;
    }

    if (primo (inferior)) {
        contador++;   
    }

    return contar (inferior + 1, limite, contador);
}


int main() {
    int matrix[100][2];

    cout << "Ingrese n: ";
    int n;
    cin >> n;
    
    int limiteInferior = 3; //ya que el problema aclara entre 2 y el n
    int cantidad = 0;
    matriz (limiteInferior, n, cantidad, matrix);
    cout << "\nCantidad: " << cantidad << endl;

    cout << "\nMatriz de primos gemelos:" << endl;
    imprimir (matrix, cantidad);

    return 0;
}