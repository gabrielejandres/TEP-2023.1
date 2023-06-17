/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 5 | Problema B | Remainders Game
*/

#include <iostream>
#include <numeric>

typedef long long int ll;

using namespace std;

int main() {
    ll ancientNumbers, k, c, div = 1; // usamos long long int para evitar overflow
    int i;

    scanf("%lld", &ancientNumbers); // scanf eh mais rapido que cin
    scanf("%lld", &k);

    for (i = 0; i < ancientNumbers; i++) {
        scanf("%lld", &c);
        div = gcd(k, lcm(div, c)); // gcd eh a funcao que calcula o mdc, lcm eh a funcao que calcula o mmc
    }

    cout << (div == k ? "Yes" : "No") << endl;

    return 0;
}