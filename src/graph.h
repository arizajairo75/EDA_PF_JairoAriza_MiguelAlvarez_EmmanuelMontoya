// edited by jairo on 06/05/2026.
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <utility>

class graph {
private:
    std::vector<std::vector<std::pair<int,int>>> adj;

public:
    int numNodes;
    int numEdges;
    std::unordered_map<int,int> idMap;

    graph() : numNodes(0), numEdges(0) {}

    void addEdge(int u, int v, int peso);
    void resize(int n);
    const std::vector<std::pair<int,int>>& getVecinos(int nodo) const;
};

#endif