/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 6 | Problema C | Factovisors
*/

#include <iostream>
#include <vector>

#define N 25000

using namespace std;

// Retorna um vetor de booleanos, onde o indice i eh true se i for primo e false caso contrario
vector<bool> eratosthenesSieve(int num) {
    vector<bool> numbers = vector<bool>(num, true); // Todos os numeros sao primos inicialmente
    int i, j;

    for (i = 3; i * i <= num; i += 2) 
        if (numbers[i]) for (j = i * i; j <= num; j += i) numbers[j] = false;

    return numbers;
}

// Retorna os primos encontrados ate num
vector<int> getPrimes(int num) {
    int i;
    vector<int> primes;
    vector<bool> numbers = eratosthenesSieve(num);

    primes.push_back(2);
    for (i = 3; i <= num; i += 2) 
        if (numbers[i]) primes.push_back(i);

    return primes;
}

bool isDivisible(int n, int m, vector<int> primes) {
    int i, aux, countN, countM;   
    for (i = 0; i < primes.size() && primes[i] * primes[i] <= m; i++) {
        if (m % primes[i] == 0) {                                        
            countN = 0;
            countM = 0; 
            aux = n;

            while (m % primes[i] == 0) {
                m /= primes[i];
                countM++;
            }

            while (aux) {
                aux /= primes[i];
                countN += aux;
            }

            if (countN < countM) return false;
        }
    }

    if (m > 1 && n < m) return false; // Se m for primo e maior que n, nao ha como dividir 

    return true;
}

int main() {
    int n, m;
    vector<int> primes = getPrimes(N);

    while (cin >> n && cin >> m) {
        if (isDivisible(n, m, primes)) {
            cout << m << " divides " << n << "!" << endl;
            continue;
        }

        cout << m << " does not divide " << n << "!" << endl;
    }

    return 0;
}