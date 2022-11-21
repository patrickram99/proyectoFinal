#ifndef PROYECTOFINAL_INVENTARIO_H
#define PROYECTOFINAL_INVENTARIO_H
#include <iostream>
#include <vector>
#include "Tela.h"
#include "Venta.h"
#include "Config.h"

class Inventario {
    string          mi_fecha;               //Vector de inventario para guardar versiones
    vector<Tela>    mi_telas;               //Vector de telas
    vector<double>  mi_descuentos;          //Vector de configuración
    string          mi_inventarioVentas;

public:
    Inventario(){}

    Inventario(string const &fecha, string const &telas, string const &ventas, string const &config)
            : mi_fecha(fecha)
            , mi_telas(cargarTelas(telas))
            , mi_descuentos(cargarConfiguracion(config))
            , mi_inventarioVentas(ventas)
    {
    }

    void generarBoletas(){
        for(auto &v: registroVentas){
            string nombreBoleta = "D:\\Lenguaje de Programacion 1\\proyectoFinal\\boletas_" + to_string(numBoleta) + ".txt";
            ofstream boleta(nombreBoleta);
            v.guardarVentaTxt(v, boleta);
            numBoleta++;
        }
    }

    void consultarTela(int id){
        mi_telas[id].imprimir();
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
        for(auto &t: mi_telas){
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
        for(auto t: mi_telas){
            t.imprimirTxt(guardaTelas);
        }
        guardarConfig << metrosOptimos;
        guardarConfig.close();
    }

};
#endif //PROYECTOFINAL_INVENTARIO_H
