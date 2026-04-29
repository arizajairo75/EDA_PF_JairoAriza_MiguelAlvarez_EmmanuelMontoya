#include "parser.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int parser(){
    FILE* dataset = fopen("data/roadNet-PA.txt", "r");
   if(!dataset){
    cout<<"error al abrir archivo."<<endl;
    return 1;
}
char line[199];
while(fgets(line, sizeof(line), dataset)){
    if (line[0], == '#') continue;
    int u,v;
sscanf(line,"%d %d", &u, &v);






}






}
