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

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSRe (arr, 0, n - 1);

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;

}