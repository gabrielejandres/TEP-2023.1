/*
  * Topicos Especiais em Programacao | UFRJ | 2023.1
  * Gabriele Jandres Cavalcanti | 119159948
  * Aula 3 | Problema B | Ordering Tasks
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ideia: ordenar a lista de tarefas utilizando ordenacao
void DFS(int source, vector<int> adj[], bool visited[], stack<int>& orderedTasks) {
    int i, destination;
    visited[source] = true; // marca o vertice como visitado

    for (i = 0; i < adj[source].size(); i++) { 
        destination = adj[source][i];
        // chama a DFS para o vizinho se ele ainda nao foi visitado
        if (!visited[destination]) DFS(destination, adj, visited, orderedTasks);
    }

    orderedTasks.push(source); // empilha o vertice atual na pilha de ordenacao
}

int main() {
    int numTasks, numPrecedences, i;
    int source, destination;

    // leitura do numero de tarefas e precedencias
    cin >> numTasks;
    cin >> numPrecedences;

    while (!(numTasks == 0 && numPrecedences == 0)) {
        vector<int> adj[numTasks + 1]; // lista de adjacencias para os vertices (tarefas)
        bool visited[numTasks + 1] = {false}; // vetor de vertices visitados
        stack<int> orderedTasks; // pilha de ordenacao

        // leitura das arestas
        for (i = 0; i < numPrecedences; i++) {
            cin >> source; 
            cin >> destination;
            adj[source].push_back(destination); // adiciona a aresta source -> destination ao vetor de adjacencia
        }

        // executa a DFS para cada vértice nao visitado
        for (i = 1; i <= numTasks; i++) 
            if (!visited[i]) DFS(i, adj, visited, orderedTasks);

        // exibe a ordenacao
        while (!orderedTasks.empty()) {
            cout << orderedTasks.top() << " ";
            orderedTasks.pop();
        }
        cout << endl;

        // leitura do numero de tarefas e precedencias para a proxima iteracao
        cin >> numTasks;
        cin >> numPrecedences;
    }

    return 0;
}

