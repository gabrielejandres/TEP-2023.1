/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 10 (Lista 9) | Problema F | Area
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int i, j, l, numCases, caseNumber, n, m, k, maxPlotArea = 0, plotsTotalCost = 0;
    vector<vector<int>> prices;
    
    cin >> numCases;

    for (caseNumber = 1; caseNumber <= numCases; caseNumber++) {
        cin >> n >> m >> k;

        prices.resize(n, vector<int>(m));

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++)
                cin >> prices[i][j];
        }

        for (i = 0; i < n; i++) {
            vector<int> accSum(m, 0);

            for (j = i; j < n; j++) {
                int startIndexArea = 0, area, cost = 0;

                for (l = 0; l < m; l++) {
                    accSum[l] += prices[j][l];
                    cost += accSum[l];

                    while (cost > k)
                        cost -= accSum[startIndexArea++];

                    area = (j - i + 1) * (l - startIndexArea + 1); 

                    if (area > maxPlotArea) {
                        maxPlotArea = area;
                        plotsTotalCost = cost;
                    } else if (area == maxPlotArea && cost < plotsTotalCost)
                        plotsTotalCost = cost;
                }
            }
        }

        cout << "Case #" << caseNumber << ": " << maxPlotArea << " " << plotsTotalCost << endl;

        maxPlotArea = 0;
        plotsTotalCost = 0;
        prices.clear();
    }

    return 0;
}