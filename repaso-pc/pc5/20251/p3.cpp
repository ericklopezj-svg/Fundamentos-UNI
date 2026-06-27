#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


bool verificarTriangulo (float a, float b, float c) {
    if (a + b > c && b + c > a && a + c > b) {
        return true;
    }

    return false;
}

float heron (float a, float b, float c) {
    float p = (a + b + c)/2;

    return sqrt ( p * (p - a) * (p - b) * (p - c));
}


class Figura {
    int Tipo;
    float* Medida = nullptr;

    public:

    Figura() {
        Tipo = 0;
        Medida = nullptr;
    }

    void configurarFigura (int Tipo) {

        if (Tipo == 3) {
            this->Tipo = Tipo;
            Medida = new float[Tipo];

            cout << "Ingrese lados a, b, c del triangulo: ";
            cin >> Medida[0] >> Medida[1] >> Medida[2];

        }else if (Tipo == 4) {
            this->Tipo = Tipo;
            Medida = new float[2];

            cout << "Ingrese lados a, b del rectangulo: ";
            cin >> Medida[0] >> Medida[1];

        } else {
            cout << "Numero de lados desconocido" << endl;

        }
    }

    ~Figura () {
        if (Medida != nullptr) {
            delete[] Medida;
        }
    }

    float area () {
        if (Tipo == 3) {
            if (verificarTriangulo (Medida[0], Medida[1], Medida[2])) {
                return heron(Medida[0], Medida[1], Medida[2]);
            }
            return 0;
            
        } else if (Tipo == 4) {
            return Medida[0] * Medida[1];
        } else {
            return 0;

        }


    }

};

int main() {
    cout << "Ingrese el numero de rectangulos o triangulos: ";
    int n;
    cin >> n;

    Figura* ptr = new Figura[n];
    int Tipo;
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el numero de lados de la figura: ";
        cin >> Tipo;

        ptr[i].configurarFigura (Tipo);

    }

    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "Area de la figura " << i + 1 << ": " << fixed << setprecision(2) << ptr[i].area() << endl;

    }

    return 0;
}