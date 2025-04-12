// Bloco principal com a implementacao de todas as estatisticas
#include <iostream>
#include "grafo.h"
#include "entrada.h"
#include "estatisticas.h"
#include "algoritmos.h"
using namespace std;

int main() {
    Grafo grafo;
    int capacidade, deposito;
    string nomeArquivo;

    cout << "Digite o nome do arquivo (.dat) na pasta 'selected_instances/': ";
    cin >> nomeArquivo;

    lerInstancia(nomeArquivo, grafo, capacidade, deposito);

    if (grafo.num_vertices == 0) {
        cerr << "Erro: grafo nao carregado corretamente.\n";
        return 1;
    }

    vector<vector<int>> dist, pred;
    floydWarshall(grafo, dist, pred);

    cout << "\n=== Estatisticas do Grafo ===\n";
    cout << "1. Vertices: " << quantidadeVertices(grafo) << endl;
    cout << "2. Arestas: " << quantidadeArestas(grafo) << endl;
    cout << "3. Arcos: " << quantidadeArcos(grafo) << endl;
    cout << "4. Vertices requeridos: " << quantidadeVerticesRequeridos(grafo) << endl;
    cout << "5. Arestas requeridas: " << quantidadeArestasRequeridas(grafo) << endl;
    cout << "6. Arcos requeridos: " << quantidadeArcosRequeridos(grafo) << endl;
    cout << "7. Densidade: " << densidadeGrafo(grafo) << endl;
    cout << "8. Componentes conectados: " << componentesConectados(grafo) << endl;
    cout << "9. Grau minimo: " << grauMinimo(grafo) << endl;
    cout << "10. Grau maximo: " << grauMaximo(grafo) << endl;
    cout << "12. Caminho medio: " << caminhoMedio(dist) << endl;
    cout << "13. Diametro: " << diametro(dist) << endl;

    return 0;
}
