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
    int nodos  = p.numNodos(dataset);
    graph g(nodos);
    p.listaAdj("data/roadNet-PA.txt", g);


    int gradoMax = p.mayorGrado(g);
    std::cout<<"nodo con mayor grado: " << gradoMax << ". Con grado: "<< g.getVecinos(683267).size()<< std::endl;

    return 0;
}




