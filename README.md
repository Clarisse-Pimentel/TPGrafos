# TPGrafos
Este projeto implementa a leitura e análise de instâncias de grafos com serviços obrigatórios. Ele é baseado em um problema modelado sob um grafo multiconexo G = (V, E, A), em que:
- **V** são os vértices (intersecções).
- **E** são as arestas (vias de mão dupla).
- **A** são os arcos (vias de mão única).
O trabalho foi dividido em quatro etapas:
- Etapa 1: Pré-processamento de dados.
- Etapa 2: Solução inicial.
- Etapa 3: Métodos de melhoria.
- Etapa 4: Relatório e entrevista.
# 👤 Desenvolvido por
Clarisse Lacerda Pimentel
# 📁 Estrutura de diretórios
```
TPGrafos/
├── main.cpp
├── grafo.h
├── entrada.h
├── algoritmos.h
├── estatisticas.h
├── output/
    │└── main.exe
├── selected_instances/
    │ └── BHW1.dat
      └── BHW2.dat
      └── ...
```
# ⚙️ Iniciando o desenvolvimento 
Para conseguir rodar o projeto na sua máquina, siga as orientações a seguir.
*Pré-Requisitos*
- Compilador C++ (com suporte a C++17)
*Clone o repositório*
- Clone o repositório utilizando o seguinte comando:
```bash
git clone https://github.com/Clarisse-Pimentel/Trabalho-Pr-tico-Grafos.git
```
*Como compilar*
```bash
g++ -std=c++17 main.cpp -o output/main.exe
```
*Como executar*
```bash
./output/main.exe
```
Você verá o seguinte prompt e poderá preenchê-lo de acordo com o arquivo de interesse.
```bash
Digite o nome do arquivo (.dat) na pasta 'selected_instances/': 
```

