#include <iostream>
#include <iomanip>
using namespace std;


float fraccion (int i, int n) {
    if (i == n) {
        return i;
    }

    float num = (i + 1)/2;

    if (i % 2 == 0) {
        return i + num/fraccion(i + 1, n);
    } else {
        return i - num/fraccion(i + 1, n);
    } 
}

int main() {
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;

    float x = 1 + 1.0/fraccion (1, n);

    cout << fixed << setprecision(10);
    cout << "El valor de x es: " << x;

    return 0;
}