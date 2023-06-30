/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 10 (Lista 9) | Problema C | Sleeping Schedule
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int i, j, numSleep, hoursInDay, goodSleepingTimeLeft, goodSleepingTimeRight, firstChoice, secondChoice, isFirstChoiceGood, isSecondChoiceGood, choice1Count, choice2Count;
    vector<int> sleepTimes;
    vector<vector<int>> goodSleepCount;
    cin >> numSleep >> hoursInDay >> goodSleepingTimeLeft >> goodSleepingTimeRight;

    sleepTimes.resize(numSleep + 1);
    goodSleepCount.resize(numSleep + 2, vector<int>(hoursInDay + 1));
    int* maxGoodSleep = &goodSleepCount[1][0];

    for (i = 1; i <= numSleep; i++)
        cin >> sleepTimes[i];

    for (i = numSleep; i >= 1; i--) {
        for (j = 0; j < hoursInDay; j++) {
            firstChoice = (j + sleepTimes[i]) % hoursInDay;
            secondChoice = (j + sleepTimes[i] - 1 + hoursInDay) % hoursInDay;
            
            isFirstChoiceGood = (goodSleepingTimeLeft <= firstChoice && firstChoice <= goodSleepingTimeRight);
            isSecondChoiceGood = (goodSleepingTimeLeft <= secondChoice && secondChoice <= goodSleepingTimeRight);

            choice1Count = goodSleepCount[i + 1][firstChoice] + (isFirstChoiceGood ? 1 : 0);
            choice2Count = goodSleepCount[i + 1][secondChoice] + (isSecondChoiceGood ? 1 : 0);

            goodSleepCount[i][j] = max(choice1Count, choice2Count);
        }
    }

    cout << (*maxGoodSleep) << endl;

    return 0;
}