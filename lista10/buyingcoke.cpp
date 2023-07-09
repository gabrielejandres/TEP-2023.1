/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 8 (Lista 10) | Problema I | Buying Coke
*/

#include <iostream>
#include <cstring>

#define MAX_COKES 160
#define MAX_COINS5 150
#define MAX_COINS10 60
#define INF 1e9

using namespace std;

int minimumCoins[MAX_COKES][MAX_COINS5][MAX_COINS10];

int calculateMinimumCoins(int cokeCount, int numCoins5, int numCoins10, int totalMoney, int numCokes) {
	if (minimumCoins[cokeCount][numCoins5][numCoins10] != -1) return minimumCoins[cokeCount][numCoins5][numCoins10];
	if (cokeCount == numCokes) return minimumCoins[cokeCount][numCoins5][numCoins10] = 0;

	int numCoins1 = totalMoney - 8 * cokeCount - 5 * numCoins5 - 10 * numCoins10;
	int minNumCoins = INF;

	if (numCoins1 >= 8) 
        minNumCoins = min(minNumCoins, 8 + calculateMinimumCoins(cokeCount + 1, numCoins5, numCoins10, totalMoney, numCokes));
	
    if (numCoins5 >= 1 && numCoins1 >= 3) 
        minNumCoins = min(minNumCoins, 4 + calculateMinimumCoins(cokeCount + 1, numCoins5 - 1, numCoins10, totalMoney, numCokes));
	
    if (numCoins10 >= 1 && numCoins1 >= 3) 
        minNumCoins = min(minNumCoins, 4 + calculateMinimumCoins(cokeCount + 1, numCoins5 + 1, numCoins10 - 1, totalMoney, numCokes));
	
    if (numCoins5 >= 2) 
        minNumCoins = min(minNumCoins, 2 + calculateMinimumCoins(cokeCount + 1, numCoins5 - 2, numCoins10, totalMoney, numCokes));
	
    if (numCoins10 >= 1) 
        minNumCoins = min(minNumCoins, 1 + calculateMinimumCoins(cokeCount + 1, numCoins5, numCoins10 - 1, totalMoney, numCokes));

    minimumCoins[cokeCount][numCoins5][numCoins10] = minNumCoins;
	return minNumCoins;
}

int main() {
    int numCases, numCokes, numCoins1, numCoins5, numCoins10, totalMoney, minCoins;
	cin >> numCases;

	while (numCases--) {
        cin >> numCokes >> numCoins1 >> numCoins5 >> numCoins10;
        
		totalMoney = numCoins1 + 5 * numCoins5 + 10 * numCoins10;
		memset(minimumCoins, -1, sizeof(minimumCoins));
        minCoins = calculateMinimumCoins(0, numCoins5, numCoins10, totalMoney, numCokes);

        cout << minCoins << endl;
	}

	return 0;
}