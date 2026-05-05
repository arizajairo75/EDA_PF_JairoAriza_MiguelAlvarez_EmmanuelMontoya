//
// Created by monto on 04/05/2026.
//

#ifndef GRAPH_H
#define GRAPH_H


class graph {

public:
    graph(int numNodos) {                 //constructor
        adj.resize(numNodos);
    }
    void addEdge(int u, int v, int peso);
private:
    std::vector<std::vector<std::pair<int,int>>> adj;
};



#endif //GRAPH_H
