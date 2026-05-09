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
    FILE* dataset = p.loadData("data/roadNet-PA.txt");
    if (p.confirmarData(dataset) == 0) {
        std::cout << "Procesando dataset..." << std::endl;
    } else {
        std::cout << "Error cargando dataset" << std::endl;
        return 1;
    }

    int numAristas = p.numNodos(dataset);
    graph g;
    g.resize(numAristas);
    p.listaAdj("data/roadNet-PA.txt", g);
    std::cout << "Grafo cargado correctamente." << std::endl;

    ejecutarConsultas(g, "results/consultas_p2p.csv");
    std::cout << "Consultas P2P generadas." << std::endl;

    return 0;
}