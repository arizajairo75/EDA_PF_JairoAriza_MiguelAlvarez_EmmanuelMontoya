#include "parser.h"
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;



int parser(){
    FILE* dataset = fopen("data/roadNet-PA.txt", "r");


    if(!dataset) {
        cout<<"error al abrir archivo."<<endl;
        return 1;
    }

    char line[199];
    unordered_map<int,int> id_nodo;
    int i=0;
    while(fgets(line, sizeof(line), dataset)){
        int u,v;
        if (line[0] == '#') continue;
        sscanf(line,"%d %d", &u, &v);



        printf("%d %d\n",u,v);
}


return 0;
}
