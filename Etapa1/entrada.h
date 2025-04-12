// Implementacao da leitura de dados
#ifndef ENTRADA_H
#define ENTRADA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "grafo.h"
using namespace std;

void lerInstancia(const string& nomeArquivo, Grafo& g, int& capacidade, int& deposito) {
    string caminho = "selected_instances/" + nomeArquivo;
    ifstream file(caminho);

    //cout << "[INFO] Lendo arquivo: " << caminho << endl;

    if (!file.is_open()) {
        cerr << "[ERRO] Não foi possivel abrir o arquivo: " << caminho << endl;
        return;
    }

    string linha;
    int num_vertices = 0;

    enum Estado { NENHUM, REN, REE, REA, NRARC } estado = NENHUM;

    while (getline(file, linha)) {
        //cout << "[LINHA] " << linha << endl;

        // Remover espacos a esquerda
        while (!linha.empty() && isspace(linha[0])) linha.erase(0, 1);
        if (linha.empty()) continue;

        istringstream iss(linha);

        if (linha.find("Depot Node:") != string::npos) {
            iss.ignore(256, ':');
            iss >> deposito;

        } else if (linha.find("Capacity:") != string::npos) {
            iss.ignore(256, ':');
            iss >> capacidade;

        } else if (linha.find("#Nodes:") != string::npos) {
            iss.ignore(256, ':');
            iss >> num_vertices;
            g = Grafo(num_vertices);
            cout << "[DEBUG] Numero de vertices definido: " << num_vertices << endl;


        } else if (linha.find("ReN.") != string::npos) {
            estado = REN;
            continue;

        } else if (linha.find("ReE.") != string::npos) {
            estado = REE;
            continue;

        } else if (linha.find("ReA.") != string::npos) {
            estado = REA;
            continue;

        } else if (linha.find("ARC") != string::npos) {
            estado = NRARC;
            continue;

        } else if (linha.find("EDGE") != string::npos) {
            estado = NENHUM;
            continue;
        }

        // Leitura por seção
        if (estado == REN) {
            string nome;
            int demanda, servico;
            istringstream parser(linha);
            parser >> nome >> demanda >> servico;

            if (nome.size() < 2 || nome[0] != 'N') {
                cerr << "[ERRO] Linha invalida na secao ReN: " << linha << endl;
                continue;
            }

            int no = stoi(nome.substr(1)) - 1;
            g.verticesRequeridos.insert(no);

        } else if (estado == REE) {
            string nome;
            int u, v, custo, demanda, servico;
            istringstream parser(linha);
            parser >> nome >> u >> v >> custo >> demanda >> servico;

            g.adicionarAresta(u - 1, v - 1, custo, demanda, true);

        } else if (estado == REA) {
            string nome;
            int u, v, custo, demanda, servico;
            istringstream parser(linha);
            parser >> nome >> u >> v >> custo >> demanda >> servico;

            g.adicionarArco(u - 1, v - 1, custo, demanda, true);

        } else if (estado == NRARC) {
            string nome;
            int u, v, custo;
            istringstream parser(linha);
            parser >> nome >> u >> v >> custo;

            g.adicionarArco(u - 1, v - 1, custo, 0, false);
        }
    }
}

#endif
