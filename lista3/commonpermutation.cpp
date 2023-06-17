/*
  * Topicos Especiais em Programacao | UFRJ | 2023.1
  * Gabriele Jandres Cavalcanti | 119159948
  * Aula 3 | Problema D | Common Permutation
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string firstWord, secondWord, result;
    int c, i, minOcurrences;
    map<char, int> firstWordCharOcurrences; // controle de caracteres da string1
    map<char, int> secondWordCharOcurrences; // controle de caracteres da string2

    while (getline(cin, firstWord)) {
        getline(cin, secondWord);

        // inicializacao dos maps
        for (c = 'a'; c <= 'z'; c++) {
            firstWordCharOcurrences[c] = 0;
            secondWordCharOcurrences[c] = 0;
        }

        // contagem de ocorrencias de cada caractere nas palavras
        for (c = 0; c < firstWord.length(); c++) 
            firstWordCharOcurrences[firstWord[c]]++;

        for (c = 0; c < secondWord.length(); c++)
            secondWordCharOcurrences[secondWord[c]]++;

        for (c = 'a'; c <= 'z'; c++) 
            if (firstWordCharOcurrences[c] > 0 && secondWordCharOcurrences[c] > 0) {
                minOcurrences = min(firstWordCharOcurrences[c], secondWordCharOcurrences[c]);
                for (i = 0; i < minOcurrences; i++) result += c;
            }
        
        cout << result << endl;
        result = "";
    }

    return 0;
}