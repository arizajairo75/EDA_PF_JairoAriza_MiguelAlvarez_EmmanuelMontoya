//
// Created by monto on 04/05/2026.
// edited by jairo on 06/05/2026.
//
#include "graph.h"

void graph::addEdge(int u, int v, int peso) {
    adj[u].push_back({v, peso});
    adj[v].push_back({u, peso});
}

void graph::resize(int n) {
    adj.resize(n);
}

const std::vector<std::pair<int,int>>& graph::getVecinos(int nodo) const {
    return adj[nodo];
}