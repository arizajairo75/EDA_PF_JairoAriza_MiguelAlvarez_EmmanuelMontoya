//
// Created by monto on 05/05/2026.
// edited by jairo on 06/05/2026.

#include "bfs.h"
#include "graph.h"
#include <vector>
#include <queue>
#include <limits>

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
