#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <cstdio>
#include <unordered_map>


class loader {

    public:
        FILE* loadData(const std::string& path);
        int confirmarData(FILE* dataset);
        int numEdges(FILE* dataset);
        int listaAdj(FILE* dataset);


    private:
        std::unordered_map<int, int> id_nodo;
        int i = 0;
    };


#endif //PARSER_H
