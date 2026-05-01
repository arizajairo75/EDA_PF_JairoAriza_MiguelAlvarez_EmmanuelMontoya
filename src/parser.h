#ifndef PARSER_H
#define PARSER_H
#include "parser.h"
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;



class parser {
public:

    static FILE* cargarDataset(const string& path);
    static int confirmarDataset(FILE* dataset);
    static int contadorNodos(FILE* dataset);

};



#endif //PARSER_H
