#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

void redondear (float &num) {
    num = (int)(num + 0.5);
}

int hallarY (int x, float a, float b) {
    float y = sqrt ( pow(b, 2) * (1 - (1.0 * pow(x, 2))/pow(a, 2)) );
    redondear (y);

    return y;
}

float ecuacion (int x, int y, int a, int b) {
    float eq = (1.0 * pow (x, 2))/pow(b, 2) + (1.0 * pow (y, 2))/pow(a, 2);

    return eq;
}

int main() {
    cout << "Ingrese el diametro mayor del ovalo: ";
    int diametro;
    cin >> diametro;

    float a = (1.0 * diametro)/2;
    float b = a;

   
    int ala = 2 * b; 
    int ancho = 2 * ala + 1; //+1 por el centro

    ofstream archivo ("grafico_cuadro_ovalo.txt");

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    //iniciar el cuadro
    for (int i = 0; i < ancho; i++) {
        archivo << "*";
    }
    archivo << endl;

    //MITAD DE ARRIBA
    for (int i = a; i >= -a; i--) {
        for (int j = -ala; j <= ala; j++) {
            

            if (j == -ala || j == ala) {
                archivo << "*";
                continue;
            } 

            float valor = ecuacion (j, i, a, b);

            if (valor >= 0.9 && valor <= 1.1) {
                archivo << "*";
            } else {
                archivo << " ";
            }
        }
        archivo << endl;
    }

    
    //cerrar el cuadro
    for (int i = 0; i < ancho; i++) {
        archivo << "*";
    }

    archivo << endl;

    archivo.close();

    ifstream archivolectura("grafico_cuadro_ovalo.txt");
    if (!archivolectura.is_open()) {
        cout << "No se pudo abrir el archivo para leer" << endl;
        return 1;
    }

    string linea;
    while (getline(archivolectura, linea)) {
        cout << linea << endl;
    }

    archivolectura.close();

    return 0;
    
}