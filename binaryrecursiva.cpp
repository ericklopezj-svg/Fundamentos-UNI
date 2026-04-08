#include <iostream>
using namespace std;

int binariaRecursiva (int arr[], int bajo, int alto, int objetivo) {

    if (bajo > alto) { //SI ES ASI >, NPO SE CONSIDERA EL >=
        return -1; //CASO BASE, la recursion debe tener una paradinha
    }

    int medio = bajo + (alto - bajo)/2;

    if (arr[medio] == objetivo) {
        return medio;
    }

    //no queremos descascarar hasta llegar a un piso, y desde ahi regresar; queremos descartar sin regreso ES POR ESO EL RETURN
    if (arr[medio] < objetivo) {
        return binariaRecursiva (arr, medio + 1, alto, objetivo);
    } else {
        return binariaRecursiva (arr, bajo, medio - 1, objetivo);
    }

}   
