#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <cstdio>


    class parser {

    public:
        static FILE* cargarDataset(const std::string& path);
        static int confirmarDataset(FILE* dataset);
        static int contadorNodos(FILE* dataset);

    };


#endif //PARSER_H
