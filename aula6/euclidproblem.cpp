/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 6 | Problema B | Euclid Problem
*/

#include <iostream>

using namespace std;

int gcd, x, y; // maior divisor comum, coeficientes x e y de ax + by = d, onde d = gcd

// Aplica o algoritmo de euclides estendido para calcular os coeficientes x, y e o mdc
void extendedEuclid(int a, int b) {
    int aux; 

    if (b == 0) { // caso base onde a eh o mdc e os coeficientes serao 1 e 0
        gcd = a;
        x = 1;
        y = 0;
        return;
    } 

    extendedEuclid(b, a % b); // chamada recursiva para o proximo passo do algoritmo

    // atualiza os coeficientes
    aux = x; 
    x = y;
    y = (aux - ((a / b) * y)); 
}

int main() {
    int a, b;

    while (cin >> a && cin >> b) {
        extendedEuclid(a, b);
        cout << x << " " << y << " " << gcd << endl;
    }

    return 0;
}