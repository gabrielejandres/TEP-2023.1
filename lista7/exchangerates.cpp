/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 7 | Problema E | Exchange Rates
*/

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

#define MAX 60

using namespace std;

int edges[MAX][MAX] = {0}, visited[MAX], parent[MAX]; // informacoes do grafo e da DFS 

// Busca em profundidade a partir do vertice u
void DFS(int u) {
    int v;
    visited[u] = 1; // marca o vertice u como visitado
    for (v = 1; v <= MAX; v++) { 
        if (edges[u][v] && !visited[v]) { // se tiver uma aresta entre u e v e nao tivermos visitado v, vamos fazer a busca em v para visitar os adjacentes
            parent[v] = u;
            DFS(v);
        }
    }
}

int main() {
    int v, u, divisor, numCoins = 0, qtFirstItem, qtSecondItem;
    char command, equals;
    string firstItem, secondItem;
    map<string, int> indexByCoin;
    pair<int, int> exchangeRates[MAX][MAX];

    cin >> command;

    while (command != '.') {
        if (command == '!') { // assercao
            cin >> qtFirstItem >> firstItem >> equals >> qtSecondItem >> secondItem;

            if (indexByCoin.find(firstItem) == indexByCoin.end()) {
                numCoins++;
                indexByCoin[firstItem] = numCoins;
            }

            if (indexByCoin.find(secondItem) == indexByCoin.end()) {
                numCoins++;
                indexByCoin[secondItem] = numCoins;
            }

            edges[indexByCoin[firstItem]][indexByCoin[secondItem]] = 1;
            edges[indexByCoin[secondItem]][indexByCoin[firstItem]] = 1;

            divisor = __gcd(qtFirstItem, qtSecondItem);
            qtFirstItem /= divisor, qtSecondItem /= divisor;

            exchangeRates[indexByCoin[firstItem]][indexByCoin[secondItem]] = make_pair(qtFirstItem, qtSecondItem);
            exchangeRates[indexByCoin[secondItem]][indexByCoin[firstItem]] = make_pair(qtSecondItem, qtFirstItem);
        } else { // consulta
            cin >> firstItem >> equals >> secondItem;

            memset(visited, 0, sizeof(visited));
            memset(parent, 0, sizeof(parent));
            DFS(indexByCoin[firstItem]);

            if (visited[indexByCoin[secondItem]]) {
                qtFirstItem = qtSecondItem = 1;
                v = indexByCoin[secondItem];

                while (parent[v]) {
                    u = parent[v];
                    qtFirstItem *= exchangeRates[u][v].first, qtSecondItem *= exchangeRates[u][v].second;
                    divisor = __gcd(qtFirstItem, qtSecondItem);
                    qtFirstItem /= divisor, qtSecondItem /= divisor;
                    v = parent[v];
                }

                cout << qtFirstItem << ' ' << firstItem << " = " << qtSecondItem << ' ' << secondItem << endl;
            } else 
                cout << "? " << firstItem << " = ? " << secondItem << endl;
        }

        cin >> command;
    }

    return 0;
}