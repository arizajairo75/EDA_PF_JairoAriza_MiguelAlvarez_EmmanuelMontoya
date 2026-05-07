//
// Created by monto on 05/05/2026.
//
#ifndef BFS_H
#define BFS_H
#include "graph.h"
#include "loader.h"
#include <queue>
class bfs {
private:
    std::queue<int> nodosPorVisitar;

public:
    int bFS(graph& g, int nodeInicial, int nodeFinal);


};




#endif //BFS_H
