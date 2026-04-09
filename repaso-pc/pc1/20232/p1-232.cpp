#include <iostream>
using namespace std;

float precioVenta (float arr[], int tam, float objetivo) {

    if (objetivo >= arr[tam - 1]) {
        return arr[tam - 1];
    }

    if (objetivo <= arr[0]) {
        return arr[0];
    }

    //Busqueda Binaria Iterativa
    int bajo = 0;
    int alto = tam - 1;

    while (bajo <= alto) {
        int medio = bajo + (alto - bajo)/2;

        if (arr[medio] == objetivo) {
            return arr[medio];
        } 

        if (arr[medio] < objetivo) {
            bajo = medio + 1;

        } else {
            alto = medio - 1;

        }
    }

    return (arr[bajo] + arr[alto])/2; //el algoritmo GARANTIZA que bajo y alto son los indices anteriores y posteriores inmediatos
}


int main() {
    float A[] = {8.8, 10.1, 14.4, 16.6, 18.8, 20.5};
    int n = sizeof(A) / sizeof(A[0]);
    float p;
    
    cout << "Peso de una galleta (en gramos): ";
    cin >> p;

    float pv = precioVenta (A, n, p);
    float ps = pv / 20;
    cout << "Precio sugerido: S/ " << ps;
    
    return 0;


}