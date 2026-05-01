#include "parser.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


int main() {



    FILE* dataset = parser::cargarDataset("data/roadNet-PA.txt");
    parser::confirmarDataset(dataset);
    if (parser::confirmarDataset(dataset) == 0) {
        parser::contadorNodos(dataset);
    }else {
        return 1;
    }

    return 0;
}




