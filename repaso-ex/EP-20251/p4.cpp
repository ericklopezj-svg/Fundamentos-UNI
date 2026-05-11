#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    char cadena[100] = "Hola, mundo feliz!";
    string cadenaString;

    char* token = strtok (cadena, ",.!¡;: ");
    while (token != NULL) {
        cadenaString += token;

        token = strtok (NULL, ",.!¡;: ");
    }

    cout << cadenaString << endl;
    string cadenaInvertida;
    int total = cadenaString.length();

    int j = 0;
    for (int i = total - 1; i >= 0; i--) {
        cadenaInvertida += cadenaString[i];
        j++;
    }

    cout << cadenaInvertida << endl;

    int inicio = 0, longitud = 1;
    while (inicio < total) {
        int proximoIndice = inicio + longitud;
        if (total - proximoIndice > longitud) {
            cout << cadenaInvertida.substr(inicio, longitud) << endl;
            inicio += longitud;
            longitud++;
        } else {
            longitud = total - inicio;
            cout << cadenaInvertida.substr(inicio, longitud) << endl;
            inicio += longitud;

        }
        
    }

    return 0;

}