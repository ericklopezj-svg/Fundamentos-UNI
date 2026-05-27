#include <iostream>
#include <cmath>
using namespace std;

struct Punto {
    int x;
    int y;
    int z;
};

struct Tiempo {
    float t;
};

float velocidadMedia (Punto* p1, Punto* p2, Tiempo* t1, Tiempo* t2) {
    int x1 = p1 -> x;
    int y1 = p1 -> y;
    int z1 = p1 -> z;
    float tiempo1 = t1 -> t;

    int x2 = p2 -> x;
    int y2 = p2 -> y;
    int z2 = p2 -> z;
    float tiempo2 = t2 -> t;

    float desplazamiento = sqrt (  pow (x1 - x2, 2) + pow (y1 - y2, 2) + pow (z1 - z2, 2)  );
    float tiempo = abs (tiempo1 - tiempo2);

    
    return 1.0*desplazamiento / tiempo;
}

int main() {
    cout << "Indique la cantidad de puntos: ";
    int cantidad;
    cin >> cantidad;

    Punto* ptr1 = new Punto [cantidad];
    Tiempo* ptr2 = new Tiempo [cantidad];

    for (int i = 0; i < cantidad; i++) {
        cout << "\nIngrese las coordenadas del punto " << i + 1 << endl;
        cout << "x: ";
        cin >> (ptr1 + i) -> x; 
        cout << "y: ";
        cin >> (ptr1 + i) -> y; 
        cout << "z: ";
        cin >> (ptr1 + i) -> z; 

        cout << "Ingrese el tiempo t" << i + 1 << ": ";
        cin >> (ptr2 + i) -> t;

        cout << endl;
    }

    for (int i = 0; i < cantidad - 1; i++) {
        cout << "\nLa velocidad media entre el punto " << i + 1 << " y el punto " << i + 2 << "es: "
        << velocidadMedia (ptr1 + i, ptr1 + (i + 1), ptr2 + i, ptr2 + (i + 1));
    }

    cout << "\nLa velocidad media total desde el primer punto hasta el ultimo punto es: "
        << velocidadMedia (ptr1, ptr1 + (cantidad - 1), ptr2, ptr2 + (cantidad - 1)) << endl;

    delete[] ptr2;
    delete[] ptr1;

    return 0;

}