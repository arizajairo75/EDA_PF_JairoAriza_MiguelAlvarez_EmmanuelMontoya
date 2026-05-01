#include "parser.h"
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

    FILE* parser::cargarDataset(const std::string& path) {
        FILE* dataset = fopen(path.c_str(), "r");
        return dataset;
    }


    int parser::confirmarDataset(FILE* dataset) {

        if(!dataset) {
            cout<<"error al abrir archivo."<<endl;
            return 1;
        }else {
            cout<<"confirmado, archivo abierto con exito."<<endl;
        }
        return 0;
    }

    int parser::contadorNodos(FILE* dataset){

        char line[199]; //aca se declara un el arreglo donde se guarda el nodo, el valor de la dimension es para que sea lo suficientemente grande como para almacenar el contenido del dataset
        unordered_map<int,int> id_nodo;
        int i=0; //contador del id_nodo


        while(fgets(line, sizeof(line), dataset)){
            int u,v;//se declaran variables del nodo
            if (line[0] == '#') continue;//ignora comentarios en el espacio 0 de la linea
            sscanf(line,"%d %d", &u, &v);//lee la linea y el primer valor lo guarda en u y el segundo en v

            if(id_nodo.find(u)==id_nodo.end()){
                i++;
                id_nodo[u]= i;
            }if(id_nodo.find(v)==id_nodo.end()){
                i++;
                id_nodo[v]= i;
            }


        }
        printf("nodos: " "%d\n", i);
        fclose(dataset);

        return 0;
    }



