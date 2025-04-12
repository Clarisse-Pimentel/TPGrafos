#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include "grafo.h"
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floydWarshall(const Grafo& g, vector<vector<int>>& dist, vector<vector<int>>& pred) {
    int n = g.num_vertices;

    if (n <= 0) {
        cout << "Erro: numero de vertices invalido (" << n << ")\n";
        return;
    }


    dist.assign(n, vector<int>(n, INT_MAX));
    pred.assign(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i)
        dist[i][i] = 0;

    for (auto& a : g.arestas) {
        dist[a.u][a.v] = a.custo;
        dist[a.v][a.u] = a.custo;
        pred[a.u][a.v] = a.u;
        pred[a.v][a.u] = a.v;
    }
    for (auto& a : g.arcos) {
        dist[a.u][a.v] = a.custo;
        pred[a.u][a.v] = a.u;
    }

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
}

#endif
