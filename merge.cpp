#include <iostream>
using namespace std;

void mezclar (int arr[], int temp[], int inicio, int medio, int fin) {
    for (int i = 0; i <= fin; i++) {
        temp[i] = arr[i];
    }

    int i = inicio;
    int j = medio + 1;
    int k = inicio;

    while (i <= medio && j <= fin) {
        if (temp[i] > temp[j]) {
            arr[k] = arr[j];
            j++;
        } else {
            arr[k] = arr[i];
            i++;
        }
        k++;
    }

    while (i <= medio) {
        arr[k] = temp[i];
        i++;
        k++;
    }
}

void mergeSort (int arr[], int temp[], int inicio, int fin) {
    while (inicio < fin) {
        int medio = inicio + (fin - inicio)/2;

        mergeSort (arr, temp, inicio, medio);
        mergeSort (arr, temp, medio + 1, fin);

        mezclar (arr, temp, inicio, medio, fin);
    }
}