#include <iostream>
#include <fstream>
#include <string>
#include "tela.h"

int main()
{
    //Declaramos un vector dinamico para almacenar los datos de las telas
    int numTelas = 5;
    tela* datosTelas;
    datosTelas = new tela[numTelas];

    almacenarDatos(datosTelas,"telas-data.txt");

    string opcion;
    std::cout << "Elija una opcion: Mantenimiento, Vender, Reportes, Configuracion o Salir"<< std::endl;
    std::getline(std::cin, opcion);

    if(opcion == "Mantenimiento"){
        std::cout <<"Desea Consultar tela, Modificar tela o Listar"<<std::endl;
        std::getline(std::cin, opcion);
        if(opcion == "Consultar tela"){
            std::cout << "Ingrese el identificador de la tela a consultar: " << std::endl;
            std::cin >> opcion;
            std::cout << datosTelas[std::stoi(opcion.substr(2, 1))];
        } else if(opcion == "Modificar tela"){
            std::cout << "Ingrese el identificador de la tela a modificar: " << std::endl;
            std::cin >> opcion;
        } else{
            std::cout << "LISTADO DE TELAS: \n" << std::endl;
            for(int i = 0; i < 5; ++i){
                std::cout << datosTelas[i] << std::endl << std::endl;
            }
        }
    }


    delete[] datosTelas;
    return 0;
}