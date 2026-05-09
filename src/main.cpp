#include "loader.h"
#include "graph.h"
#include "bfs.h"
#include "consultas.h"
#include "subgraph.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>

int main() {
    loader p;

 
    auto inicioConstGrafo = std::chrono::high_resolution_clock::now();
    FILE* dataset = p.loadData("data/roadNet-PA.txt");
    if (p.confirmarData(dataset) == 0) {
        std::cout << "Procesando dataset..." << std::endl;
    } else {
        std::cout << "Error cargando dataset" << std::endl;
        return 1;
    }

    int nodos = p.numNodos(dataset);   
    graph g(nodos);
    p.listaAdj("data/roadNet-PA.txt", g);
    std::cout << "Grafo cargado correctamente." << std::endl;

    auto finConsGrafo = std::chrono::high_resolution_clock::now();
    auto duracionConsGrafo = std::chrono::duration_cast<std::chrono::milliseconds>(finConsGrafo - inicioConstGrafo);

    
    double gradoPromedio = 2.0 * p.getNumEdges() / p.getNumNodes();
    std::cout << "grado promedio obtenido: " << gradoPromedio << std::endl;

    int gradoMax = p.mayorGrado(g);
    std::cout << "nodo con mayor grado: " << gradoMax
              << ". Con grado: " << g.getVecinos(gradoMax).size() << std::endl;

    auto inicioBFS = std::chrono::high_resolution_clock::now();
    bfs b;
    std::vector<int> distancias = b.runBFS(g, gradoMax);
    int diametro = *std::max_element(distancias.begin(), distancias.end());
    auto finBFS = std::chrono::high_resolution_clock::now();
    auto duracionBFS = std::chrono::duration_cast<std::chrono::milliseconds>(finBFS - inicioBFS);

    std::cout << "Diametro del grafo (BFS): " << diametro << std::endl;
    std::cout << "tiempo de construccion del grafo: " << duracionConsGrafo.count() << " ms" << std::endl;
    std::cout << "tiempo de ejecucion del BFS: " << duracionBFS.count() << " ms" << std::endl;

    
    std::ofstream out("results/resultados.txt");
    if (!out) {
        std::cout << "error en abrir resultados" << std::endl;
        return 1;
    }
    out << "Resultados del MODULO-A\n";
    out << "Estadisticas del grafo:\n";
    out << "   \n";
    out << "Numero de nodos obtenido: " << nodos << " |  Valor SNAP: 1,088,092\n";
    out << "   \n";
    out << "Numero de aristas no dirigidas obtenido: " << p.getNumEdges() << " |   Valor SNAP: 1,541,898\n";
    out << "   \n";
    out << "Nodos en la componente conexa principal obtenidos: " << b.getCompConexas() << " |   Valor SNAP: 1,087,562\n";
    out << "   \n";
    out << "Grado promedio obtenido: " << gradoPromedio << " |  Valor SNAP: 2.83\n";
    out << "   \n";
    out << "Diametro partiendo desde el nodo de maxGrado: " << diametro << " |  Valor SNAP: no consultado\n";
    out << "   \n";
    out << "Nodo de mayor grado obtenido: " << gradoMax
        << ". Con grado: " << g.getVecinos(gradoMax).size() << "\n";
    out.close();

    
    ejecutarConsultas(g, "results/consultas_p2p.csv");
    std::cout << "Archivo consultas_p2p.csv generado." << std::endl;

    
    std::vector<int> pathQ01 = {1, 2, 3, 4, 5};
    std::vector<int> pathQ06 = {10, 11, 12, 13, 1};
    std::cout << "Iniciando analisis de subgrafo (Modulo C).