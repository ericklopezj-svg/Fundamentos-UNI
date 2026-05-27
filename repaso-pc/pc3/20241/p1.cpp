#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

struct Coordenada {
    int x;
    int y;
    char vertice;
};

struct Arista {
    Coordenada c1;
    Coordenada c2;
    float distancia;
    char arista[3];
};

void inicializar (Arista &a, Coordenada* array, int orden) {
    a.c1 = *(array + orden);
    a.arista[0] = (array + orden) -> vertice;

    int k = (orden + 1) % 3;
    a.c2 = *(array + k);
    a.arista[1] = (array + k) -> vertice;

    a.arista[2] = '\0';

    a.distancia = sqrt( pow(a.c1.x - a.c2.x, 2) + pow(a.c1.y - a.c2.y, 2));

}

void informacion (Arista &a) {
    cout << "\nNombre de la arista: " << a.arista << endl;
    cout << "Coordenadas del punto " << a.c1.vertice << ": (" << a.c1.x << ", " << a.c1.y << ")" << endl;
    cout << "Coordenadas del punto " << a.c2.vertice << ": (" << a.c2.x << ", " << a.c2.y << ")" << endl;
    cout << "Distancia de la arista: " << a.distancia << endl;
}

float heron (Arista* array) {
    float s = 0;
    for (int i = 0; i < 3; i++) {
        s += (array + i) -> distancia;
    }
    s = 1.0 * s/2;

    float area = sqrt (  s * (s - (array + 0) -> distancia) * (s - (array + 1) -> distancia) * (s - (array + 2) -> distancia)  );

    return area;
}


int main() {
    Coordenada* array = new Coordenada[3];
    Arista* ptr = new Arista[3];

    for (int i = 0; i < 3; i++) {
        cout << "\nIngrese nombre de la coordenada " << i + 1 << ": ";
        cin >> (array + i) -> vertice;

        cout << "Ingrese valor de x de coordenada " << i + 1 << ": ";
        cin >> (array + i) -> x;

        cout << "Ingrese valor de y de coordenada " << i + 1 << ": ";
        cin >> (array + i) -> y;
    }

    for (int i = 0; i < 3; i++) {
        inicializar (*(ptr + i), array, i);
    }

    cout << "-------------------------------" << endl;

    for (int i = 0; i < 3; i++) {
        informacion (*(ptr + i));
        cout << "---------------------" << endl;
    }

    cout << "\nEl area del triangulo formado de las 3 aristas es: " << heron (ptr);

    delete[] array;
    delete[] ptr;

    return 0;

}