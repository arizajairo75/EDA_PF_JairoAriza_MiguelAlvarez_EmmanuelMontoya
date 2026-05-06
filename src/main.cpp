#include "loader.h"
#include "graph.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


int main() {
    loader p;
    FILE* dataset = p.loadData("data/roadNet-PA.txt");


    if (p.confirmarData(dataset) == 0) {
        std::cout<<"procesando"<<std::endl;
    }else {
        return 1;
    }
    int numAristas = p.numNodos(dataset);
    graph g(numAristas);
    p.listaAdj("data/roadNet-PA.txt", g);

    return 0;
}




