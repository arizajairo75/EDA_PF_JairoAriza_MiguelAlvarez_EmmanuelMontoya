//
// Created by monto on 05/05/2026.
//
#include "bfs.h"
#include "loader.h"



std::vector<int> bfs::runBFS(graph& g, int nodeInicial) {
     std::vector<int> distancia (g.numNodos(), -1);
     std::queue<int> q;
     distancia[nodeInicial] = 0;
     q.push(nodeInicial);
     int nodeActual;

     while (!q.empty()) {
          nodeActual = q.front();
          q.pop();
          const auto& vecinosActual = g.getVecinos(nodeActual);
          for(int i=0; i<g.getVecinos(nodeActual).size(); i++ ) {
               int vecino = vecinosActual[i].first;
               if (distancia[vecino]==-1) {
                    distancia[vecino]= distancia[nodeActual]+1;
                    q.push(vecino);
               }

          }


     }
     return distancia;
}























