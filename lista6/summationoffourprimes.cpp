/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 6 | Problema F | Summation of Four Primes
 */

#include <iostream>
#include <vector>

#define N 10000000

using namespace std;

// Retorna um vetor de booleanos, onde o indice i eh true se i for primo e false caso contrario
vector<bool> eratosthenesSieve(int num) {
    int i, j;
    vector<bool> numbers(num + 1, true); // todos sao primos inicialmente
 
    numbers[0] = numbers[1] = false; // 0 e 1 nao sao primos

    for (i = 2; i * i <= num; i++) 
        if (numbers[i]) // se i for primo, todos os multiplos sao marcados como nao primos
            for (j = 2 * i; j <= num; j += i) numbers[j] = false;

    return numbers;
}

int main() {
    vector<bool> numbers = eratosthenesSieve(N);
    int remainingSum, num, i, aux;
    string primes;

    while (cin >> num) {
        primes = "";
        
        if (num % 2 == 0) {
            primes += "2 2 ";
            remainingSum = num - 4;
        } else {
            primes += "2 3 ";
            remainingSum = num - 5;
        }

        for (i = 2; i < remainingSum; i++) 
            if (numbers[i] && numbers[remainingSum - i]) {
                aux = remainingSum - i;
                primes += (to_string(i) + " " + to_string(aux));
                break;
            }

        if (!(numbers[i] && numbers[remainingSum - i])) cout << "Impossible." << endl;
        else cout << primes << endl;
    }

    return 0;
}