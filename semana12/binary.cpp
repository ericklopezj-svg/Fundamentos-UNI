#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    // Ejemplos de apertura correcta:

    //FORMA 1 (cualquiera de los 3 según se requiera)
    ofstream archivoSalida("datos.bin", ios::binary);
    ifstream archivoEntrada("datos.bin", ios::binary);
    fstream archivoMixto("datos.bin", ios::in | ios::out | ios::binary);

    
    //FORMA 2
    fstream archivoLogico; //creamos la variable
    archivoLogico.open ("datos.bin", ios::out | ios::binary); //abrimos el archivo solo para escribir
    if (archivoLogico.is_open()) {
        char* ptr; //SIEMPRE puntero a char, si fuese otro tipo de dato lo casteamos
        int cantidad_bytes;
        archivoLogico.write(ptr, cantidad_bytes);

        archivoLogico.close();
    }

    return 0;
}