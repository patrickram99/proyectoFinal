#include <iostream>
#include "Inventario.h"

using namespace std;
int main() {
    Inventario v1 = Inventario("adsjashkjs", "telas-data.txt", "ventas.txt", "config-tienda.txt");
    cargarVentas("ventas.txt");
    int op;
    do{
        cout << "Que operacion desea realizar. Ingrese el numero correspondiente" << endl
             << "1. Mantenimiento" << endl
             << "2. Vender"        << endl
             << "3. Reportes"      << endl
             << "4. Configuracion" << endl
             << "5. Salir"         << endl;
        cin >> op;
        switch (op) {
            default:
                op = 5;
                break;
            case 1:
                v1.mantenimiento();
                break;
            case 2:
                v1.ventasTotales();
                break;
            case 3:
                v1.menureportes();
                break;
            case 4:
                v1.menuConfiguracion();
                break;
        }
    } while(op != 5);
    v1.generarBoletas();
    v1.guardarInventario();
    return 0;
}