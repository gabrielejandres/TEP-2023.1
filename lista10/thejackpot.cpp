/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 8 (Lista 10) | Problema B | The Jackpot
*/

#include <iostream>

#define MAX 10000

using namespace std;

int main() {
	int sequenceLength, i, bets[MAX], maxWinningStreak = 0, aux = 0;

	while (cin >> sequenceLength && sequenceLength != 0) {
		for (i = 0; i < sequenceLength; i++) 
            cin >> bets[i];

		for (i = 0; i < sequenceLength; i++) {
			aux += bets[i];
			if (aux > maxWinningStreak) maxWinningStreak = aux;
			if (aux < 0) aux = 0;
		}

		if (maxWinningStreak > 0) cout << "The maximum winning streak is " << maxWinningStreak << "." << endl;
		else cout << "Losing streak." << endl;

        maxWinningStreak = 0, aux = 0;
	}

	return 0;
}