/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 4 | Problema A | Knight Tournament
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int knights, fights, min, max, winner, i, aux; // min e max sao os limites do intervalo de luta 
    set<int> knightsInGame; // set de cavaleiros no jogo
    set<int>::iterator it; // iterator para percorrer o set de cavaleiros no jogo

    // leitura de dados
    cin >> knights;
    cin >> fights;

    int winnerByFights[knights + 1]; // vetor para armazenar quem ganhou de cada um dos cavaleiros e no caso de ser o ganhador do torneio armazena 0

    // inicializacao do set de cavaleiros ainda no jogo
    for (i = 1; i <= knights; i++) knightsInGame.insert(i);

    memset(winnerByFights, 0, sizeof(winnerByFights));

    for (i = 0; i < fights; i++) {
        // leitura dos limites do intervalo de luta e do ganhador
        cin >> min;
        cin >> max;
        cin >> winner;

        it = knightsInGame.lower_bound(min);

        while (*it <= max && it != knightsInGame.end()) {
            // se o cavaleiro nao for o ganhador, escrevemos o ganhador no vetor e removemos o cavaleiro do set
            if (*it != winner) {
                winnerByFights[*it] = winner;
                aux = *it;
                it++;
                knightsInGame.erase(aux);
            }
            // se o cavaleiro for o ganhador somente continuamos a iteracao
            else it++;
        }
    }

    for (i = 1; i <= knights; i++) {
        cout << winnerByFights[i] << " ";
    }

    cout << endl;

    return 0;
}