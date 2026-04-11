#include <iostream>
using namespace std;


void selectionSRe (int arr[], int inicio, int fin) {
    if (inicio == fin) {
        return ;
    }

    int i = inicio;
    int min = i;

    for (int j = i + 1; j <= fin; j++) {
        if (arr[j] < arr[min]) {
            min = j;
        }
    }
    
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
    
    selectionSRe (arr, inicio + 1, fin);
}