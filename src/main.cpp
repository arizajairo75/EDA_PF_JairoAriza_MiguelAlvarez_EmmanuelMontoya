#include "loader.h"
#include "graph.h"
#include "bfs.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>


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

    bfs b;
    std::vector<int> distancias = b.runBFS(g, gradoMax);
    int diametro = *std::max_element(distancias.begin(), distancias.end());
    std::cout << diametro<<std::endl;
    return 0;
}




