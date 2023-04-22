/*
  * Topicos Especiais em Programacao | UFRJ | 2023.1
  * Gabriele Jandres Cavalcanti | 119159948
  * Aula 2 | Problema C | Black Box
*/

#include <iostream>
#include <vector>
#include <set>
  
using namespace std;

void getElement(int *totalGets, multiset<int>::iterator *minimumElement) {
    (*totalGets)++;
    cout << *(*minimumElement) << endl;
    (*minimumElement)++;
}

void getTransactionsAnswers() {
    multiset<int> minimumHeap; // heap de minimo para armazenar os numeros na black box
    multiset<int>::iterator minimumElement; // elemento atual da black box
    vector <int> numbersToAdd, sizesToGet; // leitura inicial de dados
    int numAddTransactions, numGetTransactions, number, size;

    // leitura da quantidade de transacoes
    cin >> numAddTransactions;
    cin >> numGetTransactions;
    
    // leitura dos numeros a serem adicionados de forma desordenada
    while (numAddTransactions--) {
        cin >> number;
        numbersToAdd.push_back(number);
    }
    numAddTransactions = numbersToAdd.size();

    // leitura dos tamanhos da black box nos momentos de get
    while (numGetTransactions--) {
        cin >> size;
        sizesToGet.push_back(size);
    }
    numGetTransactions = sizesToGet.size();

    // adiciona o primeiro elemento na black box e atualiza o elemento atual
    minimumHeap.insert(numbersToAdd[0]);
    minimumElement = minimumHeap.begin();

    int totalGets = 0;
    for (int numberIndex = 1; numberIndex < numAddTransactions; numberIndex++) {
        // verifica se há uma solicitação de obtenção para o numero
        while (totalGets < numGetTransactions && sizesToGet[totalGets] == numberIndex) getElement(&totalGets, &minimumElement);
        minimumHeap.insert(numbersToAdd[numberIndex]);
        // para garantir ordenacao, se o numero for menor que o elemento atual, decrementamos o iterador 
        if (minimumElement == minimumHeap.end() || numbersToAdd[numberIndex] < *minimumElement) --minimumElement; 
    }
    while (totalGets < numGetTransactions && sizesToGet[totalGets] == numAddTransactions) getElement(&totalGets, &minimumElement);
}

int main() {
    int tests;
    cin >> tests;

    while (tests--) {
        getTransactionsAnswers();
        if (tests != 0) cout << '\n';
    }

    return 0;
}
