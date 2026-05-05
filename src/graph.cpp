//
// Created by monto on 04/05/2026.
//
#include <vector>
#include "graph.h"


    std::vector<std::vector<std::pair<int,int>>> adj;
    void addEdge(int u, int v, int peso) {
        adj[u].push_back({peso,peso});
        adj[v].push_back({u,peso});
    }





