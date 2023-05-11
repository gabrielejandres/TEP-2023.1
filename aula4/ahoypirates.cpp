/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 4 | Problema E | Ahoy, Pirates!
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/* Implementa uma arvore de segmentos com lazy propagation para responder a diferentes queries */

#define N 1024000

int piratesDescription[N];
int segmentTree[N * 5];
int lazyDescription[N * 5];

// Atualiza os nos da arvore que precisam ser atualizados antes que uma query possa ser realizada
void lazyPropagation(int node, int initialIndex, int lastIndex) {
    int middle;
    if (lazyDescription[node] != 0) {
        if (lazyDescription[node] == 1) segmentTree[node] = (lastIndex - initialIndex + 1);
        else if (lazyDescription[node] == 2) segmentTree[node] = 0;
        else if (lazyDescription[node] == -1) segmentTree[node] = (lastIndex - initialIndex + 1) - segmentTree[node];

        if (initialIndex != lastIndex) {
            if (lazyDescription[node] == -1) {
                middle = (initialIndex + lastIndex) / 2;
                lazyPropagation(node * 2, initialIndex, middle);
                lazyPropagation(node * 2 + 1, middle + 1, lastIndex);
            }
            lazyDescription[node * 2] = lazyDescription[node];
            lazyDescription[node * 2 + 1] = lazyDescription[node];
        }
        lazyDescription[node] = 0;
    }
}

// Retorna a soma de uma faixa de valores
int sumRange(int node, int initialIndex, int lastIndex, int i, int j) {
    int middle, p1, p2;
    if (initialIndex > lastIndex) return 0;
    else if (initialIndex > j || lastIndex < i) return 0;
    lazyPropagation(node, initialIndex, lastIndex);
    if (initialIndex >= i && lastIndex <= j) return segmentTree[node];
    middle = (initialIndex + lastIndex) / 2;
    p1 = sumRange(node * 2, initialIndex, middle, i, j);
    p2 = sumRange(node * 2 + 1, middle + 1, lastIndex, i, j);
    return p1 + p2;
}

// Atualiza uma faixa de valores com um valor especifico
void mutatePirates(int node, int initialIndex, int lastIndex, int i, int j, int val) {
    int middle; 

    lazyPropagation(node, initialIndex, lastIndex); 
    if (initialIndex > lastIndex) return;
    else if (initialIndex > j || lastIndex < i) return;

    if (initialIndex >= i && lastIndex <= j) {
        lazyDescription[node] = val;
        lazyPropagation(node, initialIndex, lastIndex);
        return;
    }

    middle = (initialIndex + lastIndex) / 2;
    mutatePirates(node * 2, initialIndex, middle, i, j, val);
    mutatePirates(node * 2 + 1, middle + 1, lastIndex, i, j, val);
    segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];
}

// Preenche a arvore recursivamente com os valores dados por piratesDescription
void initializeTree(int node, int initialIndex, int lastIndex) {
    int left, right, middle;

    if (initialIndex == lastIndex) { // condição de parada da recursão
        segmentTree[node] = piratesDescription[initialIndex];
        return;
    }

    left = node * 2;
    right = node * 2 + 1;
    middle = (initialIndex + lastIndex) / 2;

    initializeTree(left, initialIndex, middle);
    initializeTree(right, middle + 1, lastIndex);
    segmentTree[node] = segmentTree[left] + segmentTree[right];
}

int main() {
    int cases, i, j, k, l, numPairLines, numConcatenations, position, numQueries, answersForGod, firstIndex, lastIndex;
    string pirates; // string que armazena a descricao dos piratas
    char query; // query pode ser 'F', 'E', 'I' ou 'S'

    cin >> cases; // numero de casos de teste
    for (i = 1; i <= cases; i++) {
        position = 0; // armazena a posicao atual da string "piratesDescription"
        answersForGod = 0; // armazena o numero de queries do tipo 'S'

        cin >> numPairLines; // numero de pares de linha com o numero de concatenacoes e strings que seguirao
        for (j = 1; j <= numPairLines; j++) {
            cin >> numConcatenations;
            cin >> pirates;

            // concatenamos a string "pirates" "numConcatenations" vezes utilizando a adicao no vetor "piratesDescription"
            for (k = 1; k <= numConcatenations; k++)
                for (l = 0; l < pirates.size(); l++) 
                    piratesDescription[++position] = pirates[l] - '0';
        }

        memset(lazyDescription, 0, sizeof(lazyDescription));
        initializeTree(1, 1, position);
        cin >> numQueries;
        cout << "Case " << i << ":" << endl;

        for (j = 1; j <= numQueries; j++) {
            cin >> query;
            cin >> firstIndex;
            cin >> lastIndex;

            switch (query) {
                case 'F':
                    mutatePirates(1, 1, position, ++firstIndex, ++lastIndex, 1);
                    break;
                case 'E':
                    mutatePirates(1, 1, position, ++firstIndex, ++lastIndex, 2);
                    break;
                case 'I':
                    mutatePirates(1, 1, position, ++firstIndex, ++lastIndex, -1);
                    break;
                default:
                    cout << "Q" << ++answersForGod << ": " << sumRange(1, 1, position, ++firstIndex, ++lastIndex) << endl;
            }
        }
    }
}