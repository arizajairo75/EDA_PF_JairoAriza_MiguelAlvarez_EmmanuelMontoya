#include "loader.h"

#include "graph.h"

#include "subgraph.h" 

#include <iostream>

#include <string>

#include <vector>

#include <fstream>



int main() {

    loader p;

    FILE* dataset = p.loadData("data/roadNet-PA.txt");



    if (p.confirmarData(dataset) == 0) {

        std::cout << "Procesando dataset" << std::endl;

    } else {

        return 1;

    }



    int numAristas = p.numEdges(dataset);

    graph g(numAristas);

    p.listaAdj("data/roadNet-PA.txt", g);



   

    std::vector<int> pathQ01 = {1, 2, 3, 4, 5}; 

    std::vector<int> pathQ06 = {10, 11, 12, 13, 1};



    std::cout << "Iniciando Analisis subgrafo." << std::endl;



    

    ejecutarModuloC(pathQ01, pathQ06, g);



    std::cout << "Analisis Terminado" << std::endl;



    return 0;

}




