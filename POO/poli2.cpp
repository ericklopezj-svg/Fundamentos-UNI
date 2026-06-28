#include <iostream>
using namespace std;

class Animal {
public:
    virtual void hacerSonido() { 
        cout << "Sonido genérico" << endl; 
    }
};

class Perro : public Animal {
public:
    void hacerSonido() { 
        cout << "¡Guau!" << endl; 
    }
};


//Globalizamos la función, o sea le damos su propio scope, para poder usarla con cualquier clase hija Animal.
// Esta función recibe una REFERENCIA (&) a un Animal.
// Al poner el '&', C++ no copia ni recorta el objeto, usa el original.
void hacerCantarAlAnimal(Animal& animalCualquiera) {
    animalCualquiera.hacerSonido(); 
}

int main() {
    Perro miPerrito; // Objeto común y corriente, sin 'new'
    
    // Le pasamos el perro a la función. 
    // Como sabemos Perro es un Animal, entonces no habría error
    hacerCantarAlAnimal(miPerrito); // Salida: ¡Guau!

    return 0;
}