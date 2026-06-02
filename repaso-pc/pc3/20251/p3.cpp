#include <iostream>
using namespace std;

struct Termino {
    float coeficiente;
    int exponente;
};

void inicializarPolinomio (Termino* &ptr, int cantidad) {
    ptr = new Termino [cantidad];

    for (int i = 0; i < cantidad; i++) {
        cout << "\nIngrese coeficiente y exponente del termino " << i + 1 << ":" << endl;
        cin >> (ptr + i) -> coeficiente;
        cin >> (ptr + i) -> exponente;
    }
}

void intercambiar (Termino &p1, Termino &p2) {
    Termino temp = p1;
    p1 = p2;
    p2 = temp;
}

void bubbleSort (Termino* &ptr, int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - 1 - i; j++) {
            if ((ptr + j) -> exponente < (ptr + j + 1) -> exponente) {
                intercambiar (*(ptr + j), *(ptr + j + 1));
            }
        }
    }
}


void imprimirPolinomio (Termino* ptr, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        float coef = (ptr + i) -> coeficiente;
        int exp = (ptr + i) -> exponente;

        if (exp == 0) {
            cout << coef;
        } else {
            cout << coef << "x^" << exp;
        }

        if (i + 1 < cantidad) {
            cout << " + ";
        }
    }

}

void reducirPolinomio (Termino* &ptr, int &cantidad) {
    bubbleSort (ptr, cantidad); //ordenamos, esto nos asegura que los exponente giuales queden contiguos

    int k = 0;
    for (int i = 1; i < cantidad; i++) {
        if ((ptr + k) -> exponente == (ptr + i) -> exponente) { //comparamos terminos contiguos
            (ptr + k) -> coeficiente += (ptr + i) -> coeficiente;
        } else {
            k++;
            *(ptr + k) = *(ptr + i);
        }
    }

    cantidad = k + 1;

}


void sumaPolinomios (Termino* ptr1, int cantidad1, Termino* ptr2, int cantidad2, Termino* &suma, int &cantidadSuma) {
    int exp1 = (ptr1) -> exponente;
    int exp2 = (ptr2) -> exponente;

    suma = new Termino [exp1 + exp2];

    for (int i = 0; i < cantidad1; i++) { //copiamos ambos polinomios al nuevo array
        (suma + i) -> coeficiente = (ptr1 + i) -> coeficiente;
        (suma + i) -> exponente = (ptr1 + i) -> exponente;
    }

    for (int i = 0; i < cantidad2; i++) {
        (suma + i + cantidad1) -> coeficiente = (ptr2 + i) -> coeficiente;
        (suma + i + cantidad1) -> exponente = (ptr2 + i) -> exponente;
    }

    cantidadSuma = cantidad1 + cantidad2;
    reducirPolinomio (suma, cantidadSuma); //y lo reducimos

}

void productoPolinomios (Termino* ptr1, int cantidad1, Termino* ptr2, int cantidad2, Termino* &producto, int &cantidadProducto) {
    cantidadProducto = cantidad1 * cantidad2;
    producto = new Termino [cantidadProducto]; //extendemos la dim del array, en el caso que todos los exp sean diferentes

    int k = 0;
    for (int i = 0; i < cantidad1; i++) {
        float coef1 = (ptr1 + i) -> coeficiente;
        int exp1 = (ptr1 + i) -> exponente;

        for (int j = 0; j < cantidad2; j++) {
            float coef2 = (ptr2 + j) -> coeficiente;
            int exp2 = (ptr2 + j) -> exponente;

            (producto + k) -> coeficiente = coef1 * coef2;
            (producto + k) -> exponente = exp1 + exp2;
            k++;

        }
    }

    reducirPolinomio (producto, cantidadProducto);
}

int main() {
    cout << "Ingrese el numero de terminos del primer polinomio: ";
    int cantidad1;
    cin >> cantidad1;

    Termino* polinomio1 = nullptr;
    inicializarPolinomio (polinomio1, cantidad1);


    cout << "\nIngrese el numero de terminos del segundo polinomio: ";
    int cantidad2;
    cin >> cantidad2;

    Termino* polinomio2 = nullptr;
    inicializarPolinomio (polinomio2, cantidad2);

    cout << "\nPrimer polinomio: ";
    imprimirPolinomio (polinomio1, cantidad1);

    cout << "\nSegundo polinomio: ";
    imprimirPolinomio (polinomio2, cantidad2);

    Termino* suma = nullptr;
    int cantidadSuma;
    sumaPolinomios (polinomio1, cantidad1, polinomio2, cantidad2, suma, cantidadSuma);

    Termino* producto = nullptr;
    int cantidadProducto;
    productoPolinomios (polinomio1, cantidad1, polinomio2, cantidad2, producto, cantidadProducto);

    cout << "\n\nSuma: ";
    imprimirPolinomio (suma, cantidadSuma);

    cout << "\nProducto: ";
    imprimirPolinomio (producto, cantidadProducto);

    delete[] suma;
    delete[] producto;
    delete[] polinomio1;
    delete[] polinomio2;

    return 0;

}