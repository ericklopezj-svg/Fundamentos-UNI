#include <iostream>
#include <cstring>
using namespace std;

void bubbleSort (char* a) {
    int tamA = strlen(a);
    for (int i = 0; i < tamA - 1; i++) {
        for (int j = 0; j < tamA - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}


int anagrama (char* c) { 
    //en una matriz dinamica, se crea espacio para un arreglo de punteros, y luego espacio hacia donde apuntara cada puntero
    //en este caso solo creamos espacio para los dos punteros y solo eso, ya que ellos ya tienen hacia donde apuntar que son los token
    char** ptr = new char* [2];
    for (int i = 0; i < 2; i++) {
        ptr[i] = nullptr;
    }

    char* token = strtok (c, " \n");
    int i = 0;
    while (token != NULL && i < 2) {
        ptr[i] = token;
        token = strtok (NULL, " \n");
        i++;
    }

    bool validar = true;
    for (int i = 0; i < 2; i++) {
        if (ptr[i] == nullptr) {
            validar = false;
            break;
        }
    }

    if (!validar) {
        cout << "Solo ingreso una palabra";
        delete[] ptr;
        return -1;
    }

    if (strlen(ptr[0]) != strlen(ptr[1])) {
        delete[] ptr;
        return 0;

    } else {
        bubbleSort (ptr[0]);
        bubbleSort (ptr[1]);

        if (strcmp(ptr[0], ptr[1]) == 0) {
            delete[] ptr;
            return 1;
        }

        delete[] ptr;
        return 0;
    }
}

int main() {
    char cadena[20];

    cout << "Ingrese las dos palabras a comparar: ";
    cin.getline(cadena, 20, '\n');

    int resultado = anagrama (cadena);

    if (resultado == -1) {
        return 0;
    }

    cout << resultado;

    return 0;


}