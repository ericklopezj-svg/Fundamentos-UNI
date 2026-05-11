#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

void intercambiar (char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void MayorPosible (char* cadena) {
    for (int i = 0; i < 30 - 1; i++) {
        for (int j = 0; j < 30 - i - 1; j++) {
            if (cadena[j] < cadena[j + 1]) {
                intercambiar (cadena[j], cadena[j + 1]);
            }
        }   
    }
    cout << "El mayor numero que se puede formar con los digitos es: " << cadena << endl;
    cout << "Y su raiz cuadrada es: ";
    long double numero = strtold(cadena, nullptr);
    long double raiz = sqrt(numero);
    cout << raiz;

}

int main() {
    cout << "Ingrese un numero natural, no todos iguales: ";
    char numero[31]; //30 digitos y uno adicional para el caracter nulo
    cin.getline (numero, 31, '\n');

    MayorPosible (numero);

    return 0;  

}