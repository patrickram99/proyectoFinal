#include <iostream>
#include "tela.h"

int main() {
    Inventario Telas_SA("14/11/2022");
    Telas_SA.cargarTelas("telas-data.txt");


    //Comenzamos con el menú de opciones
    std::string opcion;
    do{
        std::cout << "Elija una opcion: Mantenimiento, Vender, Reportes, Configuracion o Salir"<< std::endl;
        std::getline(std::cin, opcion);

        if(opcion == "Mantenimiento"){
            std::cout << "Desea Consultar tela, Modificar tela o Listar" << std::endl;
            std::getline(std::cin, opcion);
            if(opcion == "Consultar tela"){
                std::cin >> opcion;
                Telas_SA.consultarTela(std::stoi(opcion.substr(2, 1)));
            } else if(opcion == "Modificar tela"){
                Telas_SA.modificarTela();
            } else{
                Telas_SA.listar();
            }
        } else if(opcion == "Vender"){
            Telas_SA.registrarVenta();
        } else if(opcion == "Reportes"){
            Telas_SA.menuReportes(Telas_SA);
        } else if (opcion == "Configuracion"){
            Telas_SA.menuConfig(Telas_SA);
        }
    } while(opcion != "Salir");

    return 0;
}