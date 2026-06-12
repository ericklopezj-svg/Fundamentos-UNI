#include <iostream>
#include <fstream>
using namespace std;

struct Usuario {
    int codigo;
    char arr[20];
    double saldo;
};

Usuario u1;

void agregarUsuario (fstream &archivo) {
    cout << "NUevo Usuario" << endl;
    cout << "       Codigo: ";
    cin >> u1.codigo;
    cin.ignore();
    cout << "       Nombre: ";
    cin.getline(u1.arr, 20);
    cout << "       Saldo: ";
    cin >> u1.saldo;

    archivo.write ((char*)&u1, sizeof(Usuario));

}

void mostrarLista (fstream &archivo) {
    archivo.open ("usuarios.dat", ios::in | ios::binary);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para leer" << endl;
        return;
    }

    while (archivo.read ((char*)&u1, sizeof(Usuario))) {
        cout << "Codigo:    " << u1.codigo << " | Nombre:   " << u1.arr << " | Saldo:   " << u1.saldo << endl;
    }
    archivo.close();

}


void modificarUsuario (fstream &archivo, int cod, double incremento) {
    archivo.open ("usuarios.dat", ios::in | ios::out | ios::binary);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para leer" << endl;
        return;
    }

    while (archivo.read ((char*)&u1, sizeof(Usuario))) {
        if (u1.codigo == cod) {
            u1.saldo += incremento;
            archivo.seekp (-sizeof(Usuario), ios::cur);
            archivo.write ((char*)&u1, sizeof(Usuario));
            archivo.seekp (0, ios::cur); //a pesar de que queda en la misma posicion, actualizamos
            archivo.close();

            cout << "\nSaldo actualizado correctamente" << endl;
            return;
        }
    }

    cout << "Usuario con codigo " << cod << " no existe" << endl;

}


int main() {
    cout << "Numero de usuarios: ";
    int num;
    cin >> num;

    fstream miarchivo;
    miarchivo.open ("usuarios.dat", ios::out | ios::binary);
    if (!miarchivo.is_open()) {
        cout << "Error al abrir el archivo para leer" << endl;
        return 1;
    }

    for (int i = 0; i < num; i++) {
        agregarUsuario (miarchivo);
    }
    miarchivo.close();
    cout << "Archivo creado" << endl;

    cout << "\nContenido del archivo:" << endl;
    mostrarLista (miarchivo);


    int codigo, incremento;
    cout << "Modificacion de saldo" << endl;
    cout << "       Codigo de usuario: ";
    cin >> codigo;
    cout << "       Incremento de saldo: ";
    cin >> incremento;

    modificarUsuario (miarchivo, codigo, incremento);

    cout << "Despues de modificar el saldo:" << endl;
    cout << "\nContenido del archivo:" << endl;
    mostrarLista (miarchivo);

    return 0;

}