#include <iostream>
using namespace std;


// La clase Padre pone la regla
class Animal {
public:
    virtual void hacerSonido() = 0; // toda la clase se vuelve abstracta
};


// Si el hijo no quiere seguir siendo abstracto, entonces debe llenar dicho método
class Perro : public Animal {
public:
    // Al escribir el método con su cuerpo {}, estás "heredando y reescribiendo (polimorfia)"
    void hacerSonido() override {
        std::cout << "¡Guau!" << std::endl;
    }
};