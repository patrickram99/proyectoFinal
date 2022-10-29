#include <fstream>
#include <iostream>
#include <string>
#include "tela.h"

int main()
{
    const int numTelas = 5;
    tela datosTelas[numTelas];
    std::fstream telasData;
    telasData.open("telas-data.txt", std::ios::in);
    // Leer y almacenar los datos del archivo en un array
    if(telasData.is_open()){
        string linea;
        int j = 0;
        int j1 = 0;
        int j2 = 0;
        int j3 = 0;
        int j4 = 0;
        int j5 = 0;
        for(int i = 1; i <= 30; ++i){
            std::getline(telasData, linea);
            if((i - 1) % 6 == 0){
                datosTelas[j].identificador = linea;
                j++;
            }
            if((i - 2) % 6 == 0){
                datosTelas[j1].nombre = linea;
                j1++;
            }
            if((i - 3) % 6 == 0){
                datosTelas[j2].composicion = linea;
                j2++;
            }
            if((i - 4) % 6 == 0){
                datosTelas[j3].ancho = std::stoi(linea);
                j3++;
            }
            if((i - 5) % 6 == 0){
                datosTelas[j4].peso = std::stoi(linea);
                j4++;
            }
            if((i - 6) % 6 == 0){
                datosTelas[j5].precio = std::stod(linea);
                j5++;
            }
        }
    }


    return 0;
}