#include "loader.h"
#include "graph.h"
#include "consultas.h"
#include "subgraph.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Uso: ./eda_pf [A|B|C]" << std::endl;
        return 1;
    }
    std::string modulo = argv[1];
    loader p;
    FILE* dataset = p.loadData("data/roadNet-PA.txt");
    if (p.confirmarData(dataset) != 0) return 1;

    int numNodos = p.numNodos(dataset);
    graph g;
    g.resize(numNodos);
    p.listaAdj("data/roadNet-PA.txt", g);
    std::cout << "Grafo cargado correctamente." << std::endl;

    if (modulo == "A") {
        std::cout << "Ejecutando Modulo A..." << std::endl;

    } else if (modulo == "B") {
        std::cout << "Ejecutando Modulo B..." << std::endl;
        ejecutarConsultas(g, "results/consultas_p2p.csv");
        std::cout << "Consultas P2P generadas." << std::endl;

    } else if (modulo == "C") {
        std::cout << "Ejecutando Modulo C..." << std::endl;

    } else {
        std::cout << "Modulo no reconocido. Use A, B o C." << std::endl;
        return 1;
    }

    return 0;
}