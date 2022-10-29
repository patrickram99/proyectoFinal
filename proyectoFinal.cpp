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
    if(telasData.is_open()){
        string linea;
        int j = 0;
        int j1 = 0;
        for(int i = 1; i <= 30; ++i){
            std::getline(telasData, linea);
            if((i - 1) % 6 == 0){
                datosTelas[j].identificador = linea;
                j++;
            }
        }
    }


    for(int k = 0; k < numTelas; k++){
        std::cout << datosTelas[k].identificador << std::endl;
    }

    return 0;
}