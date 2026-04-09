#include <iostream>
using namespace std;

void segregar (int a[], int tam) {
    int j = 0;
    for (int i = 0; i < tam; i++) {
        if (a[i] < 0) {
            int k = i;
            int temp = a[i];
            while (k > j) {
                a[k] = a[k - 1];
                k--;
            }
            a[k] = temp;

            j++;
        }
            
    }
}


int main() {
    int a[] = {9, -3, 5, -2, -8, -6, 1, 3};
    int tam = sizeof(a)/sizeof(a[0]);

    cout << "Entrada: ";
    for (int i = 0; i < tam; i++) {
        cout << a[i] << " ";
    }

    segregar (a, tam);

    cout << "Salida: ";
    for (int i = 0; i < tam; i++) {
        cout << a[i] << " ";
    }

    return 0;
}