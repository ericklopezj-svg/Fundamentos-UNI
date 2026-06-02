#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Hora {
    int hour;
    int minute;
};

struct Web {
    string url;
    string titulo;
    Fecha date;
    Hora time;
    int orden;

};

void lectura (Web* ptr, int id) {
    cout << "Ingrese la URL: ";
    getline (cin, ptr->url);

    cout << "Titulo de la pagina: ";
    getline (cin, ptr->titulo);

    cout << "Fecha (dd/mm/aaaa): " << endl;
    cin >> ptr->date.dia;
    cin >> ptr->date.mes;
    cin >> ptr->date.anio;

    cout << "Hora (hh:mm): " << endl;
    cin >> ptr->time.hour;
    cin >> ptr->time.minute;

    cin.ignore();

    ptr->orden = id;
}


void agregar (Web* &antiguo, int &t1, Web* &nuevo, int &t2) {
    nuevo = new Web [t2 + t1];

    if (antiguo != nullptr || t1 != 0) {
        for (int i = 0; i < t1; i++) {
            nuevo[i] = antiguo[i];
        }

        delete[] antiguo;
    }

    for (int i = 0; i < t2; i++) {
        lectura (&nuevo[i + t1], i + t1 + 1);
        cout << ">>Entrada agregada con ID: " << (nuevo + i + t1)->orden << endl;
    }

    antiguo = nuevo;
    t1 += t2;

}

void quitar (Web* &antiguo, int &t1, Web* &nuevo, int orden) {
    if (antiguo == nullptr) {
        cout << "Sin lista de navegacion" << endl;
        return;
    }

    nuevo = new Web [t1 - 1];

    if (orden != 1) {
        for (int i = 0; i < orden - 1; i++) {
            nuevo[i] = antiguo[i];
        }
    }

    if (orden != orden - 1) {
        for (int i = orden; i < t1; i++) {
            nuevo[i - 1] = antiguo[i];
        } 
    }

    cout << ">>Entrada eliminada exitosamente" << endl;

    antiguo = nuevo;
    t1--;

}

void eliminarHistorial (Web* &ptr, int &t) {
    delete[] ptr;

    ptr = nullptr;
    t = 0;

    cout << ">>Historial limpiado correctamente" << endl;

}

void imprimir (Web* ptr) {
    cout << "ID: " << (ptr)->orden << " | URL: " << (ptr)->url << " | Titulo: " << (ptr)->titulo << " | Fecha: " 
         << setfill('0') << setw(2) << (ptr)->date.dia << "/" << setw(2) << (ptr)->date.mes << "/" 
         << (ptr)->date.anio << " | Hora: " << setw(2) << (ptr)->time.hour << ":" 
         << setw(2) << (ptr)->time.minute << endl;
        
}

void mostrarHistorial (Web* ptr, int t) {
    cout << "--Historial de navegacion--" << endl;
    if (ptr != nullptr) {
        for (int i = 0; i < t; i++) {
            imprimir ((ptr + i));
        }
    } else {
        cout << "Sin resultados" << endl;
    }
}

void buscarURL (Web* ptr, int t, string buscar) {
    if (ptr == nullptr || t == 0) {
        cout << "No hay lista de navegacion" << endl; 
        return;
    }

    int contador = 0;
    for (int i = 0; i < t; i++) {
        if (buscar == (ptr + i)->url) {
            contador++;
            if (contador == 1) {
                cout << "Resultados encontrados:" << endl;
            }
            imprimir ((ptr + i));
        }
    }

    if (contador == 0) {
        cout << "No se encontraron coincidencias." << endl;
    }
}


int main() {
    Web* original = nullptr;
    int tInicial = 0;
    cout << "---HISTORIAL DE NAVEGACION WEB---" << endl;
    cout << "1. Agregar entrada al historial" << endl;
    cout << "2. Mostrar historial completo" << endl;
    cout << "3. Eliminar una entrada por ID" << endl;
    cout << "4. Buscar visitas por URL" << endl;
    cout << "5. Limpiar historial completo" << endl;
    cout << "0. Salir" << endl;

    int opcion;
    cout << "\nElija una opcion: ";
    cin >> opcion;
    cin.ignore();

    while (opcion != 0) {
        Web* modificado = nullptr;
        switch (opcion) { // el switch es una caja en la que conviven todas las variables, entonces el compilador asume que podrias usar
            //encerramos en llaves para que esas variables solo existan en ese caso
            case 1: 
                cout << "\nIngrese el numero de entradas: ";
                int entradas;
                cin >> entradas;
                cin.ignore();

                agregar (original, tInicial, modificado, entradas);

            break;

            case 2: 
                mostrarHistorial (original, tInicial);
            break;

            case 3:
                cout << "\nIngrese el ID de la entrada a eliminar: ";
                int id;
                cin >> id;
                cin.ignore();

                quitar (original, tInicial, modificado, id);
            break;

            case 4: 
                {
                    cout << "\nIngrese URL a buscar: ";
                    string busqueda;
                    getline (cin, busqueda);

                    buscarURL (original, tInicial, busqueda);
                    break;
                }
                
            case 5:
                cout << "\n¿Estas seguro que deseas borrar todo el historial? (s/n): ";
                char ans;
                cin >> ans;

                if (ans == 's') {
                    eliminarHistorial (original, tInicial);
                } else if (ans == 'n') {
                    break;
                }
            break;

        }
        cout << "\nElija otra opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 0) {
            cout << "\nSaliendo...";
            break;
        }

    }

    return 0;

}

