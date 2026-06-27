#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class CuentaBancaria {

    string titular;
    double saldo;
    int numeroCuenta;
    int transaccionesDelDia;

    public:
    CuentaBancaria (string titular, double saldo, int numeroCuenta) {
        this->titular = titular;
        this->saldo = saldo;
        this->numeroCuenta = numeroCuenta;
        this->transaccionesDelDia = 0;
    }


    
    void depositar (double monto) {
        if (monto <= 0) {
            cout << "[Error] Monto incorrecto" << endl;
            return;
        }

        saldo += monto;
        cout << "[Deposito] Se deposito " << fixed << setprecision(2) << monto << ". Saldo actual: " << fixed << setprecision(2) << saldo << endl;   

    }

    void retirar (double monto) {
        if (monto <= 0) {
            cout << "[Error] Monto incorrecto" << endl;
            return;
        }

        if (saldo >= monto && transaccionesDelDia < 3) {
            saldo -= monto;
            transaccionesDelDia++;

            cout << "[Retiro] Se retiro " << fixed << setprecision(2) << monto << ". Saldo actual: " << saldo << endl;

        } else if (saldo < monto) {
            cout << "[Error] Saldo insuficiente" << endl;

        } else if (transaccionesDelDia >= 3) {
            cout << "[Error] Ha alcanzado el limite de tres retiros diarios." << endl;
        }

    }

    void mostrarSaldo () {
        cout << "\nResumen de la cuenta:" << endl;
        cout << "Titular: " << titular << endl;
        cout << "N° de Cuenta: " << numeroCuenta << endl;
        cout << "Saldo actual: " << fixed << setprecision(2) << saldo << endl;

    }

    void resetearTransacciones () {
        transaccionesDelDia = 0;

    }

    ~CuentaBancaria () {

    }
};


int main() {
    // Creamos la cuenta según el ejemplo del PDF
    CuentaBancaria cuenta("Carlos Garcia", 500.00, 123456);
    
    // Mostramos el estado inicial
    cuenta.mostrarSaldo();
    
    // Simulemos operaciones
    cuenta.retirar(100);
    cuenta.retirar(50);
    cuenta.retirar(200);
    
    // Intento de un 4to retiro (debería dar error de límite)
    cuenta.retirar(10);
    
    // Ver saldo final
    cuenta.mostrarSaldo();
    
    return 0;
}