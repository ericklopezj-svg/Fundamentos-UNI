#include <iostream>
#include <cstring>
using namespace std;

void ajustar (char* texto, char** parrafo, int filas, int ancho) {
    int k = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < ancho; j++) {
            
            if (*(texto + k) == '\n') { //no copiamos los saltos de linea, sino lo SIMULAMOS. copiarlo alteraria nuestro ajuste
                *(*(parrafo + i) + j) = ' ';
                
                // Si ya es la última columna de esta fila, en la siguiente iteración pasamos al siguiente carácter
                if (j == ancho - 1) {
                    k++; 
                }
                continue;
            }

            if (*(texto + k) == '\0') { //SOLO SIRVE PARA EL FINAL ABSOLUTO DEL TEXTO ORIGINAL
                *(*(parrafo + i) + j) = ' ';
                continue;
            }

            *(*(parrafo + i) + j) = *(texto + k); //caracter normal
            k++;            
            
        }
        *(*(parrafo + i) + ancho) = '\0';

    }
}



int main() {
    char texto[] = "La Universidad Nacional de Ingenieria,\n"
                    "es una institucion educativa la cual fue fundada en 1876\n"
                    "por el ingeniero polaco Eduardo de Habich.";

    cout << "Ingrese el ancho de la matriz: ";
    int ancho;
    cin >> ancho;

    int tamanio = strlen(texto);
    int filas = (tamanio + ancho - 1)/ancho;
    

    char** parrafo = new char* [filas];
    for (int i = 0; i < filas; i++) {
        parrafo[i] = new char[ancho + 1]; //para el caracter nulo
    }           

    ajustar (texto, parrafo, filas, ancho);

    for (int i = 0; i < filas; i++) {
        cout << *(parrafo + i) << endl;
    }
    

    return 0;


}