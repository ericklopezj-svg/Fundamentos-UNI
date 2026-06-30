#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

class Figura3D {
    public:
    string Tipo;

    //constructor por defecto
    //destructor por defecto
    virtual double volumen() const = 0;
    virtual string descripcion() const = 0;

    virtual ~Figura3D() = default;

};

const float PI = 3.1416;

class Cubo : public Figura3D {
    double lado;

    public:
    Cubo(double lado) {
        if (lado > 0) {
            this->lado = lado;
            this->Tipo = "Cubo";
        } else {
            cout << "Error en la dimension" << endl;
            return;
        }
    }

    double volumen() const {
        return pow(lado, 3);
    }

    string descripcion() const {
        return Tipo + " de lado " + to_string(this->lado) + " -> Volumen: " + to_string(volumen());
    }

};

class Esfera : public Figura3D {
    double radio;

    public:
    Esfera(double radio) {
        if (radio > 0) {
            this->radio = radio;
            this->Tipo = "Esfera";
        } else {
            cout << "Error en la dimension" << endl;
            return;
        }
    }

    double volumen() const {
        return (4 * PI * pow(radio, 3))/3;
    }

    string descripcion() const {
        return Tipo + " de radio " + to_string(this->radio) + " -> Volumen: " + to_string(volumen());
    }

};

class Cilindro : public Figura3D {
    double radio;
    double altura;

    public:
    Cilindro(double radio, double altura) {
        if (radio > 0 && altura > radio) {
            this->radio = radio;
            this->altura = altura;

            this->Tipo = "Cilindro";
        } else {
            cout << "Error en la dimension" << endl;
            return;
        }
    
    }

    double volumen() const {
        return PI * pow(radio, 2) * altura;
    }

    string descripcion() const {
        return Tipo + " de radio " + to_string(this->radio) + " y altura " + to_string(this->altura) + " -> Volumen: " + to_string(volumen());
    }

};

class PiramideCuadrada : public Figura3D {
    double base;
    double altura;

    public:
    PiramideCuadrada(double base, double altura) {
        if (base > 0 && altura > 0) {
            this->altura = altura;
            this->base = base;
            this->Tipo = "Piramide Cuadrada";
        } else {
            cout << "Error en la dimension" << endl;
            return;
        }
    }

    double volumen() const {
        return (pow(base, 2) * altura)/3;
    }

    string descripcion() const {
        return Tipo + " con base " + to_string(this->base) + " y altura " + to_string(this->altura) + " -> Volumen: " + to_string(volumen());
    }

};


int main() {
    Figura3D* figuras[6];

    figuras[0] = new Cubo(4.00);
    figuras[1] = new Esfera(3.00);
    figuras[2] = new Cilindro(2.00, 5.00);
    figuras[3] = new PiramideCuadrada(6.00, 10.00);
    figuras[4] = new Esfera(1.50);
    figuras[5] = new Cubo(2.00);

    double volumenTotal = 0.0;
    double maximo = 0.0, minimo = 1000.0;
    int indiceMax, indiceMin;

    for (int i = 0; i < 6; i++) {         
        volumenTotal += figuras[i]->volumen();

        if (maximo < figuras[i]->volumen()) {
            maximo = figuras[i]->volumen();
            indiceMax = i;
        }

        if (minimo > figuras[i]->volumen()) {
            minimo = figuras[i]->volumen();
            indiceMin = i;
        }
    }

    cout << "Volumenes de las figuras" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "Figura " << i + 1 << ": " << figuras[i]->descripcion() << endl;
    }

    cout << "\nVolumen total de todas las figuras: " << volumenTotal;
    cout << "\nFigura de mayor volumen: " << figuras[indiceMax]->descripcion() << " -> " << figuras[indiceMax]->volumen();
    cout << "\nFigura de menor volumen: " << figuras[indiceMin]->descripcion() << " -> " << figuras[indiceMin]->volumen();


    return 0;
}