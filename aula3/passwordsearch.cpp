/*
  * Topicos Especiais em Programacao | UFRJ | 2023.1
  * Gabriele Jandres Cavalcanti | 119159948
  * Aula 3 | Problema E | Password search
*/

#include <iostream>
#include <map>

using namespace std;

int main() {
    int passwordSize, maxOccurrences, i;
    string message, password;
    map<string, int> substringOccurrences;

    while (scanf("%d", &passwordSize) == 1) {
        cin >> message;

        for (i = 0; i < message.length() - passwordSize + 1; i++) substringOccurrences[message.substr(i, passwordSize)]++;
        
        // procura a substring mais frequente
        maxOccurrences = -1; 
        for (const auto& subOccurrence : substringOccurrences) { 
            if (subOccurrence.second > maxOccurrences) { 
                maxOccurrences = subOccurrence.second; 
                password = subOccurrence.first; 
            }
        }

        cout << password << endl;
        substringOccurrences.clear();
    }

    return 0;
}