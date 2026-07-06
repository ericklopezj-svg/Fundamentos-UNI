#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <cmath>
using namespace std;

class Sensor {
    public:

    string id;
    string tipo;
    double freq;

    Sensor (string id, string tipo, double freq) {
        this->id = id;
        this->tipo = tipo;
        this->freq = freq;

    }

    virtual void simularLectura() = 0;
    virtual void mostrarDatos() = 0;

    virtual ~Sensor() = default;

};

class sensorTemperatura : public Sensor {
    double lectura;

    public:
    sensorTemperatura (string id, double freq) : Sensor (id, "Temperatura", freq) {
        lectura = 0.0;
    }

    void simularLectura() {
        lectura = (rand() % 1000 + 1) / 10.0;
    }

    void mostrarDatos() {
        cout << "[Sensor de Temperatura] ID: " << this->id << " | Frecuencia: " << fixed << setprecision(2) << this->freq << " Hz | Lectura: " << setprecision(1) << this->lectura << " °C" << endl;
    }

    ~sensorTemperatura() {
        cout << "Destruyendo sensor: Temperatura" << endl;
    }
};

class sensorMovimiento : public Sensor {
    double ax;
    double ay;
    double az;

    public:
    sensorMovimiento (string id, double freq) : Sensor (id, "Movimiento", freq) {
        ax = 0.0;
        ay = 0.0;
        az = 0.0;
    }

    void simularLectura() {
        ax = (rand() % 101) / 100.0;
        ay = (rand() % 101) / 100.0;
        az = (rand() % 101) / 100.0;
    }

    void mostrarDatos() {
        cout << "[Sensor de Movimiento] ID: " << this->id << " | Frecuencia: " << fixed << setprecision(2) << this->freq << " Hz | Aceleracion: ax = " << this->ax << " m/s2, ay = " << this->ay << 
        " m/s2, az = " << this->az << " m/s2" << endl;
    }

    ~sensorMovimiento() {
        cout << "Destruyendo sensor: Movimiento" << endl;
    }
};


class sensorDistancia : public Sensor {
    double lectura;
    double ruido;

    public:
    sensorDistancia (string id, double freq) : Sensor (id, "Distancia", freq) {
        lectura = 0.0;
        ruido = 0.0;
    }

    void simularLectura() {
        lectura = (rand() % 1000 + 1) / 100.0;
        ruido = 0.01 * pow(lectura, 2);
    }

    void mostrarDatos() {
        cout << "[Sensor de Distancia] ID: " << this->id << " | Frecuencia: " << fixed << setprecision(2) << this->freq << " Hz | Lectura: " 
        << this->lectura << " (ruido: +" << this->ruido << "m)" << endl;
    }

    ~sensorDistancia() {
        cout << "Destruyendo sensor: Distancia" << endl;
    }

};

int main() {
    srand(time(NULL));
    Sensor* ptr[3];

    string id_aux;
    double freq_aux;
    int opcion;
    for (int i = 0; i < 3; i++) {
        cout << "\nID: ";
        cin >> id_aux;

        cout << "Frecuencia: ";
        cin >> freq_aux;

        cout << "Tipo:";
        cout << "\n1. Temperatura" <<
                "\n2. Distancia" <<
                "\n3. Movimiento" << 
                "\n> ";
        cin >> opcion;

        if (opcion == 1) {
            ptr[i] = new sensorTemperatura(id_aux, freq_aux);
        } else if (opcion == 2) {
            ptr[i] = new sensorDistancia(id_aux, freq_aux);
        } else {
            ptr[i] = new sensorMovimiento(id_aux, freq_aux);
        }

        ptr[i]->simularLectura();

    }

    cout << endl << setfill('=') << setw(20) << "LECTURAS" << setw(12) << "" << endl;
    for (int i = 0; i < 3; i++) {
        ptr[i]->mostrarDatos();
    }

    for (int i = 0; i < 3; i++) {
        delete ptr[i];
    }

    return 0;
}