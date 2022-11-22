#ifndef PROYECTOFINAL_VENTA_H
#define PROYECTOFINAL_VENTA_H
#include <iomanip>
#include "Tela.h"
#include "Config.h"

using namespace std;
static int numBoleta;

class Venta{
    Tela mv_Tela;
    int mv_metrosVendidos;
    double mv_descPorcentaje;
    double mv_impCompra = mv_metrosVendidos * mv_Tela.getPrecio();
    double mv_impDescuento = mv_impCompra * mv_descPorcentaje / 100;
    double mv_impPagar = mv_impCompra - mv_impDescuento;

    double setDescuento(int can) {
        double descuento;
        if(can <= 5){
            descuento = registroConfig[0];
        } else if (can > 5 && can <= 10){
            descuento = registroConfig[1];
            descuento = registroConfig[1];
        } else if (can > 10 && can <= 15) {
            descuento = registroConfig[2];
        } else{
            descuento = registroConfig[3];
        }
        return descuento;
    }
public:
    Venta(){}
    Venta(int id, int metros, double descPorcentaje)
            : mv_Tela(dataTelas[id])
            , mv_metrosVendidos(metros)
            , mv_descPorcentaje(descPorcentaje)
    {
    }

    Venta(Tela &id, int metros, double descPorcentaje)
            : mv_Tela(id)
            , mv_metrosVendidos(metros)
            , mv_descPorcentaje(descPorcentaje)
    {
    }

    Tela getTela(){
        return mv_Tela;
    }

    double getImportePagar(){
        return mv_impPagar;
    }

    void guardarVentaTxt(Venta &v, std::ofstream &fic){
        fic << setprecision(2) << fixed << left
            << setw(18) << "BOLETA DE VENTA"    << setw(3) << ":"  << setw(10) << numBoleta                     << endl
            << setw(18) << "Tela"               << setw(3) << ":"  << setw(10) << v.mv_Tela.getDescripcion()    << endl
            << setw(18) << "Precio"             << setw(3) << ":"  << setw(10) << v.mv_Tela.getPrecio()         << endl
            << setw(18) << "Cantidad"           << setw(3) << ":"  << setw(10) << mv_metrosVendidos             << endl
            << setw(18) << "Importe compra"     << setw(3) << ":"  << setw(10) << mv_impCompra                  << endl
            << setw(18) << "Descuento"          << setw(3) << ":"  << setw(10) << mv_impDescuento               << endl
            << setw(18) << "Importe pagar"      << setw(3) << ":"  << setw(10) << mv_impPagar                   << endl;
        fic.close();
    }

    int getIDTela(){
        return stoi(mv_Tela.getID().substr(2, 1));
    }

    int getMetrosVendidos(){
        return mv_metrosVendidos;
    }

    double getDescuendtoPorcentjae(){
        return mv_descPorcentaje;
    }

};

static vector<Venta> registroVentas;

void cargarVentas(string const &fichero){
    int id, m;
    double desc;
    ifstream registroV(fichero);
    if(registroV.is_open()){
        registroV >> numBoleta;
        numBoleta = 1;
        while (registroV >> id){
            registroV >> m >> desc;
            registroVentas.emplace_back(Venta(dataTelas[id], m, desc));
        }
    } else{
        numBoleta = 1;
    }
    registroV.close();
}

void registrarVentas(){
    int registro;
    do {
        int can;
        int id;
        std::cout << "Ingrese el identificador del tipo de tela: " << std::endl;
        std::cin >> id;
        std::cout << "Ingrese el numero de metros vendidos: " << std::endl;
        std::cin >> can;
        Venta temp = Venta(dataTelas[id], can, setDescuento(can));
        registroVentas.emplace_back(Venta(dataTelas[id], can, setDescuento(can)));
        std::cout << "Desea registrar mas ventas: (0 para terminar)" << std::endl;
        std::cin >> registro;
        dataTelas[id].actualizarReporte(can, temp.getImportePagar());
    } while (registro != 0);
}
#endif //PROYECTOFINAL_VENTA_H
