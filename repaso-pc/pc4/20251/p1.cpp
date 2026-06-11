#include <iostream>
using namespace std;

struct Punto {
    int x;
    int y;
};

struct Conjunto {
    int t;
    Punto* array;
};

void leerConjunto (Conjunto &var) {
    cout << "Ingrese la cantidad de puntos: ";
    cin >> var.t;

    var.array = new Punto [var.t];

    cout << "Ingrese los puntos (x y):" << endl;
    for (int i = 0; i < var.t; i++) {
        cin >> ((var.array) + i)->x >> ((var.array) + i)->y;
    }

}

void mostrarConjunto (Conjunto var) {
    for (int i = 0; i < var.t; i++) {
        cout << "(" << ((var.array) + i)->x << "," << ((var.array) + i)->y << ") ";
    }
    cout << endl;
}

bool compararPuntos (Punto p1, Punto p2) {
    if (p1.x == p2.x && p1.y == p2.y) {
        return true;
    }
    return false;
}

void liberarMemoria (Punto* &ptr) {
    delete[] ptr;
    ptr = nullptr;
}

void unionConjuntos (Conjunto &c1, Conjunto &c2, Conjunto &u) {
    Punto* ptr = new Punto[c1.t + c2.t];

    for (int i = 0; i < c1.t; i++) {
        *(ptr + i) = *((c1.array) + i);
    }

    int k = c1.t;
    for (int i = 0; i < c2.t; i++) {
        bool flag = false;
        for (int j = 0; j < c1.t; j++) {
            if (compararPuntos (*(ptr + j), *((c2.array) + i))) {
                flag = true;
                break;
            }

        }
        if (!flag) {
            *(ptr + k) = *((c2.array) + i);
            k++;
        }
    }

    liberarMemoria (c1.array);
    liberarMemoria (c2.array);

    u.t = k;
    u.array = new Punto [u.t];
    for (int i = 0; i < u.t; i++) {
        *((u.array) + i) = *(ptr + i);
    }

    liberarMemoria (ptr);

}

int main() {
    cout << "Conjunto A:" << endl;
    Conjunto A;
    leerConjunto (A);

    cout << "\nConjunto B:" << endl;
    Conjunto B;
    leerConjunto (B);

    Conjunto Union;
    unionConjuntos (A, B, Union);

    cout << "\nUnion de A y B:" << endl;
    mostrarConjunto (Union);

    liberarMemoria (Union.array);

    return 0;
}