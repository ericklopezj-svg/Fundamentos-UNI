#include <iostream>
#include <fstream>
#include <string> //La necesitamos para manejar las cadenas de texto legibles

using namespace std;

int main() {
    // 1. Creamos el archivo lógico de entrada
    ifstream miArchivoLectura("alumnos.txt");

    // 2. Control de seguridad: ¿Existe el archivo?
    if (!miArchivoLectura.is_open()) {
        cout << "Error: El archivo no existe o no se puede abrir." << endl;
        return 1;
    }

    string linea;
    cout << "--- Contenido del archivo ---" << endl;

    // 3. Leemos de forma secuencial linea por linea hasta llegar al final
    while (getline(miArchivoLectura, linea)) {
        cout << linea << endl; // Mostramos cada linea en la pantalla
    }

    // 4. Cerramos el flujo de lectura
    miArchivoLectura.close();

    return 0;
}