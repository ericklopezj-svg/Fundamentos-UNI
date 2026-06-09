#include <iostream>
#include <fstream>
#include <string>
#include <cstring> //para el strlen, linea 19
using namespace std;

struct Empleado {
    int id;
    char nombre[20];
    float salario;
};
//En archivos binarios, lo más sano y fácil es que todos los empleados midan exactamente 
//lo mismo en el disco. Así puedes usar la fórmula posicion * sizeof(Empleado) para saltar con el cursor.

template <typename T>
void escribir (fstream &archivo, T &dato) {
    archivo.write ((char*)&dato, sizeof(T));
}

template <typename T>
void leer (fstream &archivo, T &dato) {
    archivo.read ((char*)&dato, sizeof(T));
}

//SOLO PORQUE nombre[20] es ESTATICO, el compilador hara sizeof(char[20]) y esto seria 20

void escribirArchivo (fstream &archivo, Empleado &s1) {
    escribir (archivo, s1.id);
    escribir (archivo, s1.nombre);
    escribir (archivo, s1.salario);
}

void leerArchivo (fstream &archivo, Empleado &s1) {
    leer (archivo, s1.id);
    leer (archivo, s1.nombre);
    leer (archivo, s1.salario);
}

void buscar (string nombreArchivo, float min, float max) {

    fstream archivo(nombreArchivo, ios::in | ios::binary);
    if (archivo.is_open()) {
        int t = sizeof(int) + sizeof(char) * 20;
        
        for (int i = 0; i < 8; i++) {
            archivo.seekg (sizeof(Empleado) * i + t); //se ubica delante del salario

            float salario;
            leer (archivo, salario);

            if (salario >= min && salario <= max) {
                Empleado emp;
                archivo.seekg (- sizeof(Empleado), ios::cur); //desde la posicion actual
                leerArchivo (archivo, emp);

                cout << "ID: " << emp.id << ", Nombre: " << emp.nombre << ", Salario: $" << emp.salario << endl;
            }
        }



    } else {
        cout << "Error al abrir el archivo para buscar" << endl;
    }
}


int main() {
    Empleado emp;
    fstream archivoBin;

    archivoBin.open("empleados.bin", ios::out | ios::binary);

    if (archivoBin.is_open()) {
        cout << "Introduzca los datos de los empleados:" << endl;
        for (int i = 0; i < 8; i++) {
            cout << "\nID: ";
            cin >> emp.id;
            cin.ignore();

            cout << "Nombre: ";
            cin.getline (emp.nombre, 20, '\n');

            cout << "Salario: ";
            cin >> emp.salario;
            cin.ignore();

            escribirArchivo (archivoBin, emp);
            
        }
        cout << "Agregados con exito." << endl;
        archivoBin.close();
    }

    float salarioMin, salarioMax;
    cout << "Ingrese el salario minimo: $";
    cin >> salarioMin;
    cout << "Ingrese el salario maximo: $";
    cin >> salarioMax;

    cout << "Informacion de los empleados en el rango de salarios: $" << salarioMin << " - $" << salarioMax << endl;
    buscar ("empleados.bin", salarioMin, salarioMax);


    return 0;

}