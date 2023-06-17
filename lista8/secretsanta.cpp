/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 9 (Lista 8) | Problema B | Secret Santa
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int numCases, numParticipants, fulfilledWishes, availableEmployees, a, i;
    vector<int> wishes;
    map<int, int> wishesByEmployee;

    cin >> numCases;

    while (numCases--) {       
        cin >> numParticipants;

        wishes.resize(numParticipants);
        wishesByEmployee.clear();

        fulfilledWishes = numParticipants;
        availableEmployees = numParticipants;

        for (i = 0; i < numParticipants; i++) {
            cin >> a;
            wishesByEmployee[a]++;
            wishes[i] = a;
        }

        for (i = 0; i < numParticipants; i++) {
            while (wishesByEmployee[availableEmployees] != 0)
                availableEmployees--;

            if (wishesByEmployee[wishes[i]] > 1) {
                if (i == availableEmployees) continue;               
               
                wishesByEmployee[wishes[i]]--;
                wishes[i] = availableEmployees;
                wishesByEmployee[availableEmployees]++;
                
                fulfilledWishes--;
            }
        }

        cout << fulfilledWishes << endl;

        for (i = 0; i < numParticipants; i++)
            cout << wishes[i] << ' ';

        cout << '\n';

        wishes.clear();
    }

    return 0;
}