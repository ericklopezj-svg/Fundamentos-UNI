#include <iomanip>
#include <iostream>
using namespace std;

void intercambiar (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void BurbujaRecursivo (int* &array, const int &n) {
    if (n == 1) {
        return;
    }

    int j = 0;
    while (j < n - 1) {
        if (array[j] > array[j + 1]) {
            intercambiar (array[j], array[j + 1]);
        }
        j++;
    }

    BurbujaRecursivo (array, n - 1);
}

void CreateVector (int* &ptr, int &n) {
    ptr = new int [n];
}

void ReadArray (int* &ptr, int &n, istream& cin) {
    for (int i = 0; i < n; i++) {
        cin >> ptr[i]; 
    }
}

void PrintArray (int* &ptr, int &n, ostream& cout) {
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << left << setw (4) << ptr[i]; 
    }
}

void intercambiar (int* &ptr1, int* &ptr2) {
    int* temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

void DestroyVector (int* &ptr) {
    delete[] ptr;
}

int main() {
    int* vec1 = nullptr;
    int* vec2 = nullptr;
    int size = 10;

    CreateVector (vec1, size);
    ReadArray (vec1, size, cin);
    BurbujaRecursivo (vec1, size);
    PrintArray (vec1, size, cout);

    CreateVector (vec2, size);
    ReadArray (vec2, size, cin);
    BurbujaRecursivo (vec2, size);
    PrintArray (vec2, size, cout);

    intercambiar (vec1, vec2);
    PrintArray (vec1, size, cout);
    PrintArray (vec2, size, cout);

    DestroyVector (vec1);
    DestroyVector (vec2);

    return 0;
}