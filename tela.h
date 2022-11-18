#ifndef PROYECTOFINAL_TELA_H
#define PROYECTOFINAL_TELA_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

struct Reporte{
    int         metrosTotales = 0;
    int         ventasEfectuadas = 0;
    double      ventasTotales = 0;
};


class Telas {
    std::string     m_identificador;
    std::string     m_descripcion;
    std::string     m_material;
    int             m_ancho;
    int             m_peso;
    double          m_precio;

public:

    Telas(){};

    Telas(std::string &identificador, std::string &descripcion, std::string &material, int ancho, int peso, double precio)
            : m_identificador   (identificador)
            , m_descripcion     (descripcion)
            , m_material        (material)
            , m_ancho           (ancho)
            , m_peso            (peso)
            , m_precio          (precio)
    {
    }
    Reporte         m_dataReporte;
    std::string getDescripcion(){
        return m_descripcion;
    }
    double getPrecio() const{
        return m_precio;
    }
    std::string getID() const{
        return m_identificador;
    }

    void imprimir() const{
        std::cout << "Codigo "      << m_identificador << std::endl
                  << "Descripcion: "<< m_descripcion   << std::endl
                  << "Material: "   << m_material      << std::endl
                  << "Ancho: "      << m_ancho         << std::endl
                  << "Peso: "       << m_peso          << std::endl
                  << "Precio: "     << m_precio        << std::endl;
    }

    void imprimirReporte() const{
        std::cout        << std::setprecision(2) << std::fixed << std::left <<
        std::setw(30)    << "Codigo "                                << std::setw(10) <<    m_identificador  << std::endl <<
        std::setw(30)    << "Descripcion: "                          << std::setw(10) <<    m_descripcion    << std::endl <<
        std::setw(30)    << "Cantidad total de ventas: "             << std::setw(10) <<    m_dataReporte.ventasEfectuadas      << std::endl <<
        std::setw(30)    << "Cantidad total de metros vendidos: "    << std::setw(10) <<    m_dataReporte.metrosTotales          << std::endl <<
        std::setw(30)    << "Importe total acumulado: "             << std::setw(10) <<    m_dataReporte.ventasTotales     << std::endl;
    }

    void editarTela(int aspecto) {
        std::string mod;
        switch (aspecto) {
            case 0:
                std::cout << "Ingrese el nuevo valor de la descripcion: " << std::endl;
                std::cin >> mod;
                m_descripcion = mod;
                break;
            case 1:
                std::cout << "Ingrese el nuevo valor: " << std::endl;
                std::cin >> mod;
                m_material = mod;
                break;
            case 2:
                std::cout << "Ingrese el nuevo valor: " << std::endl;
                std::cin >> mod;
                m_ancho = std::stoi(mod);
                break;
            case 3:
                std::cout << "Ingrese el nuevo valor: " << std::endl;
                std::cin >> mod;
                m_peso = std::stoi(mod);
                break;
            case 4:
                std::cout << "Ingrese el nuevo valor: " << std::endl;
                std::cin >> mod;
                m_precio = std::stod(mod);
                break;
            default:
                std::cout << "Ingrese un identificador valido: ";
        }
    }
};

class Ventas{
    int             mv_numBoleta;       //Numero de boleta
    std::string     mv_descTela;        // Descripción de la tela
    double          mv_pMetro;          // Precio por metro
    int             mv_cMetro;          //Cantidad de metro
    double          mv_impCompra;       //Importe de la compra
    double          mv_cantDescuento;   //Porcentaje del descuento
    double          mv_pagoDescuento;   //Cantidad numérica de descuento
    double          mv_impPagar;        //Importe a pagar

public:

    Ventas(){};

    Ventas(int numBoleta, Telas &a, int cant, double desc)
    : mv_numBoleta          (numBoleta)
    , mv_descTela           (a.getDescripcion())
    , mv_pMetro             (a.getPrecio())
    , mv_cMetro             (cant)
    , mv_impCompra          (cant * a.getPrecio())
    , mv_cantDescuento      (desc)
    , mv_pagoDescuento      (mv_impCompra * mv_cantDescuento/100)
    , mv_impPagar           (mv_impCompra - mv_pagoDescuento)
    {
    }


