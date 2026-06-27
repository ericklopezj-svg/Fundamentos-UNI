#include <iostream>
#include <cmath>
using namespace std;

struct Coordenada {
    float x;
    float y;
};

bool verificarCoordenada (Coordenada c) {
    if (c.x < 0 || c.y < 0 || c.x > 20 || c.y > 20) {
        return false;
    }

    return true;

}


bool verificarRectangulo (Coordenada* ptr) {

    float vec1X = ptr->x - (ptr + 1)->x;
    float vec1Y = ptr->y - (ptr + 1)->y;

    float vec2X = (ptr + 1)->x - (ptr + 2)->x;
    float vec2Y = (ptr + 1)->y - (ptr + 2)->y;

    float vec3X = (ptr + 2)->x - (ptr + 3)->x;
    float vec3Y = (ptr + 2)->y - (ptr + 3)->y;

    float vec4X = (ptr + 3)->x - ptr->x;
    float vec4Y = (ptr + 3)->y - ptr->y;

    float productoPunto1 = vec1X * vec2X + vec1Y * vec2Y;
    float productoPunto2 = vec2X * vec3X + vec2Y * vec3Y;
    float productoPunto3 = vec4X * vec1X + vec4Y * vec1Y;

    if (productoPunto1 == 0 && productoPunto2 == 0 && productoPunto3 == 0) {
        return true;
    }

    return false;

}

float distanciaPuntos (Coordenada p1, Coordenada p2) {
    return sqrt ( pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) );

}

class Rectangulo {

    Coordenada* ptr;
    bool esValido;

    public:

    Rectangulo (Coordenada c1, Coordenada c2, Coordenada c3, Coordenada c4) {
        ptr = new Coordenada[4];

        *ptr = c1;
        *(ptr + 1) = c2;
        *(ptr + 2) = c3;
        *(ptr + 3) = c4;

        for (int i = 0; i < 4; i++) {
            if (!verificarCoordenada(ptr[i])) {
                cout << "Las coordenadas no cumplen las condiciones" << endl;
                esValido = false;
                return;
            }

        }

        if (!verificarRectangulo (ptr)) {
            cout << "Las coordenadas no forman un rectangulo" << endl;
            esValido = false;
            return;
        }

        esValido = true;   


    }

    ~Rectangulo () {
        delete[] ptr;
        ptr = nullptr;
        cout << "Destructor llamado: liberando memoria del objeto Rectangulo" << endl;

    }



    float largo () {
        if (!esValido) {
            cout << "Las coordenadas no forman un rectangulo" << endl;
            return 0;
        }

        if (distanciaPuntos (ptr[0], ptr[1]) > distanciaPuntos (ptr[1], ptr[2])) {
            return distanciaPuntos (ptr[0], ptr[1]);

        } else {
            return distanciaPuntos (ptr[1], ptr[2]);

        }

    }

    float ancho () {
        if (!esValido) {
            cout << "Las coordenadas no forman un rectangulo" << endl;
            return 0;
        }

        if (distanciaPuntos (ptr[0], ptr[1]) < distanciaPuntos (ptr[1], ptr[2])) {
            return distanciaPuntos (ptr[0], ptr[1]);

        } else {
            return distanciaPuntos (ptr[1], ptr[2]);
            
        }

    }

    float perimetro () {
        if (!esValido) {
            cout << "Las coordenadas no forman un rectangulo" << endl;
            return 0;
        }

        return 2 * (distanciaPuntos (ptr[0], ptr[1]) + distanciaPuntos (ptr[1], ptr[2]));
    }

    float area () {
        if (!esValido) {
            cout << "Las coordenadas no forman un rectangulo" << endl;
            return 0;
        }

        return distanciaPuntos (ptr[1], ptr[2]) * distanciaPuntos (ptr[0], ptr[1]);

    }


    bool esCuadrado () {
        if (largo() == ancho()) {
            return true;
        }

        return false;

    }


    void mostrarDatos () {
        if (!esValido) {
            cout << "Las coordenadas no forman un rectangulo" << endl;
            return;
        }

        cout << "Largo: " << largo()
             << "\nAncho: " << ancho()
             << "\nArea: " << area()
             << "\nPerimetro: " << perimetro() << endl;

        if (esCuadrado()) {
            cout << "Es un cuadrado" << endl;
        } else {
            cout << "No es un cuadrado" << endl;
        }

    }

};


int main() {
    // Caso 1: Un rectángulo válido (un cuadrado de 5x5 en esencia)
    Coordenada r1_c1 = {0, 0};
    Coordenada r1_c2 = {0, 5};
    Coordenada r1_c3 = {5, 5};
    Coordenada r1_c4 = {5, 0};
    
    cout << "--- Intentando crear Rectangulo 1 ---" << endl;
    Rectangulo rec1(r1_c1, r1_c2, r1_c3, r1_c4);
    rec1.mostrarDatos();
    cout << endl;

    // Caso 2: Coordenadas inválidas (puntos al azar que no forman rectángulo)
    Coordenada r2_c1 = {1, 1};
    Coordenada r2_c2 = {3, 9};
    Coordenada r2_c3 = {20, 2};
    Coordenada r2_c4 = {30, 5}; // Se pasa de 20
    
    cout << "--- Intentando crear Rectangulo 2 ---" << endl;
    Rectangulo rec2(r2_c1, r2_c2, r2_c3, r2_c4);
    rec2.mostrarDatos();
    cout << endl;

    return 0;
}