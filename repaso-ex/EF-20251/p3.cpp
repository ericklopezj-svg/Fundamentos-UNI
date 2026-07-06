#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

struct Ecuacion {
    float a;
    float b;
    float c;
    float d;
};

struct Solucion {
    float x;
    float y;
    float z;
};

struct Sistema {
    int id;
    Ecuacion ec[3];
    char estado[30];
    Solucion solution = {0, 0, 0};
};


float determinanteMatrix (Sistema s) {
    float det = s.ec[0].a * s.ec[1].b * s.ec[2].c + s.ec[0].b * s.ec[1].c * s.ec[2].a + s.ec[0].c * s.ec[1].a * s.ec[2].b
    - s.ec[2].a * s.ec[1].b * s.ec[0].c - s.ec[2].b * s.ec[1].c * s.ec[0].a - s.ec[2].c * s.ec[1].a * s.ec[0].b;

    return det;
}

float determinanteX (Sistema s) {
    for (int i = 0; i < 3; i++) {
        s.ec[i].a = s.ec[i].d;
    }

    return determinanteMatrix (s);

}

float determinanteY (Sistema s) {
    for (int i = 0; i < 3; i++) {
        s.ec[i].b = s.ec[i].d;
    }

    return determinanteMatrix (s);
    
}

float determinanteZ (Sistema s) {
    for (int i = 0; i < 3; i++) {
        s.ec[i].c = s.ec[i].d;
    }

    return determinanteMatrix (s);

}

Sistema sist;
int n = 0;

void redimensionar (Sistema* &ptr) {
    Sistema* temp = new Sistema[n + 1];
    for (int i = 0; i < n; i++) {
        temp[i] = ptr[i];
    }

    delete[] ptr;
    ptr = temp;
    
}

Sistema* lista = nullptr;

int main() {
    fstream miarchivo;
    miarchivo.open ("sistemas.dat", ios::out | ios::in | ios::binary | ios::trunc);
    if (!miarchivo.is_open()) {
        cout << "No se pudo crear el archivo para escribir" << endl;
        return 1;
    }

    
    int opcion = 1;
    bool flag1 = false, flag2 = false, flag3 = false;

    while (opcion != 0) {
        cout << "\n1. Registrar sistema "
            << "\n2. Resolver todos los sistemas"
            << "\n3. Generar reporte"
            << "\n0. Salir\n";

        cin >> opcion;


        if (opcion == 1) {
            if (flag2) {
                cout << "Despues de resolver sistemas ya no se pueden registrar mas" << endl;
                continue;
            }

            flag1 = true;

            redimensionar(lista);
            cout << "\nSistema ID: " << n + 1 << endl;
            lista[n].id = n + 1;

            for (int j = 0; j < 3; j++) {
                cout << "\n>Ecuacion " << j + 1 << endl;
                cout << "Coeficiente de x: ";
                cin >> lista[n].ec[j].a;
                cout << "Coeficiente de y: ";
                cin >> lista[n].ec[j].b;
                cout << "Coeficiente de z: ";
                cin >> lista[n].ec[j].c;
                cout << "Coeficiente independiente: ";
                cin >> lista[n].ec[j].d;
            }
            strncpy(lista[n].estado, "unknow", sizeof(lista[n].estado) - 1);
            lista[n].estado[sizeof(lista[n].estado) - 1] = '\0';

            sist = lista[n];

            miarchivo.write((char*)&sist, sizeof(Sistema));
            n++;

        }

        if (opcion == 2) {
            if (!flag1) {
                cout << "No hay sistemas registrados aun" << endl;
                continue;
            }

            if (flag3) {
                cout << "Ya se resolvieron los sistemas y se realizo el reporte" << endl;
                continue;
            }

            flag2 = true;
            miarchivo.seekp(0);
            for (int i = 0; i < n; i++) {
                
                if (determinanteMatrix(lista[i]) != 0) {
                    strncpy(lista[i].estado, "Unica", sizeof(lista[i].estado) - 1);
                    lista[i].estado[sizeof(lista[i].estado) - 1] = '\0';
                    sist = lista[i];
                    
                    lista[i].solution.x = determinanteX(lista[i]) / determinanteMatrix(lista[i]);
                    lista[i].solution.y = determinanteY(lista[i]) / determinanteMatrix(lista[i]);
                    lista[i].solution.z = determinanteZ(lista[i]) / determinanteMatrix(lista[i]);

                    sist = lista[i];
                    miarchivo.write ((char*)&sist, sizeof(Sistema));

                } else if (determinanteX(lista[i]) == 0 && determinanteY(lista[i]) == 0 && determinanteZ(lista[i]) == 0) {
                    strncpy(lista[i].estado, "Infinita", sizeof(lista[i].estado) - 1);
                    lista[i].estado[sizeof(lista[i].estado) - 1] = '\0';
                    sist = lista[i];

                    miarchivo.write ((char*)&sist, sizeof(Sistema));

                } else {
                    strncpy(lista[i].estado, "Sin solucion", sizeof(lista[i].estado) - 1);
                    lista[i].estado[sizeof(lista[i].estado) - 1] = '\0';
                    sist = lista[i];

                    miarchivo.write ((char*)&sist, sizeof(Sistema));

                }

            }

        }

        if (opcion == 3) {
            flag3 = true;
            if (!flag2) {
                cout << "No se puede hacer el reporte sin antes haber resuelto los sistemas" << endl;
                continue;
            }

            ofstream archivoTexto ("reporte.txt");
            miarchivo.clear();
            miarchivo.seekg(0); 

            while (miarchivo.read((char*)&sist, sizeof(Sistema))) {
                archivoTexto << "Sistema ID: " << sist.id << endl;
                for (int i = 0; i < 3; i++) {
                    archivoTexto << sist.ec[i].a << "x + " << sist.ec[i].b << "y + " << sist.ec[i].c << "z = " << sist.ec[i].d << endl;
                }

                archivoTexto << "Estado: " << sist.estado << endl;

                if (strcmp(sist.estado, "Unica") == 0) {
                    archivoTexto << "Solucion: x = " << sist.solution.x << ", y = " << sist.solution.y << ", z = " << sist.solution.z << endl;
                }

                archivoTexto << setfill('-') << setw(30) << endl;
            }

            cout << "Se realizo el reporte con exito. Ya no se puede agregar ni registrar mas" << endl;
            archivoTexto.close();

        }


    }

    miarchivo.close();

    return 0;

}

