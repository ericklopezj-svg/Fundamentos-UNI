#include <iostream>
#include <fstream>
#include <string> //IMPORTANTE, nunca esta demás

using namespace std;

int main() {
    //FORMA 1: CREAMOS EL OBJETO E INMEDIATAMENTE INTENTAMOS ABRIR
    //Abrimos para Leer y Escribir, pero empezando desde el final (ate)
    fstream miArchivo("datos.txt", ios::in | ios::out | ios::ate);


    //FORMA 2: DECLARAMOS Y LUEGO DECIDIMOS CUANDO ABRIRLO
    // Creamos el objeto fstream
    fstream miArchivo;
    // Lo abrimos combinando: Leer (in) Y TAMBIÉN Escribir (out)
    miArchivo.open("datos.txt", ios::in | ios::out);


    fstream archivoBinario;
    // Abrimos para: Escribir (out) Y TAMBIÉN en modo Binario (binary)
    archivoBinario.open("datos.dat", ios::out | ios::binary);


    if (miArchivo.is_open()) {
        

        miArchivo.close();
    }
    return 0;
}

