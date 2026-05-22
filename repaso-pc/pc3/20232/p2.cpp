#include <iostream>
#include <string>
using namespace std;

struct Libro {
    string titulo;
    string autor;
    int anio;
    int paginas;
};

template <typename T>
void crear (T* &ptr, int n) {
    ptr = new T[n];
}

void ingresar (Libro* &ptr, int &cantidad) {
    cout << "Sobre cuantos libros desea ingresar? ";
    int n;
    cin >> n;

    cantidad = n;

    crear (ptr, n);

    for (int i = 0; i < n; i++) {
        cout << "\nLIBRO " << i + 1 << endl;
        Libro &pseudo = *(ptr + i);

        cin.ignore(); //para limpiar el \n que pseudo.pagina dejo en el buffer del libro anterior
         
        cout << "Titulo: ";
        getline (cin, pseudo.titulo);
        cout << "Autor: ";
        getline (cin, pseudo.autor);
        cout << "Anio de publicacion: ";
        cin >> pseudo.anio;
        cout << "Numero de paginas: ";
        cin >> pseudo.paginas; 
    }

    cin.ignore();

}

void detalles (Libro* ptr, int cantidad) {
    cout << "\n===LISTA DE LIBROS===" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "\nLIBRO " << i + 1 << endl;
        Libro &pseudo = *(ptr + i);
         
        cout << "\nTitulo: ";
        cout << pseudo.titulo;
        cout << "\nAutor: ";
        cout << pseudo.autor;
        cout << "\nAnio de publicacion: ";
        cout << pseudo.anio;
        cout << "\nNumero de paginas: ";
        cout << pseudo.paginas; 

        cout << endl;
    }
}

void buscar (Libro* ptr, int cantidad, string autor) {
    bool flag = false;
    for (int i = 0; i < cantidad; i++) {
        Libro &pseudo = *(ptr + i);
        if (autor == pseudo.autor) {
            cout << pseudo.titulo << endl;
            flag = true;
        }
    }

    if(!flag) {
        cout << "No se encontraron coincidencias";
    }
}

int main() {
    Libro* libros = nullptr;
    int cantidad;

    ingresar (libros, cantidad);

    cout << endl;
    detalles (libros, cantidad);

    cout << "\n===BUSQUEDA==="; 
    cout << "\nIngrese el autor: ";
    string autor;
    getline (cin, autor);

    buscar (libros, cantidad, autor);

    return 0;
}