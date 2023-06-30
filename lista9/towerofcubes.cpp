/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 10 (Lista 9) | Problema E | Tower of Cubes
*/

#include <iostream>
#include <vector>

#define MAX_CUBES 500
#define FACES 6

using namespace std;

int main() {
    int i, j, caseNumber = 1, numCubes, face, face2, opposite, prevIdx, maxLen, endIndex, endFace;
    string sides[6] = { "front", "back", "left", "right", "top", "bottom" }, entry;

    while (cin >> numCubes && numCubes != 0) {
        vector<vector<int>> cubes(numCubes, vector<int>(FACES));
        vector<vector<int>> longestSeq(numCubes, vector<int>(FACES, 1));
        vector<vector<vector<int>>> previousCubeFace(numCubes, vector<vector<int>>(FACES, vector<int>(2)));
        vector<string> tower;

        if (caseNumber > 1) cout << endl;

        for (i = 0; i < numCubes; i++) {
            for (j = 0; j < FACES; j++) {
                cin >> cubes[i][j];
                previousCubeFace[i][j][0] = i;
                previousCubeFace[i][j][1] = 0;
            }
        }

        maxLen = 1, endIndex = 0, endFace = 0;
        for (i = 1; i < numCubes; i++) {
            for (j = 0; j < i; j++) {
                for (face = 0; face < FACES; face++) {
                    for (face2 = 0; face2 < FACES; face2++) {
                        opposite = (face2 % 2) ? face2 - 1 : face2 + 1;
                        if (cubes[i][face] == cubes[j][opposite] && longestSeq[i][face] < longestSeq[j][face2] + 1) {
                            longestSeq[i][face] = longestSeq[j][face2] + 1;
                            previousCubeFace[i][face][0] = j;
                            previousCubeFace[i][face][1] = face2;
                            if (longestSeq[i][face] > maxLen) {
                                maxLen = longestSeq[i][face];
                                endIndex = i;
                                endFace = face;
                            }
                        }
                    }
                }
            }
        }

        while (previousCubeFace[endIndex][endFace][0] != endIndex) {
            prevIdx = endIndex;
            entry = to_string(endIndex + 1) + " " + sides[endFace];
            tower.push_back(entry);
            endIndex = previousCubeFace[endIndex][endFace][0];
            endFace = previousCubeFace[prevIdx][endFace][1];
        }
        entry = to_string(endIndex + 1) + " " + sides[endFace];
        tower.push_back(entry);

        cout << "Case #" << caseNumber++ << endl << tower.size() << endl;
        for (auto it = tower.rbegin(); it != tower.rend(); ++it)
            cout << *it << endl;
    }

    return 0;
}
