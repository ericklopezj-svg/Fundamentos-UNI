#include <iostream>
using namespace std;

void bubbleRe (int arr[], int n) {

    if (n == 1) {
        return;
    }

    int j = 0;
    while (j < n - 1) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp; 
        }
        j++;
    }

    bubbleRe (arr, n - 1);

}