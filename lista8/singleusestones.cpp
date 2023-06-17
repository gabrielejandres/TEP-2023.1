/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 9 (Lista 8) | Problema C | Single-use Stones
*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int riverWidth, maxJumpLength, i, maxFrogs = numeric_limits<int>::max();
    vector<int> stones(riverWidth);

    cin >> riverWidth >> maxJumpLength;
    
    for (i = 0; i < riverWidth; i++) {
        if (i == 0) stones[i] = 0;
        else {
            cin >> stones[i];
            stones[i] += stones[i - 1];
        }
    }

    for (i = maxJumpLength; i < riverWidth; i++) 
        maxFrogs = min(maxFrogs, stones[i] - stones[i - maxJumpLength]);

    cout << maxFrogs << endl;

    return 0;
}