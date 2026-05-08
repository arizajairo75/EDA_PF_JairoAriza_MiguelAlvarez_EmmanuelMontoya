// Created by monto on 05/05/2026.
// edited by jairo on 06/05/2026.


#ifndef BFS_H
#define BFS_H

#include "graph.h"
#include <vector>
#include <queue>

std::vector<int> bfs(const graph& g, int origen, std::vector<int>& prev, int& nodosExplorados);

#endif