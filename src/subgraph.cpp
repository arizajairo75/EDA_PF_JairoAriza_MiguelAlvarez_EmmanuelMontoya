#include "subgraph.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <map>
#include <cstdlib>

struct Arista {
    int origen, destino, peso;
    bool operator<(const Arista& otra) const {
        return peso < otra.peso;
    }
};

struct DSU {
    std::map<int, int> padre;
    int buscar(int i) {
        if (padre.find(i) == padre.end() || padre[i] == i)
            return padre[i] = i;
        return padre[i] = buscar(padre[i]);
    }
    void unir(int i, int j) {
        int root_i = buscar(i);
        int root_j = buscar(j);
        if (root_i != root_j) padre[root_i] = root_j;
    }
};

bool tieneCiclo(int u, std::map<int, std::vector<int>>& adj, std::map<int, int>& estado) {
    estado[u] = 1;
    for (int v : adj[u]) {
        if (estado[v] == 1) return true;
        if (estado[v] == 0 && tieneCiclo(v, adj, estado)) return true;
    }
    estado[u] = 2;
    return false;
}

void ejecutarModuloC(const std::vector<int>& pathQ01, const std::vector<int>& pathQ06, graph& g) {
    std::set<int> nodosSubgrafo;
    for (int n : pathQ01) nodosSubgrafo.insert(n);
    for (int n : pathQ06) nodosSubgrafo.insert(n);

    std::vector<Arista> todasLasAristas;
    std::map<int, std::vector<int>> adjSubgrafo;
    srand(42);

    for (int u : nodosSubgrafo) {
       for (const auto& par : g.getVecinos(u)) {
            int v = par.first;
            if (nodosSubgrafo.count(v)) {
                int peso = rand() % 100 + 1;
                todasLasAristas.push_back({u, v, peso});
                adjSubgrafo[u].push_back(v);
            }
        }
    }

    std::map<int, int> estado;
    bool esAciclico = true;
    for (int u : nodosSubgrafo) {
        if (estado[u] == 0 && tieneCiclo(u, adjSubgrafo, estado)) {
            esAciclico = false;
            break;
        }
    }

    std::sort(todasLasAristas.begin(), todasLasAristas.end());
    DSU dsu;
    int pesoMST = 0;

    for (const auto& arista : todasLasAristas) {
        if (dsu.buscar(arista.origen) != dsu.buscar(arista.destino)) {
            dsu.unir(arista.origen, arista.destino);
            pesoMST += arista.peso;
        }
    }

    std::ofstream out("results/analisis_subgrafo.txt");
    if (out.is_open()) {
        out << "Nodos en el subgrafo: " << nodosSubgrafo.size() << std::endl;
        out << "Es un DAG: " << (esAciclico ? "SI" : "NO") << std::endl;
        out << "Peso total del MST: " << pesoMST << std::endl;
        out.close();
        std::cout << "Analisis completado." << std::endl;
    }
}

