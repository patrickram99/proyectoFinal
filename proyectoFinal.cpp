#include <iostream>
#include "Inventario.h"

using namespace std;
int main() {
    std::cout << "Hello, World! " << numBoleta << endl;
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
                cout << "MANTENIMIENTO" << endl
                     << "¿Qué operacion desea realizar?. Ingrese el numero correspondiente" << endl
                     << "1. Consultar tela" << endl
                     << "2. Modificar tela" << endl
                     << "3. Listar telas" << endl;
                cin >> op;
                switch (op) {
                    default:
                        cout << "Ingrese una opcion valida";
                    case 1:
                        cout << "Ingrese la tela que desea consultar: "
                             << "0. TL0" << endl
                             << "1. TL1" << endl
                             << "2. TL2" << endl
                             << "3. TL3" << endl
                             << "4. TL4" << endl;
                        cin >> op;
                        v1.consultarTela(op);
                    case 2:
                        v1.modificarTela();
                    case 3:
                        v1.listarTelas();
                }
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
