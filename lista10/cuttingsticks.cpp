/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 8 (Lista 10) | Problema E | Cutting Sticks
*/

#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int calculateMinimumCuttingCost(int left, int right, vector<vector<int>>& minimumCost, const vector<int>& cuttingPoints) {
    int i, minCost = INF;
    if (left + 1 == right) return 0;

    if (minimumCost[left][right] != -1) return minimumCost[left][right];

    for (i = left + 1; i < right; i++)
        minCost = min(minCost, cuttingPoints[right] - cuttingPoints[left] + calculateMinimumCuttingCost(left, i, minimumCost, cuttingPoints) + calculateMinimumCuttingCost(i, right, minimumCost, cuttingPoints));

    minimumCost[left][right] = minCost;
    return minCost;
}

int main() {
    int i, stickLength, numCuts, minCuttingCost;

    while (cin >> stickLength && stickLength != 0) {
        cin >> numCuts;

        vector<int> cuttingPoints(numCuts + 2);
        for (i = 1; i <= numCuts; i++)
            cin >> cuttingPoints[i];

        cuttingPoints[0] = 0;
        cuttingPoints[numCuts + 1] = stickLength;

        vector<vector<int>> minimumCost(numCuts + 2, vector<int>(numCuts + 2, -1));

        minCuttingCost = calculateMinimumCuttingCost(0, numCuts + 1, minimumCost, cuttingPoints);

        cout << "The minimum cutting is " << minCuttingCost << "." << endl;
    }

    return 0;
}
