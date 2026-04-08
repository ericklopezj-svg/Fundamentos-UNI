#include <iostream>
using namespace std;

void quickSort (int arr[], int  inicio, int fin) {
    if (inicio < fin) {
        int pivote = arr[fin];
        int i = inicio - 1;

        for (int j = inicio; j < fin; j++) {
            if (arr[j] < pivote) {
                i++;
            }

            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }

        int temp = arr[fin];
        arr[fin] = arr[i + 1];
        arr[i + 1] = temp;

        int indPivote = i + 1;

        quickSort (arr, inicio, indPivote - 1);
        quickSort (arr, indPivote + 1, fin);
    }
}