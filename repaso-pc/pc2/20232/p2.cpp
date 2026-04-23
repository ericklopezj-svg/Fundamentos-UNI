#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool comparar (char c1, char c2) {
    if (c1 == c2) {
        return true;
    }
    return false;
}

int Comparar (string str, int tam, int i, int j) {
    int k = 0;
    while (i >= 0 && j < tam && comparar(str[i], str[j])) {
        i--;
        j++;

        k++;
    }

    return k;

}

int main() {
    string cadena = "abdcbcdbdcbbc";
    int n = cadena.length();

    int maximo = 0;
    int indice, max_cont;

    for (int i = 0; i < n; i++) {

        if ( i < n - 1 && comparar (cadena[i], cadena[i + 1])) {
            int contador = Comparar (cadena, n, i - 1, i + 2);
            int longitud = 2 * (contador + 1);

            if (longitud > maximo) {
                maximo = longitud;
                indice = i;
                max_cont = contador;
            }
        } else if (i > 0 && i < n - 1) {
            int contador = Comparar (cadena, n, i - 1, i + 1);
            int longitud = 2 * contador + 1;

            if (longitud > maximo) {
                maximo = longitud;
                indice = i;
                max_cont = contador;
            }
        }

        
    }

    cout << "Entrada: ";
    cout << cadena << endl;

    cout << "\nSalida: ";

    int inicio = indice - max_cont;
    int fin = inicio + maximo - 1;

    for (int i = inicio; i <= fin; i++) {
        cout << cadena[i];
    }

    return 0;


}