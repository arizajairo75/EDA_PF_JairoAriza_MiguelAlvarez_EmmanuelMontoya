#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "graph.h"
#include "dijkstra.h"
#include "bfs.h"
#include <string>

void ejecutarConsultas(const graph& g, const std::string& archivoSalida);
#endif