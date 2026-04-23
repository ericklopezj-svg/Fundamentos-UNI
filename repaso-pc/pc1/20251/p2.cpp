#include <iostream>
using namespace std;

bool contar (int arr[], int tam, int cant, int temp) {
    for (int i = 0; i < tam; i++) {
        int k = 0;
        for (int j = 0; j < tam; j++) {
            if (arr[j] == arr[i]) {
                k++;
            }
        }

        if (k == cant) {
            temp = arr[i];
            return true;
        }
    }
    return false;
}

int main() {
    int arr[] = {4, 5, 1, 2, 1, 4, 2};
    int tam = sizeof(arr)/sizeof(arr[0]);

    int e;
    bool v = contar (arr, tam, 1, e);

    if (v) {
        cout << "El numero es " << e;
    } else {
        cout << "Ningun elemento coincide";
    }

    return 0;
}