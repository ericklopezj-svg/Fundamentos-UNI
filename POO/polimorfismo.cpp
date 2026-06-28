#include <iostream>
using namespace std;

// Clase Padre
class Animal {
public:
    // 'virtual' activa la magia del polimorfismo en C++
    virtual void hacerSonido() {
        cout << "Sonido de animal genérico." << endl;
    }
};

// Clase Hija 1
class Perro : public Animal {
public:
    // Cambiamos el código del método original
    void hacerSonido() { 
        cout << "¡Guau!" << endl;
    }
};

// Clase Hija 2
class Gato : public Animal {
public:
    // Cambiamos el código del método original
    void hacerSonido() {
        cout << "¡Miau!" << endl;
    }
};

int main() {
    // Creamos apuntadores tipo "Animal", pero guardamos un Perro y un Gato reales
    Animal* mascota1 = new Perro();
    Animal* mascota2 = new Gato();

    // Llamamos al MISMO método en ambos
    mascota1->hacerSonido(); // Salida: ¡Guau!
    mascota2->hacerSonido(); // Salida: ¡Miau!

    // Limpieza de memoria (buena práctica en C++)
    delete mascota1;
    delete mascota2;
    return 0;
}