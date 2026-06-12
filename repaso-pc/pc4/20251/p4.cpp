#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Alumno {
    int codigo;
    char nombre[20];
    float nota;
};

string doc = "alumnos.dat";
Alumno A; //para no estar creando usamos una sola, ya no es relevante


void registrar (fstream &archivo) {
    cout << "\nCodigo: ";
    cin >> A.codigo;
    cout << "Nombre: ";
    cin >> A.nombre; //como es nombre sin espacios, usamos cin
    cout << "Nota: ";
    cin >> A.nota;

    archivo.write ((char*)&A, sizeof(Alumno));
}


void swipearArchivo (fstream &archivo, int posElementoMayor, int posActual) {
    Alumno Atemp1, Atemp2;
    //leemos y guardamos ambos elementos
        //elemento mayor
    archivo.seekg (posElementoMayor * sizeof(Alumno));
    archivo.read ((char*)&Atemp1, sizeof(Alumno));

        //posicion actual
    archivo.seekg (posActual * sizeof(Alumno)); 
    archivo.read ((char*)&Atemp2, sizeof(Alumno));


    //reescribimos
        //elemento mayor
    archivo.seekp (posActual * sizeof(Alumno)); 
    archivo.write ((char*)&Atemp1, sizeof(Alumno)); 

        //posicion actual
    archivo.seekp (posElementoMayor * sizeof(Alumno));
    archivo.write ((char*)&Atemp2, sizeof(Alumno)); 

}


void ordenarArchivo (fstream &archivo, int cantidad) {
    archivo.open (doc, ios::in | ios::out | ios::binary);
    if (!archivo.is_open()) {
        cout << "Error al intentar abrir el archivo para modificar" << endl;
        return;
    }

    
    //usamos la variable global A
    //buscamos el mayor
    for (int i = 0; i < cantidad - 1; i++) {
        int j = i, posicion = i; //actualizar el j es vital, pero posicion es por si acaso
        float max = -1.0;
        archivo.seekg (i * sizeof(Alumno)); //a medida que ordeno quiero busque el mayor desde la posicion a la que avanzo
        while (archivo.read ((char*)&A, sizeof(Alumno)) && j < cantidad) { //la segunda condicion es por si acaso
            if (max < A.nota) {
                max = A.nota;
                posicion = j;
            }
            j++;

        }
        archivo.clear(); //ya que hicimos fallar el archivo y como lo seguiremos usando

        if (posicion != i) {
            swipearArchivo (archivo, posicion, i);
        }
        

    }

    archivo.close();

}

void mostrarRegistro (fstream &archivo) {
    archivo.open (doc, ios::in | ios::binary);
    if (!archivo.is_open()) {
        cout << "Error al leer, no se pudo abrir el archivo" << endl;
        return;
    }

    while (archivo.read ((char*)&A, sizeof(Alumno))) {
        cout << "Codigo: " << A.codigo << " - " << A.nombre << " - " << fixed << setprecision(1) << A.nota << endl;
    }

    archivo.close();

}


int main() {
    cout << "Ingrese cantidad de estudiantes: ";
    int n;
    cin >> n;

    fstream miarchivo;
    miarchivo.open (doc, ios::out | ios::binary);
    if (!miarchivo.is_open()) {
        cout << "Error al registrar, no se pudo abrir el archivo" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        registrar (miarchivo);
    }
    miarchivo.close();

    ordenarArchivo (miarchivo, n);

    cout << "\nRegistro ordenado por nota (descendente):" << endl;
    mostrarRegistro (miarchivo);

    return 0;

}