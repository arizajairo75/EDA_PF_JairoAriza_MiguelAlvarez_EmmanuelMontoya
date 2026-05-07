//
// Created by monto on 05/05/2026.
//
#include "bfs.h"
#include "loader.h"



int bfs::runBFS(graph& g, int nodeInicial, int nodeFinal) {
     std::vector<int> nodosVisitados(g.getVecinos(nodeInicial).size(), 0);
     std::queue<int> q;
     q.push(nodeInicial);
     nodosVisitados[nodeInicial] = 1;
     for (int i =0; i<g.getVecinos(nodeInicial).size(); i++) {


     }

}





















