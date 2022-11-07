#ifndef PROYECTOFINAL_TELACONSTRUCTOR_H
#define PROYECTOFINAL_TELACONSTRUCTOR_H
#include <iostream>
#include <fstream>
#include <vector>
#include "tela.h"

using std::string;

class Tela{
    string              m_identificador;
    string              m_nombre;
    string              m_composicion;
    int                 m_ancho;
    int                 m_peso;
    double              m_precio;
public:
    Tela(){}

    Tela(string &identificador, string &nombre, string &composicion, int ancho, int peso, double precio)
            :m_identificador    (identificador)
            ,m_nombre           (nombre)
            ,m_composicion      (composicion)
            ,m_ancho            (ancho)
            ,m_peso             (peso)
            ,m_precio           (precio)
    {
    }

    void imprimir() const{
        std::cout << "Codigo "      << m_identificador << std::endl
                  << "Descripcion: "<< m_nombre        << std::endl
                  << "Material: "   << m_composicion   << std::endl
                  << "Ancho: "      << m_ancho         << std::endl
                  << "Peso: "       << m_peso          << std::endl
                  << "Precio: "     << m_precio        << std::endl;

    }

};

class Venta{
    Tela m_tipo;
    int m_metros;
    double m_importe;
    double m_descuento;
    double m_totalPagar;
public:
    Venta(Tela &tipo, int metros, double descuento)
            :m_tipo(tipo)
            ,m_metros(metros)
            ,m_descuento(descuento)
    {
    }

};



void almacenarDatos(Tela *datosTelas, string fichero) {
    string identificador, nombre, composicion, anchoS, pesoS, precioS;
    int ancho, peso;
    double precio;
    std::fstream telasFichero;
    telasFichero.open(fichero, std::ios::in);
    if(telasFichero.is_open()){
        // Leer y almacenar los datos del archivo en un array
        while (telasFichero >> identificador){
            std::getline(telasFichero, identificador);
            std::getline(telasFichero, nombre);
            std::getline(telasFichero, composicion);
            std::getline(telasFichero, anchoS);
            std::getline(telasFichero, pesoS);
            std::getline(telasFichero, precioS);
            Tela(identificador, nombre, composicion,
                 std::stoi(anchoS), std::stoi(pesoS), std::stod(precioS));
        }

        telasFichero.close();
    } else{
        std::cout << "No se pudo abrir el archivo";
    }
}

void consultarTela(const Tela* datosTelas){
    string opcion;
    std::cout << "Ingrese el identificador de la tela a consultar: " << std::endl;
    std::cin >> opcion;
    datosTelas[std::stoi(opcion.substr(2, 1))].imprimir();
}

void modificarTela(Tela* &datosTelas) {
    string telaModificar;
    std::vector<string> aspectos = {"Identificador", "Descripcion", "Material", "Ancho", "Peso", "Precio"};
    std::cout << "Ingrese el identificador de la tela a modificar: " << std::endl;
    std::cin >> telaModificar;
    for(int i = 0; i < 5; ++i){
        if(std::stoi(telaModificar.substr(2, 1)) == i){
            std::cout << "Que aspecto desea modificar: ";
            std::cin >> telaModificar;
            for(size_t j = 0; j < aspectos.size(); ++j){
                if(telaModificar == aspectos[j]){

                }
            }

        }
    }
}

void listarTelas(const Tela* datosTelas){
    std::cout << "LISTADO DE TELAS: \n" << std::endl;
    for(int i = 0; i < 5; ++i){
        datosTelas[i].imprimir();
        std::cout << std::endl;
    }
}


#endif //PROYECTOFINAL_TELACONSTRUCTOR_H
