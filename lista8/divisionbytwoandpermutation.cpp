/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 9 (Lista 8) | Problema A | Division by Two and Permutation
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAX 50

int main() {
    int numCases, n, i, num;
    bool isPermutation;
    vector<bool> isUsed(MAX, false);

    cin >> numCases;

    while (numCases--) {
        isPermutation = true;
        cin >> n;

        for (i = 0; i < n; i++) {
            cin >> num;

            while (num > n || isUsed[num]) 
                num /= 2;

            if (num == 0) isPermutation = false;
            else isUsed[num] = true;
        }

        cout << (isPermutation ? "YES" : "NO") << endl;
        isUsed.assign(MAX, false);
    }

    return 0;
}