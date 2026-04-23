#include <iostream>
using namespace std;

int menor (int &a, int &b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

int mayor (int &a, int &b) {
    if (a <= b) {
        return b;
    } else {
        return a;
    }
}

void recorte (int &a, int &b, int contador) {
    int sup = mayor (a, b);
    int inf = menor (a, b);

    if (sup == 1 || sup == inf) {
        cout << contador << " losetas de " << inf << " m de lado" << endl;
        return;
    }

    sup -= inf;

    //esta seccion es para saber si el menor, ahora con el superior recortado, sigue siendo el menor actual
    int inf1 = menor (sup, inf);
    if (inf1 == inf) {
        contador++; //si es que fuese asi entonces contamos
    } else {
        cout << contador << " losetas de " << inf << " m de lado" << endl; //si es que no imprimimos
        contador = 1; //y volvemos a incializar el contador
    }

    recorte (sup, inf, contador);
}
int main() {
    int base, altura;
    cout << "Base: ";
    cin >> base;
    cout << "Altura: ";
    cin >> altura; 

    int contador = 1;
    recorte (base, altura, contador);

    return 0;

}