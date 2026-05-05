//
// Created by monto on 04/05/2026.
//

#include "graph.h"

    void graph::addEdge(int u, int v, int peso) {
        adj[u].push_back({peso,peso});
        adj[v].push_back({u,peso});
    }





