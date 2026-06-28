#include <iostream>
#include <string>
using namespace std;

// Clase Padre (Base)
class Animal {
public:
    string nombre;

    void respirar() {
        cout << nombre << " esta respirando... Inhala, exhala." << endl;
    }
};

// Clase Hija (Derivada) que hereda de Animal
class Perro : public Animal {
public:
    void ladrar() {
        cout << "¡Guau, guau!" << endl;
    }
};

int main() {
    Perro miPerro;
    miPerro.nombre = "Firulais";

    // El perro puede usar respirar() porque lo HEREDÓ del padre
    miPerro.respirar(); // Salida: Firulais esta respirando... Inhala, exhala.
    miPerro.ladrar();   // Salida: ¡Guau, guau!

    return 0;
}