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
int compConexas;

public:
   std::vector<int> runBFS(graph& g, int nodeInicial);

   int getCompConexas() const {
       return compConexas;
   }


};




#endif //BFS_H
