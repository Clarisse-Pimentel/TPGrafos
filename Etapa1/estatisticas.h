// Calculo das estatisticas
#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#include "grafo.h"
#include <vector>
#include <queue>
#include <limits>

int quantidadeVertices(const Grafo& g) { return g.num_vertices; }
int quantidadeArestas(const Grafo& g) { return g.arestas.size(); }
int quantidadeArcos(const Grafo& g) { return g.arcos.size(); }
int quantidadeVerticesRequeridos(const Grafo& g) { return g.verticesRequeridos.size(); }
int quantidadeArestasRequeridas(const Grafo& g) { return g.qtdArestasRequeridas; }
int quantidadeArcosRequeridos(const Grafo& g) { return g.qtdArcosRequeridos; }

// 7. Densidade do grafo
double densidadeGrafo(const Grafo& g) {
    int totalLigacoes = g.arcos.size();
    int maxLigacoes = g.num_vertices * (g.num_vertices - 1);
    return (double)totalLigacoes / maxLigacoes;
}

// 8. Componentes conectados
int componentesConectados(const Grafo& g) {
    vector<bool> visitado(g.num_vertices, false);
    int componentes = 0;
    for (int i = 0; i < g.num_vertices; ++i) {
        if (!visitado[i]) {
            componentes++;
            queue<int> q;
            q.push(i);
            visitado[i] = true;
            while (!q.empty()) {
                int v = q.front(); q.pop();
                for (int viz : g.adj[v]) {
                    if (!visitado[viz]) {
                        visitado[viz] = true;
                        q.push(viz);
                    }
                }
            }
        }
    }
    return componentes;
}

// 9. Grau minimo dos vertices
int grauMinimo(const Grafo& g) {
    int minGrau = INT_MAX;
    for (const auto& lista : g.adj) {
        int grau = lista.size();
        minGrau = min(minGrau, grau);
    }
    return minGrau;
}

// 10. Grau maximo dos vertices
int grauMaximo(const Grafo& g) {
    int maxGrau = 0;
    for (const auto& lista : g.adj) {
        int grau = lista.size();
        maxGrau = max(maxGrau, grau);
    }
    return maxGrau;
}

// 12. Caminho medio
double caminhoMedio(const vector<vector<int>>& dist) {
    double soma = 0;
    int cont = 0;
    for (int i = 0; i < dist.size(); ++i)
        for (int j = 0; j < dist.size(); ++j)
            if (i != j && dist[i][j] < INT_MAX) {
                soma += dist[i][j];
                cont++;
            }
    return cont > 0 ? soma / cont : 0;
}

// 13. Diametro
int diametro(const vector<vector<int>>& dist) {
    int diam = 0;
    for (int i = 0; i < dist.size(); ++i)
        for (int j = 0; j < dist.size(); ++j)
            if (i != j && dist[i][j] < INT_MAX)
                diam = max(diam, dist[i][j]);
    return diam;
}

#endif
