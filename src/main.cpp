#include "parser.h"

int main() {
    FILE* dataset = parser::cargarDataset("data/roadNet-PA.txt");
    parser::confirmarDataset(dataset);
    parser::contadorNodos(dataset);
    return 0;
}




