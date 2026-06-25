#include <iostream>
#include <string>

using namespace std;

class Mascota {
public: // OBLIGATORIO: Para que podamos usarlo desde fuera

    // ATRIBUTOS (Las características del objeto)
    string nombre;

    // 2. CONSTRUCTOR (Mismo nombre de la clase, sin tipo de retorno)
    Mascota(string nombre) {
        // 4. USO DE 'this' (Obligatorio porque el parámetro y el atributo se llaman igual)
        this->nombre = nombre; 
        cout << this->nombre << " ha nacido gracias al Constructor." << std::endl;
    }

    // MÉTODO (La acción que sabe hacer)
    void hacerSonido() {
        cout << this->nombre << " dice: ¡Guau o Miau!" << std::endl;
    }

    // 3. DESTRUCTOR (Lleva la tilde '~', mismo nombre y sin parámetros)
    ~Mascota() {
        cout << this->nombre << " es eliminado de la memoria por el Destructor." << std::endl;
    }
}; // <-- OBLIGATORIO el punto y coma


// --- ASÍ SE USA TODO JUNTO EN EL PROGRAMA ---
int main() {
    cout << "--- Inicio del programa ---" << std::endl;

    // Aquí creamos el OBJETO real llamado 'miPerro' basado en la CLASE 'Mascota'
    // En este segundo exacto se ejecuta el CONSTRUCTOR
    Mascota miPerro("Firulais");

    // Usamos un MÉTODO (acción)
    miPerro.hacerSonido();

    cout << "--- Fin del programa ---" << std::endl;
    
    return 0; 
    // Al llegar aquí, el programa termina, 'miPerro' deja de existir 
    // y el DESTRUCTOR se activa solo para limpiar la memoria.
}