#ifndef PROYECTOFINAL_INVENTARIO_H
#define PROYECTOFINAL_INVENTARIO_H
#include <iostream>
#include <vector>
#include "Tela.h"
#include "Venta.h"
#include "Config.h"

class Inventario {
    string          mi_fecha;
    vector<double>  mi_descuentos;
    string          mi_inventarioVentas;

    string setDate(string const &date, string const &telas){
        cargarTelas(telas);
        return date;
    }

public:
    Inventario(){}

    Inventario(string const &fecha, string const &telas, string const &ventas, string const &config)
            : mi_fecha(setDate(fecha, telas))
            , mi_descuentos(cargarConfiguracion(config))
            , mi_inventarioVentas(ventas)
    {
    }

    void mantenimiento(){
        int op;
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
                cout << "Ingrese la tela que desea consultar: " << endl
                     << "0. TL0" << endl
                     << "1. TL1" << endl
                     << "2. TL2" << endl
                     << "3. TL3" << endl
                     << "4. TL4" << endl;
                cin >> op;
                consultarTela(op);
                break;
            case 2:
                modificarTela();
                break;
            case 3:
                listarTelas();
                break;
        }
    }

    void generarBoletas(){
        for(auto &v: registroVentas){
            string nombreBoleta = "D:\\Lenguaje de Programacion 1\\proyectoFinal\\boletas\\boleta_" + to_string(numBoleta) + ".txt";
            ofstream boleta(nombreBoleta);
            v.guardarVentaTxt(v, boleta);
            numBoleta++;
        }
    }

    void consultarTela(int id){
        dataTelas[id].imprimir();
    }

    void modificarTela() {
        int i = 0;
        int id;
        int aspecto;
        vector<string> nombres = {"Descripcion", "Material", "Ancho", "Peso", "Precio"};
        cout   << "Coloque la opcion relacionada: " << endl;
        for(auto &a : dataTelas){
            cout << i << ". " << a.getID() << endl;
            i++;
        }
        cin >> id;
        i = 0;
        std::cout   << "Coloque la opcion relacionada: " << endl;
        for(auto &a : nombres){
            cout << i << ". " << nombres[i] << endl;
            i++;
        }
        cin >> aspecto;

        dataTelas[id].modificarTela(aspecto);
        cout << "La tela modificada resulta en: " << endl;
        dataTelas[id].imprimir();
    }

    void listarTelas(){
        cout << "LITADO DE TELAS" << endl;
        for(auto &t: dataTelas){
            t.imprimir();
            cout << endl;
        }
    }

    void ventasTotales(){
        registrarVentas();
    }

    void menureportes(){
        int opcion;
        cout << "Coloque el numero relacionado: " << endl
             << "1. Ventas del dia" << endl
             << "2. Ventas generales" << endl;
        cin >> opcion;
        if(opcion == 1){
            cout << "Coloque el numero relacionado: " << endl
                 << "1. Ventas por tela." << endl
                 << "2. Telas con venta optima." << endl;
            cin >> opcion;
            if(opcion == 1){
                double totalImportes = 0;
                cout << "VENTAS POR TELA: " << endl;
                for(auto t: dataTelas){
                    t.imprimirReporte();
                    totalImportes += t.getImporteParcial();
                }
                cout << endl << "Importe total acumulado general: " << totalImportes << endl;
            } else{
                for(auto t: dataTelas){
                    t.imprimirReporteTelasOptimas();
                }
            }
        } else{
            /*
            cout << "Coloque el numero relacionado: " << endl
                 << "1. Ventas por tela." << endl
                 << "2. Telas con venta optima." << endl;
            cin >> opcion;
            if(opcion == 1){
                double totalImportes = 0;
                cout << "VENTAS POR TELA: " << endl;
                for(auto v: registroVentas){
                    v.getTela().getImporteParcial();
                }
                cout << endl << "Importe total acumulado general: " << totalImportes << endl;
            } else{
                for(auto t: dataTelas){
                    t.imprimirReporteTelasOptimas();
                }
            }*/
            cout << "Funcion aun no disponible";
        }
    }

    void menuConfiguracion(){
        double opcion;
        cout << "Coloque el numero relacionado al valor que desea modificar: " << endl
             << "1. Valores de descuento" << endl
             << "2. Metros para venta optima" << endl;
        cin >> opcion;
        if(opcion == 1){
            cout << "Que descuento desea modificar(1, 2, 3, 4)" << endl;
            cin >> opcion;
            cout << "Ingrese el nuevo valor para el descuento " << opcion << endl;
            cin >> opcion;
            mi_descuentos[opcion - 1] = opcion;

        } else{
            cout << "Ingrese el nuevo valor optimo de ventas: " << endl;
            cin >> metrosOptimos;
        }
    }

    void guardarInventario(){
        ofstream historialVentas(mi_inventarioVentas);
        if(historialVentas.is_open()){
            historialVentas << numBoleta << endl;
            for(auto v: registroVentas){
                historialVentas << v.getIDTela() << endl << v.getMetrosVendidos() << endl
                                << v.getDescuendtoPorcentjae() << endl;
            }
        } else{
            cout << "No se puede crear el archivo de historial";
        }

        ofstream guardarConfig("config-tienda.txt");
        for(auto c: mi_descuentos){
            guardarConfig << c << endl;
        }
        guardarConfig << metrosOptimos;
        guardarConfig.close();

        ofstream guardaTelas("telas-data.txt");
        for(auto t: dataTelas){
            t.imprimirTxt(guardaTelas);
        }
        guardarConfig << metrosOptimos;
        guardarConfig.close();
    }

};
#endif //PROYECTOFINAL_INVENTARIO_H