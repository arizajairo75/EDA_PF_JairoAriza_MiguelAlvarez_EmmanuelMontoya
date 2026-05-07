#include <vector>
#ifndef GRAPH_H
#define GRAPH_H

class graph {
public:
    std::vector<std::vector<std::pair<int,int>>> adj;

    graph(int numNodos) {
        adj.resize(numNodos);
    }
    void addEdge(int u, int v, int peso);
};

#endif
