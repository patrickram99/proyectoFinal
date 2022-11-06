#ifndef PROYECTOFINAL_TELA_H
#define PROYECTOFINAL_TELA_H
#include <fstream>
#include <vector>

using std::string;

class tela{
public:
    string              identificador;
    string              nombre;
    string              composicion;
    int                 ancho;
    int                 peso;
    double              precio;

    void imprimir() const{
        std::cout << "Codigo "      << identificador << ": \n"
                  << "Descripcion: "<< nombre        << "\n"
                  << "Material: "   << composicion   << "\n"
                  << "Ancho: "      << ancho         << "\n"
                  << "Peso: "       << peso          << "\n"
                  << "Precio: "     << precio        << "\n";

    }
};

class ventas{
public:
    int identificador;

};
void almacenarDatos(tela *datosTelas, string fichero) {
    string linea;
    std::fstream telasFichero;
    telasFichero.open(fichero, std::ios::in);
    // Leer y almacenar los datos del archivo en un array
        for (size_t i = 0; i < 5; ++i){
            std::getline(telasFichero, datosTelas[i].identificador);
            std::getline(telasFichero, datosTelas[i].nombre);
            std::getline(telasFichero, datosTelas[i].composicion);
            std::getline(telasFichero, linea);
            datosTelas[i].ancho = std::stoi(linea);
            std::getline(telasFichero, linea);
            datosTelas[i].peso = std::stoi(linea);
            std::getline(telasFichero, linea);
            datosTelas[i].precio = std::stod(linea);
        }
        telasFichero.close();
}

void consultarTela(const tela* datosTelas){
    string opcion;
    std::cout << "Ingrese el identificador de la tela a consultar: " << std::endl;
    std::cin >> opcion;
    datosTelas[std::stoi(opcion.substr(2, 1))].imprimir();
}

void modificarTela(tela* &datosTelas) {
    string opcion;
    std::vector<string> aspectos = {"Identificador", "Descripcion", "Material", "Ancho", "Peso", "Precio"};
    std::cout << "Ingrese el identificador de la tela a modificar: " << std::endl;
    std::cin >> opcion;
    for(int i = 0; i < 5; ++i){
        if(std::stoi(opcion.substr(2, 1)) == i){
            std::cout << "Que aspecto desea modificar: ";
            std::cin >> opcion;
            for(size_t j = 0; j < aspectos.size(); ++j){
                if(opcion == aspectos[j]){

                }
            }

        }
    }
}

void listarTelas(const tela* datosTelas){
    std::cout << "LISTADO DE TELAS: \n" << std::endl;
    for(int i = 0; i < 5; ++i){
        datosTelas[i].imprimir();
        std::cout << std::endl;
    }
}

#endif //PROYECTOFINAL_TELA_H
