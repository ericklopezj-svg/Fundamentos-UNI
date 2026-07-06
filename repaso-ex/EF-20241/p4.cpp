#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream miarchivo, archivoOut;

    archivoOut.open("nombreM.txt", ios::out);
    if(!archivoOut.is_open()) {
        cout << "Error al abrir el archivo para escribir" << endl;
        return 1;
    }

    miarchivo.open("archivo1.txt", ios::in);
    if(!miarchivo.is_open()) {
        cout << "Error al abrir el archivo para leer" << endl;
        return 1;
    }

    string linea;
    while (getline(miarchivo, linea)) {
        archivoOut << linea << endl;
    }

    miarchivo.close();

    miarchivo.open("archivo2.txt", ios::in);
    if(!miarchivo.is_open()) {
        cout << "Error al abrir el archivo para leer" << endl;
        return 1;
    }

    while (getline(miarchivo, linea)) {
        archivoOut << linea << endl;
    }

    miarchivo.close();

    archivoOut.close();

    return 0;
    
}