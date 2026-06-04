#include <iostream>
#include <fstream> // Librería obligatoria para usar archivos
#include <string>

using namespace std;

int main() {
    // 1. Creamos el archivo lógico y abrimos el archivo físico, los enlazamos
    ofstream miArchivo("alumnos.txt");
    //Si alumnos.txt NO existe: El programa lo va a crear automáticamente en la misma carpeta donde se ejecuta tu código.
    //Si alumnos.txt YA existe: Por defecto, el programa borra todo, y lo deja listo para escribir.


    // 2. Verificamos que el archivo se haya podido crear correctamente
    if (!miArchivo.is_open()) {
        cout << "Error: No se pudo crear o abrir el archivo." << endl;
        return 1; // Terminamos el programa si algo falló
    }

    // 3. Escribimos datos de forma secuencial (como el cout)
    miArchivo << "Carlos - Fisica Pura" << endl;
    miArchivo << "Ana - Arquitectura" << endl;

    // 4. Cerramos el archivo obligatoriamente para salvar los cambios
    miArchivo.close();

    cout << "¡Datos guardados con exito en alumnos.txt!" << endl;
    return 0;
}