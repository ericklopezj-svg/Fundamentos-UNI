#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
using namespace std;

struct regVendedor {
    int id;
    double ventasTri[4];
    double ventasTo = 0;
};

struct informeAnual {
    regVendedor* registro;
};

informeAnual global;
int n = 6;

void registroID () {
    for (int i = 0; i < n; i++) {
        cin >> global.registro[i].id;
    }
}

int busquedaID (char id[6]) {
    int idn = atoi(id);
    for (int i = 0; i < n; i++) {
        if (idn == global.registro[i].id) {
            return i;
        }
    }

    return -1;
}

int trimestre (int mes) {
    if (mes <= 3 && mes >= 1) {
        return 1;
    }

    if (mes <=6 && mes >= 4) {
        return 2;
    }

    if (mes >= 7 && mes <= 9) {
        return 3;
    }

    if (mes >= 10 && mes <= 12) {
        return 4;
    }

    return -1;
}

void registroVentas (char id[6], int mes, double monto) {
    int indice = busquedaID(id);

    if (indice == -1) {
        cout << "ID invalido" << endl;
        return;
    }

    int numTrimestre = trimestre(mes);
    if (numTrimestre == -1) {
        cout << "Mes invalido" << endl;
    }

    global.registro[indice].ventasTri[numTrimestre - 1] = monto;
    global.registro[indice].ventasTo += monto;

}

int maximoVendedor () {
    double maximo = 0.0;
    int indice;
    for (int i = 0; i < n; i++) {
        if (maximo < global.registro[i].ventasTo) {
            maximo = global.registro[i].ventasTo;
            indice = i;
        }
    }

    return indice;
}

double ventasTotales (int numTrimestre) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma += global.registro[i].ventasTri[numTrimestre - 1];
    }

    return suma;
}

int mayorTrimestre () {
    double maximo = 0.0;
    int mayorTrimestre;
    for (int i = 0; i < 4; i++) {
        if (maximo < ventasTotales(i + 1)) {
            maximo = ventasTotales(i + 1);
            mayorTrimestre = i;
        }
    } 
    
    return mayorTrimestre + 1;
}

int main() {
    global.registro = new regVendedor[n];
    cout << "Registre los IDs de los vendedores:" << endl;
    registroID();

    int mes;
    double monto;
    char id[6];
    cout << "\nIngrese los datos de ventas: (ID, mes, monto) fin para terminar:" << endl;
    while (strcmp(id, "fin") != 0) {
        cout << "> ";
        cin >> id >> mes >> monto;
        registroVentas(id, mes, monto);
    }

    cout << setfill('-') << setw(45) << "Reporte Anual de Ventas" << setw(15) << "" << endl;
    cout << left << setfill(' ') << setw(10) << "ID" << setw(10) << "Trim 1" << setw(10) << "Trim 2" << setw(10) << "Trim 3" << setw(10) << "Trim 4" << "Total" << endl;
    cout << setfill('=') << setw(60) << "" << endl;

    for (int i = 0; i < n; i++) {
        cout << setfill(' ') << setw(10) << global.registro[i].id << fixed << setprecision(2) << setw(10) << global.registro[i].ventasTri[0] << setw(10) << global.registro[i].ventasTri[1] 
        << setw(10) << global.registro[i].ventasTri[2] << setw(10) << global.registro[i].ventasTri[3] << setw(10) << global.registro[i].ventasTo << endl;
    }
    cout << setw(10) << "Total" << setw(10) << ventasTotales(1) << setw(10) << ventasTotales(2) << setw(10) << ventasTotales(3) << setw(10) << ventasTotales(4) << endl;
    
    int indice = maximoVendedor();
    cout << "\nMaxima venta por Vendedor: ID = " << global.registro[indice].id << ", cantidad = S/" << global.registro[indice].ventasTo << endl;
    cout << "Maxima venta por Trimestre: Trimestre " << mayorTrimestre() << ", cantidad = S/" << ventasTotales(mayorTrimestre()) << endl;

    return 0;
}