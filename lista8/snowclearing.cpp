/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 9 (Lista 8) | Problema D | Snow Clearing
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define VELOCITY 20.0

int main() {
    int numCases, x1, y1, x2, y2;
    double distance = 0, hours, minutes;
    string streetCoordinates;

    cin >> numCases;

    while (numCases--){
        distance = 0;

        cin >> x1 >> y1;

        getline(cin, streetCoordinates);

        while (getline(cin, streetCoordinates)){
            if (streetCoordinates.empty()) break;

            stringstream ss(streetCoordinates);

            ss >> x1 >> y1 >> x2 >> y2;

            distance += hypot(x2 - x1, y2 - y1);
        }

        minutes = modf(distance * 2.0 / 1000.0 / VELOCITY, &hours);

        if (round(minutes * 60) >= 60.0){
            minutes = 0;
            hours += 1;
        }

        cout << hours << ":" << setfill('0') << setw(2) << round(minutes * 60) << endl;

        if (numCases) cout << '\n';
    }
}