#include <iostream>
#include <cstring>
using namespace std;

int comparaCadenas (char* str1, char* str2) {
    int tam1 = strlen(str1);
    int tam2 = strlen(str2);

    int tam;
    if (tam1 < tam2) {
        tam = tam2;
    } else {
        tam = tam1;
    }

    for (int i = 0; i < tam; i++) { // si una cadena es mar larga compararian caracter nulo, aqui ya la mas chica seria la menor
        if (*(str1 + i) != *(str2 + i)) {
            if (*(str1 + i) < *(str2 + i)) {
                return -1;
            } else {
                return 1;
            }
        }
    }
    //si sale del bucle es porque no retorno nada, lo que significa que las cadenas son iguales
    return 0;
}

int comparaSubcadenas (char* str1, char* str2, int longitud) {
    for (int i = 0; i < longitud; i++) {
        if (*(str1 + i) != *(str2 + i)) {
            if (*(str1 + i) < *(str2 + i)) {
                return -1;
            } else {
                return 1;
            }
        }
        
        if (*(str1 + i) == '\0') { //en caso, ambos son iguales pero as chicos que la longitud, seguiria comparando basura entonces salimos
            break;
        }
     }

     return 0;
}

int buscarPalabra (char* frase, char* palabra) {
    int t = strlen(frase);
    int longitud = strlen(palabra);

    int contador = 0;
    for (int i = 0; i < t; i++) {
        if (comparaSubcadenas (frase + i, palabra, longitud) == 0) {
            contador++;
        }
    }

    return contador;
}


int main() {
    // 1. Pruebas de comparaCadenas
    cout << "comparaCadenas abce y abdh: " << comparaCadenas((char*)"abce", (char*)"abdh") << endl;
    cout << "comparaCadenas hola y hola: " << comparaCadenas((char*)"hola", (char*)"hola") << endl;
    cout << "comparaCadenas wxyz y abc: " << comparaCadenas((char*)"wxyz", (char*)"abc") << endl;

    // 2. Pruebas de comparaSubcadenas
    cout << "comparaSubcadenas de longitud 3 de abce y abdh: " << comparaSubcadenas((char*)"abce", (char*)"abdh", 3) << endl;
    cout << "comparaSubcadenas de longitud 4 de hola y hola: " << comparaSubcadenas((char*)"hola", (char*)"hola", 4) << endl;
    cout << "comparaSubcadenas de longitud 2 de wxyz y abc: " << comparaSubcadenas((char*)"wxyz", (char*)"abc", 2) << endl;

    // 3. Prueba de buscarPalabra
    char frase[] = "El éxito es la suma de pequeños esfuerzos repetidos día tras día.";
    char palabra[] = "día";
    int veces = buscarPalabra(frase, palabra);

    cout << "En la frase: \"" << frase << "\"" << endl;
    cout << "la palabra " << palabra << " aparece " << veces << " veces" << endl;

    return 0;
}
