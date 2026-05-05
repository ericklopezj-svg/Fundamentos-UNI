#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main() {
    char cadena[200];

    cout << "Ingrese N: ";
    int N;
    cin >> N;
    cin.ignore();

    char nombre[N][20];
    char direccion[N][50];
    char celular[N][12];
    int edad[N];
    float talla[N];

    int contador = 1, cantidad = 0;
    do {
        cout << "Ingrese entrada " << contador<< ":";
        cin.getline (cadena, 200, '\n');

        char* token = strtok(cadena, ",\n");
        int fila = 0; //k lo usamos para descartar si alguno es menos o mas cantidad de datos
        while (token != NULL) {
            switch (fila) {
                case 0: strcpy(nombre[cantidad], token);
                break;

                case 1: strcpy(direccion[cantidad], token);
                break;

                case 2: strcpy(celular[cantidad], token);
                break;

                case 3: edad[cantidad] = atoi(token);
                break;

                case 4: talla[cantidad] = atof(token);
                break;
            }

            fila++;
            token = strtok(NULL, ",\n");
        }
        contador++;

        if (fila == 5) { //si fueron 5 datos, entonces incrementamos k para que se guarde, sino sobreescribimos
            cantidad++;    //para sobreescribir no debemos incrementar k
        }
        
    } while (contador <= N);

    cout << left << setw(20) << "Nombre" << left << setw(25) << "Direccion" << left << setw(15) << "Celular" << left << setw(8) << "Edad" 
    << left << setw(8) << "Talla" << endl;

    for (int i = 0; i < cantidad; i++) {
        cout << left << setw(20) << nombre[i] << left << setw(50) << direccion[i] << left << setw(15) << celular[i] << left << setw(8) 
        << edad[i] << left << setw(8) << talla[i] << endl;
    }

    return 0;
}