#include <iostream>
using namespace std;

void insertionSRe (int arr[], int n) {
    if (n < 1) {
        return;
    } 

    insertionSRe (arr, n - 1);

    int temp = arr[n];
    int j = n - 1;
    while (j >= 0 && arr[j] > temp) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = temp;
}

