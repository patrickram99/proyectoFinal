#ifndef PROYECTOFINAL_TELA_H
#define PROYECTOFINAL_TELA_H
#include <fstream>
#include <iomanip>
#include <string>
#include "Config.h"

struct Reporte{
    int    cantVentasTotales = 0;
    int    cantmetrosVendidos = 0;
    double importesTotales = 0;
};

class Tela{
    string      m_identificador;
    string      m_descripcion;
    string      m_material;
    int         m_ancho;
    int         m_peso;
    double      m_precio;
    Reporte     m_datosReporte;


public:
    Tela(){}

    Tela(string &identificador, string &descripcion, string &material,
         int ancho, int peso, double precio)
            : m_identificador   (identificador)
            , m_descripcion     (descripcion)
            , m_material        (material)
            , m_ancho           (ancho)
            , m_peso            (peso)
            , m_precio          (precio)
    {
    }

    string cantidadOptima(int num){
        if(num > metrosOptimos){
            return (to_string(num) + " (" + to_string(num - metrosOptimos) + " mas que la cantidad optima)");
        } else if( num == metrosOptimos){
            return " (Igual a la cantidad optima)";
        } else {
            return "false";
        }
    }

    void imprimirTxt(ofstream &fichero){
        fichero << m_identificador  << endl
                << m_descripcion    << endl
                << m_material       << endl
                << m_ancho          << endl
                << m_peso           << endl
                << m_precio         << endl;
    }

    void imprimirReporte(){
        cout << setprecision(2) << fixed << left
             << setw(18) << "Codigo"                             << setw(3) << ":"  << setw(10) << m_identificador                    << endl
             << setw(18) << "Descripcion"                        << setw(3) << ":"  << setw(10) << m_descripcion                      << endl
             << setw(18) << "Cantidad total de ventas"           << setw(3) << ":"  << setw(10) << m_datosReporte.cantVentasTotales   << endl
             << setw(18) << "Cantidad total de metros vendidos"  << setw(3) << ":"  << setw(10) << m_datosReporte.cantmetrosVendidos  << endl
             << setw(18) << "Importe total acumulado"            << setw(3) << ":"  << setw(10) << m_datosReporte.importesTotales     << endl;
    }

    void imprimirReporteTelasOptimas(){
        string temp = cantidadOptima(m_datosReporte.cantmetrosVendidos);
        if(temp != "false"){
            cout << setprecision(2) << fixed << left
                 << setw(18) << "Codigo"                             << setw(3) << ":"  << setw(10) << m_identificador                    << endl
                 << setw(18) << "Descripcion"                        << setw(3) << ":"  << setw(10) << m_descripcion                      << endl
                 << setw(18) << "Metros vendidos"                    << setw(3) << ":"  << setw(10) << temp << endl;
        }
    }

    double getImporteParcial(){
        return m_datosReporte.importesTotales;
    }

    string getID() const{
        return m_identificador;
    }

    string getDescripcion() const{
        return m_descripcion;
    }
    double getPrecio() const{
        return m_precio;
    }

    void actualizarReporte(int metros, double importe){
        m_datosReporte.cantmetrosVendidos += metros;
        m_datosReporte.importesTotales += importe;
        m_datosReporte.cantVentasTotales++;
    }

    void imprimir() const{
        cout << "Codigo "      << m_identificador << endl
             << "Descripcion: "<< m_descripcion   << endl
             << "Material: "   << m_material      << endl
             << "Ancho: "      << m_ancho         << endl
             << "Peso: "       << m_peso          << endl
             << "Precio: "     << m_precio        << endl;
    }

    void modificarTela(int aspecto) {
        string mod;
        switch (aspecto) {
            case 0:
                cout << "Ingrese el nuevo valor de la descripcion: " << endl;
                cin.ignore();
                getline(cin, mod);
                m_descripcion = mod;
                break;
            case 1:
                cout << "Ingrese el nuevo valor: " << endl;
                cin.ignore();
                getline(cin, mod);
                m_material = mod;
                break;
            case 2:
                cout << "Ingrese el nuevo valor: " << endl;
                cin.ignore();
                getline(cin, mod);
                m_ancho = stoi(mod);
                break;
            case 3:
                cout << "Ingrese el nuevo valor: " << endl;
                cin.ignore();
                getline(cin, mod);
                m_peso = stoi(mod);
                break;
            case 4:
                std::cout << "Ingrese el nuevo valor: " << std::endl;
                cin.ignore();
                getline(cin, mod);
                m_precio = std::stod(mod);
                break;
            default:
                std::cout << "Ingrese un identificador valido: ";
        }
    }

};

static vector<Tela> dataTelas;

vector<Tela> cargarTelas(string const &fichero){
    ifstream    telasData(fichero);
    string      identificador, descripcion, material, temp;
    int         ancho, peso;
    double      precio;
    if(telasData.is_open()) {
        while (getline(telasData, identificador)){
            getline(telasData, descripcion);
            getline(telasData, material);
            getline(telasData, temp);
            ancho = stoi(temp);
            getline(telasData, temp);
            peso = stoi(temp);
            getline(telasData, temp);
            precio = stod(temp);
            dataTelas.emplace_back(Tela(identificador, descripcion, material, ancho, peso, precio));
        }
    } else{
        cout << "No se pudo abrir el archivo: " + fichero << endl;
    }
    telasData.close();
    return dataTelas;
}
#endif //PROYECTOFINAL_TELA_H