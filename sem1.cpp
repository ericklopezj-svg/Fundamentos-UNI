#include <iostream>
using namespace std;

void imprimir (int arr[], int n) {
    for (int i=0; i<n;  i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;
}

void bubbleSort (int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-1-i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void selectionSort (int arr[], int n){
    for (int i=0; i<n - 1; i++) {
        int min = i;
        for (int j=i + 1; j<n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}


void insertionSort (int arr[], int n) {
    for (int i=1; i<n; i++) {
        int temp = arr[i]; // tomo mi carta
        int j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        arr[j + 1] = temp; // el j + 1 justamente es el hueco que hice para mi carta, asi que meto mi carta aqui
    }
}

void mezclar (int arr[], int temp[], int inicio, int medio, int fin) {
    for (int i=inicio; i<=fin; i++) {
        temp[i] = arr[i];
    }

    int i = inicio;
    int j = medio + 1;
    int k = inicio; //para ir redactando el arreglo original

    while (i <= medio && j <= fin) {
        if (temp[i] <= temp[j]) {
            arr[k] = temp[i];
            i++;
        } else {
            arr[k] = temp[j];
            j++;
        }

        k++;
    }

    while (i <= medio) { //solo si es que quedan elementos en la mitad izquierda
        arr[k] = temp[i];
        i++;
        k++;
    }

    //si quedase en la mitad derecha ya no es necesario, ya que ya esta donde debe estar
}

void mergeSort (int arr[], int temp[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = inicio + (fin - inicio)/2;

        mergeSort (arr, temp, inicio, medio); //para la mitad izquierda
        mergeSort (arr, temp, medio + 1, fin); //para la mitad derecha

        mezclar (arr, temp, inicio, medio, fin);
        
    }
}


void quickSort (int arr[], int inicio, int fin) {
    if (inicio < fin) {
        int pivote = arr[fin];

        int i = inicio - 1;

        for (int j = inicio; j < fin; j++) { //como vemos nuestro for no recorre todo el arreglo, esto es porque nuestro pivote justo es el ultimo
            if (arr[j] < pivote) {
                i++;

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

        }

        int temp = arr[i + 1]; //cuidado con poner pivote en vez de arr[fin], ya que queremos intercambiar fisicamente valores del arr, no nos importa el pivote
        arr[i + 1] = arr[fin];
        arr[fin] = temp;

        

        int indPivote = i + 1;
        quickSort (arr, inicio, indPivote - 1);
        quickSort (arr, indPivote + 1, fin);
    }


}
int main() {
    int arr[] = {99, 57, 4, 2, 15, 84, 72};
    int n = sizeof(arr) / sizeof(arr[0]);
    //int temp[n];

    

    /*cout <<"El arreglo ordenado por bubble sort es ";
    bubbleSort (arr, n);
    

    cout <<"El arreglo ordenado por selection sort es ";
    selectionSort (arr, n);


    cout <<"El arreglo ordenado por insertion sort es ";
    insertionSort (arr, n);
    imprimir (arr, n);

    cout <<"El arreglo ordenado por merge sort es ";
    mergeSort (arr, temp, 0, n - 1);*/

    cout <<"El arreglo ordenado por merge sort es ";
    quickSort (arr, 0, n - 1);
    imprimir (arr, n);
    return 0;
}