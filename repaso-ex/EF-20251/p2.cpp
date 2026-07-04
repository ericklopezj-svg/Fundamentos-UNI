#include <iostream>
#include <cstring>
using namespace std;


struct Pagina {
    char url[100];
    int tiempoVisita;

};

Pagina* lista = nullptr;
int t = 0;


void visitarPagina (const char* direccion, int tiempo) {
    Pagina* listaTemp = new Pagina[t + 1];

    for (int i = 0; i < t; i++) {
        listaTemp[i + 1] = lista[i];
    }

    strncpy(listaTemp->url, direccion, sizeof(listaTemp->url) - 1);
    listaTemp->url[sizeof(listaTemp->url) - 1] = '\0';

    listaTemp->tiempoVisita = tiempo;

    delete[] lista;
    lista = listaTemp;
    t++;

}

void mostrarHistorial () {
    cout << "\nHistorial de navegacion" << endl;
    if (lista == nullptr) {
        cout << "[Historial vacio]" << endl;
        return ;
    }

    for (int i = 0; i < t; i++) {
        cout << i + 1 << ". URL: " << (lista + i)->url << " | Tiempo de visita: " << lista[i].tiempoVisita << " s" << endl;
    }

}


bool eliminarPagina (const char* direccion) {
    int indice = -1;
    for (int i = 0; i < t; i++) {
        if (strcmp(lista[i].url, direccion) == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        return false;
    }

    Pagina* listaTemp = new Pagina[t - 1];

    int k = 0;
    for (int i = 0; i < t; i++) {
        if (i == indice) {
            continue;
        }

        listaTemp[k] = lista[i];
        k++;
    }

    delete[] lista;
    lista = listaTemp;
    t--;

    return true;

}


void liberarHistorial () {
    delete[] lista;
    lista = nullptr;
}


int main() {
    cout << "Ingrese la cantidad de visitas que desea agregar: ";
    int n;
    cin >> n;

    lista = new Pagina[n];

    char direccion[100];
    int tiempo;
    for (int i = 0; i < n; i++) {
        cout << "Visita registrada: ";
        cin >> direccion;

        cout << "Tiempo de visita: ";
        cin >> tiempo;
        cin.ignore(1000, '\n');

        visitarPagina(direccion, tiempo);

    }

    mostrarHistorial();

    cout << "\nEliminando pagina: ";
    cin >> direccion;

    if (eliminarPagina(direccion)) {
        cout << "Pagina eliminada con exito" << endl;
    } else {
        cout << "Pagina no encontrada" << endl;
    }

    mostrarHistorial();

    cout << "Liberando historial..." << endl;
    liberarHistorial();

    mostrarHistorial();


    return 0;

}