    void imprimirVenta(){
        std::cout << std::setprecision(2) << std::fixed << std::left
                  << std::setw(18) << "BOLETA DE VENTA"    << std::setw(3) << ":"  << std::setw(10) << mv_numBoleta        << std::endl
                  << std::setw(18) << "Tela"               << std::setw(3) << ":"  << std::setw(10) << mv_descTela         << std::endl
                  << std::setw(18) << "Precio"             << std::setw(3) << ":"  << std::setw(10) << mv_pMetro           << std::endl
                  << std::setw(18) << "Cantidad"           << std::setw(3) << ":"  << std::setw(10) << mv_cMetro           << std::endl
                  << std::setw(18) << "Importe compra"     << std::setw(3) << ":"  << std::setw(10) << mv_impCompra        << std::endl
                  << std::setw(18) << "Descuento"          << std::setw(3) << ":"  << std::setw(10) << mv_pagoDescuento    << std::endl
                  << std::setw(18) << "Importe pagar"      << std::setw(3) << ":"  << std::setw(10) << mv_impPagar         << std::endl;
    }

    void guardarVentaTxt(Ventas &v, std::ofstream &fic){
        fic << std::setprecision(2) << std::fixed << std::left
               << std::setw(18) << "BOLETA DE VENTA"    << std::setw(3) << ":"  << std::setw(10) << mv_numBoleta        << std::endl
               << std::setw(18) << "Tela"               << std::setw(3) << ":"  << std::setw(10) << mv_descTela         << std::endl
               << std::setw(18) << "Precio"             << std::setw(3) << ":"  << std::setw(10) << mv_pMetro           << std::endl
               << std::setw(18) << "Cantidad"           << std::setw(3) << ":"  << std::setw(10) << mv_cMetro           << std::endl
               << std::setw(18) << "Importe compra"     << std::setw(3) << ":"  << std::setw(10) << mv_impCompra        << std::endl
               << std::setw(18) << "Descuento"          << std::setw(3) << ":"  << std::setw(10) << mv_pagoDescuento    << std::endl
               << std::setw(18) << "Importe pagar"      << std::setw(3) << ":"  << std::setw(10) << mv_impPagar         << std::endl;
        fic.close();
    }

    double getVentaTotal() const{
        return mv_impPagar;
    }

};

class Inventario{
    std::string             mi_fecha;      //Vector de inventario para guardar versiones
    std::vector<Telas>      mi_telas;      //Vector de telas
    std::vector<double>     mi_descuentos; //Vector de configuración
    std::vector<Ventas>     mi_ventas;     //Vector de ventas


    //Función para retornar un número en base a un string para poder usar switch case en las funciones
    std::vector<std::string> nombres = {"Descripcion", "Material", "Ancho", "Peso", "Precio"};
    int num(std::string &as){
        for(int id = 0; id < 5; id++){
            if(nombres[id] == as){
                return id;
            }
        }
    }

public:
    Inventario(){}

    Inventario(const std::string &fecha)
            :  mi_fecha(fecha)
    {
    }

    //Funciones del menu de mantenimiento

    void cargarTelas(const std::string &fichero){
        std::string identificador, descripcion, material;
        std::string temp;
        int ancho, peso;
        double precio;
        std::ifstream telasFichero(fichero);
        while (std::getline(telasFichero, identificador)) {
            std::getline(telasFichero, descripcion);
            std::getline(telasFichero, material);
            std::getline(telasFichero,temp);
            ancho = stoi(temp);
            std::getline(telasFichero,temp);
            peso = stoi(temp);
            std::getline(telasFichero,temp);
            precio = stod(temp);
            nuevaTela(Telas(identificador, descripcion, material, ancho, peso, precio));
        }
        telasFichero.close();
    }

    void nuevaTela(const Telas &t){
        mi_telas.push_back(t);
    }

    void consultarTela(int num){
        mi_telas[num].imprimir();
    }

    void listar() const{
        std::cout << "LISTADO DE TELAS: " << std::endl;
        for(auto &t : mi_telas){
            t.imprimir();
            std::cout << std::endl;
        }
    }

    void modificarTela() {
        int pos;
        std::string aspecto;
        std::cout << "Ingrese el identificador de la tela a modificar: " << std::endl;
        std::cin >> aspecto;
        pos = std::stoi(aspecto.substr(2, 1));
        std::cout << "Ingrese el aspecto a modificar: " << std::endl;
        std::cin >> aspecto;
        mi_telas[pos].editarTela(num(aspecto));
        mi_telas[pos].imprimir();
    }

