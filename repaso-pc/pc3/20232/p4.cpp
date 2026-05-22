#include <iostream>
using namespace std;

int partir (int* cortes, int* precios, int n) {
    if (n <= 0) {
        return 0;
    }

    int maximo = -1;
    int corte;

    for (int j = 1; j <= n; j++) {
        int valor = precios[j - 1] + partir (cortes, precios, n - j);

        if (maximo < valor) {
            maximo = valor;    
            corte = j; 
        }
    }

    cortes[n] = corte; //para una varilla de longitud n el PRIMER MEJOR corte es cortes[n]

    return maximo;
}
//Entonces la logica seria, ir almacenando el mejor primer corte segun sea la longitud, y cuando imprimamos los cortes, si la varilla
//mide 4, iremos al arreglo en la posicion 4 y vemos el primer corte (optimo) luego
//vemos cual seria el primer corte para la longitud restante


int main() {
    //int longitud[] = {1, 2, 3, 4, 5, 6, 7, 8}; //no se usa pero sirve como formalidad
    int precio[] = {1, 5, 8, 9, 10, 17, 17, 20};

    int varilla = 8;
    cout << "Longitud  de varilla: " << varilla << endl;

    int* cortes = new int[varilla + 1]; // +1 ya que para no complicarnos guaradaremos en la posicion segun la longitud

    int beneficio = partir (cortes, precio, varilla);

    cout << "\nEl corte optimo seria: ";
    int largo = varilla;
    while (largo > 0) {
        cout << cortes[largo] << " ";

        largo -= cortes[largo];
    }

    cout << "\nEl beneficio es " << beneficio;

    delete[] cortes;

    return 0;

}