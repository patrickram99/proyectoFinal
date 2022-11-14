#ifndef PROYECTOFINAL_TELA_H
#define PROYECTOFINAL_TELA_H
#include <iostream>
#include <vector>
#include <fstream>

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

    double getPrecio(){
        return m_precio;
    }
    double getAncho(){
        return m_peso;
    }
    double getPeso(){
        return m_peso;
    }
    void imprimir() const{
        std::cout << "Codigo "      << m_identificador << std::endl
                  << "Descripcion: "<< m_descripcion        << std::endl
                  << "Material: "   << m_material   << std::endl
                  << "Ancho: "      << m_ancho         << std::endl
                  << "Peso: "       << m_peso          << std::endl
                  << "Precio: "     << m_precio        << std::endl;

    }

    void cargarDatos(const std::string &fic){
        std::ifstream archivo(fic);
    }
};

class Inventario{
    std::string m_fecha;
    std::vector<Telas> m_telas;

public:
    Inventario(){}

    Inventario(const std::string &fecha)
            :  m_fecha(fecha)
    {
    }

    void cargarDatos(const std::string &fichero){
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


    }

    void nuevaTela(const Telas &t){
        m_telas.push_back(t);
    }

    const std::vector<Telas> &getTelas() const{
        return m_telas;
    }

    void consultarTela(int num){
        m_telas[num].imprimir();
    }

    void listar() const{
        std::cout << "LISTADO DE TELAS: " << std::endl;
        for(auto &t : m_telas){
            t.imprimir();
            std::cout << std::endl;
        }
    }
};


#endif //PROYECTOFINAL_TELA_H