#include <iostream>
using namespace std;

int minimo (int a, int b, int c) {
    if (a < b) {
        if (a < c) {
            return a;
        } else {
            return c;
        }
    } else {
        if (b < c) {
            return b;
        } else {
            return c;
        }
    }
}

int manzanas (int cant) {
    if (cant == 0) {
        return 0;
    }

    if (cant == 1) {
        return 1;
    }

    int opcion1 = 1 + manzanas (cant - 1);

    int opcion2 = 9999, opcion3 = 9999;

    if (cant % 2 == 0) {
        opcion2 = 1 + manzanas (cant/2);
    }

    if (cant % 3 == 0) {
        opcion3 = 1 + manzanas (cant/3);
    }

    return minimo (opcion1, opcion2, opcion3); 
    //Se pone el return, ya que manzanas llama a una funcion asistente, esta funcion tiene return lo que devolver el valor pero solo a manzanas,
    //manzanas con el valor no nos lo devuelve sino que se lo queda, es por eso la importancia del return
}

int main() {
    cout << "Ingrese la cantidad de manzanas: ";
    int n;
    cin >> n;

    int min = manzanas (n);

    cout << "El minimo numero de dias para comer " << n << " manzanas es " << min;

    return 0;

}