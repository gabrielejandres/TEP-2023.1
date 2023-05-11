/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 4 | Problema D | The Door Problem
*/

#include <iostream>
#include <string.h>

using namespace std;

const int N = 2e5 + 105;
int headEdge[N], totalEdges = 0; 
int destination[N << 1], nextEdge[N << 1];
int controlIndex, stackTop, totalSCC;
bool inVertexStack[N];
int low[N], dfn[N], vertexStack[N], belongToSCC[N];

// adiciona uma aresta direcionada do vértice x para o vértice y
void addEdge(int x, int y) {
    destination[totalEdges] = y;
    nextEdge[totalEdges] = headEdge[x];
    headEdge[x] = totalEdges++;
}

// algoritmo de Tarjan para encontrar as componentes fortemente conectadas (SCC) do grafo
void getSCC(int x) {
    int i, y;
    low[x] = dfn[x] = ++controlIndex;
    vertexStack[stackTop++] = x;
    inVertexStack[x] = true;

    for (i = headEdge[x]; i != -1; i = nextEdge[i]){
        y = destination[i];
        if (!dfn[y]){
            getSCC(y);
            if(low[x] > low[y] ) low[x] = low[y];
        }
        else if (inVertexStack[y] && low[x] > dfn[y]) low[x] = dfn[y];
    }

    if (low[x] == dfn[x]){
        totalSCC++;
        do {
            y = vertexStack[--stackTop];
            inVertexStack[y] = false;
            belongToSCC[y] = totalSCC;
        } while(y != x);
    }
}

int main() {
    int i, x, controlledRooms, possible, numRooms, numSwitches, doorStatus[N], controlx[N], controly[N];

    cin >> numRooms;
    cin >> numSwitches;
    for (i = 1; i <= numRooms; ++i) cin >> doorStatus[i];

    totalEdges = 0;
    memset(headEdge, -1, sizeof(headEdge));

    for (i = 1; i <= numSwitches; ++i) {
        cin >> controlledRooms;
        while (controlledRooms--){
            cin >> x;
            if (!controlx[x]) controlx[x] = i;
            else controly[x] = i;
        }
    }

    for (i = 1; i <= numRooms; ++i){
        if (doorStatus[i]){
            addEdge(controlx[i], controly[i]);
            addEdge(controly[i], controlx[i]);
            addEdge(controlx[i] + numSwitches, controly[i] + numSwitches);
            addEdge(controly[i] + numSwitches, controlx[i] + numSwitches);
        }
        else {
            addEdge(controlx[i], controly[i] + numSwitches);
            addEdge(controly[i], controlx[i] + numSwitches);
            addEdge(controlx[i] + numSwitches, controly[i]);
            addEdge(controly[i] + numSwitches, controlx[i]);
        }
    }

    memset(dfn, 0, sizeof(dfn));
    memset(inVertexStack, false, sizeof(inVertexStack));
    controlIndex = stackTop = totalSCC = 0;
    for(i = 1; i <= numSwitches * 2; ++i)
        if(!dfn[i]) getSCC(i);

    possible = 1;
    for (i = 1; i <= numSwitches; ++i) {
        if (belongToSCC[i] == belongToSCC[i + numSwitches]){
            possible = 0; 
            break;
        }
    }

    cout << (possible ? "YES" : "NO") << endl;

    return 0;
}
