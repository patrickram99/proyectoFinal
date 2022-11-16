#ifndef PROYECTOFINAL_TELA_H
#define PROYECTOFINAL_TELA_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Telas {
    std::string m_identificador;
    std::string m_descripcion;
    std::string m_material;
    int m_ancho;
    int m_peso;
    double m_precio;

public:

    Telas(){};

    Telas(std::string &identificador, std::string &descripcion, std::string &material, int ancho, int peso, double precio)
            : m_identificador(identificador)
            , m_descripcion(descripcion)
            , m_material(material)
            , m_ancho(ancho)
            , m_peso(peso)
            , m_precio(precio)
    {
    }

    std::string getDescripcion(){
        return m_descripcion;
    }
    int getPrecio(){
        return m_precio;
    }

    void imprimir() const{
        std::cout << "Codigo "      << m_identificador << std::endl
                  << "Descripcion: "<< m_descripcion   << std::endl
                  << "Material: "   << m_material      << std::endl
                  << "Ancho: "      << m_ancho         << std::endl
                  << "Peso: "       << m_peso          << std::endl
                  << "Precio: "     << m_precio        << std::endl;
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
        }
    }
};

class Ventas{
    int mv_numBoleta; //Numero de boleta
    std::string mv_descTela; // Descripcion de la tela
    double mv_pMetro; // Precio por metro
    int mv_cMetro; //Cantidad de metro
    double mv_impCompra; //Importe de la compra
    double mv_cantDescuento; //Monto de descuento
    double mv_impPagar; //Importe a pagar

public:

    Ventas(){};

    Ventas(Telas &a, int cant, double desc)
    : mv_descTela(a.getDescripcion())
    , mv_pMetro(a.getPrecio())
    , mv_cMetro(cant)
    , mv_impCompra(cant * a.getPrecio())
    , mv_cantDescuento(desc)
    , mv_impPagar(mv_impCompra - mv_impCompra * desc/100)

    {
    }


};



class Inventario{
    std::string mi_fecha;
    std::vector<Telas> mi_telas;
    std::vector<double> mi_descuentos;
    std::vector<Ventas> mi_ventas;

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

    std::vector<double> getConfig(){
        return mi_descuentos;
    };


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

    void cargarConfig(const std::string &fichero){
        std::ifstream telasFichero(fichero);
        double temp;
        while (telasFichero >> temp) {
            mi_descuentos.push_back(temp);
        }
    }
    void nuevaVenta(){

    }


    void registrarVenta(){
        int m;
        std::cout << "Ingrese el numero de metros vendidos: " << std::endl;
        std::cin >> m;

    };
};

#endif //PROYECTOFINAL_TELA_H