//
// Created by monto on 04/05/2026.
//

#include <vector>
#ifndef GRAPH_H
#define GRAPH_H


class graph {

private:
    std::vector<std::vector<std::pair<int,int>>> adj;


public:
    const std::vector<std::pair<int,int>> getVecinos(int nodo) const {
        return adj[nodo];
    }

    graph(int numNodos) {                 //constructor
        adj.resize(numNodos);
    }
    void addEdge(int u, int v, int peso);
};



#endif //GRAPH_H
