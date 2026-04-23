#include <iostream>
using namespace std;

void Merge (int a[], int tama, int b[], int tamb, int R[]) {
    int i = 0, j = 0, k = 0;

    while (i < tama && j < tamb) {
        if (a[i] < b[j]) {
            R[k] = a[i];
            i++;
        } else {
            R[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < tama) {
        R[k] = a[i];
        k++;
        i++;
    }

    while (j < tamb) {
        R[k] = b[j];
        j++;
        k++;
    }
}

void QuickSortRecursivo (int arr[], int inicio, int fin) {
    if (inicio < fin) {
        int pivote = arr[fin];
        int i = inicio - 1;
        
        for (int j = inicio; j < fin; j++) {
            if (arr[j] < pivote) {
                i++;

                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[fin];
        arr[fin] = temp;

        int indPivote = i + 1;
        QuickSortRecursivo (arr, inicio, indPivote - 1);
        QuickSortRecursivo (arr, indPivote + 1, fin);
    }  
}

void imprimir (int arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }

}

int main() {
    int vec1[] = {7, 2, 5, 10};
    int tvec1 = sizeof(vec1)/sizeof(vec1[0]);
    int vec2[] = {5, 2, 18, 1, 0, 14, 7, 3, 6};
    int tvec2 = sizeof(vec2)/sizeof(vec2[0]);

    cout << "Los vectores son" << endl;
    cout << "vec1 = { ";
    imprimir (vec1, tvec1);
    cout << "}" << endl;


    cout << "vec2 = { ";
    imprimir (vec2, tvec2);
    cout << "}" << endl;

    QuickSortRecursivo (vec1, 0, tvec1 - 1);
    QuickSortRecursivo (vec2, 0, tvec2 - 1);
    
    cout << "ordenando" << endl;

    int R[tvec1 + tvec2];
    Merge (vec1, tvec1, vec2, tvec2, R);

    cout << "Resultado: ";
    imprimir (R, tvec1 + tvec2);

    return 0;
    
    
}