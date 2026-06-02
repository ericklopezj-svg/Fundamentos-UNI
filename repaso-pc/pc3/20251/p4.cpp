#include <iostream>
using namespace std;

struct Datos {
    int respuestas;
    int freq;
};


void intercambiar (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void lectura (int* &ptr, int cantidad) {
    cout << "Ingrese las respuestas (entre 1 y 5):" << endl;
    
    int k = 0, temp;
    while (k < cantidad) {
        cin >> temp;

        if (temp >= 1 && temp <= 5) {
            *(ptr + k) = temp;
            k++;
        } else {
            cout << "Fuera del limite, ingrese otra vez" << endl;
        }

    }
}

float promedio (int* ptr, int cantidad) {
    int suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += *(ptr + i);
    }

    return (1.0 * suma)/cantidad;
}

void bubbleSort (int* &ptr, int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - 1 - i; j++) {
            if (*(ptr + j) > *(ptr + j + 1)) {
                intercambiar (*(ptr + j), *(ptr + j + 1));
            }
        }
    }
}

void frecuencias (int* &ptr, int cantidad, int &moda, int &respuesta, Datos* &lista) {
    bubbleSort (ptr, cantidad);

    int max = 0;

    int inicio = 0;
    while (inicio < cantidad) {
        int contador = 0;
        for (int j = inicio; j < cantidad; j++) {
            if (*(ptr + inicio) == *(ptr + j)) {
                contador++;
            } 
        }

        int indice = *(ptr + inicio) - 1;
        (lista + indice) -> freq = contador;

        if (max < contador) {
            max = contador;
            respuesta = *(ptr + inicio);
        }

        inicio += contador;
    }

    moda = max;

    for (int i = 0; i < 5; i++) {
        cout << (lista + i) -> respuestas << ": " << (lista + i) -> freq << endl; 
    }

}


int main() {
    cout << "Ingrese la cantidad de respuestas: ";
    int cantidad;
    cin >> cantidad;

    int* ptr = new int [cantidad];

    lectura (ptr, cantidad);

    cout << "\nPromedio de satisfaccion: " << promedio (ptr, cantidad) << endl;

    int moda, numero;
    Datos* dat = new Datos [5];
    for (int i = 0; i < 5; i++) {
        (dat + i) -> respuestas = i + 1;
        (dat + i) -> freq = 0;
    }
    cout << "\nFrecuencia de respuestas: " << endl;
    frecuencias (ptr, cantidad, moda, numero, dat);
    

    cout << "\nModa: " << moda << endl;
    cout << "La respuesta que mas se repitio fue " << numero << " un total de " << moda << " veces" << endl;

    delete[] dat;
    delete[] ptr;

    return 0;

}