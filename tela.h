#ifndef PROYECTOFINAL_TELA_H
#define PROYECTOFINAL_TELA_H
#include <fstream>
using std::string;

class tela{
public:
    string identificador;
    string nombre;
    string composicion;
    int ancho;
    int peso;
    double precio;

    friend std::ostream& operator << (std::ostream& os, const tela& p)
    {
        return os << "Codigo "
                  << p.identificador << ": " << std::endl
                  << "Descripcion: "<< p.nombre << "\n"
                  << "Material: "<< p.composicion << "\n"
                  << "Ancho: "<< p.ancho << "\n"
                  << "Peso: "<< p.peso << "\n"
                  << "Precio: "<< p.precio;
    }
};

void almacenarDatos(tela* datosTelas, string fichero){
    std::fstream telasFichero;
    telasFichero.open(fichero, std::ios::in);
    // Leer y almacenar los datos del archivo en un array
    if(telasFichero.is_open()){
        string linea;
        int j = 0;
        int j1 = 0;
        int j2 = 0;
        int j3 = 0;
        int j4 = 0;
        int j5 = 0;
        for(int i = 1; i <= 30; ++i){
            std::getline(telasFichero, linea);
            if((i - 1) % 6 == 0){
                datosTelas[j].identificador = linea;
                j++;
            } else if((i - 2) % 6 == 0){
                datosTelas[j1].nombre = linea;
                j1++;
            } else if((i - 3) % 6 == 0){
                datosTelas[j2].composicion = linea;
                j2++;
            } else if((i - 4) % 6 == 0){
                datosTelas[j3].ancho = std::stoi(linea);
                j3++;
            } else if((i - 5) % 6 == 0){
                datosTelas[j4].peso = std::stoi(linea);
                j4++;
            } else{
                datosTelas[j5].precio = std::stod(linea);
                j5++;
            }
        }
    }
    telasFichero.close();
}


#endif //PROYECTOFINAL_TELA_H
