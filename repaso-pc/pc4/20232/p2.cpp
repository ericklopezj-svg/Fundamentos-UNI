#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

const float PI = 3.1416;

struct Punto {
    float x;
    float y;
};

void rotacion (float &x, float &y, float angulo) {
    angulo = (angulo * PI)/180;
    float xR = x * cos(angulo) - y * sin(angulo);
    float yR = x * sin(angulo) + y * cos(angulo);

    x = xR;
    y = yR;
}

int main() {

    ifstream archivoLectura("poligono1.txt");
    if (!archivoLectura.is_open()) {
        cout << "Error intentando abrir el archivo para leer" << endl;
        return 1;
    }

    string linea;
    int t;
    archivoLectura >> t; //como solo es un int usamos el >>, ademas que ocnvierte auto. al tipo de dato
    archivoLectura.ignore(); //limpiamos el salto de linea que dejo el >>


    Punto** ptr = new Punto* [t];
    Punto temp;
    int i = 0;
    while (archivoLectura >> temp.x >> temp.y) {
        *(ptr + i) = new Punto;
        **(ptr + i) = temp;
        i++;       
    }

    archivoLectura.close();
    cout << "Datos leidos y guardados correctamente" << endl;


    cout << "Ingrese un angulo (sexagesimal): ";
    float angulo;
    cin >> angulo;

    ofstream archivoEscritura("poligono2.txt");
    if (!archivoEscritura.is_open()) {
        cout << "Error al intentar abrir archivo para escribir" << endl;
        return 1;
    }

    archivoEscritura << t << endl;

    for (int i = 0; i < t; i++) {
        float x = (*(ptr + i))->x;
        float y = (*(ptr + i))->y;

        rotacion (x, y, angulo);

        archivoEscritura << x << " " << y << endl;
    }

    archivoEscritura.close();
    cout << "Archivo creado correctamente" << endl;

    return 0;
}