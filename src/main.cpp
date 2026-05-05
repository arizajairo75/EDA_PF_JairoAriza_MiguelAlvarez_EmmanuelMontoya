#include "loader.h"
#include "graph.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


int main() {

    loader p;



    FILE* dataset = p.loadData("data/roadNet-PA.txt");
    p.confirmarData(dataset);

    if (p.confirmarData(dataset) == 0) {
        p.numEdges(dataset);
    }else {
        return 1;
    }
    p.listaAdj(dataset);





    return 0;
}




