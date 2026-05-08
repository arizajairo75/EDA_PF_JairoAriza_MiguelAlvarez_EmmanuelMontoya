//created by jairo on 06/05/2026.

#include "consultas.h"
#include "dijkstra.h"
#include "bfs.h"
#include <fstream>
#include <iostream>
#include <chrono>
#include <limits>

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

            archivo << "Q" << (i + 1) << ","
                    << origen << ","
                    << destino << ","
                    << "INF,INF,0,0,0,0\n";

            continue;
        }

        int origenId = g.idMap.at(origen);
        int destinoId = g.idMap.at(destino);

        auto inicioDijkstra =
            std::chrono::high_resolution_clock::now();

        std::vector<int> prevDijkstra;

        std::vector<int> distDijkstra =
            dijkstra(g, origenId, prevDijkstra);

        auto finDijkstra =
            std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duracionDijkstra =
            finDijkstra - inicioDijkstra;

        double tiempoDijkstra =
            duracionDijkstra.count();

        auto inicioBFS =
            std::chrono::high_resolution_clock::now();

        std::vector<int> prevBFS;

        std::vector<int> distBFS =
            bfs(g, origenId, prevBFS);

        auto finBFS =
            std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duracionBFS =
            finBFS - inicioBFS;

        double tiempoBFS =
            duracionBFS.count();

        int distD = distDijkstra[destinoId];
        int saltos = distBFS[destinoId];

        std::string distanciaStr;
        std::string saltosStr;

        if (distD == std::numeric_limits<int>::max()) {

            distanciaStr = "INF";
            saltosStr = "INF";

        } else {

            distanciaStr = std::to_string(distD);
            saltosStr = std::to_string(saltos);
        }

        archivo << "Q" << (i + 1) << ","
        << origen << ","
        << destino << ","
        << distanciaStr << ","
        << saltosStr << ","
        << "0,0,"
        << tiempoDijkstra << ","
        << tiempoBFS << "\n";
    }

    archivo.close();
    std::cout << "Consultas ejecutadas correctamente.\n";
}