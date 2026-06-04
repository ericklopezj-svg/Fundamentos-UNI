#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Abrimos el archivo pasándole un segundo parámetro: ios::app (Append / Añadir)
    ofstream miArchivoApendice("alumnos.txt", ios::app);

    if (miArchivoApendice.is_open()) {
        // Esta línea se agregará justo debajo de la última línea existente
        miArchivoApendice << "Luis - Ingenieria Industrial" << endl;
        
        miArchivoApendice.close();
        cout << "Nuevo alumno agregado sin borrar los anteriores." << endl;
    } else {
        cout << "Error al intentar abrir el archivo." << endl;
    }

    return 0;
}