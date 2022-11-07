#include <iostream>
#include "tela.h"

int main(){
    //Declaramos un vector dinamico para almacenar los datos de las telas
    int numTelas = 5;
    tela* datosTelas;
    datosTelas = new tela[numTelas];

    //Almacenamos los datos del ficero en el array datosTelas
    almacenarDatos(datosTelas,"telas-data.txt");

    //Comenzamos con el menú de opciones
    string opcion;
    std::cout << "Elija una opcion: Mantenimiento, Vender, Reportes, Configuracion o Salir"<< std::endl;
    std::getline(std::cin, opcion);


    if(opcion == "Mantenimiento"){
        std::cout << "Desea Consultar tela, Modificar tela o Listar" << std::endl;
        std::getline(std::cin, opcion);
        if(opcion == "Consultar tela"){
            consultarTela(datosTelas);
        } else if(opcion == "Modificar tela"){
            modificarTela(datosTelas);
        } else{
            listarTelas(datosTelas);
        }
    } else if(opcion == "Vender"){

    } else{

    }

    delete[] datosTelas;
    return 0;
}