#include "loader.h"
#include "graph.h"
#include "bfs.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>


//tiempo construccion grafo
auto inicioConstGrafo = std::chrono::high_resolution_clock::now();
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
    auto finConsGrafo = std::chrono::high_resolution_clock::now();
    auto duracionConsGrafo = std::chrono::duration_cast<std::chrono::seconds>(inicioConstGrafo - finConsGrafo);



    double gradoPromedio = 2.0 * p.getNumEdges()/p.getNumNodes();
    std::cout<<"grado promedio obtenido: "<< gradoPromedio<<std::endl;

    int gradoMax = p.mayorGrado(g);
    std::cout<<"nodo con mayor grado: " << gradoMax << ". Con grado: "<< g.getVecinos(gradoMax).size()<< std::endl;

    auto inicioBFS = std::chrono::high_resolution_clock::now();
    bfs b;
    std::vector<int> distancias = b.runBFS(g, gradoMax);
    int diametro = *std::max_element(distancias.begin(), distancias.end());
    auto finBFS = std::chrono::high_resolution_clock::now();
    auto duracionBFS = std::chrono::duration_cast<std::chrono::seconds>(inicioBFS - finBFS);
    std::cout <<"Diametro del grafo.(BFS)" << diametro<<std::endl;



    std::cout<<"tiempo de construccion del grafo: " << duracionConsGrafo<<std::endl;
    std::cout<<"tiempo de ejecucion del BFS: "<< duracionBFS<<std::endl;




    return 0;
}




