//created by jairo on 06/05/2026.

#include "consultas.h"
#include "dijkstra.h"
#include "bfs.h"
#include <fstream>
#include <iostream>
#include <chrono>
#include <limits>
#include <iomanip>

void ejecutarConsultas(const graph& g, const std::string& archivoSalida) {

    int consultas[10][2] = {
        {1, 500000},
        {100, 1000000},
        {50000, 750000},
        {200000, 800000},
        {300000, 100000},
        {1, 1087562},
        {500000, 1},
        {250000, 600000},
        {10000, 900000},
        {400000, 150000}
    };

    std::ofstream archivo(archivoSalida);
    archivo << "consulta,origen,destino,dist_dijkstra,"
            << "saltos_bfs,nodos_dijkstra,nodos_bfs,"
            << "t_dijkstra_ms,t_bfs_ms\n";

    for (int i = 0; i < 10; i++) {
        int origen = consultas[i][0];
        int destino = consultas[i][1];

        if (g.idMap.find(origen) == g.idMap.end() ||
            g.idMap.find(destino) == g.idMap.end()) {
            archivo << "Q" << std::setw(2) << std::setfill('0') << (i+1)
                    << "," << origen << "," << destino
                    << ",INF,INF,0,0,0,0\n";
            continue;
        }

        int origenId  = g.idMap.at(origen);
        int destinoId = g.idMap.at(destino);

        int nodosDijkstra = 0;
        std::vector<int> prevDijkstra;
        auto inicioDijkstra = std::chrono::high_resolution_clock::now();
        std::vector<int> distDijkstra = dijkstra(g, origenId, prevDijkstra, nodosDijkstra);
        auto finDijkstra = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> durDijkstra = finDijkstra - inicioDijkstra;
        double tiempoDijkstra = durDijkstra.count();

        int nodosBFS = 0;
        std::vector<int> prevBFS;
        auto inicioBFS = std::chrono::high_resolution_clock::now();
        std::vector<int> distBFS = bfs(g, origenId, prevBFS, nodosBFS);
        auto finBFS = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> durBFS = finBFS - inicioBFS;
        double tiempoBFS = durBFS.count();

        int distD  = distDijkstra[destinoId];
        int saltos = distBFS[destinoId];

        if (i == 0 || i == 5) {
        std::vector<int> camino = reconstruirCamino(prevDijkstra, destinoId);
        std::string nombreArchivo = "results/camino_Q0" + std::to_string(i == 0 ? 1 : 6) + ".txt";
       std::ofstream fileCamino(nombreArchivo);
        if (!fileCamino.is_open()) {
        std::cout << "Error: no se pudo crear " << nombreArchivo << std::endl;
        } else {
        for (int nodo : camino) {
        fileCamino << nodo << "\n";
        }
        fileCamino.close();
        std::cout << "Camino guardado: " << nombreArchivo << std::endl;
}
}

        std::string distanciaStr = (distD  == std::numeric_limits<int>::max()) ? "INF" : std::to_string(distD);
        std::string saltosStr    = (saltos == std::numeric_limits<int>::max()) ? "INF" : std::to_string(saltos);

        archivo << "Q" << std::setw(2) << std::setfill('0') << (i+1) << ","
                << origen << "," << destino << ","
                << distanciaStr << "," << saltosStr << ","
                << nodosDijkstra << "," << nodosBFS << ","
                << tiempoDijkstra << "," << tiempoBFS << "\n";
    }

    archivo.close();
    std::cout << "Consultas ejecutadas correctamente.\n";
}