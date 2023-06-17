/*
  * Topicos Especiais em Programacao | UFRJ | 2023.1
  * Gabriele Jandres Cavalcanti | 119159948
  * Aula 2 | Problema F | Tree Summing
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool goalSumFound = false;

bool processTrees(int totalSum, int goalSum, char &c) {
    string nodeValue; // string para salvar o valor do no a medida que a leitura for feita
    bool leftTree, rightTree, negativeValue = false; // indicam se ha ramos na esquerda e direita

    while (c == '\n' || c == ' ') // consome espacos em branco e quebras de linhas
        c = getchar();

    if (c == '(') {
        while (c = getchar()) { // leitura do valor do no
            if (c >= '0' && c <= '9') nodeValue += (c);
            
            else {
                if (c == '-') negativeValue = true;
                else break; 
            }            
        }

        nodeValue = negativeValue ? "-" + nodeValue : nodeValue;

        while (c == '\n' || c == ' ')
            c = getchar();

        // se o valor do no esta vazio, nao ha ramos, entao eh folha
        if (nodeValue.empty()) return false;        

        // busca em profundidade nos ramos da esquerda e direita da arvore
        leftTree = processTrees(totalSum + stoi(nodeValue), goalSum, c); 
        while ((c = getchar()) != '('); 
        rightTree = processTrees(totalSum + stoi(nodeValue), goalSum, c); 
        while ((c = getchar()) != ')'); 

        if (leftTree == false && rightTree == false) // se os ramos nao existem, eh uma folha
            if (totalSum + stoi(nodeValue) == goalSum) goalSumFound = true;

        return true; 
    }

    return false;  
}

int main() {
    int goalSum;
    char c;

    while (scanf("%d", &goalSum) == 1) {
        c = getchar();
        processTrees(0, goalSum, c);
        cout << (goalSumFound ? "yes" : "no") << endl;
        goalSumFound = false;
    }

    return 0;
}