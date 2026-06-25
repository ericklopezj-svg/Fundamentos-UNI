#include <iostream>
#include <string>

using namespace std;

class Mascota {
public:
    string nombre;

    // CONSTRUCTOR 1: Para cuando lo quieres crear VACÍO
    Mascota() {
        this->nombre = "Sin nombre"; // Le asignas un valor temporal
    }

    // CONSTRUCTOR 2: Para cuando ya sabes el nombre desde el inicio
    Mascota(string nombre) {
        this->nombre = nombre;
    }
};

int main() {
    // Opción A: Nace con el Constructor 1 (vacío)
    Mascota perroAnonimo; 
    // Si quieres cambiarle el nombre después, lo haces directamente al atributo:
    perroAnonimo.nombre = "Firulais"; 

    // Opción B: Nace directamente con el Constructor 2
    Mascota perroConNombre("Oliver"); 
}