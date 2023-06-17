/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 5 | Problema D | Digits Sum
*/

#include <iostream>

using namespace std;

int main() {
    int cases, num, totalInterestings;

    cin >> cases;

    while (cases--) {
        cin >> num;
        totalInterestings = num / 10; // como 9 eh o primeiro digito interessante, o numero de interessantes eh o numero dado dividido por 10 
        if (num % 10 == 9) totalInterestings++; // se o resto da divisao por 10 for 9, o numero eh interessante e deve ser contado
        cout << totalInterestings << endl;
    }

    return 0;
}