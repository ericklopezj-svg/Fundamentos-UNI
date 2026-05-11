#include <iostream>
#include <string>
using namespace std;

const int MAX_FILAS = 10, MAX_COLUMNAS = 10;

template <typename T>
void intercambiar (T &s1, T &s2) {
    T temp = s1;
    s1 = s2;
    s2 = temp;
}

void BubbleSort (string* lista, int* fila, int* columna, int* dirI, int* dirJ, int contador) {
    for (int i = 0; i < contador - 1; i++) {
        for (int j = 0; j < contador - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                intercambiar (lista[j], lista[j + 1]);
                intercambiar (fila[j], fila[j + 1]);
                intercambiar (columna[j], columna[j + 1]);
                intercambiar (dirI[j], dirI[j + 1]);
                intercambiar (dirJ[j], dirJ[j + 1]); 
            }
        }
    }
}


int buscarPalabra (string* lista, int contador, string palabra) {
    int inicio = 0;
    int final = contador - 1;

    while (inicio <= final) {
        int medio = inicio + (final - inicio)/2;

        if (lista[medio] == palabra) {
            return medio;
        }

        if (lista[medio] > palabra) {
            final = medio - 1;
        } else {
            inicio = medio + 1;
        }
    }

    return -1; //palabra no encontrada
}

void extraerPalabras (char tablero[MAX_FILAS][MAX_COLUMNAS], int longitud, string* lista, int* fila, int* columna, int* dirI, 
    int* dirJ, int &contador) {

    //instrucciones para moverme
    //arriba, abajo, derecha, izquierda, diag der arriba, diag izq arriba, diag der abajo, diag izq abajo
    int pasoI[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int pasoJ[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    

    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            
            for (int k = 0; k < 8; k++) { //esto para cada direccion, segun nuestros pasos (linea 18 y 19)
                string palabraTemporal = ""; //limpiamos para la siguiente direccion

                bool flag = true;
                
                for (int pasos = 0; pasos < longitud; pasos++) {
                    int nuevoI = i + pasos * pasoI[k];
                    int nuevoJ = j + pasos * pasoJ[k];

                    if (nuevoI >= 0 && nuevoI < MAX_FILAS && nuevoJ >= 0 && nuevoJ < MAX_COLUMNAS) {
                        palabraTemporal += tablero[nuevoI][nuevoJ];
                    } else {
                        flag = false;
                        break;
                    }

                }

                if (flag) { //si guardo una palabra, entonces la agreagamos a nuestra lista
                    lista[contador] = palabraTemporal;
                    fila[contador] = i;
                    columna[contador] = j;
                    dirI[contador] = pasoI[k];
                    dirJ[contador] = pasoJ[k];
                    contador++;
                }

            }
        
        }
    }
}


int main() {
    char tablero[MAX_FILAS][MAX_COLUMNAS] = {
    {'J', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'},
    {'K', 'A', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'},
    {'U', 'V', 'V', 'C', 'C', '3', '1', '2', 'c', 'd'},
    {'e', 'f', 'g', 'I', 'i', 'j', 'k', 'l', 'm', 'n'},
    {'o', 'C', 'q', 'r', 'E', 't', 'u', 'v', 'w', 'x'},
    {'y', 'C', 'A', 'N', 'D', 'R', 'E', 'A', 'G', 'H'},
    {'T', '1', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R'},
    {'S', '1', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b'},
    {'c', '2', 'e', 'A', 'N', 'D', 'R', 'E', 'A', 'I'},
    {'m', 'n', 'o', 'C', 'C', '4', '2', '2', 'u', 'v'}
    };

    string lista[1000];
    int fila[1000];
    int columna[1000];
    int dirI[1000]; //direccion i
    int dirJ[1000]; //direccion j
    int contador = 0;

    cout << "Ingrese la palabra a buscar: ";
    string palabra;
    getline(cin, palabra);

    int longitud = palabra.length();

    //extraemos todas las palabras posibles, de MISMA LONGITUD QUE LA INTRODUCIDA, de cada letra de la sopa de letras
    extraerPalabras (tablero, longitud, lista, fila, columna, dirI, dirJ, contador);

    //ya con la lista, la ordenamos para usar en esta lista LA BUSQUEDA BINARIA
    BubbleSort (lista, fila, columna, dirI, dirJ, contador);

    //finalmente, buscamos la palabra y devolvemos el indice
    int indice = buscarPalabra (lista, contador, palabra);

    if (indice != - 1) {
        cout << "Palabra encontrada en la posicion (" << fila[indice] << ", " << columna[indice] 
        << ") con direccion (" << dirI[indice] <<", " << dirJ[indice] << ")" << endl;
    } else {
        cout << "Palabra no encontrada";
    }

    return 0;

}