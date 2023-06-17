/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 7 | Problema B | Minimal Height Tree
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numCases, vertices, i, index;
    cin >> numCases;

    while (numCases--) {
        cin >> vertices;

        vector<int> heights(vertices, 0);
        vector<int> elements(vertices);

        index = 0; // indice do elemento atual
        heights[1] = 1; // o segundo elemento eh sempre o filho direito do primeiro elemento na arvore, e a altura desse filho direito eh 1
        
        for (i = 0; i < vertices; i++) cin >> elements[i];
        for (i = 2; i < vertices; i++) {
            if (elements[i] < elements[i - 1]) index++; // se o elemento atual for menor que o anterior, incrementa o indice atual e cria novo ramo 
            heights[i] = heights[index] + 1; // altura do elemento eh altura do atual + 1, para garantir que a altura da arvore seja atualizada corretamente 
        }

        cout << heights.back() << endl;
    }

    return 0;
}