#include "loader.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


int main() {



    FILE* dataset = loader::cargarDataset("data/roadNet-PA.txt");
    loader::confirmarDataset(dataset);
    if (loader::confirmarDataset(dataset) == 0) {
        loader::contadorNodos(dataset);
    }else {
        return 1;
    }

    return 0;
}




