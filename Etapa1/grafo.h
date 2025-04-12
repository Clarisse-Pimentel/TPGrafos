// Modelagem do problema atraves de estruturas de dados em grafos
#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

struct Aresta {
    int u, v, custo, demanda;
    bool requerido;
};

struct Arco {
    int u, v, custo, demanda;
    bool requerido;
};

class Grafo {
public:
    int num_vertices;
    vector<Aresta> arestas;
    vector<Arco> arcos;
    set<int> verticesRequeridos;
    vector<vector<int>> adj;

    int qtdArestasRequeridas = 0;
    int qtdArcosRequeridos = 0;

    Grafo(int n = 0) {
        num_vertices = n;
        adj.resize(n);
    }

    void adicionarAresta(int u, int v, int custo, int demanda, bool requerido) {
        if (u >= num_vertices || v >= num_vertices || u < 0 || v < 0) {
            cerr << "Indice fora do intervalo: " << u << " -> " << v << endl;
            return;
        }
    
        arestas.push_back({u, v, custo, demanda, requerido});
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (requerido) qtdArestasRequeridas++;
    }
    

    void adicionarArco(int u, int v, int custo, int demanda, bool requerido) {
        cout << "[DEBUG] Tentando adicionar arco: " << u << " -> " << v << endl;

        if (u >= num_vertices || v >= num_vertices || u < 0 || v < 0) {
            cerr << "Indice fora do intervalo: " << u << " -> " << v << endl;
            return;
        }
    
        arcos.push_back({u, v, custo, demanda, requerido});
        adj[u].push_back(v);
        if (requerido) qtdArcosRequeridos++;
    }
    
};

#endif
