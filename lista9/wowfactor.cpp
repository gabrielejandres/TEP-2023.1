/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 10 (Lista 9) | Problema D | WOW Factor
*/

#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
    string s;
    ll wowFactor = 0, i, stringSize, countSize;
    vector<ll> leftCount, rightCount;

    cin >> s;
    stringSize = s.size();
    countSize = stringSize + 1;

    leftCount.resize(countSize, 0);
    rightCount.resize(countSize, 0);

    for (i = 1; i < stringSize; i++) {
        if (s[i] == 'v' && s[i - 1] == 'v') leftCount[i] = leftCount[i - 1] + 1;
        else leftCount[i] = leftCount[i - 1];
    }

    for (i = stringSize - 1; i > 0; i--) {
        if (s[i] == 'v' && s[i - 1] == 'v') rightCount[i] = rightCount[i + 1] + 1;
        else rightCount[i] = rightCount[i + 1];
    }

    for (i = 0; i < stringSize; i++) 
        if (s[i] == 'o') wowFactor += leftCount[i] * rightCount[i];

    cout << wowFactor << endl;

    return 0;
}