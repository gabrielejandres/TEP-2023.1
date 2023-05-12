/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 5 | Problema A | Competitive Programmer
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int numGrandmasters, i, digit, totalEven, sum;
    bool hasZero;
    string number;

    cin >> numGrandmasters;

    while (numGrandmasters--) {
        sum = 0;
        hasZero = false;
        totalEven = 0;

        cin >> number;

        // para ser divisivel por 60, o numero deve ser divisivel por 3, 4 e 5
            // para ser divisivel por 3, a soma dos digitos deve ser divisivel por 3
            // para ser divisivel por 4, os ultimos dois digitos devem ser divisiveis por 4 (se tiver pelo menos um zero, entao deve ter pelo menos dois pares)
            // para ser divisivel por 5, deve ter pelo menos um zero
        for (i = 0; i < number.length(); i++) {
            digit = number[i] - '0';
            if (digit % 2 == 0) totalEven++;
            if (digit == 0) hasZero = true;
            sum += digit;
        }

        if (sum % 3 == 0 && totalEven > 1 && hasZero) cout << "red" << endl;
        else cout << "cyan" << endl;
    }

    return 0;
}