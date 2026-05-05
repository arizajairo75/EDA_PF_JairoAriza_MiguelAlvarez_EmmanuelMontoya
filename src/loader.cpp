#include "loader.h"
#include "graph.h"
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
graph graph;

unordered_map<int,int> id_nodo;
int i = 0;//contador del id_nodo

    FILE* loadData(const std::string& path) {
        FILE* dataset = fopen(path.c_str(), "r");
        return dataset;
    }


    int confirmarData(FILE* dataset) {

        if(!dataset) {
            cout<<"error al abrir archivo."<<endl;
            return 1;
        }else {
            cout<<"confirmado, archivo abierto con exito."<<endl;
        }
        return 0;
    }

    int numEdges(FILE* dataset){

        char line[199]; //aca se declara un el arreglo donde se guarda el nodo, el valor de la dimension es para que sea lo suficientemente grande como para almacenar el contenido del dataset
        unordered_map<int,int> id_nodo;



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

        return i;
        fclose(dataset);
    }

      int listaAdj(FILE* dataset) {
        srand(42);
        char line[200];
        int i = 0;
        int xu;
        int xv;

        while (fgets(line, sizeof(line), dataset)) {
            int u, v;

            if (line [0] == '#') continue;
            sscanf(line, "%d %d", &u, &v);
            if (u<v) {
                int peso = rand() % 10 + 1;
                xu = id_nodo[u];
                xv = id_nodo[v];
                graph.addEdge(xu, xv, peso);
            }




        }

    }







