#include <iostream>
using namespace std;

void quickSort (int arr[], int inicio, int fin) {
    if (inicio < fin) {
        int pivote = arr[fin];

        int i = inicio - 1;

        for (int j = inicio; j < fin; j++) { //j < fin porque nuestro pivote convenientemente es el último
            if (arr[j] < pivote) {
                i++;

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

        }

        int temp = arr[i + 1]; //cuidado con poner pivote en vez de arr[fin], ya que queremos intercambiar fisicamente valores del arr
        arr[i + 1] = arr[fin];
        arr[fin] = temp;

        

        int indPivote = i + 1;
        quickSort (arr, inicio, indPivote - 1);
        quickSort (arr, indPivote + 1, fin);
    }


}