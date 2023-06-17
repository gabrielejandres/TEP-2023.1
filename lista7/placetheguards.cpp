/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 7 | Problema G | Place the Guards
*/

#include <iostream>
#include <queue>
#include <vector>

#define PART1 0
#define PART2 1
#define NOT_VISITED 2
#define MAX 2

using namespace std;

int main() {
    int numCases, numJunctions, numStreets, junctionA, junctionB, numGuards, i, j, next, junctionCount[MAX];
    queue<int> junctionQueue;
    bool isBipartite; 

    cin >> numCases;

    while (numCases--) {
        cin >> numJunctions >> numStreets;

        vector<vector<int>> adj(numJunctions); // grafo das ruas e cruzamentos
        vector<int> partition(numJunctions, NOT_VISITED); // particao de cada cruzamento
        isBipartite = true;

        while (numStreets--) {
            cin >> junctionA >> junctionB;
            adj[junctionA].push_back(junctionB);
            adj[junctionB].push_back(junctionA);
        }

        numGuards = 0;
        for (i = 0; i < adj.size() && isBipartite; i++) { // busca em largura (BFS) nos cruzamentos do grafo, para verificar se eh bipartido
            if (partition[i] != NOT_VISITED) continue; // ignora se ele ja foi visitado
            fill(junctionCount, junctionCount + MAX, 0);
            partition[i] = PART1;
            junctionCount[partition[i]]++;
            junctionQueue = {};
            junctionQueue.push(i);

            while (!junctionQueue.empty() && isBipartite) {
                next = junctionQueue.front();
                junctionQueue.pop();
                for (j = 0; j < adj[next].size(); j++) {
                    numJunctions = adj[next][j];
                    if (partition[numJunctions] == partition[next]) {
                        isBipartite = false;
                        break;
                    }
                    else if (partition[numJunctions] == NOT_VISITED) {
                        partition[numJunctions] = 1 - partition[next];
                        junctionCount[partition[numJunctions]]++;
                        junctionQueue.push(numJunctions);
                    }
                }
            }
            
            numGuards += max(1, min(junctionCount[PART1], junctionCount[PART2])); // junctionCount armazena quantos cruzamentos de cada cor foram encontrados em cada componente conexo do grafo durante a busca em largura (BFS), no fim soma-se o minimo, pois queremos a menor quantidade possivel de guardas
        }

        cout << (isBipartite ? numGuards : -1) << endl;
    }

    return 0;
}