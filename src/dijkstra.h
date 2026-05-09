// created by jairo on 06/05/2026.

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"
#include <vector>
#include <queue>
#include <utility>

std::vector<int> dijkstra(const graph& g, int origen, std::vector<int>& prev, int& nodosExplorados);
std::vector<int> reconstruirCamino(const std::vector<int>& prev, int destino);

#endif
