/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 7 | Problema D | Friends
*/

#include <iostream>

#define MAX 30000

using namespace std;

int parents[MAX], Rank[MAX], elements[MAX], peopleInLargestGroup;

// Inicializa os arrays de elementos e de controle
void initialize(int n) {
    int i;
    for (i = 0; i < n; ++i) {
        parents[i] = i; // o pai eh ele proprio
        Rank[i] = 0; // classificacao inicial
        elements[i] = 1; // cada grupo tem inicialmente um elemento
    }
}

// Encontra o representante (raiz) do conjunto que contem o elemento 
int find(int indexElement) {
    if (indexElement != parents[indexElement]) parents[indexElement] = find(parents[indexElement]);
    return parents[indexElement];
}

// Junta dois conjuntos, identificados pelos elementos x e y. Ela verifica se os dois elementos ja estao no mesmo conjunto. Se nao estiverem, o conjunto com menor classificacao (Rank) eh anexado ao conjunto com maior classificacao.
void join(int x, int y) {
    if (find(x) != find(y)) {
        if (Rank[x] > Rank[y]) {
            parents[y] = x;
            elements[x] += elements[y];
            peopleInLargestGroup = (peopleInLargestGroup < elements[x]) ? elements[x] : peopleInLargestGroup;
        } else {
            parents[x] = y;
            elements[y] += elements[x];
            peopleInLargestGroup = (peopleInLargestGroup < elements[y]) ? elements[y] : peopleInLargestGroup;
            if (Rank[x] == Rank[y]) Rank[y] = Rank[y] + 1;
        }
    }
}

// Realiza a uniao dos conjuntos contendo os elementos x e y
void Union(int x, int y) {
    join(find(x), find(y));
}

int main() {
    int numCitizens, numPairs, friendA, friendB, numCases;
    cin >> numCases;

    while (numCases--) {
        cin >> numCitizens;
        cin >> numPairs;

        peopleInLargestGroup = 1;
        initialize(numCitizens);
        
        while (numPairs--) {
            cin >> friendA >> friendB;
            Union(--friendA, --friendB);
        }

        cout << peopleInLargestGroup << endl;
    }

    return 0;
}