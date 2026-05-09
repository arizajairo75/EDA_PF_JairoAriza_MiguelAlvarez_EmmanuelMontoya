#include "dijkstra.h"
#include "graph.h"
#include <vector>
#include <queue>
#include <limits>
#include <utility>
#include <algorithm>

std::vector<int> dijkstra(const graph& g, int origen, std::vector<int>& prev, int& nodosExplorados) {
    nodosExplorados = 0;
    int n = g.numNodes;
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    prev.resize(n, -1);
    dist[origen] = 0;

    using DistNodo = std::pair<int,int>;
    std::priority_queue<DistNodo, std::vector<DistNodo>, std::greater<DistNodo>> pq;
    pq.push({0, origen});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;
        nodosExplorados++;

        for (const auto& [v, peso] : g.getVecinos(u)) {
            if (dist[u] != std::numeric_limits<int>::max() && dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

std::vector<int> reconstruirCamino(const std::vector<int>& prev, int destino) {
    std::vector<int> camino;
    int nodoActual = destino;
    while (nodoActual != -1) {
        camino.push_back(nodoActual);
        nodoActual = prev[nodoActual];
    }
    std::reverse(camino.begin(), camino.end());
    return camino;
}
   
