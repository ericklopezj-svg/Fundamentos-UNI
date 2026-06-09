#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    char bufer[100];

    ifstream miarchivo("input.txt");
    if (!miarchivo.is_open()) {
        cout << "No se pudo leer el archivo" << endl;
        return 1;
    }

    ofstream escritura("output.txt");
    if (!escritura.is_open()) {
        cout << "No se pudo leer el archivo" << endl;
        return 1;
    }

    while (miarchivo.getline(bufer, 100, '\n')) {
        for (int i = 0; i < 100; i++) {
            if (bufer[i] == '\0') {
                escritura << endl;
                break;
            }

            if (bufer[i] == ' ') { //omito lo espacios
                continue;
            }

            if (bufer[i] == 'Z') {
                escritura << 'A';
                continue;
            }
            if (bufer[i] == 'z') {
                escritura << 'a';
                continue;
            }
            if (bufer[i] == '9') {
                escritura << '0';
                continue;
            } 

            if ( (bufer[i] >= 'A' && bufer[i] < 'Z') || (bufer[i] >= 'a' && bufer[i] < 'z') || (bufer[i] >= '0' && bufer[i] < '9')) {
                bufer[i]++;
            }

            escritura << bufer[i];

        }
    }

    cout << "Modificado correctamente" << endl;

    escritura.close();
    miarchivo.close();

    return 0;
}