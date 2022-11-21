#ifndef PROYECTOFINAL_CONFIG_H
#define PROYECTOFINAL_CONFIG_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
static vector<double> registroConfig;
static int metrosOptimos;

vector<double> cargarConfiguracion(string const &fichero){
    ifstream ficConfig(fichero);
    if(ficConfig.is_open()){
        for(int i = 0; i < 4; ++i){
            double temp;
            ficConfig >> temp;
            registroConfig.push_back(temp);
        }
        ficConfig >> metrosOptimos;
    } else{
        cout << "No se pudo abrir el archivo de configuracion." << endl;
    }
    ficConfig.close();
    return registroConfig;
}

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
#endif //PROYECTOFINAL_CONFIG_H