    //Funciones del menu de venta
    void cargarConfig(const std::string &fichero){
        std::ifstream telasFichero(fichero);
        double temp;
        while (telasFichero >> temp) {
            mi_descuentos.push_back(temp);
        }
    }

    void nuevaVenta(const Ventas &v){
        mi_ventas.push_back(v);
    }

    double static setDescuento(std::vector<double> &d, int can){
        double descuento;
        if(can <= 5){
            descuento = d[0];
        } else if (can > 5 && can <= 10){
            descuento = d[1];
        } else if (can > 10 && can <= 15) {
            descuento = d[2];
        } else{
            descuento = d[3];
        }
        return descuento;
    }

    void static generarBoletas(std::vector<Ventas> &ventas){
        int i = 1;
        for(auto v: ventas){
            std::string nombreBoleta = "D:\\Lenguaje de Programacion 1\\proyectoFinal\\boletas\\boleta_" + std::to_string(i) + ".txt";
            std::ofstream boleta(nombreBoleta);
            v.guardarVentaTxt(v, boleta);
            i++;
        }
    }

    void registrarVenta(){
        cargarConfig("config-tienda.txt");
        std::string registro = "Si";
        int numBoleta = 0;
        while(registro == "Si"){
            numBoleta++;
            int can;
            int id;
            std::cout << "Ingrese el identificador del tipo de tela: " << std::endl;
            std::cin >> id;
            std::cout << "Ingrese el numero de metros vendidos: " << std::endl;
            std::cin >> can;

            double desc = setDescuento(mi_descuentos, can);
            Ventas temp = Ventas(numBoleta, mi_telas[id], can, desc);
            nuevaVenta(temp);

            mi_telas[id].m_dataReporte.metrosTotales += can;
            mi_telas[id].m_dataReporte.ventasEfectuadas += 1;
            mi_telas[id].m_dataReporte.ventasTotales += temp.getVentaTotal();

            std::cout << "Desea registrar mas ventas: (Si para continuar)" << std::endl;
            std::cin >> registro;
        }
        for(auto t: mi_ventas){
            t.imprimirVenta();
        }
        generarBoletas(mi_ventas);
    };

    //Funciones del menú reportes
    void reportesVentasPorTela(){
        double totalImportes = 0;
        std::cout << std::setw(20)    <<  "VENTAS POR TELA" << std::endl << std::endl;
        for(auto &t: mi_telas){
            totalImportes += t.m_dataReporte.ventasTotales;
            t.imprimirReporte();
        }
        std::cout << std::endl << std::endl << "Importe total acumulado general: " << totalImportes << std::endl;
    }

    void reportesTelasOptimas(){
        std::cout << "TELAS CON VENTA OPTIMA: " << std::endl << std::endl;
        for(auto &t : mi_telas){
            if(t.m_dataReporte.metrosTotales > mi_descuentos[5]){
                std::cout << std::setw(20) << "Codigo" << std::setw(3) << ":" << std::setw(20) << t.getID()
                          << std::setw(20) << "Descripcion" << std::setw(3) << ":" << std::setw(20) << t.getDescripcion()
                          << std::setw(20) << "Metros vendidos" << std::setw(3) << ":" << std::setw(20) << t.m_dataReporte.metrosTotales
                          << " (" << t.m_dataReporte.metrosTotales - mi_descuentos[5] << " más que la cantidad optima)"<< std::endl << std::endl;
            }
        }
    }

    void menuReportes(Inventario &I){
        char op1;
        std::cout << "1. Ventas por tela, 2. Telas con venta optima";
        std::cin >> op1;
        if(op1 == '1'){
            I.reportesVentasPorTela();
        } else{
            I.reportesTelasOptimas();
        }
    }


    //Funciones menu configuracion
    void menuConfig(Inventario &I){
        int op1;
        double nuevoValor;
        std::cout << "1. Configurar descuentos, 2. Configurar venta optima";
        std::cin >> op1;
        if(op1 == '1'){
            std::cout << "Descuento a modificar (0, 1, 2, 3, 4)";
            std::cin >> op1;
            std::cout << "Ingrese el nuevo valor: ";
            std::cin >> nuevoValor;
            for(int i = 0; i < 5; ++i){
                if(i == op1){
                    mi_descuentos[i] = nuevoValor;
                }
            }
        } else{
            std::cout << "Ingrese el nuevo valor de ventas optimas: ";
            std::cin >> mi_descuentos[5];
        }
    }

};
#endif //PROYECTOFINAL_TELA_H