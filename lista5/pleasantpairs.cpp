/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 5 | Problema E | Pleasant Pairs
*/

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
    int cases, i;

    cin >> cases;

    while (cases--) {
        ll totalNumbers, numberOfPairs = 0, i, j;
        
        cin >> totalNumbers;

        vector<pair<ll, ll>> numbers(totalNumbers); 

        for (i = 0; i < totalNumbers; i++) {
            cin >> numbers[i].first; // valor
            numbers[i].second = i + 1; // indice
        } 

        sort(numbers.begin(), numbers.end());
        
        for (i = 0; i < totalNumbers; i++) {
            for (j = i + 1; j < totalNumbers ; j++) {
                if (numbers[i].first * numbers[j].first > 2 * totalNumbers) break; 
                if (numbers[i].first * numbers[j].first == numbers[i].second + numbers[j].second) numberOfPairs++;
            }
        }

        cout << numberOfPairs << endl;
    }

    return 0;
}