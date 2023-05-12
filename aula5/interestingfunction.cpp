/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 5 | Problema F | Interesting Function
*/

#include <iostream>

using namespace std;

int main() {
    int cases, l, r, changedDigits;

    cin >> cases;

    while (cases--) {
        changedDigits = 0;

        cin >> l;
        cin >> r;

        while (l != 0 || r != 0) {
            changedDigits += r - l; 
            r /= 10; 
            l /= 10;
        }

        cout << changedDigits << endl;
    }
}