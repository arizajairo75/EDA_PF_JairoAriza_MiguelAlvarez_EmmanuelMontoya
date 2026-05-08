#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <cstdio>
#include <unordered_map>
#include "graph.h"


class loader {

    public:
        FILE* loadData(const std::string& path);
        int confirmarData(FILE* dataset);
        int numNodos(FILE* dataset);
        int listaAdj(const std::string& path, graph& g);
        int mayorGrado(graph& g);

        int getNumNodes() const {
            return numNodes;
        }

        int getNumEdges() const {
            return j;
        }


    private:
        std::unordered_map<int, int> id_nodo;
        int numNodes = 0;
        int j = 0;
        int m = 0;
    };


#endif //PARSER_H
