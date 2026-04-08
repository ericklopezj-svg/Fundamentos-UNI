#include <iostream>
using namespace std;

int binariaIterativa (int arr[], int tam, int objetivo) {
    int bajo = 0; //es la pared baja que limita la busqueda
    int alto = tam - 1; //es la pared superior que limita la busqueda

    while (bajo <= alto) {
        int medio = bajo + (alto - bajo)/2;

        if (arr[medio] == objetivo) {
            return medio;
        }

        if (arr[medio] < objetivo) {
            bajo = medio + 1; //movemos la pared a la derecha del medio, descartamos toda la mitad izquierda
        } else {
            alto = medio - 1; //bajamos la pared sup a antes del medio, descartamos toda la mitad derecha
        }
    }

    return -1; //en caso que salga del while porque las paredes se HAYAN CRUZADO sin encontrar al objetivo
}