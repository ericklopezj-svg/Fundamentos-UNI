#include <iostream>
using namespace std;

void subarreglo (int indice, int *a, int *arr) {
    if (a[indice] == -1) {
        cout << arr[indice] << " ";
        return;
    }

    subarreglo (a[indice], a, arr);
    cout << arr[indice] << " ";
}

int main() {
    int a[] = {1, 3, 5, 2, 3, 4, 9, 3, 6, 3, 6};
    int n = sizeof(a)/sizeof(a[0]);

    int temp[n];
    int origen[n]; //en la posicion i pondremos la posicion con la que conecta
    for (int i = 0; i < n; i++) {
        *(temp + i) = 1; //cada elemento ya forma un subarreglo de longitud uno, cuando se una a otro es cuando sumaremos
        *(origen + i) = -1; //para que cuando llegue al inicio del subarreglo, este conecte con la posicion-1 y saber que este es el inicio
    }

    //la idea es ir uniendo a los subarreglos ya formados por todos los numeros anteriores a la posicion actual i
    for (int i = 1; i < n; i++) {
    
        for (int j = 0; j < i; j++) {
            if ( *(a + i) > *(a + j)) {

                if (*(temp + i) < *(temp + j) + 1) { //esto decide unirse solo a la cadena mas larga, esto se entiende con el jpg
                    *(temp + i) = *(temp + j) + 1;
                    *(origen + i) = j; //esto es para edjar rastros de con que subarreglo de cierta posicion acaba de unirse
                }
            }
        }
    }

    int max = temp[0];
    int indice;
    for (int i = 1; i < n; i++) {
        if ( *(temp + i) > max) {
            max = *(temp + i);
            indice = i;
        }
    }

    subarreglo (indice, origen, a); //la recursividad fue mi idea

    return 0;
}