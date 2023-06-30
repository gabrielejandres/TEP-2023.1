/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 10 (Lista 9) | Problema B | Road Optimization
*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define MAX numeric_limits<int>::max()

int main() {
    int i, j, k, numRoadSigns, distance, maxRemovedSigns, minTime = MAX, offset = 2;
    vector<int> signsCoordinates, speedLimits; 

    cin >> numRoadSigns >> distance >> maxRemovedSigns;
    speedLimits.resize(numRoadSigns + offset);
    signsCoordinates.resize(numRoadSigns + offset);

    for (i = 1; i <= numRoadSigns; i++)
        cin >> signsCoordinates[i];

    for (i = 1; i <= numRoadSigns; i++)
        cin >> speedLimits[i];

    numRoadSigns++;

    signsCoordinates[numRoadSigns] = distance;
    vector<vector<int>> currentTimes(numRoadSigns + offset, vector<int>(numRoadSigns + offset, (MAX - 1) / 2));
    currentTimes[1][0] = 0;

    for (i = 1; i <= numRoadSigns; i++) {
        for (j = 0; j <= maxRemovedSigns; j++) {
            for (k = 1; k < i; k++)
                if (i - k - 1 <= j) 
                    currentTimes[i][j] = min(currentTimes[i][j], currentTimes[k][j - (i - k - 1)] + speedLimits[k] * (signsCoordinates[i] - signsCoordinates[k]));

            if (i == numRoadSigns) minTime = min(minTime, currentTimes[i][j]);
        }
    }

    cout << minTime << endl;

    return 0;
}