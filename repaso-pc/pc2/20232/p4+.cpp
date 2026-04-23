#include <iostream>
using namespace std;

void recortar (int &a, int &b) {
    if (a == 0 || b == 0) {
        return;
    }

    if (a <= b) {
        int cantidad = b / a;
        cout << cantidad << " losetas de " << a << " m de lado" << endl;
        b = b - cantidad * a;

        recortar (a, b);

    } else {
        int cantidad = a / b;
        cout << cantidad << " losetas de " << b << " m de lado" << endl;
        a = a - cantidad * b;

        recortar (a, b);
    }
}

int main() {
    int base, altura;
    cout << "Base: ";
    cin >> base;
    cout << "Altura: ";
    cin >> altura; 

    recortar (base, altura);

    return 0;
}