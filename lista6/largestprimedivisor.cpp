/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 6 | Problema A | Largest Prime Divisor
*/

#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    ll number, largestPrimeDivisor, i;
    int totalPrimeDivisors;

    cin >> number;

    while (number != 0) {

        if (number < 0) number *= -1; // torna os numeros negativos em positivos

        // inicialmente o numero nao tem LPD 
        largestPrimeDivisor = -1; 
        totalPrimeDivisors = 0; 

        for (i = 2; i * i <= number; i++) {
            if (number == 1) break;

            while (number % i == 0) {
                number /= i;
                largestPrimeDivisor = i;
            }
            
            if (largestPrimeDivisor == i) totalPrimeDivisors++;
        }

        if (number != 1 && largestPrimeDivisor != -1) largestPrimeDivisor = number; // proprio numero eh primo divisor
        else largestPrimeDivisor = totalPrimeDivisors == 1 ? -1 : largestPrimeDivisor; // nao tem mais que um divisor primo

        cout << largestPrimeDivisor << endl;

        cin >> number;
    }

    return 0;
}