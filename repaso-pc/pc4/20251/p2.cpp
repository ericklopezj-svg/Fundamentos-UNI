#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

const string doc = "sismos.txt";

struct Sismo {
    int id;
    string fecha;
    string hora;
    double magnitud;
    string ubicacion;
};


bool bisiesto (int anio) {
    if (anio % 4 == 0) {
        if (anio % 100 == 0) {
            if (anio % 400 == 0) {
                return true;
            }
            return false;
        }
        return true;
    }

    return false;

}


bool validarFecha (string fecha) {

    if (fecha.length() != 10) { //longitud determinada
        return false;
    }

    if (fecha[2] != '/' || fecha[5] != '/') { //posicion correcta de los /
        return false;
    }
    
    
    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5) {
            if (!isdigit(fecha[i])) { //que sean digitos numericos
                return false;
            }
        }
    }

    int dia = stoi (fecha.substr(0, 2));
    int mes = stoi (fecha.substr(3, 2));
    int anio = stoi (fecha.substr(6, 4));

    if (anio < 1 || mes < 1 || mes > 12 || dia < 1) {
        return false;
    }

    int diaspormes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes == 2 && bisiesto(anio)) {
        diaspormes[2] = 29;
    }

    if (dia > diaspormes[mes]) {
        return false;
    }

    return true;
    
}

bool validarHora (string tiempo) {
    if (tiempo.length() != 8) {
        return false;
    }

    if (tiempo[2] != ':' || tiempo[5] != ':') {
        return false;
    }

    for (int i = 0; i < 8; i++) {
        if (i != 2 && i != 5) {
            if (!isdigit(tiempo[i])) {
                return false;
            }
        }
    }

    int hora = stoi (tiempo.substr(0, 2));
    int minuto = stoi (tiempo.substr(3, 2));
    int segundo = stoi (tiempo.substr(6, 2));

    if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59 || segundo < 0 || segundo > 59) {
        return false;
    }

    return true;

}

void menu () {
    cout << "\n\n=====MENU====="
            "\n1. Mostrar todos los sismos registrados en el archivo" 
            "\n2. Registrar nuevo sismo en el archivo"
            "\n3. Salir del programa" << endl;

}

int numeroRegistro (fstream &archivo) {
    archivo.open(doc);
    int contador = 0;
    string linea;

    if (!archivo.is_open()) {
        return 0; //asumimos que el archivo no existe
    }

    while (getline(archivo, linea)) {
        contador++;
    }

    archivo.close();

    return contador;
}

void escritura (fstream &archivo, Sismo s1) {
    s1.id = numeroRegistro (archivo) + 1;

    archivo.open(doc, ios::out | ios::app);
    if (!archivo.is_open()) {
        cout << "Error al intentar abrir el archivo" << endl;
        return;
    }

    
    archivo << s1.id << " " 
            << s1.fecha << " " 
            << s1.hora << " " 
            << fixed << setprecision(1) << s1.magnitud << " " 
            << s1.ubicacion << endl;

    archivo.close();
    cout << ">> Agregado con exito" << endl;

}

void lectura (fstream &archivo) {
    archivo.open(doc, ios::in);
    if (!archivo.is_open()) {
        cout << "Error al intentar abrir el archivo" << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();

}


int main() {
    fstream miarchivo;
    int opcion;
    do {
        menu();
        cout << "\nElija su opcion: ";
        cin >> opcion;
        cin.ignore();
    
        if (opcion == 1) {
            lectura (miarchivo);
            continue; //ira directo al while
        }

        if (opcion == 2) {
            Sismo s;
            cout << "Fecha (dd/mm/aaaa): ";
            do {
                getline (cin, s.fecha);
                if (!validarFecha(s.fecha)) {
                    cout << "Introduzca una fecha correcta" << endl;
                    cout << ">";
                }
            } while (validarFecha(s.fecha) == false);
            cout << "Hora (hh:mm:ss): ";
            do {
                getline (cin, s.hora);
                if (!validarHora(s.hora)) {
                    cout << "Introduzca una hora correcta" << endl;
                    cout << ">";
                }
            } while (validarHora(s.hora) == false);
            cout << "Magnitud: ";
            cin >> s.magnitud;
            cout << "Ubicacion (Sin espacios): ";
            cin >> s.ubicacion; //ya que las indicaciones dicen que debe ir sin espacios

            escritura (miarchivo, s);
            continue;
        }

    } while (opcion != 3);

    return 0;

}