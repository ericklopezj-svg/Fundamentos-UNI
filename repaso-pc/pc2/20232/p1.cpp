#include <iostream>
using namespace std;

float suma (float a, float b) {
    return a + b;
}

float resta (float a, float b) {
    return a - b;
}

float producto (float a, float b) {
    return a * b;
}

float division (float a, float b) {
    return 1.0 * a / b;
}

int main() {
    float (*g[3]) (float, float);
    *g = suma;
    *(g + 1) = resta;
    *(g + 2) = producto;
    *(g + 3) = division;

    cout << "Introduzca dos numeros: ";
    float a, b;
    cin >> a >> b;

    cout << "La suma es " << g[0](a, b) << endl;
    cout << "La resta es " << (*(g + 1)) (a, b);

    return 0;

}