//
// Created by monto on 05/05/2026.
// edited by jairo on 06/05/2026.
//
#include "bfs.h"
#include "graph.h"
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

// modulo A
std::vector<int> bfs::runBFS(graph& g, int nodeInicial) {
    std::vector<int> distancia(g.numNodes, -1);
    std::queue<int> q;
    distancia[nodeInicial] = 0;
    q.push(nodeInicial);

    while (!q.empty()) {
        int nodeActual = q.front();
        q.pop();
        const auto& vecinosActual = g.getVecinos(nodeActual);
        for (size_t i = 0; i < vecinosActual.size(); i++) {
            int vecino = vecinosActual[i].first;
            if (distancia[vecino] == -1) {
                distancia[vecino] = distancia[nodeActual] + 1;
                q.push(vecino);
                compConexas++;
            }
        }
    }
    std::cout << "Componentes conexas: " << compConexas << std::endl;
    return distancia;
}

// 
std::vector<int> bfs(const graph& g, int origen, std::vector<int>& prev, int& nodosExplorados) {
    nodosExplorados = 0;
    int n = g.numNodes;
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    prev.resize(n, -1);
    std::queue<int> q;

    dist[origen] = 0;
    q.push(origen);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        nodosExplorados++;

        for (const auto& [v, peso] : g.getVecinos(u)) {
            if (dist[v] == std::numeric_limits<int>::max()) {
                dist[v] = dist[u] + 1;
                prev[v] = u;
                q.push(v);
            }
        }
    }
    return dist;
}
