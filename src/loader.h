#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <cstdio>


    class loader {

    public:
        static FILE* cargarDataset(const std::string& path);
        static int confirmarDataset(FILE* dataset);
        static int contadorNodos(FILE* dataset);
        static int contadorAristas(FILE* dataset);

    };


#endif //PARSER_H
