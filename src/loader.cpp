#include "loader.h"
#include "graph.h"
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


    FILE* loader::loadData(const std::string& path) {
        FILE* dataset = fopen(path.c_str(), "r");
        return dataset;
    }


    int loader::confirmarData(FILE* dataset) {

        if(!dataset) {
            cout<<"error al abrir archivo."<<endl;
            return 1;
        }else {
            cout<<"confirmado, archivo abierto con exito."<<endl;
        }
        return 0;
    }

    int loader::numNodos(FILE* dataset){

        char line[199]; //aca se declara un el arreglo donde se guarda el nodo, el valor de la dimension es para que sea lo suficientemente grande como para almacenar el contenido del dataset

        while(fgets(line, sizeof(line), dataset)){
            int u,v;//se declaran variables del nodo
            if (line[0] == '#') continue;//ignora comentarios en el espacio 0 de la linea
            sscanf(line,"%d %d", &u, &v);//lee la linea y el primer valor lo guarda en u y el segundo en v

            if(id_nodo.find(u)==id_nodo.end()){
                id_nodo[u]= numNodes;
                numNodes++;
            }if(id_nodo.find(v)==id_nodo.end()){
                id_nodo[v]= numNodes;
                numNodes++;
            }


        }
        fclose(dataset);
        printf("nodos: " "%d\n", numNodes);
        return numNodes;
    }

        int loader::listaAdj(const std::string& path, graph& g) {
        FILE* dataset2 = fopen("data/roadNet-PA.txt", "r");
        if (!dataset2) return 1;
        srand(42);
        char line[200];


    while (fgets(line, sizeof(line), dataset2)) {
        int u, v;

        if (line[0] == '#') continue;
        m++;
        sscanf(line, "%d %d", &u, &v);
        if (u<v) {
            int peso = rand() % 10 + 1;
            int xu = id_nodo[u];
            int xv = id_nodo[v];
            j++;
            g.addEdge(xu, xv, peso);

        }
    }
        printf("numero de aristas no dirigidas: " "%d\n", m);
        printf("numero de aristas  dirigidas: " "%d\n", j);
    fclose(dataset2);
    return 0;
    }



int loader::mayorGrado(graph &g) {
        int mayorGrado = 0;
        int actualNodo;
        for (int i =0; i<numNodes; i++) {
            if (mayorGrado < g.getVecinos(i).size()) {
                mayorGrado = g.getVecinos(i).size();
                actualNodo = i;
            }
        }
        return actualNodo;
    }










