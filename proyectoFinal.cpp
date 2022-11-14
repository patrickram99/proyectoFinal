#include <iostream>
#include "tela.h"

int main() {
    Inventario Telas_SA("14/11/2022");
    Telas_SA.cargarDatos("telas-data.txt");

    //Comenzamos con el menú de opciones
    std::string opcion;
    std::cout << "Elija una opcion: Mantenimiento, Vender, Reportes, Configuracion o Salir"<< std::endl;
    std::getline(std::cin, opcion);

    if(opcion == "Mantenimiento"){
        std::cout << "Desea Consultar tela, Modificar tela o Listar" << std::endl;
        std::getline(std::cin, opcion);
        if(opcion == "Consultar tela"){
            std::cout << "Ingrese el identificador de la tela a consultar: " << std::endl;
            std::cin >> opcion;
            Telas_SA.consultarTela(std::stoi(opcion.substr(2, 1)));

        } else if(opcion == "Modificar tela"){

        } else{
            Telas_SA.listar();
        }
    } else if(opcion == "Vender"){
        std::cout << "Ingrese el tipo de tela" << std::endl;
        std::cout << "Ingrese la canidad de metros" << std::endl;

    } else{

    }

    return 0;
}
