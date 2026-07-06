#include <iostream>
using namespace std;


int** registro = nullptr;
int n = 0;


void redimensionar () {
    int** temp = new int*[n + 1];
    for (int i = 0; i < n + 1; i++) {
        temp[i] = new int[3];
    }

    for (int i = 0; i < n; i++) {
        temp[i][0] = registro[i][0];
        temp[i][1] = registro[i][1];
        temp[i][2] = registro[i][2];
    }

    for (int i = 0; i < n; i++) {
        delete registro[i];
    }

    delete[] registro;
    registro = temp;

}


void imprimirRegistro () {
    for (int i = 0; i < n; i++) {
        cout << "Estudiante " << i + 1 << ":\n";
        cout << "Nota 1: " << registro[i][0] << ", Nota 2: " << registro[i][1] << ", Promedio: " << registro[i][2] << endl;
    }

}



int main() {
    registro = new int*[n];
    for (int i = 0; i < n; i++) {
        registro[i] = new int[3];
    }


    int nota;
    int i = 0;
    while (nota != -1) {
        cout << "\nEstudiante " << i + 1 << ":" << endl;
        cout << "Ingrese primera nota: ";
        cin >> nota;

        if (nota == -1) {
            continue;
        }

        redimensionar();
        registro[i][0] = nota;

        cout << "Ingrese segunda nota: ";
        cin >> nota;

        if (nota == -1) {
            continue;
        }

        registro[i][1] = nota;

        registro[i][2] = (registro[i][0] + registro[i][1]) / 2;

        i++;
        n++;

    }

    cout << endl << "=======REGISTRO=======" << endl;
    imprimirRegistro();

    for (int i = 0; i < n; i++) {
        delete registro[i];
    }
    delete[] registro;

    return 0;

}