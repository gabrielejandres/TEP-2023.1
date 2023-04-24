/*
  * Topicos Especiais em Programacao | UFRJ | 2023.1
  * Gabriele Jandres Cavalcanti | 119159948
  * Aula 3 | Problema A | Vito's Family
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

// particao utilizada no algoritmo Quick Select
int partition(vector<int>& array, int left, int right) {
    int x = array[right], i = left;
    for (int j = left; j <= right - 1; j++) {
        if (array[j] <= x) {
            swap(array[i], array[j]);
            i++;
        }
    }
    swap(array[i], array[right]);
    return i;
}
  
// retorna o k-esimo menor elemento do array usando Quick Select
int kthSmallest(vector<int>& array, int left, int right, int k) {
    if (k > 0 && k <= right - left + 1) { 
        int index = partition(array, left, right);
        if (index - left == k - 1) return array[index];
        if (index - left > k - 1) return kthSmallest(array, left, index - 1, k);
        return kthSmallest(array, index + 1, right, k - index + left - 1);
    }
  
    return INT_MAX;
}

int main() {
    int numTests, numRelatives, i, median, sum;
    double kIndex;
    vector<int> houses(numRelatives);

    cin >> numTests;

    while (numTests--) {
        cin >> numRelatives;

        // leitura dos numeros das casas
        for (i = 0; i < numRelatives; i++) cin >> houses[i];

        // quick select para evitar ordenacao e obter a mediana dos valores
        kIndex = numRelatives / 2.0;
        median = kthSmallest(houses, 0, numRelatives - 1, ceil(kIndex));
        
        // calculo da distancia de cada casa ate a mediana
        sum = 0;
        for (i = 0; i < numRelatives; i++) sum += abs(houses[i] - median);
        
        cout << sum << endl;

        // limpa o vetor para proxima iteracao
        houses.clear();
    }
    return 0;
}