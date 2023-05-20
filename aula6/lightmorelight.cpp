/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 6 | Problema E | Light, More Light
*/

#include <iostream>
#include <cmath>

typedef long long ll;

using namespace std;

// Verifica se o numero eh um quadrado perfeito
bool isPerfectSquare(ll num) {
    ll root = sqrt(num);
    if (root * root == num) return true;
    return false;
}

int main() {
    ll nthBulb;

    while (cin >> nthBulb && nthBulb != 0) 
        cout << (isPerfectSquare(nthBulb) ? "yes" : "no") << endl;

    return 0;
}