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
        
        archivoLogico << "Annie are you ok?" << endl;

        archivoLogico.close();
    }
    
    return 0;
}